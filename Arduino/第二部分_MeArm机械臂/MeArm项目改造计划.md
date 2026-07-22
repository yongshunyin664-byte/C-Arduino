# MeArm 机械臂项目 · 学习与改造计划

> 目标:先跑通太极创客第二部分原版课程,再逐步用结构体、指针、传感器、OLED 改造,
> 把第 4 周的 Arduino 知识点全部串进这一个作品。

---

## 阶段 0:先做原版(建立基准)

按文件夹编号循序渐进,做到 `meArm6` 就是原课程完整终点。

| 顺序 | 文件夹 | 目标 |
|---|---|---|
| 1 | `2 直流伺服电机/sweep` | 确认单个舵机能动 |
| 2 | `5、6 控制伺服电机` | 串口控制舵机 |
| 3 | `7、8 数组` | 一维 / 二维数组 |
| 4 | `12、13 调试 / 控制速度` | 装上机械臂,调 `servoCmd` |
| 5 | `14、15、16 开发机械臂程序` | 一路做到 `meArm6`(最终版) |

**终点:** `meArm6` = 指令模式 + 手柄模式,能通过串口完整控制机械臂。

### ⚠️ 两个关键提醒

- **舵机极限值按自己的机械臂改**:代码里的 `baseMin/baseMax` 等是太极创客那套的值。
  装好后先用 `sweep` 或手柄模式慢慢试每个关节的实际安全范围,再填进 `const`,
  否则可能把结构件顶坏。
- **舵机独立供电**:4 个舵机同时动,Arduino 的 5V 带不动。必须用独立 5V 电源给舵机,
  并与 Arduino **共地**。否则会出现舵机抖动 / 板子重启的怪现象。

---

## 阶段 1:结构体 + 指针改造(功能不变,先练语法)

**原则:功能和原版一模一样,只改代码结构。** 编译烧录后动作应与原版一致,风险最低。

### 痛点 → 改造理由

1. 4 个舵机是 4 个孤立全局变量 + 8 个孤立 `const` → **用结构体打包**
2. `servoCmd` 里 60 行大 switch,只为"按代号找舵机 + 极限值" → **结构体数组 + 指针查找**
3. `Servo servo2go = base;` 复制了整个舵机对象 → **改用指针,指向而非复制**

### 核心代码骨架

```cpp
#include <Servo.h>

struct ServoJoint {
  Servo servo;    // 舵机对象
  char  name;     // 代号 'b' 'r' 'f' 'c'
  int   minPos;   // 最小角度
  int   maxPos;   // 最大角度
  int   pin;      // 引脚
};

// 一个数组管住全部关节,取代 4 个全局变量 + 8 个 const
ServoJoint joints[4] = {
  { Servo(), 'b', 0,  180, 11 },
  { Servo(), 'r', 45, 180, 10 },
  { Servo(), 'f', 35, 120, 9  },
  { Servo(), 'c', 25, 100, 6  }
};

void setup() {
  for (int i = 0; i < 4; i++) {
    joints[i].servo.attach(joints[i].pin);
    delay(200);
    joints[i].servo.write(90);
  }
  Serial.begin(9600);
}

// 按代号返回指针;找不到返回 nullptr
ServoJoint* findJoint(char name) {
  for (int i = 0; i < 4; i++) {
    if (joints[i].name == name) return &joints[i];  // 取地址→返回指针
  }
  return nullptr;
}

// 原来 60 行 switch → 现在十几行
void servoCmd(char servoName, int toPos, int servoDelay) {
  ServoJoint *j = findJoint(servoName);
  if (j == nullptr) { Serial.println("+Warning: Unknown servo!"); return; }

  if (toPos < j->minPos || toPos > j->maxPos) {   // -> 访问指针成员
    Serial.print("+Warning: "); Serial.print(servoName);
    Serial.println(" out of limit!");
    return;
  }

  int fromPos = j->servo.read();
  int stepDir = (fromPos <= toPos) ? 1 : -1;
  for (int i = fromPos; i != toPos; i += stepDir) {
    j->servo.write(i);
    delay(servoDelay);
  }
  j->servo.write(toPos);
}
```

**验收:** 机械臂动作与原版一致,但加第 5 个舵机只需在数组里加一行。

---

## 阶段 2:加 OLED(0.96" I2C)

把原来只发串口的 `reportStatus` 同步显示到屏幕。传数组时传指针,不复制整个数组。

```cpp
#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled(U8G2_R0);

// 参数是指针:只传地址,省 RAM
void showOnOLED(ServoJoint *arr, int distance) {
  oled.clearBuffer();
  oled.setFont(u8g2_font_6x10_tf);
  for (int i = 0; i < 4; i++) {
    oled.setCursor(0, 12 + i * 12);
    oled.print(arr[i].name); oled.print(": ");
    oled.print(arr[i].servo.read());
  }
  oled.setCursor(70, 12);
  oled.print("D:"); oled.print(distance);
  oled.sendBuffer();
}
// 调用:showOnOLED(joints, 距离);  数组名 joints 本身就是指针
```

---

## 阶段 3:加传感器(超声波 HC-SR04,补第 3 周缺口)

新增"自动感知模式":手 / 物体靠近爪子 → 自动夹取。

```cpp
#include <NewPing.h>
NewPing sonar(7, 8, 30);   // Trig=7, Echo=8, 最大 30cm

void autoGrabCheck() {
  int distance = sonar.ping_cm();
  if (distance > 0 && distance < 8) {   // 8cm 内有物体
    Serial.println("Object detected -> Auto Grab!");
    servoCmd('c', joints[3].minPos, DSD);  // 闭合爪子
  }
}
```

> 备选:嫌超声波麻烦,可用电位器 `analogRead` 直接控制舵机角度,同样补"模拟输入",接线更简单。

---

## 最终架构

```
┌─────────────────────────────────────┐
│  struct ServoJoint  →  joints[4]     │  ← 结构体 + 数组
├─────────────────────────────────────┤
│  findJoint(char) → ServoJoint*       │  ← 指针查找
├─────────────────────────────────────┤
│  loop():                             │
│   ├ 串口有指令? → 指令 / 手柄模式     │  ← 串口(已有)
│   ├ autoGrabCheck()                  │  ← 超声波传感器
│   └ showOnOLED(joints, dist)         │  ← OLED + 指针传数组
└─────────────────────────────────────┘
```

## 知识点覆盖对照

| 知识点 | 落在哪 |
|---|---|
| 结构体 | `ServoJoint` 打包舵机信息 |
| 指针 | `findJoint` 返回指针、`servoCmd` 用 `->`、显示函数传数组指针 |
| 传感器 | HC-SR04 超声波(或电位器) |
| 串口 | 已有,保留 |
| OLED | `showOnOLED` 显示状态 |
| 数组 / 函数 | 已有,结构体数组进一步强化 |

---

## 动手顺序(每步单独验证,不一次堆太多)

1. ✅ 跑通原版 `meArm6`
2. ⬜ 结构体 + 指针改造(功能不变,先编译确认动作一致)
3. ⬜ 加 OLED,显示状态
4. ⬜ 加超声波,做自动夹取模式
5. ⬜ 代码整理成函数模块

> 跑通原版后,可以让 Claude 把"阶段 1 结构体+指针改造版"写成完整可编译 `.ino`,对照学习。

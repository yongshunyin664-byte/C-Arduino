# Arduino学习清单

- [ ] 学习串口通信 Serial.begin() / Serial.println()
- [ ] 用串口监视器查看调试数据
- [ ] 学习蜂鸣器 tone()
- [ ] 读取 DHT11 温湿度传感器
- [ ] 读取光敏电阻
- [ ] 读取 HC-SR04 超声波测距传感器
- [ ] 把功能代码封装成函数

## 1. 串口通信 Serial.begin() / Serial.println()

串口是 Arduino 和电脑之间**通信的通道**，用于发送调试信息。

```c
void setup() {                       // setup() 上电/复位后只执行 1 次，专门做初始化
  Serial.begin(9600);                // 开启硬件串口通信，波特率 9600 bps
                                     // 波特率 = 每秒传输的 bit 数，9600 是最常用的
                                     // 电脑串口监视器右下角必须也选 9600，否则显示乱码
  Serial.println("Hello Arduino!");  // 通过串口向电脑发送一行文字，末尾自动加换行
                                     // println = print + line（换行）
  Serial.print("Temperature: ");     // Serial.print() 不换行，适合拼接输出
  Serial.print(25);
  Serial.println(" °C");             // 最后补上换行
}                                    // 输出：Temperature: 25 °C

void loop() {
  // 通常在这里持续打印传感器数据
}
```

### 接线

| Arduino | 电脑 |
|---------|------|
| USB 口 | USB 线 → 电脑 |

> 串口走 USB 线，不需要额外接线。上传程序时串口也会被占用。

## 2. 用串口监视器查看调试数据

串口监视器是调试利器——**别人看不见的，它看得见**。

```c
int sensorValue = 0;                 // 全局变量，存储传感器读数

void setup() {
  Serial.begin(9600);                // 开启串口
  Serial.println("=== 程序启动 ==="); // 启动提示
}

void loop() {
  sensorValue = analogRead(A0);      // 读取 A0 模拟值（0~1023）
  
  Serial.print("传感器值: ");         // 标签 + 数值，便于阅读
  Serial.println(sensorValue);
  
  // 用 if 判断范围，加调试注释
  if (sensorValue > 800) {
    Serial.println("  → 环境很亮");
  } else if (sensorValue > 400) {
    Serial.println("  → 环境中等");
  } else {
    Serial.println("  → 环境很暗");
  }
  
  delay(500);                        // 每 0.5s 打印一次，太快人眼看不过来
}
```

- 工具 → 串口监视器（快捷键 Ctrl+Shift+M）
- 波特率必须匹配（代码 9600 → 监视器选 9600）
- 在代码里写 `Serial.println()`，就像在代码各个角落装了"摄像头"

## 3. 蜂鸣器 tone()

`tone(pin, frequency)` 让无源蜂鸣器发出指定频率的声音。`noTone(pin)` 停止发声。

```c
int buzzerPin = 8;                   // 定义全局变量，蜂鸣器接在 8 号数字引脚
                                     // 用变量代替硬编码，方便改引脚

void setup() {                       // setup() 上电/复位后只执行 1 次
  pinMode(buzzerPin, OUTPUT);        // 蜂鸣器引脚设为 OUTPUT 输出模式
}                                    // tone() 驱动需要 OUTPUT 模式

void loop() {                        // loop() 无限循环反复执行
  // 基础用法：发出 1000Hz 声音，持续 500ms，停 300ms
  tone(buzzerPin, 1000);             // tone(引脚, 频率Hz)：输出 1000Hz 方波给蜂鸣器
                                     // 频率越高声音越尖，越低越低沉
                                     // 人耳可听范围约 20Hz ~ 20000Hz
  delay(500);                        // 保持发声 500 毫秒
  noTone(buzzerPin);                 // noTone(引脚)：停止方波输出，蜂鸣器静音
  delay(300);                        // 静音 300 毫秒
                                     // 循环 → 嘀...嘀...嘀...间歇音效果
}
```

### 进阶：播放简单旋律

```c
int buzzerPin = 8;

// 频率数组：Do Re Mi Fa So La Si Do
int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
int noteCount = 8;                   // 音符数量

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < noteCount; i++) {
    tone(buzzerPin, melody[i]);      // 按数组中的频率依次发音
    delay(300);                      // 每个音符持续 300ms
  }
  noTone(buzzerPin);                 // 全部播完后静音
  delay(1000);                       // 停 1 秒再重复
}
```

### 常用频率参考

| 音符 | 频率(Hz) |
|:---:|:---:|
| Do | 262 |
| Re | 294 |
| Mi | 330 |
| Fa | 349 |
| So | 392 |
| La | 440 |
| Si | 494 |
| Do(高) | 523 |

### 接线

| 元件 | 连接 |
|------|------|
| 无源蜂鸣器正极(+) | Arduino **8 号引脚** |
| 无源蜂鸣器负极(-) | Arduino **GND** |

> ⚠ 必须用**无源蜂鸣器**（底部无封胶/绿色电路板可见）。有源蜂鸣器（底部封胶）通电就响固定频率，`tone()` 控制不了音高。

## 4. 读取 DHT11 温湿度传感器

DHT11 是数字温湿度传感器，可以同时读取温度和湿度。

```c
#include <DHT.h>                     // 导入 DHT 传感器库
                                     // 需要在 Arduino IDE 中安装：工具 → 管理库 → 搜索 "DHT sensor library"

#define DHTPIN 2                     // #define 宏定义：DHTPIN 就代表 2，数据引脚接 2 号引脚
#define DHTTYPE DHT11                // 定义传感器型号为 DHT11（如果是 DHT22 就写 DHT22）

DHT dht(DHTPIN, DHTTYPE);            // 创建 DHT 对象 dht，传入引脚和型号

void setup() {
  Serial.begin(9600);                // 开启串口，波特率 9600
  Serial.println("DHT11 温湿度测试");
  dht.begin();                       // 初始化 DHT11 传感器
}

void loop() {
  delay(2000);                       // DHT11 读取间隔至少 2 秒（传感器内部采样速度有限）

  float humidity = dht.readHumidity();        // 读取湿度，返回浮点数（%）
  float temperature = dht.readTemperature();  // 读取温度，返回浮点数（℃）

  if (isnan(humidity) || isnan(temperature)) { // isnan() 判断是否读取失败（返回 NaN）
    Serial.println("读取 DHT11 失败！请检查接线");
    return;                                      // 提前结束本次 loop，不执行后面的打印
  }

  Serial.print("湿度: ");
  Serial.print(humidity);
  Serial.print(" %\t");              // \t 是制表符（Tab），让输出对齐
  Serial.print("温度: ");
  Serial.print(temperature);
  Serial.println(" °C");
}
```

### 元件与接线

### 需要准备的元件

| 元件 | 数量 | 说明 |
|------|:---:|------|
| DHT11 模块（带小板） | 1 | 三脚：VCC/DATA/GND |
| 公对母杜邦线 | 3 | 连接模块和 Arduino |

### 引脚连接表

| DHT11 模块引脚 | Arduino 引脚 | 说明 |
|:---:|:---:|------|
| **VCC (+)** | **5V** | 供电正极 |
| **DATA (OUT)** | **2** | 数据信号线 |
| **GND (-)** | **GND** | 供电负极 |

> ⚠ DHT11 模块上通常有上拉电阻，直接接三根线即可。如果模块是裸传感器（四脚），需要在 DATA 和 VCC 之间接 4.7kΩ~10kΩ 上拉电阻。
>
> 信号流：DHT11 感应温湿度 → 输出数字信号 → 2 号引脚读取 → `dht.readHumidity()` / `dht.readTemperature()` 解出数值。

## 5. 读取光敏电阻

光敏电阻的阻值随光照强度变化：**光越强，阻值越小**。

```c
int ldrPin = A0;                     // 光敏电阻接模拟引脚 A0
                                     // 模拟引脚读取连续变化的电压值
int ledPin = 13;                     // 板载 LED 接 13 号引脚

void setup() {
  Serial.begin(9600);                // 开启串口，波特率 9600
  pinMode(ledPin, OUTPUT);           // LED 引脚设为 OUTPUT 输出模式
}

void loop() {
  int lightValue = analogRead(ldrPin); // analogRead(模拟引脚)：读取 A0 的电压值
                                       // 返回 0~1023（0=最暗/0V，1023=最亮/5V）
                                       // 值越大表示光越强（阻值越小，分压越大）

  Serial.print("光照值: ");
  Serial.println(lightValue);

  if (lightValue < 300) {            // 光线暗（自己根据实际环境调整阈值）
    digitalWrite(ledPin, HIGH);      // 点亮 LED 作为补光
    Serial.println("  → 暗，自动开灯");
  } else {
    digitalWrite(ledPin, LOW);       // 光线够，熄灭 LED
    Serial.println("  → 亮，自动关灯");
  }

  delay(500);                        // 每 0.5s 检测一次
}
```

### 需要准备的元件

| 元件 | 数量 | 说明 |
|------|:---:|------|
| 光敏电阻（LDR / GL5528） | 1 | 光照越强阻值越小 |
| 10kΩ 电阻（棕黑橙金） | 1 | **分压电阻**，和光敏电阻串联 |
| 公对公杜邦线 | 若干 | 连接面包板和 Arduino |

### 面包板接线图

```
          ┌──────────────────────────────────────────────────────┐
          │                    面包板                             │
          │                                                      │
          │   【分压电路】                                        │
          │   5V ─── 光敏电阻 ───┬─── A0（模拟信号读取）          │
          │                      │                               │
          │                      └─── 10kΩ电阻 ─── GND            │
          │                                                      │
          │   原理：光敏电阻 + 10kΩ 固定电阻 构成分压电路          │
          │   光照强 → 光敏阻值↓ → A0 电压↑ → analogRead 值↑      │
          │   光照弱 → 光敏阻值↑ → A0 电压↓ → analogRead 值↓      │
          └──────────────────────────────────────────────────────┘
```

### 引脚连接表

| Arduino 引脚 | 连接到 | 说明 |
|:---:|------|------|
| **5V** | 光敏电阻脚① | 提供 5V 电压 |
| **A0** | 光敏电阻脚② + 10kΩ → GND | 读取分压点的电压 |
| **GND** | 10kΩ 电阻另一端 | 分压电路接地 |
| **13** | LED 长脚(+)（220Ω 限流） | 输出控制 LED |

> 信号流：光照变化 → 光敏电阻阻值变化 → 分压点电压变化 → A0 analogRead 读数变化 → 代码判断控制 LED

## 6. 读取 HC-SR04 超声波测距传感器

HC-SR04 通过发射超声波并接收回波来计算距离。

```c
int trigPin = 9;                     // Trig（触发）引脚接 9 号数字引脚
                                     // 发送 10μs 高电平脉冲，触发超声波发射
int echoPin = 10;                    // Echo（回波）引脚接 10 号数字引脚
                                     // 返回高电平，高电平持续时间 = 超声波往返时间

void setup() {
  Serial.begin(9600);                // 开启串口，波特率 9600
  pinMode(trigPin, OUTPUT);          // Trig 是输出引脚（Arduino → 传感器）
  pinMode(echoPin, INPUT);           // Echo 是输入引脚（传感器 → Arduino）
}

void loop() {
  // 步骤1：发送触发信号
  digitalWrite(trigPin, LOW);        // 先确保 Trig 为低电平
  delayMicroseconds(2);              // 保持 2 微秒（稳定）
  digitalWrite(trigPin, HIGH);       // 拉高 Trig
  delayMicroseconds(10);             // 保持 10 微秒高电平 → 传感器发射 8 个 40kHz 超声波
  digitalWrite(trigPin, LOW);        // 拉低 Trig，发射完毕

  // 步骤2：读取回波时间
  long duration = pulseIn(echoPin, HIGH); // pulseIn(引脚, HIGH)：测量 Echo 引脚高电平持续的时间
                                          // 返回微秒数（μs）
                                          // 这个时间就是超声波从发射到收到回波的总时间

  // 步骤3：计算距离
  float distance = duration * 0.034 / 2;  // 距离 = 时间 × 声速 ÷ 2
                                          // 声速 ≈ 340 m/s = 0.034 cm/μs
                                          // ÷ 2 是因为时间是往返（来回），距离只要单程

  Serial.print("距离: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {               // 距离小于 10cm 时报警
    Serial.println("  ⚠ 太近了！");
  }

  delay(200);                        // 每 200ms 测一次
}
```

### 工作原理

```
          HC-SR04 传感器
          ┌─────────────┐
Trig ◄── │  发射超声波  │  →→→ 遇到障碍物 →→→ 反射回来
          │             │
Echo ──► │  接收回波    │  ←←← 收到反射波 ←←←
          └─────────────┘

  时间线：
  ──┬──────┬──────────────────────┬────
    Trig   Echo=HIGH（回波在路上） Echo=LOW（收到）
    触发   开始计时               停止计时
    
  距离 = 声速 × 时间 ÷ 2
```

### 需要准备的元件

| 元件 | 数量 | 说明 |
|------|:---:|------|
| HC-SR04 超声波模块 | 1 | 四脚：VCC/Trig/Echo/GND |
| 公对母杜邦线 | 4 | 连接模块和 Arduino |

### 引脚连接表

| HC-SR04 引脚 | Arduino 引脚 | 说明 |
|:---:|:---:|------|
| **VCC** | **5V** | 供电正极 |
| **Trig** | **9** | 触发信号（Arduino 输出） |
| **Echo** | **10** | 回波信号（Arduino 输入） |
| **GND** | **GND** | 供电负极 |

> 信号流：Trig 发脉冲 → 传感器发射超声波 → 遇到障碍物反射 → Echo 收到回波 → `pulseIn()` 测时间 → 公式算距离。

## 7. 把功能代码封装成函数

随着代码越来越复杂，把每个功能封装成独立函数，让代码清晰好维护。

```c
// ========== 改造前：所有代码都堆在 loop() 里 ==========
void loop() {
  // 读取 DHT11...
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("湿度: "); Serial.print(h);
  Serial.print(" %\t温度: "); Serial.print(t); Serial.println(" °C");

  // 读取光敏...
  int light = analogRead(A0);
  Serial.print("光照: "); Serial.println(light);
  if (light < 300) { digitalWrite(13, HIGH); }
  else { digitalWrite(13, LOW); }

  // 测距...
  digitalWrite(9, LOW); delayMicroseconds(2);
  digitalWrite(9, HIGH); delayMicroseconds(10);
  digitalWrite(9, LOW);
  long d = pulseIn(10, HIGH);
  float dist = d * 0.034 / 2;

  delay(1000);
}

// ========== 改造后：每个功能封装成函数 ==========
int buzzerPin = 8;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  readDHT11();                       // 读温湿度，函数名一看就知道做什么
  readLight();                       // 读光敏电阻
  float dist = readDistance();       // 读距离，返回值存到变量
  checkAlarm(dist);                  // 根据距离决定是否报警
  delay(1000);
}

// ---- 各功能函数定义 ----
void readDHT11() {                   // 封装 DHT11 读取
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (!isnan(h) && !isnan(t)) {
    Serial.print("湿度: "); Serial.print(h);
    Serial.print(" %\t温度: "); Serial.print(t); Serial.println(" °C");
  }
}

void readLight() {                   // 封装光敏电阻读取
  int light = analogRead(A0);
  Serial.print("光照: "); Serial.print(light);
  if (light < 300) {
    digitalWrite(13, HIGH);
    Serial.println(" → 开灯");
  } else {
    digitalWrite(13, LOW);
    Serial.println(" → 关灯");
  }
}

float readDistance() {               // 封装距离测量，返回 float
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;       // return 返回计算结果
}

void checkAlarm(float dist) {        // 封装报警判断
  Serial.print("距离: "); Serial.print(dist); Serial.println(" cm");
  if (dist < 10) {
    Serial.println("  ⚠ 太近了！");
    tone(buzzerPin, 1000);           // 蜂鸣器报警
    delay(200);
    noTone(buzzerPin);
  }
}
```

> 封装的好处：loop() 一目了然，要改某个功能只改对应的函数，方便调试和复用。

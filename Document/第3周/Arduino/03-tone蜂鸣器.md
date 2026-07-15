# 蜂鸣器 tone()

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

## 使用注意
- 阅读示例代码时，注意变量类型和条件表达式的写法。
- 复制代码前确认引脚、输入/输出和循环边界是否适合当前项目。
- Arduino 代码中，使用 pinMode()、digitalRead()、digitalWrite()、analogRead()、analogWrite() 和 tone() 时，要确保对应引脚已正确接线。
- 编写循环时，避免死循环和错误的终止条件。
- 使用 break 和 continue 时，确认它们是否会影响循环逻辑。

# 蜂鸣器 tone()

`tone(pin, frequency)` 发出指定频率的声音。

```c
int buzzerPin = 8;               // 定义全局变量 buzzerPin，蜂鸣器接在 8 号数字引脚

void setup() {                   // setup() 上电/复位后只执行 1 次，专门做初始化
  pinMode(buzzerPin, OUTPUT);    // pinMode(引脚, 模式)：设置 8 号引脚为 OUTPUT 输出模式
}                                // 蜂鸣器由 tone() 驱动，但引脚仍需设为 OUTPUT

void loop() {                    // loop() 无限循环反复执行，是程序主体
  tone(buzzerPin, 1000);         // tone(引脚, 频率)：让 8 号引脚输出 1000Hz（1kHz）的方波
                                 // 蜂鸣器发出 1000Hz 的持续音
                                 // 频率越高声音越尖，越低越低沉
  delay(500);                    // 暂停 500 毫秒 = 0.5 秒，保持发声
  noTone(buzzerPin);             // noTone(引脚)：停止 8 号引脚的方波输出
                                 // 蜂鸣器停止发声
  delay(500);                    // 再暂停 500 毫秒，保持静音 0.5 秒
}                                // loop() 结束，回到开头继续循环 → 发出嘀-嘀-嘀的间歇音
```

## 使用注意
- 阅读示例代码时，注意变量类型和条件表达式的写法。
- 复制代码前确认引脚、输入/输出和循环边界是否适合当前项目。
- Arduino 代码中，使用 pinMode()、digitalRead()、digitalWrite()、analogRead()、analogWrite() 和 tone() 时，要确保对应引脚已正确接线。
- 编写循环时，避免死循环和错误的终止条件。
- 使用 break 和 continue 时，确认它们是否会影响循环逻辑。


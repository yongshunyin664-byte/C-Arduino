# digitalWrite() 控制引脚

`digitalWrite(pin, value)` 用于设置数字引脚为 `HIGH` 或 `LOW`。

```c
int ledPin = 13;                 // 定义全局整型变量 ledPin，赋值为 13（LED 接在 13 号数字引脚）
                                 // 用变量代替硬编码，方便后续修改引脚号

void setup() {                   // setup() 上电/复位后只执行 1 次，专门做初始化
  pinMode(ledPin, OUTPUT);       // pinMode(引脚, 模式)：设置 13 号引脚为 OUTPUT 输出模式
                                 // OUTPUT 模式用于控制外部设备（LED、继电器等）输出高低电平
}

void loop() {                    // loop() 无限循环反复执行，是程序主体
  digitalWrite(ledPin, HIGH);    // digitalWrite(引脚, 电平)：给 13 号引脚输出 HIGH（高电平）
                                 // HIGH = 5V，LED 通电点亮
  delay(500);                    // delay(毫秒)：程序暂停 500 毫秒 = 0.5 秒
                                 // 保持 LED 点亮 0.5 秒，什么都不做
  digitalWrite(ledPin, LOW);     // 给 13 号引脚输出 LOW（低电平）
                                 // LOW = 0V，LED 断电熄灭
  delay(500);                    // 再暂停 500 毫秒，保持熄灭 0.5 秒
}                                // loop() 结束，回到开头继续循环 → 实现闪烁效果
```

## 使用注意
- 阅读示例代码时，注意变量类型和条件表达式的写法。
- 复制代码前确认引脚、输入/输出和循环边界是否适合当前项目。
- Arduino 代码中，使用 pinMode()、digitalRead()、digitalWrite()、analogRead()、analogWrite() 和 tone() 时，要确保对应引脚已正确接线。
- 编写循环时，避免死循环和错误的终止条件。
- 使用 break 和 continue 时，确认它们是否会影响循环逻辑。


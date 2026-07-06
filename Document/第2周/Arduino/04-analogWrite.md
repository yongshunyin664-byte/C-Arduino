# analogWrite() 调节亮度

`analogWrite(pin, value)` 用于 PWM 输出，`value` 范围是 `0` 到 `255`。

```c
int ledPin = 9;                  // 定义全局变量 ledPin，LED 接在 9 号数字引脚
                                 // 注意：必须是支持 PWM 的引脚（标有 ~ 的引脚，如 ~9）

void setup() {                   // setup() 上电/复位后只执行 1 次，专门做初始化
  pinMode(ledPin, OUTPUT);       // pinMode(引脚, 模式)：设置 9 号引脚为 OUTPUT 输出模式
}                                // PWM 输出也是 OUTPUT 模式

void loop() {                    // loop() 无限循环反复执行，是程序主体
  for (int brightness = 0; brightness <= 255; brightness += 5) {
                                 // for(初始化; 循环条件; 每次迭代后的操作)
                                 // brightness 从 0 开始；≤255 时继续循环；每次 +5
    analogWrite(ledPin, brightness); // analogWrite(引脚, 值)：PWM 输出
                                     // 值范围 0~255，0=完全熄灭，255=最亮
                                     // 随着 brightness 逐渐增大，LED 从暗变亮
    delay(20);                   // 暂停 20 毫秒，让亮度变化人眼可见（逐渐呼吸效果）
  }                              // for 循环结束 → brightness 超过 255 后退出
                                 // loop() 回到开头，重新从 0 开始 → 循环呼吸效果
}
```

## 使用注意
- 阅读示例代码时，注意变量类型和条件表达式的写法。
- 复制代码前确认引脚、输入/输出和循环边界是否适合当前项目。
- Arduino 代码中，使用 pinMode()、digitalRead()、digitalWrite()、analogRead()、analogWrite() 和 tone() 时，要确保对应引脚已正确接线。
- 编写循环时，避免死循环和错误的终止条件。
- 使用 break 和 continue 时，确认它们是否会影响循环逻辑。


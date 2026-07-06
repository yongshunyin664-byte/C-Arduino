# analogRead() 读取电位器数值

`analogRead(pin)` 读取模拟引脚的电压值，返回 `0` 到 `1023`。

```c
int potPin = A0;                 // 定义全局变量 potPin，电位器接在模拟引脚 A0
                                 // 模拟引脚以 A 开头（A0~A5），专门读取连续变化的电压
int ledPin = 9;                  // LED 接在 9 号 PWM 引脚（标有 ~），用于亮度调节

void setup() {                   // setup() 上电/复位后只执行 1 次，专门做初始化
  pinMode(ledPin, OUTPUT);       // 设置 9 号引脚为 OUTPUT 输出模式（PWM 输出）
  Serial.begin(9600);            // 开启硬件串口通信，波特率 9600
                                 // 电脑串口监视器必须同步选 9600 才能看到数值
}                                // 注意：模拟输入引脚（A0）不需要 pinMode() 设置

void loop() {                    // loop() 无限循环反复执行，是程序主体
  int potValue = analogRead(potPin); // analogRead(模拟引脚)：读取 A0 的模拟电压值
                                     // 返回 0~1023（0=0V，1023=5V）
                                     // 存入局部变量 potValue，类型为 int
  Serial.println(potValue);      // 通过串口向电脑打印电位器的值
                                 // 可以在串口监视器中看到实时的数值变化
  int brightness = map(potValue, 0, 1023, 0, 255);
                                 // map(输入值, 输入最小值, 输入最大值, 输出最小值, 输出最大值)
                                 // 把电位器值 0~1023 按比例映射到亮度值 0~255
                                 // 存入局部变量 brightness
  analogWrite(ledPin, brightness); // 用映射后的值控制 LED 亮度
                                   // 旋动电位器 → LED 亮度随之变化
  delay(100);                    // 暂停 100 毫秒，让读取和更新稳定，避免抖动
}                                // loop() 结束，回到开头继续读取电位器
```

## 使用注意
- 阅读示例代码时，注意变量类型和条件表达式的写法。
- 复制代码前确认引脚、输入/输出和循环边界是否适合当前项目。
- Arduino 代码中，使用 pinMode()、digitalRead()、digitalWrite()、analogRead()、analogWrite() 和 tone() 时，要确保对应引脚已正确接线。
- 编写循环时，避免死循环和错误的终止条件。
- 使用 break 和 continue 时，确认它们是否会影响循环逻辑。


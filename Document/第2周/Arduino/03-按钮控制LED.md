# 用按钮控制 LED 亮灭

按钮按下时点亮 LED，松开时熄灭。

```c
int buttonPin = 2;               // 定义全局变量 buttonPin，按钮接在 2 号数字引脚
int ledPin = 13;                 // 定义全局变量 ledPin，LED 接在 13 号数字引脚
                                 // 全局变量：setup() 和 loop() 都能直接使用

void setup() {                   // setup() 上电/复位后只执行 1 次，专门做初始化
  pinMode(buttonPin, INPUT);     // 设置 2 号引脚为 INPUT 输入模式，用于读取按钮状态
  pinMode(ledPin, OUTPUT);       // 设置 13 号引脚为 OUTPUT 输出模式，用于控制 LED 亮灭
}

void loop() {                    // loop() 无限循环反复执行，是程序主体
  int buttonState = digitalRead(buttonPin); // digitalRead(引脚)：读取 2 号按钮引脚的电平
                                            // 返回 HIGH（按下，5V）或 LOW（松开，0V）
                                            // 存入局部变量 buttonState，类型为 int
  if (buttonState == HIGH) {     // 判断按钮是否被按下（读到高电平）
                                 // == 是比较运算符，= 是赋值运算符，写法不同不要混淆
    digitalWrite(ledPin, HIGH);  // 按钮按下 → 给 13 号引脚输出 HIGH，LED 点亮
  } else {                       // else：上述条件不成立时执行（即按钮松开）
    digitalWrite(ledPin, LOW);   // 按钮松开 → 给 13 号引脚输出 LOW，LED 熄灭
  }                              // if-else 语句块结束
}                                // loop() 结束，回到开头继续循环检测按钮
```

## 使用注意
- 阅读示例代码时，注意变量类型和条件表达式的写法。
- 复制代码前确认引脚、输入/输出和循环边界是否适合当前项目。
- Arduino 代码中，使用 pinMode()、digitalRead()、digitalWrite()、analogRead()、analogWrite() 和 tone() 时，要确保对应引脚已正确接线。
- 编写循环时，避免死循环和错误的终止条件。
- 使用 break 和 continue 时，确认它们是否会影响循环逻辑。


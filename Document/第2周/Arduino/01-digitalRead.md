# digitalRead() 读取按钮状态

`digitalRead(pin)` 用于读取数字引脚的电平，返回 `HIGH` 或 `LOW`。通常按钮连接到输入引脚。

```c
int buttonPin = 2;

void setup() {
  pinMode(buttonPin, INPUT);
}

void loop() {
  int state = digitalRead(buttonPin);
  if (state == HIGH) {
    // 按钮被按下
  }
}
```

## 使用注意
- 阅读示例代码时，注意变量类型和条件表达式的写法。
- 复制代码前确认引脚、输入/输出和循环边界是否适合当前项目。
- Arduino 代码中，使用 pinMode()、digitalRead()、digitalWrite()、analogRead()、analogWrite() 和 tone() 时，要确保对应引脚已正确接线。
- 编写循环时，避免死循环和错误的终止条件。
- 使用 break 和 continue 时，确认它们是否会影响循环逻辑。


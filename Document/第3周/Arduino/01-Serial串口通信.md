# 串口通信 Serial.begin() / Serial.println()

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

## 使用注意
- 阅读示例代码时，注意变量类型和条件表达式的写法。
- 复制代码前确认引脚、输入/输出和循环边界是否适合当前项目。
- Arduino 代码中，使用 pinMode()、digitalRead()、digitalWrite()、analogRead()、analogWrite() 和 tone() 时，要确保对应引脚已正确接线。
- 编写循环时，避免死循环和错误的终止条件。
- 使用 break 和 continue 时，确认它们是否会影响循环逻辑。

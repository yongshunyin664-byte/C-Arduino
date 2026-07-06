# Arduino学习清单

- [ ] 学习 `digitalRead()` 读取按钮状态
- [ ] 学习 `digitalWrite()` 控制引脚
- [ ] 用按钮控制 LED 亮灭
- [ ] 学习 `analogWrite()` 调节亮度
- [ ] 用电位器 `analogRead()` 读取数值
- [ ] 学习蜂鸣器 `tone()`

## 1. digitalRead() 读取按钮状态

`digitalRead(pin)` 用于读取数字引脚的电平，返回 `HIGH` 或 `LOW`。通常按钮连接到输入引脚。

```c
int buttonPin = 2;               // 定义全局整型变量 buttonPin，赋值为 2（按钮接在 2 号数字引脚）
                                 // 用变量代替硬编码数字，后面改引脚只需改这一行

void setup() {                   // setup() 上电/复位后只执行 1 次，专门做初始化
  pinMode(buttonPin, INPUT);     // pinMode(引脚, 模式)：设置 2 号引脚为 INPUT 输入模式
                                 // INPUT 模式用于读取外部信号（按钮、传感器等）
}                                // 注意：INPUT 模式下引脚处于高阻态，建议外接下拉/上拉电阻

void loop() {                    // loop() 无限循环反复执行，是程序主体
  int state = digitalRead(buttonPin); // digitalRead(引脚)：读取 2 号引脚的电平状态
                                      // 返回 HIGH（高电平，约 5V）或 LOW（低电平，约 0V）
                                      // 存入局部变量 state，类型是 int
  if (state == HIGH) {           // 判断 state 是否等于 HIGH（按钮按下时读到高电平）
                                 // == 是相等比较运算符，= 是赋值运算符，二者不要混淆
    // 按钮被按下                  // 条件成立时执行这里的代码（例如点亮 LED、发送串口消息等）
  }                              // if 语句块结束
}                                // loop() 结束，回到开头继续循环
```

## 2. digitalWrite() 控制引脚

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

## 3. 用按钮控制 LED 亮灭

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

## 4. analogWrite() 调节亮度

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

## 5. 用电位器 analogRead() 读取数值

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

## 6. 蜂鸣器 tone()

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

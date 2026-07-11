# 第二周 · Arduino 综合考题（120题）

> **范围**：digitalRead()、digitalWrite()、按钮控制LED、analogWrite()、analogRead()/电位器、tone()/蜂鸣器
> **题型**：选择题（60道） + 填空题（20道） + 判断题（15道） + 简答题（15道） + 综合编程题（10道）
> **满分**：120分（选择题每题1分共60分，填空题每题1分共20分，判断题每题1分共15分，简答题每题1分共15分，编程题每题1分共10分）

---

## 一、选择题（每题1分，共60分）

### digitalRead() 与按钮输入

**1.** `digitalRead(2)` 的返回值不可能是以下哪个？
A. `HIGH`
B. `LOW`
C. `0`
D. `255`

**2.** 在按钮电路中，下拉电阻的典型阻值是：
A. 220Ω
B. 1kΩ
C. 10kΩ
D. 100kΩ

**3.** 按钮松开时，如果2号引脚没有接下拉电阻，会发生什么？
A. digitalRead() 稳定返回 LOW
B. digitalRead() 稳定返回 HIGH
C. 引脚处于"悬空"状态，读到随机跳变的电平
D. Arduino 自动复位

**4.** 按钮的四个脚中，按下时哪两个脚之间导通？
A. ①和②
B. ①和④、②和③ 同时分别导通（①↔④, ②↔③）
C. ①和③、②和④ 交叉导通
D. 四个脚全部导通

**5.** 关于 `INPUT` 模式下的引脚状态，以下说法正确的是：
A. 引脚处于低阻态，不需要外接电阻
B. 引脚处于高阻态，建议外接上拉或下拉电阻
C. 引脚自动输出 5V
D. 引脚自动输出 0V

**6.** 以下代码中，`pinMode(buttonPin, INPUT)` 的作用是：
```c
int buttonPin = 2;
void setup() {
    pinMode(buttonPin, INPUT);
}
```
A. 将2号引脚设置为输出模式
B. 将2号引脚设置为输入模式，用于读取外部信号
C. 给2号引脚输出高电平
D. 读取2号引脚的当前电平

**7.** 按钮按下时 `digitalRead(2)` 返回 HIGH，说明按钮电路采用了什么接法？
A. 上拉电阻接法（电阻接VCC，按钮接GND）
B. 下拉电阻接法（电阻接GND，按钮接VCC）
C. 浮空接法
D. 内部上拉接法（INPUT_PULLUP）

**8.** 以下关于 Arduino UNO 数字引脚电平的描述，**错误**的是：
A. HIGH 约等于 5V
B. LOW 约等于 0V
C. HIGH 和 LOW 也可以用 1 和 0 表示
D. HIGH 约等于 3.3V

### digitalWrite() 与 LED 控制

**9.** `digitalWrite(13, HIGH)` 执行后，13号引脚的电平是：
A. 0V
B. 3.3V
C. 5V
D. 13V

**10.** LED 电路中串联 220Ω 电阻的主要作用是：
A. 提高亮度
B. 限流保护LED，防止烧坏
C. 改变LED颜色
D. 加快闪烁速度

**11.** 如果 LED 电路中不加限流电阻，直接接 5V 和 GND，会发生什么？
A. LED 正常工作
B. LED 不亮
C. LED 电流过大，可能烧坏
D. Arduino 自动断电保护

**12.** LED 长脚（正极）应该接在哪里？
A. GND
B. 信号输出引脚（经过限流电阻）
C. 直接接 5V
D. 接 A0 模拟输入

**13.** 以下关于 Arduino UNO 13号引脚的说法，正确的是：
A. 13号引脚不能用于输出
B. 13号引脚板载了一个LED，即使不外接LED也会同步闪烁
C. 13号引脚只能用于输入
D. 13号引脚不支持PWM

**14.** `delay(500)` 中的 500 表示：
A. 500秒
B. 500毫秒（0.5秒）
C. 500微秒
D. 500分钟

**15.** 如果想让 LED 以 1 秒亮、1 秒灭的节奏闪烁，delay 参数应设为：
A. delay(1)
B. delay(10)
C. delay(100)
D. delay(1000)

**16.** LED 接反了（长脚接GND，短脚接信号端）会怎样？
A. LED 烧坏
B. Arduino 烧坏
C. LED 不亮（二极管单向导电）
D. LED 更亮

**17.** 以下哪个 `pinMode()` 设置是正确的 LED 输出配置？
A. `pinMode(13, INPUT);`
B. `pinMode(13, OUTPUT);`
C. `pinMode(13, INPUT_PULLUP);`
D. `pinMode(13, PWM);`

### 按钮控制 LED 综合

**18.** 在按钮控制LED的项目中，按钮回路和LED回路的关系是：
A. 共用同一个回路
B. 两条回路完全独立，通过代码逻辑关联
C. 串联在同一个回路中
D. 并联在同一个回路中

**19.** 以下代码中，如果把 `if (buttonState == HIGH)` 误写成 `if (buttonState = HIGH)`，会发生什么？
```c
int buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
}
```
A. 编译报错
B. 条件永远为真，LED 一直亮（= 是赋值，值为 HIGH 非零即真）
C. 条件永远为假，LED 一直灭
D. 正常运行，没有区别

**20.** 在按钮控制LED的代码中，`buttonState` 变量的类型是：
A. `char`
B. `float`
C. `int`
D. `bool`

**21.** 按钮按下时 LED 亮、松开时灭，这个逻辑的核心判断语句是：
A. `while (buttonState == HIGH)`
B. `if (buttonState == HIGH) ... else ...`
C. `for (;;)`
D. `switch (buttonState)`

**22.** 以下关于全局变量的说法，**正确**的是：
```c
int buttonPin = 2;  // 在 setup() 和 loop() 之外定义
int ledPin = 13;
```
A. 只能在 setup() 中使用
B. 只能在 loop() 中使用
C. setup() 和 loop() 都能直接使用
D. 必须用 `extern` 关键字才能使用

**23.** `pinMode()` 函数通常放在哪里？
A. loop() 函数中
B. setup() 函数中
C. 任意位置都可以
D. 不能放在任何函数中

### analogWrite() 与 PWM

**24.** `analogWrite(9, 128)` 中，第二个参数 128 表示：
A. 电压为 1.28V
B. 50% 占空比（约 2.5V 等效电压）
C. 128Hz 频率
D. 128mA 电流

**25.** `analogWrite()` 的第二个参数取值范围是：
A. 0~1023
B. 0~255
C. 0~5
D. 0~65535

**26.** Arduino UNO 上支持 PWM 的引脚是：
A. 所有数字引脚
B. 所有模拟引脚
C. 3, 5, 6, 9, 10, 11（标有 ~ 的引脚）
D. 0, 1, 2, 4, 7, 8

**27.** 如果把 LED 插在 2 号引脚（非PWM引脚），然后调用 `analogWrite(2, 128);`，会发生什么？
A. LED 以一半亮度发光
B. LED 全亮
C. 编译报错
D. 没有 PWM 效果，可能不亮或表现异常

**28.** `analogWrite()` 本质上是通过什么方式实现亮度调节的？
A. 改变输出电压的幅度
B. PWM（脉冲宽度调制）——快速开关模拟等效电压
C. 改变电流大小
D. 改变电阻值

**29.** 以下哪段代码实现 LED 从暗到亮的呼吸效果？
A.
```c
for (int b = 255; b >= 0; b -= 5) {
    analogWrite(9, b);
    delay(20);
}
```
B.
```c
for (int b = 0; b <= 255; b += 5) {
    analogWrite(9, b);
    delay(20);
}
```
C.
```c
digitalWrite(9, HIGH);
delay(1000);
```
D.
```c
analogWrite(9, 0);
delay(1000);
analogWrite(9, 255);
```

**30.** 呼吸灯代码中 `for (int brightness = 0; brightness <= 255; brightness += 5)` 中的 `brightness += 5` 表示：
A. 亮度每次增加5倍
B. 亮度值每次增加5（步进值，控制变化速度）
C. 亮度加5秒
D. 循环执行5次

**31.** 在呼吸灯代码中，如果把 `delay(20)` 改成 `delay(1000)`，会看到什么效果？
A. LED 变化更快
B. LED 变化更慢，每步间隔1秒
C. LED 直接最亮
D. 没有变化

**32.** `analogWrite()` 写 0 和 `digitalWrite()` 写 LOW 的区别是什么？
A. 没有区别，都是输出0V
B. analogWrite(0) 输出 0V（占空比0%），digitalWrite(LOW) 输出 0V，效果相同
C. analogWrite(0) 输出 5V
D. digitalWrite(LOW) 不能用

**33.** PWM 占空比为 50% 时，LED 的等效电压约为：
A. 0V
B. 2.5V
C. 5V
D. 1.25V

**34.** 以下关于 `pinMode()` 在 PWM 输出中的说法，正确的是：
A. PWM 输出需要 `pinMode(pin, PWM)`
B. PWM 输出仍然是 `pinMode(pin, OUTPUT)`，不需要特殊模式
C. PWM 输出不需要 pinMode 设置
D. PWM 输出需要 `pinMode(pin, ANALOG)`

### analogRead() 与电位器

**35.** `analogRead(A0)` 的返回值范围是：
A. 0~255
B. 0~1023
C. 0~5
D. 0~65535

**36.** 为什么 `analogRead()` 的范围是 0~1023？
A. Arduino UNO 的 ADC（模数转换器）是 10 位的（2¹⁰ = 1024）
B. 厂家随意定的
C. 因为电压范围是 0~5V
D. 因为 1023 = 255 × 4

**37.** Arduino UNO 的模拟输入引脚有哪些？
A. 0~13
B. A0~A5
C. D0~D13
D. PWM0~PWM5

**38.** 电位器三个脚的典型接法是：
A. 左脚接GND，中间脚接A0，右脚接5V
B. 左脚接5V，中间脚接A0，右脚接GND
C. 左脚接A0，中间脚接5V，右脚接GND
D. 左脚接GND，中间脚接5V，右脚接A0

**39.** 模拟输入引脚（如 A0）在使用 `analogRead()` 之前是否需要 `pinMode()` 设置？
A. 需要 `pinMode(A0, INPUT)`
B. 需要 `pinMode(A0, OUTPUT)`
C. 不需要，模拟输入引脚默认就是输入模式
D. 需要 `pinMode(A0, ANALOG)`

**40.** `map()` 函数的作用是：
A. 绘制图形
B. 将一个范围内的值按比例映射到另一个范围
C. 创建数组
D. 读取地图数据

**41.** `map(potValue, 0, 1023, 0, 255)` 中，如果 `potValue = 512`（约一半），返回值约为：
A. 0
B. 128（约一半）
C. 255
D. 512

**42.** `Serial.begin(9600)` 中的 9600 表示：
A. 串口发送 9600 个字节
B. 波特率 9600 bps（每秒传输位数）
C. 延时 9600 毫秒
D. 电压为 9.6V

**43.** 在串口监视器中看不到数据，以下哪个原因**不可能**？
A. `Serial.begin(9600)` 和串口监视器的波特率不一致
B. 忘记调用 `Serial.begin()`
C. 没有接 LED
D. USB 线接触不良

**44.** `Serial.println(potValue)` 和 `Serial.print(potValue)` 的主要区别是：
A. 没有区别
B. `println` 会在末尾自动加换行，`print` 不会换行
C. `println` 输出速度更快
D. `print` 只在串口绘图器中使用

**45.** 电位器的中间脚输出的电压范围是：
A. 0V 或 5V，只有两种状态
B. 0V~5V 连续变化（可调电阻分压器）
C. -5V~5V
D. 0V~3.3V

### tone() 与蜂鸣器

**46.** `tone(8, 1000)` 的含义是：
A. 让 8 号引脚输出 1000V 电压
B. 让 8 号引脚输出 1000Hz 的方波
C. 延时 1000 毫秒后发声
D. 把 8 号引脚的音量设为 1000

**47.** 要停止蜂鸣器发声，应使用：
A. `stopTone(8);`
B. `tone(8, 0);`
C. `noTone(8);`
D. `digitalWrite(8, LOW);`

**48.** 无源蜂鸣器和有源蜂鸣器的主要区别是：
A. 有源蜂鸣器更贵
B. 无源蜂鸣器底部无封胶，需要 tone() 驱动才能发声，可以控制音高；有源蜂鸣器通电就响，只能开关
C. 无源蜂鸣器声音更大
D. 有源蜂鸣器不能用 Arduino 控制

**49.** 以下关于蜂鸣器的接线，正确的是：
A. 蜂鸣器正极接 5V，负极接 GND
B. 蜂鸣器正极接信号引脚，负极接 GND
C. 蜂鸣器正极接 GND，负极接信号引脚
D. 蜂鸣器不需要区分正负极

**50.** `tone()` 函数中频率参数的作用是：
A. 控制声音的持续时间
B. 控制声音的音量
C. 控制声音的音高（频率越高音调越高，越低越低沉）
D. 控制声音的节奏

**51.** 以下哪段代码可以实现"嘀——嘀——嘀——"的间歇音效果？
A.
```c
tone(8, 1000);
delay(1000);
```
B.
```c
tone(8, 1000);
delay(500);
noTone(8);
delay(500);
```
C.
```c
noTone(8);
delay(500);
```
D.
```c
digitalWrite(8, HIGH);
delay(500);
```

**52.** 如果蜂鸣器一直不响，以下排查思路**不正确**的是：
A. 检查是否用了有源蜂鸣器（有源蜂鸣器 tone() 无法控制音高）
B. 检查引脚是否接对
C. 检查蜂鸣器是否接反
D. 外接一个 LED 到蜂鸣器位置看亮不亮

**53.** `tone()` 函数驱动蜂鸣器的本质是：
A. 输出固定电压
B. 输出特定频率的方波信号，让蜂鸣器振膜按频率振动
C. 通过蓝牙发送信号
D. 输出模拟电压

### 综合/跨知识点

**54.** 以下哪个函数的参数范围与其他三个不同？
A. `analogWrite()` 的值参数
B. `analogRead()` 的返回值
C. `delay()` 的参数
D. `tone()` 的频率参数

**55.** 以下哪种写法可以把电位器的值用于控制 LED 亮度？
A. `analogWrite(ledPin, potValue);`
B. `analogWrite(ledPin, map(potValue, 0, 1023, 0, 255));`
C. `digitalWrite(ledPin, potValue);`
D. `analogRead(ledPin);`

**56.** 关于 `setup()` 和 `loop()` 的描述，**错误**的是：
A. `setup()` 在上电或复位后只执行一次
B. `loop()` 会无限循环反复执行
C. `setup()` 中可以写 `pinMode()`，但不能写 `digitalWrite()`
D. `loop()` 是程序的主体运行部分

**57.** 在同一程序中同时使用按钮和 LED 时，以下说法正确的是：
A. 按钮和 LED 必须接在同一个引脚上
B. 按钮用 `pinMode(pin, INPUT)`，LED 用 `pinMode(pin, OUTPUT)`，互不影响
C. 不能同时使用输入和输出引脚
D. 按钮必须接在模拟引脚上

**58.** 以下哪个函数调用前**不需要**事先 `pinMode()` 设置对应引脚？
A. `digitalRead(A0)`
B. `digitalWrite(13, HIGH)`
C. `analogWrite(9, 128)`
D. `tone(8, 1000)`

> 注：`analogRead(A0)` 不需要 pinMode()，但 `digitalRead(A0)` 仍需 pinMode()（虽然模拟引脚也可当数字引脚用）。此题考察的是 analogRead 不需要 pinMode 的知识点。

**59.** 如果要把 `analogRead()` 的 0~1023 范围转换为 0~100（百分比），正确的 `map()` 写法是：
A. `map(value, 0, 1023, 0, 100);`
B. `map(value, 1023, 0, 0, 100);`
C. `map(value, 0, 100, 0, 1023);`
D. `map(value, 0, 255, 0, 1023);`

**60.** 关于 Arduino UNO 的引脚功能，以下说法正确的是：
A. 所有数字引脚都支持 PWM
B. A0~A5 只能做模拟输入，不能做数字 I/O
C. 标有 ~ 的引脚（3,5,6,9,10,11）支持 PWM 输出
D. 0 号和 1 号引脚不能用于任何功能

---

## 二、填空题（每题1分，共20分）

### digitalRead() / 按钮

**61.** `digitalRead()` 的两个可能返回值是 `HIGH` 和 `______`。

**62.** 按钮电路中，为了防止引脚悬空读到随机值，需要外接 ______ 电阻或上拉电阻。

**63.** 在按钮 + 下拉电阻电路中，按钮按下时 `digitalRead()` 返回 `______`。

**64.** 在 Arduino 中，`digitalRead()` 和 `digitalWrite()` 操作的都是 ______ 引脚（填"数字"或"模拟"）。

**65.** `pinMode(pin, INPUT)` 设置引脚为 ______ 模式。（填"输入"或"输出"）

### digitalWrite() / LED

**66.** LED 电路中串联 220Ω 电阻的作用是 ______（填"限流"或"分压"或"滤波"）。

**67.** `digitalWrite(ledPin, LOW)` 给引脚输出 ______ 伏电压。

**68.** LED 的 ______ 脚是正极（填"长"或"短"），接信号端。

**69.** 如果想在 `setup()` 中设置 LED 引脚模式，应写 `pinMode(ledPin, ______);`。

**70.** `delay(1000)` 让程序暂停 ______ 秒。

### analogWrite() / PWM

**71.** Arduino UNO 上支持 PWM 的引脚有 3、5、6、______、10、11。

**72.** `analogWrite(pin, 255)` 输出 ______% 的占空比。

**73.** PWM 的全称是 ______（英文缩写展开）。

**74.** 呼吸灯代码 `for (int brightness = 0; brightness <= 255; brightness += 5)` 中，`brightness` 的初始值是 ______。

### analogRead() / 电位器

**75.** `analogRead()` 的返回值范围是 0 到 ______。

**76.** 电位器的中间脚（②脚）应连接到 Arduino 的 ______ 引脚（填引脚名称）。

**77.** `Serial.begin(9600)` 中的 9600 称为 ______。

**78.** 把电位器值 0~1023 映射到亮度 0~255，应使用 `______(potValue, 0, 1023, 0, 255)`。

### tone() / 蜂鸣器

**79.** `tone(8, 500)` 让 8 号引脚输出 ______ Hz 的方波。

**80.** 要让蜂鸣器静音，应使用 `______(8);` 函数。

---

## 三、判断题（每题1分，共15分）

**81.** `digitalRead()` 可以读取模拟引脚的电压值。 （ ）

**82.** 按钮使用 INPUT 模式时，不接下拉电阻也能稳定工作。 （ ）

**83.** 220Ω 限流电阻的色环是"红红棕金"。 （ ）

**84.** `delay()` 函数的参数单位是秒。 （ ）

**85.** Arduino UNO 的 13 号引脚板载了一个 LED。 （ ）

**86.** `analogWrite()` 只能用在标有 `~` 的 PWM 引脚上。 （ ）

**87.** `analogWrite()` 的参数范围是 0~1023。 （ ）

**88.** `analogRead()` 读取的是模拟引脚上的数字信号。 （ ）

**89.** 模拟输入引脚 A0 在使用 `analogRead()` 之前必须调用 `pinMode(A0, INPUT)`。 （ ）

**90.** `Serial.println()` 和 `Serial.print()` 功能完全相同。 （ ）

**91.** 电位器是一个可调电阻分压器，中间脚输出电压随旋钮位置变化。 （ ）

**92.** 有源蜂鸣器可以通过 `tone()` 控制音高。 （ ）

**93.** `noTone()` 函数用于停止蜂鸣器发声。 （ ）

**94.** `tone()` 函数驱动蜂鸣器之前，引脚必须设置为 `pinMode(pin, OUTPUT)`。 （ ）

**95.** `setup()` 函数在 Arduino 上电/复位后只执行一次。 （ ）

---

## 四、简答题（每题1分，共15分）

**96.** 简述下拉电阻在按钮电路中的作用。如果不接下拉电阻会怎样？

**97.** 简述 `digitalWrite()` 和 `analogWrite()` 的区别（至少两点：输出类型、值范围、适用引脚等）。

**98.** 简述 PWM（脉冲宽度调制）的基本原理——它是如何实现"模拟电压"效果的？

**99.** 为什么 Arduino UNO 的 `analogRead()` 返回值是 0~1023，而不是 0~255 或其他范围？

**100.** 简述无源蜂鸣器和有源蜂鸣器的区别。为什么 `tone()` 只能用无源蜂鸣器？

**101.** 在按钮控制 LED 的项目中，按钮回路和 LED 回路是如何关联的？它们是物理连接还是逻辑关联？

**102.** 简述 `map()` 函数的作用，并举例说明为什么在电位器控制 LED 亮度时需要用到它。

**103.** 写出 Arduino UNO 上所有支持 PWM 的引脚编号。

**104.** 简述 `loop()` 函数的特点。为什么它能实现"持续检测按钮状态"的效果？

**105.** 如果串口监视器显示乱码或不显示数据，请列出至少两个可能的原因。

**106.** 在呼吸灯代码中，如果把 `for` 循环的步进值从 `+=5` 改成 `+=50`，会有什么效果变化？为什么？

**107.** 写出 `analogRead()` 和 `analogWrite()` 各自的参数范围，并解释为什么两者范围不同。

**108.** 按钮电路中为什么需要 10kΩ 的下拉电阻，而 LED 电路中只需要 220Ω 的限流电阻？两者的作用有何不同？

**109.** 简述 `tone()` 函数中频率参数对人耳听感的影响（频率高/低分别听到什么？）。

**110.** 如果想把按钮改成"按下灭、松开亮"（反转逻辑），只需要改代码的哪一部分？请给出关键修改。

---

## 五、综合编程题（每题1分，共10分）

**111.** 编写一个完整的 Arduino 程序：用按钮（2号引脚）控制 LED（13号引脚）。按钮按下时 LED 亮，松开时灭。要求包含完整的 `setup()` 和 `loop()`。

**112.** 编写一个完整的 Arduino 程序：让 9 号引脚上的 LED 实现呼吸灯效果（从暗到亮再到暗，循环往复）。要求使用两个 for 循环。

**113.** 编写一个完整的 Arduino 程序：读取电位器（A0）的值，将其映射到 0~255 范围，然后用 PWM（9号引脚）控制 LED 亮度，同时在串口打印电位器的原始值和映射后的亮度值。

**114.** 编写一个完整的 Arduino 程序：用蜂鸣器（8号引脚）演奏一段简单的音阶——依次发出 262Hz（Do）、294Hz（Re）、330Hz（Mi）、349Hz（Fa）、392Hz（Sol）五个音，每个音持续 300ms，音之间间隔 50ms。

**115.** 编写一个完整的 Arduino 程序：用按钮（2号引脚）切换 LED（13号引脚）的状态——按一下亮，再按一下灭，再按一下亮……（提示：需要考虑按钮去抖动的简单逻辑，用 `delay()` 即可）。

**116.** 阅读以下代码，指出其中的两处错误并改正：
```c
int led = 2; // LED 接 2 号引脚（非PWM引脚）
void setup() {
    pinMode(led, INPUT);
}
void loop() {
    analogWrite(led, 128);
    delay(500);
    analogWrite(led, 0);
    delay(500);
}
```

**117.** 阅读以下代码，写出串口监视器中会显示什么：
```c
int val = analogRead(A0);
val = map(val, 0, 1023, 0, 100);
val = constrain(val, 20, 80);
// 假设 analogRead(A0) 返回 1023，最终 val 的值是多少？
```
> 提示：`constrain(x, min, max)` 将 x 限制在 min~max 之间。

**118.** 补全以下代码，实现"按钮按下时蜂鸣器响（1000Hz），松开时静音"：
```c
int buttonPin = 2;
int buzzerPin = 8;

void setup() {
    pinMode(buttonPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    int state = digitalRead(buttonPin);
    if (__________) {
        ______________;
    } else {
        ______________;
    }
}
```

**119.** 编写一个完整的 Arduino 程序：用两个按钮（2号和3号引脚）分别控制 LED（13号引脚）的亮灭和蜂鸣器（8号引脚）的鸣叫——按钮2按下 LED 亮，按钮3按下蜂鸣器响 500Hz。两个按钮独立工作互不影响。

**120.** 编写一个完整的 Arduino 程序：实现一个简单的"电子琴"——用 4 个按钮（2、3、4、5号引脚）分别对应 Do(262Hz)、Re(294Hz)、Mi(330Hz)、Fa(349Hz) 四个音，按下哪个按钮就发出对应的音，松开静音。蜂鸣器接 8 号引脚。（提示：可用多个 if 判断或 if-else if 结构）

---

> **考试结束。请仔细检查所有答案，特别注意易混淆的知识点（如 digitalWrite/analogWrite 的范围区别、PWM引脚限制、有源/无源蜂鸣器区分、= 与 == 的区别等）。**

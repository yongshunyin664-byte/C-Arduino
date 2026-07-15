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

> ✅ 你的答案：**D**
> `digitalRead()` 只返回 HIGH(1) 或 LOW(0)，不可能返回 255。

**2.** 在按钮电路中，下拉电阻的典型阻值是：
A. 220Ω
B. 1kΩ
C. 10kΩ
D. 100kΩ

> ❌ 你的答案：**B** → 正确答案：**C（10kΩ）**
> 📌 **知识点**：按钮电路中的上拉/下拉电阻典型阻值是 **10kΩ**（10,000欧姆）。10kΩ 既能有效将引脚拉到确定电平，又不会消耗过大电流。1kΩ 虽然也能用，但功耗较大；220Ω 是 LED 限流电阻的典型值，不可混淆。

**3.** 按钮松开时，如果2号引脚没有接下拉电阻，会发生什么？
A. digitalRead() 稳定返回 LOW
B. digitalRead() 稳定返回 HIGH
C. 引脚处于"悬空"状态，读到随机跳变的电平
D. Arduino 自动复位

> ❌ 你的答案：**A** → 正确答案：**C**
> 📌 **知识点**：数字引脚设置为 INPUT 模式时处于高阻态。如果没有外接上拉或下拉电阻，引脚处于「悬空（floating）」状态，会受到周围电磁干扰，导致 `digitalRead()` 读到**随机跳变的高/低电平**，表现不稳定。接了上拉/下拉电阻后，引脚才被固定在确定电平。

**4.** 按钮的四个脚中，按下时哪两个脚之间导通？
A. ①和②
B. ①和④、②和③ 同时分别导通（①↔④, ②↔③）
C. ①和③、②和④ 交叉导通
D. 四个脚全部导通

> ✅ 你的答案：**B**
> 四脚轻触按键内部，①④和②③分别为常通的两对。测量时注意：未按下时①④通、②③通（同侧不通）；按下后①和②、③和④也导通。

**5.** 关于 `INPUT` 模式下的引脚状态，以下说法正确的是：
A. 引脚处于低阻态，不需要外接电阻
B. 引脚处于高阻态，建议外接上拉或下拉电阻
C. 引脚自动输出 5V
D. 引脚自动输出 0V

> ❌ 你的答案：**C** → 正确答案：**B**
> 📌 **知识点**：`pinMode(pin, INPUT)` 将引脚设为输入模式后，引脚处于**高阻态**（阻抗很大，几乎不吸收电流）。此时引脚对电压变化非常敏感，若不接上拉/下拉电阻，会处于悬空状态读到随机值。C/D 描述的是 OUTPUT 模式的行为。

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

> ✅ 你的答案：**B**
> `pinMode(pin, INPUT)` 设置引脚为输入模式，准备用 `digitalRead()` 读取外部按钮信号。

**7.** 按钮按下时 `digitalRead(2)` 返回 HIGH，说明按钮电路采用了什么接法？
A. 上拉电阻接法（电阻接VCC，按钮接GND）
B. 下拉电阻接法（电阻接GND，按钮接VCC）
C. 浮空接法
D. 内部上拉接法（INPUT_PULLUP）

> ✅ 你的答案：**B**
> 下拉电阻接法：电阻一端接 GND，一端接引脚；按钮一端接 VCC，一端接引脚。按下时引脚通过按钮接到 VCC → HIGH。

**8.** 以下关于 Arduino UNO 数字引脚电平的描述，**错误**的是：
A. HIGH 约等于 5V
B. LOW 约等于 0V
C. HIGH 和 LOW 也可以用 1 和 0 表示
D. HIGH 约等于 3.3V

> ✅ 你的答案：**D**
> Arduino UNO 是 5V 系统，HIGH ≈ 5V；3.3V 是 Arduino Due 等 3.3V 板子的电平。

### digitalWrite() 与 LED 控制

**9.** `digitalWrite(13, HIGH)` 执行后，13号引脚的电平是：
A. 0V
B. 3.3V
C. 5V
D. 13V

> ✅ 你的答案：**C**
> `digitalWrite(pin, HIGH)` 在 UNO 上输出 5V。

**10.** LED 电路中串联 220Ω 电阻的主要作用是：
A. 提高亮度
B. 限流保护LED，防止烧坏
C. 改变LED颜色
D. 加快闪烁速度

> ✅ 你的答案：**B**
> 220Ω 电阻限制通过 LED 的电流（约 15~20mA），防止 LED 过流烧毁。

**11.** 如果 LED 电路中不加限流电阻，直接接 5V 和 GND，会发生什么？
A. LED 正常工作
B. LED 不亮
C. LED 电流过大，可能烧坏
D. Arduino 自动断电保护

> ✅ 你的答案：**C**
> LED 工作电压约 2V，直接接 5V 会导致电流过大，烧坏 LED。

**12.** LED 长脚（正极）应该接在哪里？
A. GND
B. 信号输出引脚（经过限流电阻）
C. 直接接 5V
D. 接 A0 模拟输入

> ✅ 你的答案：**B**
> LED 长脚为阳极（+），经限流电阻后接信号输出引脚；短脚为阴极（-），接 GND。

**13.** 以下关于 Arduino UNO 13号引脚的说法，正确的是：
A. 13号引脚不能用于输出
B. 13号引脚板载了一个LED，即使不外接LED也会同步闪烁
C. 13号引脚只能用于输入
D. 13号引脚不支持PWM

> ⚠️ 你的答案：**D** → B 和 D 都正确，但考点首选 **B**
> 📌 **知识点**：13号引脚板载了一个内置LED（标记为L），这是它与其他引脚最大的区别。同时 13 号引脚确实不支持 PWM（PWM 仅限 3,5,6,9,10,11），D 说法也对，但 B 是 Arduino UNO 最经典的特性考点。

**14.** `delay(500)` 中的 500 表示：
A. 500秒
B. 500毫秒（0.5秒）
C. 500微秒
D. 500分钟

> ✅ 你的答案：**B**
> `delay()` 参数单位为毫秒（ms），500 = 0.5 秒。

**15.** 如果想让 LED 以 1 秒亮、1 秒灭的节奏闪烁，delay 参数应设为：
A. delay(1)
B. delay(10)
C. delay(100)
D. delay(1000)

> ✅ 你的答案：**D**
> 1秒 = 1000毫秒，所以用 delay(1000)，亮灭各一次共 2 秒一个周期。

**16.** LED 接反了（长脚接GND，短脚接信号端）会怎样？
A. LED 烧坏
B. Arduino 烧坏
C. LED 不亮（二极管单向导电）
D. LED 更亮

> ✅ 你的答案：**C**
> LED 本质是发光二极管，具有单向导电性，反向截止，电流无法通过所以不亮。

**17.** 以下哪个 `pinMode()` 设置是正确的 LED 输出配置？
A. `pinMode(13, INPUT);`
B. `pinMode(13, OUTPUT);`
C. `pinMode(13, INPUT_PULLUP);`
D. `pinMode(13, PWM);`

> ✅ 你的答案：**B**
> LED 需要由 Arduino 输出信号控制，所以用 OUTPUT 模式。

### 按钮控制 LED 综合

**18.** 在按钮控制LED的项目中，按钮回路和LED回路的关系是：
A. 共用同一个回路
B. 两条回路完全独立，通过代码逻辑关联
C. 串联在同一个回路中
D. 并联在同一个回路中

> ✅ 你的答案：**B**
> 按钮有自己的回路（VCC→按钮→引脚→下拉电阻→GND），LED 有自己的回路（引脚→限流电阻→LED→GND），两者在物理上独立，靠代码中 `digitalRead() → if() → digitalWrite()` 的逻辑关联起来。

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

> ✅ 你的答案：**B**
> 📌 **重要知识点**：`==` 是**比较**，`=` 是**赋值**。`buttonState = HIGH` 把 HIGH 赋给 buttonState，然后赋值的返回值是 HIGH（非零），在 C 语言中非零即为真，所以 `if` 条件永远成立，LED 一直亮。这是非常常见的初学者错误！

**20.** 在按钮控制LED的代码中，`buttonState` 变量的类型是：
A. `char`
B. `float`
C. `int`
D. `bool`

> ✅ 你的答案：**C**
> `digitalRead()` 返回值类型为 `int`（返回 0 或 1），所以通常用 `int buttonState` 来存储。

**21.** 按钮按下时 LED 亮、松开时灭，这个逻辑的核心判断语句是：
A. `while (buttonState == HIGH)`
B. `if (buttonState == HIGH) ... else ...`
C. `for (;;)`
D. `switch (buttonState)`

> ✅ 你的答案：**B**
> `if...else` 是分支判断结构：条件成立执行 A（亮），不成立执行 B（灭）。

**22.** 以下关于全局变量的说法，**正确**的是：
```c
int buttonPin = 2;  // 在 setup() 和 loop() 之外定义
int ledPin = 13;
```
A. 只能在 setup() 中使用
B. 只能在 loop() 中使用
C. setup() 和 loop() 都能直接使用
D. 必须用 `extern` 关键字才能使用

> ✅ 你的答案：**C**
> 在函数外定义的变量是全局变量，所有函数（setup、loop 等）都能直接访问。

**23.** `pinMode()` 函数通常放在哪里？
A. loop() 函数中
B. setup() 函数中
C. 任意位置都可以
D. 不能放在任何函数中

> ✅ 你的答案：**B**
> `pinMode()` 通常在 `setup()` 中调用，用于初始化引脚模式，只执行一次即可。

### analogWrite() 与 PWM

**24.** `analogWrite(9, 128)` 中，第二个参数 128 表示：
A. 电压为 1.28V
B. 50% 占空比（约 2.5V 等效电压）
C. 128Hz 频率
D. 128mA 电流

> ✅ 你的答案：**B**
> 128/255 ≈ 50% 占空比，等效输出电压 ≈ 5V × 50% = 2.5V。

**25.** `analogWrite()` 的第二个参数取值范围是：
A. 0~1023
B. 0~255
C. 0~5
D. 0~65535

> ✅ 你的答案：**B**
> `analogWrite()` 使用 8 位 PWM，范围是 0~255（2⁸ = 256 个值）。

**26.** Arduino UNO 上支持 PWM 的引脚是：
A. 所有数字引脚
B. 所有模拟引脚
C. 3, 5, 6, 9, 10, 11（标有 ~ 的引脚）
D. 0, 1, 2, 4, 7, 8

> ✅ 你的答案：**C**
> UNO 的 PWM 引脚固定为 3, 5, 6, 9, 10, 11，板子上标有 `~` 号。

**27.** 如果把 LED 插在 2 号引脚（非PWM引脚），然后调用 `analogWrite(2, 128);`，会发生什么？
A. LED 以一半亮度发光
B. LED 全亮
C. 编译报错
D. 没有 PWM 效果，可能不亮或表现异常

> ✅ 你的答案：**D**
> 非 PWM 引脚使用 `analogWrite()` 不会报错，但无法产生 PWM 波形，LED 可能不亮或表现异常。

**28.** `analogWrite()` 本质上是通过什么方式实现亮度调节的？
A. 改变输出电压的幅度
B. PWM（脉冲宽度调制）——快速开关模拟等效电压
C. 改变电流大小
D. 改变电阻值

> ✅ 你的答案：**B**
> PWM 通过快速切换 HIGH/LOW，改变高电平在一周期内的占比（占空比）来调节等效平均电压，并非真正输出模拟电压。

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

> ✅ 你的答案：**B**
> 从 0 → 255 递增 = 占空比越来越大 = 越来越亮（暗→亮呼吸）。A 是从亮到暗，方向反了。

**30.** 呼吸灯代码中 `for (int brightness = 0; brightness <= 255; brightness += 5)` 中的 `brightness += 5` 表示：
A. 亮度每次增加5倍
B. 亮度值每次增加5（步进值，控制变化速度）
C. 亮度加5秒
D. 循环执行5次

> ✅ 你的答案：**B**
> `+=` 是自增运算符，`brightness += 5` 等价于 `brightness = brightness + 5`，每次循环亮度值加 5，步进越大变化越快。

**31.** 在呼吸灯代码中，如果把 `delay(20)` 改成 `delay(1000)`，会看到什么效果？
A. LED 变化更快
B. LED 变化更慢，每步间隔1秒
C. LED 直接最亮
D. 没有变化

> ✅ 你的答案：**B**

**32.** `analogWrite()` 写 0 和 `digitalWrite()` 写 LOW 的区别是什么？
A. 没有区别，都是输出0V
B. analogWrite(0) 输出 0V（占空比0%），digitalWrite(LOW) 输出 0V，效果相同
C. analogWrite(0) 输出 5V
D. digitalWrite(LOW) 不能用

> ✅ 你的答案：**B**
> 两者最终都输出 0V，效果等效。

**33.** PWM 占空比为 50% 时，LED 的等效电压约为：
A. 0V
B. 2.5V
C. 5V
D. 1.25V

> ✅ 你的答案：**B**
> 50% 占空比 = 5V × 50% = 2.5V 等效电压。

**34.** 以下关于 `pinMode()` 在 PWM 输出中的说法，正确的是：
A. PWM 输出需要 `pinMode(pin, PWM)`
B. PWM 输出仍然是 `pinMode(pin, OUTPUT)`，不需要特殊模式
C. PWM 输出不需要 pinMode 设置
D. PWM 输出需要 `pinMode(pin, ANALOG)`

> ❌ 你的答案：**C** → 正确答案：**B**
> 📌 **知识点**：PWM 输出本质上还是数字输出的一种，引脚必须先 `pinMode(pin, OUTPUT)` 才能正常使用 `analogWrite()`。Arduino 没有 PWM 或 ANALOG 模式，只有 INPUT / OUTPUT / INPUT_PULLUP 三种。

### analogRead() 与电位器

**35.** `analogRead(A0)` 的返回值范围是：
A. 0~255
B. 0~1023
C. 0~5
D. 0~65535

> ✅ 你的答案：**B**
> Arduino UNO ADC 为 10 位，返回 0~1023。

**36.** 为什么 `analogRead()` 的范围是 0~1023？
A. Arduino UNO 的 ADC（模数转换器）是 10 位的（2¹⁰ = 1024）
B. 厂家随意定的
C. 因为电压范围是 0~5V
D. 因为 1023 = 255 × 4

> ✅ 你的答案：**A**
> 10 位 ADC 精度：2¹⁰ = 1024 个不同值，对应 0~1023。

**37.** Arduino UNO 的模拟输入引脚有哪些？
A. 0~13
B. A0~A5
C. D0~D13
D. PWM0~PWM5

> ✅ 你的答案：**B**
> UNO 有 6 个模拟输入引脚 A0~A5。

**38.** 电位器三个脚的典型接法是：
A. 左脚接GND，中间脚接A0，右脚接5V
B. 左脚接5V，中间脚接A0，右脚接GND
C. 左脚接A0，中间脚接5V，右脚接GND
D. 左脚接GND，中间脚接5V，右脚接A0

> ✅ 你的答案：**A**（A/B 均可）
> 两侧脚分别接 5V 和 GND（哪边接哪个只是方向不同），中间脚接 A0 输出分压。A 和 B 本质一样，只是旋转方向相反。

**39.** 模拟输入引脚（如 A0）在使用 `analogRead()` 之前是否需要 `pinMode()` 设置？
A. 需要 `pinMode(A0, INPUT)`
B. 需要 `pinMode(A0, OUTPUT)`
C. 不需要，模拟输入引脚默认就是输入模式
D. 需要 `pinMode(A0, ANALOG)`

> ✅ 你的答案：**C**
> 模拟引脚默认即可用于 `analogRead()`，无需 pinMode 设置。

**40.** `map()` 函数的作用是：
A. 绘制图形
B. 将一个范围内的值按比例映射到另一个范围
C. 创建数组
D. 读取地图数据

> ✅ 你的答案：**B**
> `map(value, fromLow, fromHigh, toLow, toHigh)` 将值从原始范围等比映射到目标范围。

**41.** `map(potValue, 0, 1023, 0, 255)` 中，如果 `potValue = 512`（约一半），返回值约为：
A. 0
B. 128（约一半）
C. 255
D. 512

> ✅ 你的答案：**B**
> 512/1023 ≈ 50%，映射到 0~255 是 255 × 50% ≈ 128。

**42.** `Serial.begin(9600)` 中的 9600 表示：
A. 串口发送 9600 个字节
B. 波特率 9600 bps（每秒传输位数）
C. 延时 9600 毫秒
D. 电压为 9.6V

> ✅ 你的答案：**B**
> `Serial.begin(9600)` 设置串口通信波特率为 9600 bps (bits per second)。

**43.** 在串口监视器中看不到数据，以下哪个原因**不可能**？
A. `Serial.begin(9600)` 和串口监视器的波特率不一致
B. 忘记调用 `Serial.begin()`
C. 没有接 LED
D. USB 线接触不良

> ✅ 你的答案：**C**
> 串口监视器只依赖串口通信，不接 LED 完全不影响串口数据收发。

**44.** `Serial.println(potValue)` 和 `Serial.print(potValue)` 的主要区别是：
A. 没有区别
B. `println` 会在末尾自动加换行，`print` 不会换行
C. `println` 输出速度更快
D. `print` 只在串口绘图器中使用

> ✅ 你的答案：**B**
> `println` = print + line（自动换行），`print` 输出后不换行，后续内容接在后面。

**45.** 电位器的中间脚输出的电压范围是：
A. 0V 或 5V，只有两种状态
B. 0V~5V 连续变化（可调电阻分压器）
C. -5V~5V
D. 0V~3.3V

> ✅ 你的答案：**B**
> 电位器是分压器，中间脚电压在 0V（旋到 GND 端）到 5V（旋到 5V 端）之间连续可调。

### tone() 与蜂鸣器

**46.** `tone(8, 1000)` 的含义是：
A. 让 8 号引脚输出 1000V 电压
B. 让 8 号引脚输出 1000Hz 的方波
C. 延时 1000 毫秒后发声
D. 把 8 号引脚的音量设为 1000

> ✅ 你的答案：**B**
> `tone(pin, frequency)` 在指定引脚产生指定频率（Hz）的方波信号。

**47.** 要停止蜂鸣器发声，应使用：
A. `stopTone(8);`
B. `tone(8, 0);`
C. `noTone(8);`
D. `digitalWrite(8, LOW);`

> ✅ 你的答案：**C**
> `noTone(pin)` 是停止指定引脚方波输出的正确函数。Arduino 中不存在 `stopTone()` 函数。

**48.** 无源蜂鸣器和有源蜂鸣器的主要区别是：
A. 有源蜂鸣器更贵
B. 无源蜂鸣器底部无封胶，需要 tone() 驱动才能发声，可以控制音高；有源蜂鸣器通电就响，只能开关
C. 无源蜂鸣器声音更大
D. 有源蜂鸣器不能用 Arduino 控制

> ✅ 你的答案：**B**
> 📌 **要点**：无源蜂鸣器无内部振荡电路，需外部方波（tone）驱动，可调音高；有源蜂鸣器底部有封胶，内含振荡电路，通电即响（固定频率），只能开关不能调音高。

**49.** 以下关于蜂鸣器的接线，正确的是：
A. 蜂鸣器正极接 5V，负极接 GND
B. 蜂鸣器正极接信号引脚，负极接 GND
C. 蜂鸣器正极接 GND，负极接信号引脚
D. 蜂鸣器不需要区分正负极

> ❌ 你的答案：**A** → 正确答案：**B**
> 📌 **知识点**：使用 `tone()` 驱动无源蜂鸣器时，正极应接**信号输出引脚**（如 8 号脚），负极接 GND，这样 Arduino 才能输出方波控制音高。A 是给有源蜂鸣器直通 5V 的接法（通电即响，无法用 tone 控制）。

**50.** `tone()` 函数中频率参数的作用是：
A. 控制声音的持续时间
B. 控制声音的音量
C. 控制声音的音高（频率越高音调越高，越低越低沉）
D. 控制声音的节奏

> ✅ 你的答案：**C**
> 频率（Hz）决定音高：高频 = 尖锐高音，低频 = 低沉低音。人耳能听到约 20Hz~20kHz。

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

> ❌ 你的答案：**A** → 正确答案：**B**
> 📌 **知识点**：间歇音需要「响→停→响→停」的循环。A 只是持续响 1 秒（没有间隙），B 才是正确的模式：`tone()` 响 500ms → `noTone()` 停 500ms → 循环，形成"嘀——嘀——嘀——"效果。

**52.** 如果蜂鸣器一直不响，以下排查思路**不正确**的是：
A. 检查是否用了有源蜂鸣器（有源蜂鸣器 tone() 无法控制音高）
B. 检查引脚是否接对
C. 检查蜂鸣器是否接反
D. 外接一个 LED 到蜂鸣器位置看亮不亮

> ✅ 你的答案：**D**
> 蜂鸣器是发声器件，用 LED 替换无法检测蜂鸣器电路的问题。LED 亮不亮跟蜂鸣器响不响没有直接关系。

**53.** `tone()` 函数驱动蜂鸣器的本质是：
A. 输出固定电压
B. 输出特定频率的方波信号，让蜂鸣器振膜按频率振动
C. 通过蓝牙发送信号
D. 输出模拟电压

> ✅ 你的答案：**B**
> tone() 通过快速翻转引脚电平产生方波，驱动无源蜂鸣器振膜按方波频率振动发声。

### 综合/跨知识点

**54.** 以下哪个函数的参数范围与其他三个不同？
A. `analogWrite()` 的值参数
B. `analogRead()` 的返回值
C. `delay()` 的参数
D. `tone()` 的频率参数

> ⚠️ 你的答案：**B**（争议题，B 0~1023 与其他范围不同，可视为正确）

**55.** 以下哪种写法可以把电位器的值用于控制 LED 亮度？
A. `analogWrite(ledPin, potValue);`
B. `analogWrite(ledPin, map(potValue, 0, 1023, 0, 255));`
C. `digitalWrite(ledPin, potValue);`
D. `analogRead(ledPin);`

> ✅ 你的答案：**B**
> 电位器返回 0~1023，但 analogWrite 只接受 0~255，必须用 `map()` 做范围映射。

**56.** 关于 `setup()` 和 `loop()` 的描述，**错误**的是：
A. `setup()` 在上电或复位后只执行一次
B. `loop()` 会无限循环反复执行
C. `setup()` 中可以写 `pinMode()`，但不能写 `digitalWrite()`
D. `loop()` 是程序的主体运行部分

> ✅ 你的答案：**C**
> `setup()` 中完全可以写 `digitalWrite()`，例如初始化时让某个 LED 亮一下。

**57.** 在同一程序中同时使用按钮和 LED 时，以下说法正确的是：
A. 按钮和 LED 必须接在同一个引脚上
B. 按钮用 `pinMode(pin, INPUT)`，LED 用 `pinMode(pin, OUTPUT)`，互不影响
C. 不能同时使用输入和输出引脚
D. 按钮必须接在模拟引脚上

> ✅ 你的答案：**B**
> 每个引脚独立工作，不同引脚可设为不同模式，互不影响。

**58.** 以下哪个函数调用前**不需要**事先 `pinMode()` 设置对应引脚？
A. `digitalRead(A0)`
B. `digitalWrite(13, HIGH)`
C. `analogWrite(9, 128)`
D. `tone(8, 1000)`

> ⚠️ 你的答案：**A**（题目可能有笔误，原意应是 `analogRead(A0)`，它确实不需要 pinMode）
> 注：`digitalRead(A0)` 仍需 pinMode，但 `analogRead(A0)` 不需要。按题注说明，A 为预期答案。

**59.** 如果要把 `analogRead()` 的 0~1023 范围转换为 0~100（百分比），正确的 `map()` 写法是：
A. `map(value, 0, 1023, 0, 100);`
B. `map(value, 1023, 0, 0, 100);`
C. `map(value, 0, 100, 0, 1023);`
D. `map(value, 0, 255, 0, 1023);`

> ✅ 你的答案：**A**
> `map(value, fromLow, fromHigh, toLow, toHigh)` → 1023 对应 100。

**60.** 关于 Arduino UNO 的引脚功能，以下说法正确的是：
A. 所有数字引脚都支持 PWM
B. A0~A5 只能做模拟输入，不能做数字 I/O
C. 标有 ~ 的引脚（3,5,6,9,10,11）支持 PWM 输出
D. 0 号和 1 号引脚不能用于任何功能

> ✅ 你的答案：**C**
> A 错（只有 6 个 PWM 脚），B 错（A0~A5 也可作数字 IO），D 错（0/1 是串口通信脚，也可作普通 IO）。

---

## 二、填空题（每题1分，共20分）

### digitalRead() / 按钮

**61.** `digitalRead()` 的两个可能返回值是 `HIGH` 和 `______`。

> ✅ 你的答案：**LOW**

**62.** 按钮电路中，为了防止引脚悬空读到随机值，需要外接 ______ 电阻或上拉电阻。

> ✅ 你的答案：**下拉**

**63.** 在按钮 + 下拉电阻电路中，按钮按下时 `digitalRead()` 返回 `______`。

> ❌ 你的答案：**LOW** → 正确答案：**HIGH**
> 📌 **知识点**：下拉电阻电路 = 电阻一端接 GND、一端接引脚，按钮一端接 VCC、一端接引脚。按下按钮时，引脚通过按钮直接连通 VCC（5V），所以 `digitalRead()` 返回 **HIGH**。松开时电阻将引脚拉到 GND，返回 LOW。

**64.** 在 Arduino 中，`digitalRead()` 和 `digitalWrite()` 操作的都是 ______ 引脚（填"数字"或"模拟"）。

> ❌ 你的答案：**模拟** → 正确答案：**数字**
> 📌 **知识点**：函数名称中的 `digital` 即表示"数字"。`digitalRead()`/`digitalWrite()` 操作**数字**引脚，`analogRead()` 操作模拟引脚。注意 `analogWrite()` 虽然名含 analog，但操作的是数字引脚中的 PWM 引脚。

**65.** `pinMode(pin, INPUT)` 设置引脚为 ______ 模式。（填"输入"或"输出"）

> ✅ 你的答案：**输入**

### digitalWrite() / LED

**66.** LED 电路中串联 220Ω 电阻的作用是 ______（填"限流"或"分压"或"滤波"）。

> ✅ 你的答案：**限流**

**67.** `digitalWrite(ledPin, LOW)` 给引脚输出 ______ 伏电压。

> ✅ 你的答案：**0伏**

**68.** LED 的 ______ 脚是正极（填"长"或"短"），接信号端。

> ✅ 你的答案：**长**

**69.** 如果想在 `setup()` 中设置 LED 引脚模式，应写 `pinMode(ledPin, ______);`。

> ❌ 你的答案：**INTPUT_PULLUP** → 正确答案：**OUTPUT**
> 📌 **知识点**：LED 是输出设备，需要 Arduino 向其输出信号控制亮灭，引脚模式必须设为 **OUTPUT**。INPUT_PULLUP 是用于按钮的输入模式（启用内部上拉电阻），完全是另一回事。另外拼写应为 INPUT（不是 INTPUT）。

**70.** `delay(1000)` 让程序暂停 ______ 秒。

> ✅ 你的答案：**1**

### analogWrite() / PWM

**71.** Arduino UNO 上支持 PWM 的引脚有 3、5、6、______、10、11。

> ✅ 你的答案：**9**

**72.** `analogWrite(pin, 255)` 输出 ______% 的占空比。

> ✅ 你的答案：**100**

**73.** PWM 的全称是 ______（英文缩写展开）。

> ⚠️ 你的答案：**pules width modulation** → 正确拼写：**Pulse Width Modulation**（脉冲宽度调制），意思对即可

**74.** 呼吸灯代码 `for (int brightness = 0; brightness <= 255; brightness += 5)` 中，`brightness` 的初始值是 ______。

> ✅ 你的答案：**0**

### analogRead() / 电位器

**75.** `analogRead()` 的返回值范围是 0 到 ______。

> ❌ 你的答案：**255** → 正确答案：**1023**
> 📌 **知识点**：`analogRead()` 使用 Arduino UNO 的 **10 位 ADC**，范围是 0~1023（2¹⁰ = 1024 个值）。不要跟 `analogWrite()` 的 0~255（8 位）混淆！analogRead = 读模拟（10位，0~1023），analogWrite = 写 PWM（8位，0~255）。

**76.** 电位器的中间脚（②脚）应连接到 Arduino 的 ______ 引脚（填引脚名称）。

> ✅ 你的答案：**A0**

**77.** `Serial.begin(9600)` 中的 9600 称为 ______。

> ✅ 你的答案：**波特率**

**78.** 把电位器值 0~1023 映射到亮度 0~255，应使用 `______(potValue, 0, 1023, 0, 255)`。

> ✅ 你的答案：**map**

### tone() / 蜂鸣器

**79.** `tone(8, 500)` 让 8 号引脚输出 ______ Hz 的方波。

> ✅ 你的答案：**500**

**80.** 要让蜂鸣器静音，应使用 `______(8);` 函数。

> ✅ 你的答案：**noTone**（大小写不严格，正确函数名为 `noTone`）

---

## 三、判断题（每题1分，共15分）

**81.** `digitalRead()` 可以读取模拟引脚的电压值。 （ ）

> ✅ 你的答案：**错** — `digitalRead()` 只返回 HIGH/LOW，不能读取连续电压值。

**82.** 按钮使用 INPUT 模式时，不接下拉电阻也能稳定工作。 （ ）

> ✅ 你的答案：**错** — 不接上拉/下拉电阻引脚会悬空，读到随机值。

**83.** 220Ω 限流电阻的色环是"红红棕金"。 （ ）

> ✅ 你的答案：**对** — 红(2)红(2)棕(×10)金(±5%) = 22×10 = 220Ω ±5%。

**84.** `delay()` 函数的参数单位是秒。 （ ）

> ✅ 你的答案：**错** — `delay()` 参数单位是**毫秒**(ms)。

**85.** Arduino UNO 的 13 号引脚板载了一个 LED。 （ ）

> ✅ 你的答案：**对** — 13号引脚连接到板载 LED（标记 L），输出 HIGH 时亮。

**86.** `analogWrite()` 只能用在标有 `~` 的 PWM 引脚上。 （ ）

> ✅ 你的答案：**对** — 非 PWM 引脚使用 `analogWrite()` 不会有 PWM 效果。

**87.** `analogWrite()` 的参数范围是 0~1023。 （ ）

> ✅ 你的答案：**错** — `analogWrite()` 范围是 **0~255**（8位）。0~1023 是 `analogRead()` 的范围。

**88.** `analogRead()` 读取的是模拟引脚上的数字信号。 （ ）

> ✅ 你的答案：**错** — `analogRead()` 读取的是**模拟信号**，返回 0~1023 的连续值。

**89.** 模拟输入引脚 A0 在使用 `analogRead()` 之前必须调用 `pinMode(A0, INPUT)`。 （ ）

> ✅ 你的答案：**错** — `analogRead()` 不需要事先 `pinMode()`，模拟引脚默认即输入模式。

**90.** `Serial.println()` 和 `Serial.print()` 功能完全相同。 （ ）

> ✅ 你的答案：**错** — `println()` 输出后自动换行，`print()` 不换行。

**91.** 电位器是一个可调电阻分压器，中间脚输出电压随旋钮位置变化。 （ ）

> ✅ 你的答案：**对** — 电位器两端接 5V 和 GND，中间脚输出 0~5V 分压。

**92.** 有源蜂鸣器可以通过 `tone()` 控制音高。 （ ）

> ✅ 你的答案：**错** — 有源蜂鸣器内部自带振荡电路，通电即响（固定频率），`tone()` 只能用于无源蜂鸣器。

**93.** `noTone()` 函数用于停止蜂鸣器发声。 （ ）

> ✅ 你的答案：**对**

**94.** `tone()` 函数驱动蜂鸣器之前，引脚必须设置为 `pinMode(pin, OUTPUT)`。 （ ）

> ✅ 你的答案：**对** — 输出方波需要引脚设为 OUTPUT 模式。

**95.** `setup()` 函数在 Arduino 上电/复位后只执行一次。 （ ）

> ✅ 你的答案：**对** — `setup()` 只在上电或按复位键时执行一次，之后 `loop()` 无限循环。

---

## 四、简答题（每题1分，共15分）

**96.** 简述下拉电阻在按钮电路中的作用。如果不接下拉电阻会怎样？

> ❌ 你的答案：下拉电阻可以限制电流过大，不接容易烧坏电路
>
> 📌 **正确答案**：下拉电阻的作用是**在按钮未按下时，将引脚电平固定在 LOW（0V）**，防止引脚处于悬空（floating）状态。如果不接下拉电阻，按钮未按下时引脚悬空，受到周围电磁干扰会读到**随机跳变的高低电平**，导致程序判断不可靠。
>
> ⚠️ 你的理解完全错了：下拉电阻的作用是**确定电平**，不是限流保护！限流是 LED 电路中 220Ω 电阻的作用，不要混淆。

**97.** 简述 `digitalWrite()` 和 `analogWrite()` 的区别（至少两点：输出类型、值范围、适用引脚等）。

> ⚠️ 你的答案：digitalWrite()的输出类型为HIGH和LOW，值范围是1和0；analogWrite()的输出类型为pwm，值范围为0～255
>
> 📌 **补充完善**：
> | 对比项 | digitalWrite() | analogWrite() |
> |--------|---------------|---------------|
> | 输出类型 | 数字信号（HIGH/LOW） | PWM方波（占空比） |
> | 值范围 | HIGH(1) 或 LOW(0) | 0~255 |
> | 适用引脚 | 所有数字引脚 | 仅PWM引脚（3,5,6,9,10,11） |
> | 典型用途 | LED开关、控制继电器 | LED亮度调节、电机调速 |

**98.** 简述 PWM（脉冲宽度调制）的基本原理——它是如何实现"模拟电压"效果的？

> ❌ 你的答案：是通过模拟输入信号，加上map函数实现的
>
> 📌 **正确答案**：PWM 是通过**快速切换数字信号的高低电平**来模拟等效模拟电压。在一个固定周期内，改变高电平所占的时间比例（**占空比**），使负载感受到的平均电压发生变化。例如：占空比 50% → 一半时间 5V、一半时间 0V → 等效约 2.5V。由于 PWM 频率很高（约 490Hz/980Hz），人眼感觉到 LED 连续亮，人耳则听到连续的音频。
>
> ⚠️ map 函数只是范围映射工具，跟 PWM 原理本身无关！不要混淆。

**99.** 为什么 Arduino UNO 的 `analogRead()` 返回值是 0~1023，而不是 0~255 或其他范围？

> ✅ 你的答案：因为是10位的也就是2的十次方
>
> 📌 **补充**：Arduino UNO 的 ADC（模数转换器）精度为 **10 位**，2¹⁰ = 1024 个不同值，范围 0~1023。而 `analogWrite()` 是 8 位（2⁸ = 256，范围 0~255）。两者精度不同。

**100.** 简述无源蜂鸣器和有源蜂鸣器的区别。为什么 `tone()` 只能用无源蜂鸣器？

> ⚠️ 你的答案：有源插上就会响，无源需要通过tone函数来调节蜂鸣（过于简略）
>
> 📌 **完善**：
> - **有源蜂鸣器**：内部自带振荡电路，底部有封胶，通电即响（固定频率），只能开关无法调音高，`tone()` 对其无效
> - **无源蜂鸣器**：内部无振荡电路，底部无封胶，需要外部方波信号驱动，`tone()` 可以控制不同频率发出不同音高

**101.** 在按钮控制 LED 的项目中，按钮回路和 LED 回路是如何关联的？它们是物理连接还是逻辑关联？

> ✅ 你的答案：逻辑关联
>
> 📌 按钮回路（VCC→按钮→引脚→下拉电阻→GND）和 LED 回路（引脚→限流电阻→LED→GND）是两条**物理上完全独立**的电路，它们之间通过代码逻辑关联：`digitalRead()` → `if` 判断 → `digitalWrite()`。

**102.** 简述 `map()` 函数的作用，并举例说明为什么在电位器控制 LED 亮度时需要用到它。

> ⚠️ 你的答案：将一个比例转换为另一个比例（过于简略）
>
> 📌 **完善**：`map(value, fromLow, fromHigh, toLow, toHigh)` 将 value 从原始范围等比映射到目标范围。例如：`analogRead(A0)` 返回 0~1023，但 `analogWrite()` 只接受 0~255，需要用 `map(potValue, 0, 1023, 0, 255)` 做比例转换，使电位器旋到一半时 LED 也是半亮。

**103.** 写出 Arduino UNO 上所有支持 PWM 的引脚编号。

> ✅ 你的答案：3，5，6，9，10，11

**104.** 简述 `loop()` 函数的特点。为什么它能实现"持续检测按钮状态"的效果？

> ✅ 你的答案：loop函数是循环结构，可以一直运行
>
> 📌 `loop()` 函数在执行完毕后会自动重新从头执行，形成**无限循环**。每次循环都会重新 `digitalRead()` 检测按钮状态，所以能持续响应按钮的按下和松开。

**105.** 如果串口监视器显示乱码或不显示数据，请列出至少两个可能的原因。

> ✅ 你的答案：波特率编写与串口处不一致、代码错误
>
> 📌 常见原因：① 代码中 `Serial.begin(9600)` 与串口监视器右下角波特率不一致；② 忘记调用 `Serial.begin()`；③ USB 线接触不良或只支持充电不支持数据传输；④ `Serial.print()` 未放入 `loop()` 中。

**106.** 在呼吸灯代码中，如果把 `for` 循环的步进值从 `+=5` 改成 `+=50`，会有什么效果变化？为什么？

> ✅ 你的答案：亮度会一次性增加很多，因为亮度的范围值是0～255，一次性加50亮度会格外大
>
> 📌 步进值从 5 变成 50 后，每次亮度跳跃 50，变化会非常**陡峭**（只有 0→50→100→150→200→250 几个阶梯），失去了"呼吸"的平滑过渡感。原来的 +=5 有约 51 个亮度级别，+=50 只有约 6 个级别，肉眼可见的阶梯感明显。

**107.** 写出 `analogRead()` 和 `analogWrite()` 各自的参数范围，并解释为什么两者范围不同。

> ⚠️ 你的答案：0～1023和0～255（正确），但未解释为什么不同
>
> 📌 **原因**：`analogRead()` 使用 **10 位 ADC**（2¹⁰=1024，范围 0~1023），`analogWrite()` 使用 **8 位 PWM**（2⁸=256，范围 0~255）。精度差异源于硬件设计：ADC 需要更高精度来区分微小电压变化，PWM 8 位对于亮度/速度控制已经足够。

**108.** 按钮电路中为什么需要 10kΩ 的下拉电阻，而 LED 电路中只需要 220Ω 的限流电阻？两者的作用有何不同？

> ❌ 你的答案：不清楚
>
> 📌 **正确答案**：
> - **10kΩ 下拉电阻**：作用是**确定引脚电平**（未按下时拉到 GND）。阻值较大（10kΩ）是为了减少功耗——未按下时通过电阻从 5V 到 GND 的电流只有 0.5mA。如果阻值太小会浪费电流，太大则拉低效果不好
> - **220Ω 限流电阻**：作用是**限制通过 LED 的电流**，保护 LED 不被烧毁。LED 工作电压约 2V，通过 220Ω 限制电流约为 (5V-2V)/220Ω ≈ 14mA，在 LED 安全范围内
> - 两者**作用完全不同**：一个是确定逻辑电平，一个是限制电流保护元件

**109.** 简述 `tone()` 函数中频率参数对人耳听感的影响（频率高/低分别听到什么？）。

> ❌ 你的答案：不知道
>
> 📌 **正确答案**：频率参数决定了音调的高低。**频率越高（如 2000Hz），听到的音调越尖锐、越高亢**；**频率越低（如 200Hz），听到的音调越低沉、越厚重**。人耳可听范围约 20Hz~20kHz。例如钢琴中央 C 为 262Hz，高一个八度的 C 为 524Hz（频率翻倍=升八度）。

**110.** 如果想把按钮改成"按下灭、松开亮"（反转逻辑），只需要改代码的哪一部分？请给出关键修改。

> ✅ 你的答案：在循环条件里把检测按钮状态加上逻辑非即可
>
> 📌 两种方法：
> ① `if (buttonState == LOW)` — 改为判断 LOW
> ② `if (!digitalRead(buttonPin))` — 使用逻辑非 `!` 取反
> 最简单的写法：把 `if (buttonState == HIGH)` 改为 `if (buttonState == LOW)`。

---

## 五、综合编程题（每题1分，共10分）

**111.** 编写一个完整的 Arduino 程序：用按钮（2号引脚）控制 LED（13号引脚）。按钮按下时 LED 亮，松开时灭。要求包含完整的 `setup()` 和 `loop()`。

> ❌ 未作答
>
> 📌 **参考答案**：
> ```c
> int buttonPin = 2;
> int ledPin = 13;
> 
> void setup() {
>     pinMode(buttonPin, INPUT);
>     pinMode(ledPin, OUTPUT);
> }
> 
> void loop() {
>     int buttonState = digitalRead(buttonPin);
>     if (buttonState == HIGH) {
>         digitalWrite(ledPin, HIGH);   // 按钮按下 → LED 亮
>     } else {
>         digitalWrite(ledPin, LOW);    // 按钮松开 → LED 灭
>     }
> }
> ```

**112.** 编写一个完整的 Arduino 程序：让 9 号引脚上的 LED 实现呼吸灯效果（从暗到亮再到暗，循环往复）。要求使用两个 for 循环。

> ❌ 未作答
>
> 📌 **参考答案**：
> ```c
> int ledPin = 9;
> 
> void setup() {
>     pinMode(ledPin, OUTPUT);
> }
> 
> void loop() {
>     // 从暗到亮（0 → 255）
>     for (int brightness = 0; brightness <= 255; brightness += 5) {
>         analogWrite(ledPin, brightness);
>         delay(20);
>     }
>     // 从亮到暗（255 → 0）
>     for (int brightness = 255; brightness >= 0; brightness -= 5) {
>         analogWrite(ledPin, brightness);
>         delay(20);
>     }
> }
> ```

**113.** 编写一个完整的 Arduino 程序：读取电位器（A0）的值，将其映射到 0~255 范围，然后用 PWM（9号引脚）控制 LED 亮度，同时在串口打印电位器的原始值和映射后的亮度值。

> ❌ 未作答
>
> 📌 **参考答案**：
> ```c
> int potPin = A0;
> int ledPin = 9;
> 
> void setup() {
>     pinMode(ledPin, OUTPUT);
>     Serial.begin(9600);
> }
> 
> void loop() {
>     int potValue = analogRead(potPin);                  // 0~1023
>     int brightness = map(potValue, 0, 1023, 0, 255);    // 映射到 0~255
>     analogWrite(ledPin, brightness);
>     
>     Serial.print("电位器值: ");
>     Serial.print(potValue);
>     Serial.print("  亮度: ");
>     Serial.println(brightness);
>     
>     delay(50);
> }
> ```

**114.** 编写一个完整的 Arduino 程序：用蜂鸣器（8号引脚）演奏一段简单的音阶——依次发出 262Hz（Do）、294Hz（Re）、330Hz（Mi）、349Hz（Fa）、392Hz（Sol）五个音，每个音持续 300ms，音之间间隔 50ms。

> ❌ 未作答
>
> 📌 **参考答案**：
> ```c
> int buzzerPin = 8;
> int notes[] = {262, 294, 330, 349, 392};  // Do, Re, Mi, Fa, Sol
> 
> void setup() {
>     pinMode(buzzerPin, OUTPUT);
> }
> 
> void loop() {
>     for (int i = 0; i < 5; i++) {
>         tone(buzzerPin, notes[i]);   // 发当前音
>         delay(300);                   // 持续 300ms
>         noTone(buzzerPin);           // 静音
>         delay(50);                    // 间隔 50ms
>     }
>     delay(1000);  // 演奏完停顿1秒再重复
> }
> ```

**115.** 编写一个完整的 Arduino 程序：用按钮（2号引脚）切换 LED（13号引脚）的状态——按一下亮，再按一下灭，再按一下亮……（提示：需要考虑按钮去抖动的简单逻辑，用 `delay()` 即可）。

> ❌ 未作答
>
> 📌 **参考答案**：
> ```c
> int buttonPin = 2;
> int ledPin = 13;
> int ledState = LOW;  // 记录当前 LED 状态
> 
> void setup() {
>     pinMode(buttonPin, INPUT);
>     pinMode(ledPin, OUTPUT);
>     digitalWrite(ledPin, ledState);
> }
> 
> void loop() {
>     if (digitalRead(buttonPin) == HIGH) {
>         delay(20);  // 去抖动延时
>         if (digitalRead(buttonPin) == HIGH) {  // 再次确认
>             ledState = !ledState;  // 翻转状态：亮→灭，灭→亮
>             digitalWrite(ledPin, ledState);
>             while (digitalRead(buttonPin) == HIGH);  // 等待松开
>             delay(20);  // 松开去抖动
>         }
>     }
> }
> ```

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

> ❌ 未作答
>
> 📌 **参考答案**：两处错误：
> 1. `pinMode(led, INPUT)` → 应改为 `pinMode(led, OUTPUT)`；LED 是输出设备，必须设为 OUTPUT 模式
> 2. `analogWrite(led, 128)` → 2 号引脚不是 PWM 引脚（PWM 只有 3,5,6,9,10,11），应改用 PWM 引脚（如 9 号）或将 `led` 改为 9

**117.** 阅读以下代码，写出串口监视器中会显示什么：
```c
int val = analogRead(A0);
val = map(val, 0, 1023, 0, 100);
val = constrain(val, 20, 80);
// 假设 analogRead(A0) 返回 1023，最终 val 的值是多少？
```
> 提示：`constrain(x, min, max)` 将 x 限制在 min~max 之间。

> ❌ 未作答
>
> 📌 **参考答案**：**80**
> 推导过程：analogRead(A0) = 1023 → map(1023, 0, 1023, 0, 100) = 100 → constrain(100, 20, 80) → 100 超过了上限 80，被截断为 **80**。

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

> ❌ 未作答
>
> 📌 **参考答案**：
> ```c
>     if (state == HIGH) {
>         tone(buzzerPin, 1000);
>     } else {
>         noTone(buzzerPin);
>     }
> ```

**119.** 编写一个完整的 Arduino 程序：用两个按钮（2号和3号引脚）分别控制 LED（13号引脚）的亮灭和蜂鸣器（8号引脚）的鸣叫——按钮2按下 LED 亮，按钮3按下蜂鸣器响 500Hz。两个按钮独立工作互不影响。

> ❌ 未作答
>
> 📌 **参考答案**：
> ```c
> int button1 = 2;   // 控制 LED
> int button2 = 3;   // 控制蜂鸣器
> int ledPin = 13;
> int buzzerPin = 8;
> 
> void setup() {
>     pinMode(button1, INPUT);
>     pinMode(button2, INPUT);
>     pinMode(ledPin, OUTPUT);
>     pinMode(buzzerPin, OUTPUT);
> }
> 
> void loop() {
>     // 按钮2控制 LED
>     if (digitalRead(button1) == HIGH) {
>         digitalWrite(ledPin, HIGH);
>     } else {
>         digitalWrite(ledPin, LOW);
>     }
>     // 按钮3控制蜂鸣器
>     if (digitalRead(button2) == HIGH) {
>         tone(buzzerPin, 500);
>     } else {
>         noTone(buzzerPin);
>     }
> }
> ```

**120.** 编写一个完整的 Arduino 程序：实现一个简单的"电子琴"——用 4 个按钮（2、3、4、5号引脚）分别对应 Do(262Hz)、Re(294Hz)、Mi(330Hz)、Fa(349Hz) 四个音，按下哪个按钮就发出对应的音，松开静音。蜂鸣器接 8 号引脚。

> ❌ 未作答
>
> 📌 **参考答案**：
> ```c
> int buzzerPin = 8;
> int buttons[] = {2, 3, 4, 5};
> int notes[] = {262, 294, 330, 349};  // Do, Re, Mi, Fa
> 
> void setup() {
>     for (int i = 0; i < 4; i++) {
>         pinMode(buttons[i], INPUT);
>     }
>     pinMode(buzzerPin, OUTPUT);
> }
> 
> void loop() {
>     bool isPlaying = false;
>     for (int i = 0; i < 4; i++) {
>         if (digitalRead(buttons[i]) == HIGH) {
>             tone(buzzerPin, notes[i]);  // 按哪个发哪个音
>             isPlaying = true;
>             break;
>         }
>     }
>     if (!isPlaying) {
>         noTone(buzzerPin);  // 全部松开 → 静音
>     }
> }
> ```（提示：可用多个 if 判断或 if-else if 结构）

---

> **考试结束。请仔细检查所有答案，特别注意易混淆的知识点（如 digitalWrite/analogWrite 的范围区别、PWM引脚限制、有源/无源蜂鸣器区分、= 与 == 的区别等）。**

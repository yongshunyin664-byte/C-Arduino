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

## 2. digitalWrite() 控制引脚

`digitalWrite(pin, value)` 用于设置数字引脚为 `HIGH` 或 `LOW`。

```c
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}
```

## 3. 用按钮控制 LED 亮灭

按钮按下时点亮 LED，松开时熄灭。

```c
int buttonPin = 2;
int ledPin = 13;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
```

## 4. analogWrite() 调节亮度

`analogWrite(pin, value)` 用于 PWM 输出，`value` 范围是 `0` 到 `255`。

```c
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(ledPin, brightness);
    delay(20);
  }
}
```

## 5. 用电位器 analogRead() 读取数值

`analogRead(pin)` 读取模拟引脚的电压值，返回 `0` 到 `1023`。

```c
int potPin = A0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.println(potValue);
  int brightness = map(potValue, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
  delay(100);
}
```

## 6. 蜂鸣器 tone()

`tone(pin, frequency)` 发出指定频率的声音。

```c
int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 1000); // 1kHz
  delay(500);
  noTone(buzzerPin);
  delay(500);
}
```

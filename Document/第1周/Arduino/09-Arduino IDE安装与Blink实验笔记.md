# Arduino IDE 安装与 Blink 实验笔记

## 1. 先准备什么
- 一块 Arduino UNO 开发板
- 一台电脑
- 一根 USB 数据线

## 2. 安装 Arduino IDE
1. 打开浏览器，搜索“Arduino IDE 下载”。
2. 进入 Arduino 官方网站。
3. 下载适合你电脑系统的版本。
4. 安装完成后，打开 Arduino IDE。

## 3. 选择开发板
1. 连接 Arduino UNO 到电脑。
2. 打开 Arduino IDE。
3. 点击“工具” → “开发板”。
4. 选择 “Arduino Uno”。

## 4. 选择端口
1. 点击“工具” → “端口”。
2. 选择你 Arduino 对应的端口。
   - Windows 通常是 COM3、COM4 等。

## 5. 打开 Blink 示例
1. 点击“文件” → “示例” → “01.Basics” → “Blink”。
2. 这会打开一个内置的点灯示例程序。

## 6. 上传程序
1. 点击上传按钮（右箭头）。
2. 等待程序上传完成。
3. 如果成功，底部会显示“上传完成”。

## 7. 看到什么效果
- 上传成功后，Arduino 板上的内置 LED 会开始闪烁。
- 也就是一秒亮、一秒灭。

## 8. Blink 程序的核心意思
```cpp
void setup() //程序开始时只执行一次，用来做初始化设置。
{
  pinMode(LED_BUILTIN, OUTPUT);//把内置 LED 对应的引脚设置为“输出模式”，这样它才能发出信号去点亮灯。
}

void loop() //程序会一直重复执行。
{
  digitalWrite(LED_BUILTIN, HIGH);//让 LED 引脚输出高电平，灯亮。
  delay(1000);//停顿 1000 毫秒，也就是 1 秒。
  digitalWrite(LED_BUILTIN, LOW);//让 LED 引脚输出低电平，灯灭。
  delay(1000);//再停 1 秒。
}
```

### 说明
- `setup()`：初始化设置。
- `loop()`：循环执行。
- `HIGH`：点亮 LED。
- `LOW`：熄灭 LED。
- `delay(1000)`：等待 1000 毫秒，也就是 1 秒。

## 9. 记忆口诀
- 安装 IDE：先装软件
- 选开发板：选 Arduino Uno
- 选端口：选连接电脑的口
- 打开 Blink：直接跑示例
- 上传成功：板子上的灯开始闪

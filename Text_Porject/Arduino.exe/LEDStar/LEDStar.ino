int LED = 2;//定义整型变量 LED，赋值数字 2，代表板子上2 号数字引脚。好处：后面改引脚只需要改这一行，不用到处修改代码。
void setup() // setup () 初始化函数（上电只执行 1 次）
{
  pinMode(LED,OUTPUT);
  /*
  pinMode(引脚, 模式)：
  设置引脚工作模式LED 就是 2 号引脚；
  OUTPUT：输出模式，用来控制 LED、继电器等外部设备输出高低电平。
  */
}

void loop() // loop () 无限主循环（上电后反复跑）
{
   digitalWrite(LED,HIGH);//给 2 号引脚输出高电平 → LED 通电点亮
   delay(3000);//程序暂停 3000 毫秒 = 3 秒，保持 LED 常亮 3 秒
   digitalWrite(LED,LOW);//给 2 号引脚输出低电平 → LED 断电熄灭
   delay(3000);//程序再暂停 3 秒，保持熄灭 3 秒
}

int val;
/*
定义一个全局整型变量 val，用来存放串口读取到的字符数据。
全局变量：setup() 和 loop() 里都能直接使用。
为什么用 int 而不是 char？
Serial.read() 返回值是 int：正常字符是 ASCII 码；无数据时返回 -1，用 int 才能区分。
*/
void setup() // setup() 只在上电 / 复位后运行 1 次，专门做初始化
{
   Serial.begin(9600);//开启硬件串口通信，波特率设置为 9600。电脑串口监视器必须同步选 9600 才能正常收发文字
}

void loop() //loop() 会无限循环反复执行，是程序主体。
{
   val=Serial.read();
   /*
   从串口缓冲区读取 1 个字符，存入变量 val。
   电脑串口监视器发送文字，数据会存在串口缓冲区；
   缓冲区为空时，val = -1；
   收到字符时，val 等于该字符的 ASCII 数值。
   */
   if(val=='R')//判断读到的字符是不是大写字母 R：
   {
    Serial.println("Hello World!");//条件成立时，向电脑串口打印字符串：
   }
}

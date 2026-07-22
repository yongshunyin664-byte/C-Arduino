/*
ASCII 代码查询工具 (1.0)
by 太极创客 (2017-06-01)
www.taichi-maker.com
 
在串口监视器中输入字符并点击发送，串口监视器将
输入字符的ASCII代码进行显示。
*/
 
void setup() {
  Serial.begin(9600);
  Serial.println("Please input serial data.");
}
 
void loop() {
  // check if data has been sent from the computer:
  if (Serial.available()>0 ) {   //检查串口缓存中是否有数据等待读取
    Serial.println("======================");        
    char serialData = Serial.read();     //读取串口缓存中等待的字符
                                         //并赋值给字符变量serialData
    Serial.print("Your serialData: '");
    Serial.print(serialData);            //显示刚刚读取到的字符
    Serial.println("'");
 
    Serial.print("serialData in DEC ");
    Serial.println(serialData, DEC);   //显示刚刚读取到字符的ASCII编码（十进制）
    Serial.print("serialData in BIN ");
    Serial.println(serialData, BIN);   //显示刚刚读取到字符的ASCII编码（二进制）
    Serial.print("serialData in OCT ");
    Serial.println(serialData, OCT);   //显示刚刚读取到字符的ASCII编码（八进制）
    Serial.print("serialData in HEX ");
    Serial.println(serialData, HEX);   //显示刚刚读取到字符的ASCII编码（十六进制）
    Serial.println("======================");
  }
}

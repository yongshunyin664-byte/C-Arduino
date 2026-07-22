/*
HC-06蓝牙模块设置以及功能测试
by 太极创客（2017-07-08）
www.taici-maker.com
此程序旨在演示如何通过HC-06模块使用蓝牙通讯向Arduino数字IO引脚
收发串口数据，以及如何设置HC-06蓝牙模块。
 
如需获得更多关于本程序的使用说明，请参见太极创客制作的《零基础入门学用Arduino》教程。
 
---- 电路连接 ---- 
HC-06     Arduino Uno R3 引脚
TX                2  
RX                3
VCC              +5v
GND              GND
注意：须使用分压电路，确保HC-06 RX信号电压为3.3伏特。
 
//  
 
---- AT指令 ---- 
 
指令               答复                        说明
AT                 OK                          通讯测试
AT+VERSION         OKlinvorV1.8                固件版本
AT+NAMEmyBTmodule  OKsetname                   设置设备名 “myBTmodule”
AT+PIN6789         OKsetPIN                    设置设备 PIN 6789
AT+BAUD1           OK1200                      设置波特率 1200
AT+BAUD2           OK2400                      设置波特率 2400
AT+BAUD3           OK4800                      设置波特率 4800
AT+BAUD4           OK9600                      设置波特率 9600
AT+BAUD5           OK19200                     设置波特率 19200
AT+BAUD6           OK38400                     设置波特率 38400
AT+BAUD7           OK57600                     设置波特率 57600
AT+BAUD8           OK115200                    设置波特率 115200
AT+BAUD9           OK230400                    设置波特率 230400
AT+BAUDA           OK460800                    设置波特率 460800
AT+BAUDB           OK921600                    设置波特率 921600
AT+BAUDC           OK1382400                   设置波特率 1382400
 
*/
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // 建立SoftwareSerial对象，RX引脚2, TX引脚3
 
void setup() {
  Serial.begin(9600);
  BTserial.begin(9600); // HC-06 默认波特率 9600
 
  Serial.print("HC-06 DEMO/TEST  ");
   
  BTserial.print("AT");   //可在此处输入设置HC-06蓝牙模块的AT指令。
                          //此AT指令须在HC-06未连接蓝牙状态输入。
 
  pinMode(11, OUTPUT);                        
 
}
  
void loop(){
  
    // 通过串口监视器显示HC-06发送的数据
    if( BTserial.available()>0 ){            //如果软件串口有HC-06发来的数据
      char BTserialData =  BTserial.read();  //将软件串口中的数据赋值给变量BTserialData
      Serial.print( BTserialData );         //通过硬件串口监视器显示HC-06发来的数据
      if (BTserialData == '1') {             //判断HC-06发来的数据是否是字符1
        digitalWrite(11, HIGH);              //如果是字符1，则点亮LED
      } else if (BTserialData == '0') {      //如果不是字符0
        digitalWrite(11, LOW);               //则熄灭LED
      }
    }
  
    // 将用户通过串口监视器输入的数据发送给HC-06
    if (Serial.available()>0) {            //如果硬件串口缓存中有等待传输的数据
      char serialData =  Serial.read();    //将硬件串口中的数据赋值给变量serialData
      BTserial.print( serialData );         //将硬件串口中的数据发送给HC-06
    }
  
}

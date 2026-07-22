/*
Serial-Servo-2
by太极创客(2016-06-03)
www.taichi-maker.com
  
本示例程序为配合太极创客制作的《零基础入门学用Arduino教程-MeArm篇》使用
本示例程序旨在演示如何通过串口监视器控制4个伺服电机（舵机）。
  
有关电路连接以及其他相关内容，请参见太极创客网站关于本示例程序的相关页面。
This example code is in the public domain.
*/
#include <Servo.h>
 
Servo base, fArm, rArm, claw;  //建立4个电机对象
 
int dataIndex = 0;
void setup() {
  base.attach(11);     // base 伺服电机连接引脚11 电机代号'b'
  rArm.attach(10);     // rArm 伺服电机连接引脚10 电机代号'r'
  fArm.attach(9);      // fArm 伺服电机连接引脚9  电机代号'f'
  claw.attach(6);      // claw 伺服电机连接引脚6  电机代号'c'
  Serial.begin(9600);
  Serial.println("Please input serial data.");
}
 
void loop() {
  if (Serial.available()) {  // 检查串口缓存是否有数据等待传输 
    char servoName = Serial.read();   //获取电机指令中电机编号信息
 
    Serial.print("servoName = ");
    Serial.print(servoName);    
    Serial.print(" , ");      
     
    int data = Serial.parseInt();   //获取电机指令中电机角度信息
 
    switch(servoName){ //根据电机指令中电机信息决定对哪一个电机进行角度设置
      case 'b':   // 电机指令b，设置base电机角度
        base.write(data);
        Serial.print("Set base servo value: ");
        Serial.println(data);
        break;
      case 'r':  // 电机指令r，设置rArm电机角度  
        rArm.write(data);
        Serial.print("Set rArm servo value: ");
        Serial.println(data);
        break;
      case 'f':   // 电机指令f，设置fArm电机角度  
        fArm.write(data);
        Serial.print("Set fArm servo value: ");
        Serial.println(data);
        break;
      case 'c':   // 电机指令c，设置claw电机角度  
        claw.write(data);  
        Serial.print("Set claw servo value: ");
        Serial.println(data);
        break;
    }
  }
}

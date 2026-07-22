/*
Array-2
by太极创客(2016-06-05)
www.taichi-maker.com
    
本示例程序为配合太极创客制作的《零基础入门学用Arduino教程-MeArm篇》使用
本示例程序旨在演示通过ARDUINO用二维数组让伺服电机独立执行一系列指令工作。
    
有关电路连接以及其他相关内容，请参见太极创客网站关于本示例程序的相关页面。
This example code is in the public domain.
*/
#include <Servo.h>
 
Servo base, fArm, rArm, claw;
 
int data2dArray[4][5] = {  //建立二维数组用以控制四台舵机
  {0,   45,   90,   135,  180},
  {45,  90,   135,  90,   45},
  {135, 90,   45,   90,   135},
  {180, 135,  90,   45,   0}
};
 
void setup() {
  base.attach(11);     // base 伺服电机连接引脚11 电机代号'b'
  rArm.attach(10);     // rArm 伺服电机连接引脚10 电机代号'r'
  fArm.attach(9);      // fArm 伺服电机连接引脚9  电机代号'f'
  claw.attach(6);      // claw 伺服电机连接引脚6  电机代号'c'
}
 
void loop() { 
  for (int i = 0; i <= 4; i++){  
    base.write(data2dArray[0][i]);  //base舵机对应data2dArray数组中第1“行”元素
    delay(100);                     
    rArm.write(data2dArray[1][i]);  //rArm舵机对应data2dArray数组中第2“行”元素
    delay(100);                     
    fArm.write(data2dArray[2][i]);  //fArm舵机对应data2dArray数组中第3“行”元素
    delay(100);                     
    claw.write(data2dArray[3][i]);  //claw舵机对应data2dArray数组中第4“行”元素
    delay(500);                     
  }
  for (int i = 4; i >= 0; i--){
    base.write(data2dArray[0][i]);  //base舵机对应data2dArray数组中第1“行”元素
    delay(100);                     
    rArm.write(data2dArray[1][i]);  //rArm舵机对应data2dArray数组中第2“行”元素
    delay(100);                     
    fArm.write(data2dArray[2][i]);  //fArm舵机对应data2dArray数组中第3“行”元素
    delay(100);                     
    claw.write(data2dArray[3][i]);  //claw舵机对应data2dArray数组中第4“行”元素
    delay(500);  
  }
}

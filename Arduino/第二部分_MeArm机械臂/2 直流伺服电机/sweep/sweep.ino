/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.
 
 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
 
#include <Servo.h>
 
Servo myservo;  // 创建Servo对象用以控制伺服电机
                 // 很多开发板允许同时创建12个Servo对象
 
int pos = 0;    // 存储伺服电机角度信息的变量
 
void setup() {
  myservo.attach(9);  // Servo对象连接在9号引脚 
  Serial.begin(9600);
}
 
void loop() {
  for (pos = 0; pos <= 180; pos += 45) { // 0度转到180度
    // 每一步增加1度
    myservo.write(pos);              // 告诉伺服电机达到'pos'变量的角度
    Serial.println(pos);
    delay(1000);                       // 等待15毫秒以确保伺服电机可以达到目标角度
  }
  for (pos = 180; pos >= 0; pos -= 45) { // 180度转到0度
    myservo.write(pos);              // 告诉伺服电机达到'pos'变量的角度
    Serial.println(pos);
    delay(1000);                       // 等待15毫秒以确保伺服电机可以达到目标角度
  }
}

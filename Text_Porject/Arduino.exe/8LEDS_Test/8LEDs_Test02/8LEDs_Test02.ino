/*
此程序实现的功能是，在原有基础上，修改getrandomNumber这个自定义函数；
让他在串口监视器上输出5个随机数字，并在阴极二极管上显示最后一个数字。
*/

void setup(){
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  int pinNumber = 3;
  while(pinNumber <= 9){
    pinMode(pinNumber,OUTPUT);
    pinNumber++;
  }
}

void loop(){
  int myNumber = getrandomNumber(0,10);
  displayNumber(myNumber);
  delay(500);
  displayClean();
  delay(500);
}

int getrandomNumber(int minNumber,int maxNumber){
  int randomNumber;
  for(int i = 1;i <= 5;i++){
    randomNumber = random(minNumber,maxNumber);
    displayNumber(randomNumber);
    delay(100);
    displayClean();
    delay(100);

    Serial.print("i = ");
    Serial.println(i);
    Serial.println("这个随机数是:");
    Serial.println(randomNumber);
    Serial.println("");
  }
  return randomNumber;
}

void displayNumber(int ledNumber){
  switch(ledNumber){
    case 1:  //显示1
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH); 
      break;   
    case 2:  //显示2
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH); 
      digitalWrite(5, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;   
    case 3:   //显示3
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH); 
      digitalWrite(5, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      break;   
    case 4:  //显示4
      digitalWrite(4, HIGH); 
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      break;  
    case 5:  //显示5
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      break;
    case 6:  //显示6
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;    
    case 7:  //显示7
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH); 
      digitalWrite(7, HIGH);  
      break;
    case 8:  //显示8
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;
    case 9:  //显示9
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      break;
    case 0:  //显示0
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;
    default: //显示默认
        digitalWrite(4, HIGH); 
        digitalWrite(5, HIGH); 
        digitalWrite(7, HIGH); 
        digitalWrite(8, HIGH);  
        digitalWrite(9, HIGH);   
  }
}

void displayClean(){
  int cleanNumber = 3;
  while(cleanNumber <= 9){
    digitalWrite(cleanNumber,LOW);
    cleanNumber++;
  }
}








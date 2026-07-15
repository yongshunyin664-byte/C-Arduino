/*
实现的功能：阴极二极管可以显示一个随机数，并在串口监视器可以检测。
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

//生成随机数并实现串口检测的自定义函数（有返回有定义）
int getrandomNumber(int minNumber,int maxNumber){
  int randomNumber = random(minNumber,maxNumber);
  Serial.print("这个随机值是:");
  Serial.println(randomNumber);
  Serial.println("");
  return randomNumber;
}

//让自定义数字在阴极二极管上显示的自定义函数（有定义）
void displayNumber(int ledNumber){
  switch(ledNumber){
    case 1:
      digitalWrite(4,HIGH);
      digitalWrite(7,HIGH);
      break;
    case 2:
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
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
    default:
        digitalWrite(4, HIGH); 
        digitalWrite(5, HIGH); 
        digitalWrite(7, HIGH); 
        digitalWrite(8, HIGH);  
        digitalWrite(9, HIGH);  
    
  }
}

//清理显示内容的自定义函数（无返回无定义）
void displayClean(){
  int cleanNumber = 3;
  while(cleanNumber <= 9){
    digitalWrite(cleanNumber,LOW);
    cleanNumber++;
  }
}
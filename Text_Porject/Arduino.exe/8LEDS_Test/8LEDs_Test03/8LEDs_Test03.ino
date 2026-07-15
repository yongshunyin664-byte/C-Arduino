/*
此程序目的:每次按键后闪动随机图案，最后停留在一个数字上面。
*/
void setup(){
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  for(int pinNumber = 3;pinNumber <= 9;pinNumber++){
    pinMode(pinNumber,OUTPUT);
  }
  randomSeed(analogRead(A0));
}

void loop(){
  if(!digitalRead(2)){
    int myNumber = getrandomNumber(0,10);
    displayNumber(myNumber);
  }
}

int getrandomNumber(int minNumber,int maxNumber){
  int randomNumber;
  for(int i = 1;i <= 5;i++){
    randomNumber = random(minNumber,maxNumber);
    displayNumber(randomNumber);
    delay(500);
    displayClean();

    Serial.print("i = ");
    Serial.println(i);
    Serial.print("randomNumber:");
    Serial.println(randomNumber);
    Serial.println("");
  }
  delay(1000);
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
    case 0:  //显示默认
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

void displayClean(){
  for(int pinNumber = 3;pinNumber <= 9;pinNumber++){
    digitalWrite(pinNumber,LOW);
  }
}
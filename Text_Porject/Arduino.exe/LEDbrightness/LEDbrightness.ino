bool pushButton1;
bool pushButton2;
int pinNumber = 9;
int brightness =18;

void setup(){
  Serial.begin(9600);
  pinMode(pinNumber,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
}

void loop(){
  if(!digitalRead(2) && brightness > 0){
    brightness--;
  }else if(!digitalRead(8) && brightness < 255){
    brightness++;
  }
  analogWrite(pinNumber,brightness);
  Serial.print("亮度为:");
  Serial.println(brightness);
  delay(10);
}
void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
}

void loop() {
  int analogInputVal = analogRead(A0);
  int brightness = map(analogInputVal,0,1023,0,255);
  analogWrite(9,brightness);
}

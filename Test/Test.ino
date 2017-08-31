void setup(){
  Serial.begin(9600);
}
void loop(){
  int niv = analogRead(A0)/4;
  int digital = digitalRead(2);
  analogWrite(8, niv);
  Serial.println(digital);
  delay(100);
}

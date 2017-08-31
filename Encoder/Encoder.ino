unsigned long trig = 0;
unsigned long length = 0;
unsigned long previousTime = 0;
float seconds = 0;

int pin = 2;
byte tgl = 0;

float f = 0;
float T = 0;
float w = 0;

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  //lcd.begin(16, 2);
  //lcd.print("Holiwis");
  Serial.begin(9600);
}
void loop(){
  int niv = analogRead(A0)/4;
  int digital = digitalRead(2);
  analogWrite(8, niv);
  if(!digitalRead(pin) && !tgl){
    trig = millis();
    tgl = 1;
  }  
  if(digitalRead(pin) && tgl){
    length = millis() - trig;
    tgl = 0;
    seconds = length * 0.001;
    f = 1/seconds;
    T = 1/f;
    w = f * 2 * 3.1416;
    Serial.print("Frecuencia: ");
    Serial.print(f);
    Serial.print(" - Periodo: ");
    Serial.print(T);
    Serial.print(" - Frecuencia Angular: ");
    Serial.print(w);
    Serial.println();
  }
  //lcd.display();
}

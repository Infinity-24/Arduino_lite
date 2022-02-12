 

#include <LiquidCrystal.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = A0, d5 = A1, d6 = A4, d7 = A2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int led=7;
int switch1 = 2;
int switch2 = 3;
int switch3 = 4;
int switch4 = 5;
int switch5 = 1;
int switch6 = 0;



void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //declare inputs
  pinMode(led,OUTPUT);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);
  pinMode(switch5, INPUT);
  pinMode(switch6, INPUT);
  // set servo motor
  
}

void loop() {
  switch1 = digitalRead(2);
  switch2 = digitalRead(3);
  switch3 = digitalRead(4);
  switch4 = digitalRead(5);
  switch6 = digitalRead(1);
  if(switch1 && switch4 && switch6 == HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.write("Door not lock");
    digitalWrite(led,HIGH);
    delay(5000);
    
  } else
  {
    lcd.clear();
    
    lcd.write("Door locked");
    digitalWrite(led,LOW);
  }
  
}
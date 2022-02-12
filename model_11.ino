

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//Motor 1
const int motor1_Pin1  = 6; 
const int motor1_Pin2  = 8; 
int buzzer_pin=9;
int degree;
double realDegree;
String lcdBuffer;
int pir=7;
int direction[5];
int valid = 0;


void setup() {
  pinMode(motor1_Pin1, OUTPUT);
  pinMode(motor1_Pin2, OUTPUT);
  pinMode(buzzer_pin,OUTPUT);
  pinMode(pir,INPUT);
  lcd.begin(16, 2);
  degree = 0;
  realDegree = 0;
  lcd.print("Today's temp:");
  // Print a message to the LCD.
  Serial.begin(9600);
  
}


void loop(){
  
  int motion=0;
  motion = digitalRead(pir); 
   if (motion==HIGH){
   digitalWrite(buzzer_pin,HIGH); 
  }
  
  else {
   digitalWrite(buzzer_pin,LOW);   
  }
  delay(10);
  
  lcd.print(" ");
  int val = digitalRead(pir);
  Serial.println(val);
  
  
  degree = analogRead(0);
  realDegree = (double)degree/1024;
  realDegree *= 5;
  realDegree -= 0.5;
  realDegree *= 100;
  lcd.setCursor(0,1);
  realDegree = (9.0/5)*(realDegree) + 32;
  Serial.println(realDegree);
  if(realDegree>65){
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, HIGH);
   delay(2000);
  }
  else{
  digitalWrite(motor1_Pin1, LOW);
  digitalWrite(motor1_Pin2, LOW);
   delay(2000);
  }
  
  
  String output = String(realDegree) + String((char)178) + "F";
  lcd.print(output);
  
  
  
}
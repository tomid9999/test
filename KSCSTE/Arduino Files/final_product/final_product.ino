#include <string.h>
#include "DHT.h"
#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

DHT dht;
int sensorPin = A2;    
int sensorValue = 0;

int temperature=0;
int pflag=0;
int pH_Value; 
float Voltage;

String s="nil";
String temp="nil";
String humidity="nil";
String ph="nil";
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(pH_Value, INPUT);
  /*digital_communication for dht11*/
  dht.setup(8);
}

void loop() {
  lcd.clear();
  delay(10000);
  float humidity_11 = dht.getHumidity();    
  float temperature = dht.getTemperature(); 
  
  sensorValue = analogRead(sensorPin);
  
  pH_Value = analogRead(A0); 
  Voltage = pH_Value * (5.0 / 1023.0); 
  delay(500);
  
  Serial.print("Temp:"); 
  Serial.print(temperature);
  Serial.print("  Humidity:");
  Serial.print(sensorValue);
  Serial.print("      ph:");
  Serial.print(pH_Value);
  Serial.print("\n");
  

  if(temperature<=23){
    temp="cool";
  }
  else if(temperature>23 & temperature<=28){
    temp="moderate";
  }
  else if(temperature>28){
    temp="hot";
  }
  if(sensorValue>750){
    humidity="dry";
  }
  else if(sensorValue>=500 & humidity_11<=750){
    humidity="moderate";
  }
  else if(humidity_11<500){
    humidity="wet";
  }
  if(pH_Value<85 & pH_Value>55){
    ph="ma";
  }
  else if(pH_Value>85 & pH_Value<100){
    ph="n";
  }
  if(temp=="cool" & humidity=="wet" & ph=="ma"){
    s="apple,maize";
    lcd.print(s);
    delay(600);
    lcd.clear();
    s="pomegranate";
    lcd.print(s);
    delay(600);
    lcd.clear();
    pflag=1;
    
  }  
  else if(temp=="moderate" & humidity=="wet" & ph=="ma"){ 
    s="banana,coconut";
    lcd.print(s);
    delay(6000);
    lcd.clear();
    s="grapes,jute,rice";
    lcd.print(s);
    delay(6000);
    lcd.clear();
    s="watermelon";
    lcd.print(s);
    delay(6000);
    lcd.clear();
    pflag=1;
  } 
  else if(temp=="hot" & humidity=="wet" & ph=="n"){
    s="blackgram";
  }  
  else if(temp=="cool" & humidity=="dry" & ph=="n"){
    s="chickpea";
  }   
  else if(temp=="moderate" & humidity=="moderate" & ph=="ma"){
    s="coffee, pigeonpeas";
  } 
  else if(temp=="moderate" & humidity=="wet" & ph=="n"){
    s="cotton";
  } 
  else if(temp=="cool" & humidity=="dry" & ph=="ma"){
    s="kidneybeans";
  }  
  else if(temp=="moderate" & humidity=="moderate" & ph=="n"){
    s="lentil";
  }  
  else if(temp=="hot" & humidity=="moderate" & ph=="ma"){
    s="mango";
  }  
  else if(temp=="hot" & humidity=="moderate" & ph=="n"){
    s="mothbeans";
  } 
  else if(temp=="hot" & humidity=="wet" & ph=="ma"){
    s="mungbean, muskmelon";
    lcd.print(s);
    delay(6000);
    lcd.clear();
    s="papaya";
    lcd.print(s);
    delay(6000);
    lcd.clear();
    pflag=1;
  }
  if(pflag==0){
    lcd.print(s); 
    delay(7000);
    lcd.clear(); 
  }

}

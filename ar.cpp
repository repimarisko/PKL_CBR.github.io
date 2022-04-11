#include<Liquidcrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int RainSensor = 6;
int buzzer = 7;
int DC_Motor = 8;
int Lcd 16x2 = 9;
int Red_LED = 13;
int Green_LED = 14;

void setup() {
  pinMode(RainSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(DC_Motor, OUTPUT);
  pinMode(Lcd, OUTPUT);
  pinMode(Red_LED, OUTPUT);
  pinMode(Green_LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
    int sensorValue = digitalRead(RainSensor);
    if (sensorValue == HIGH)
    {
        digitalWrite(buzzer, HIGH);
        digitalWrite(DC_Motor, HIGH);
        digitalWrite(Lcd, HIGH);
        digitalWrite(Red_LED, HIGH);
        digitalWrite(Green_LED, LOW);
        lcd.clear();
        lcd.print("Rain Detected");
        delay(1000);
    }
    else
    {
        digitalWrite(buzzer, LOW);
        digitalWrite(DC_Motor, LOW);
        digitalWrite(Lcd, LOW);
        digitalWrite(Red_LED, LOW);
        digitalWrite(Green_LED, HIGH);
        lcd.clear();
        lcd.print("No Rain Detected");
        delay(1000);
    }
}
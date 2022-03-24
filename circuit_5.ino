#include <LiquidCrystal.h>

int Trig = A0;
int Echo = A1;
//int a = 5, b = 6, c = 7, d = 8,
	//e = 9, f = 10, g = 11;

int a=1, b=2, c=3, d=4, e=5, f=6, g=7;  
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
  
void setup()
{
 	//Serial.begin(9600);
  	pinMode(Trig, OUTPUT);
  	pinMode(Echo, INPUT);
  
  	for(int i=1; i <=7; i++)
      pinMode(i, OUTPUT);
  	lcd.begin(16, 2);
  	
  	
}

void LedsFlash()
{
	ShowNumber8();
  	delay(50);
  	for(int i=1; i<=7; i++)
      digitalWrite(i,HIGH);
  	delay(50);
}

void ShowNumber1() 
{
  for(int i = 1; i <= 7; i++) {
    digitalWrite(i, HIGH);
  }
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
}

void ShowNumber2() {
  for(int i = 1; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(c, HIGH);
  digitalWrite(f, HIGH);
}

void ShowNumber3() {
  for(int i = 1; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
}

void ShowNumber4() {
  for(int i = 1; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(a, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
}

void ShowNumber5() {
  for(int i = 1; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(b, HIGH);
  digitalWrite(e, HIGH);
}

void ShowNumber6() {
  for(int i = 1; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(b, HIGH);
}

void ShowNumber7() {
  for(int i = 1;i <= 7;i++) {
    digitalWrite(i, HIGH);
  }
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
}

void ShowNumber8() {
  for(int i = 1; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
}

void ShowNumber9() {
  for(int i = 1; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(e, HIGH);
}

float DistanceInCm()
{
  	digitalWrite(Trig, LOW);
  	delay(200);
  	digitalWrite(Trig, HIGH);
  	delay(200);
  	digitalWrite(Trig, LOW);

  	float Distance = pulseIn(Echo, HIGH)*0.0344/2;
  	return Distance;
  	//2.2cm - 330cm+
}

void ShowDistance(float Distance)
{	
	if (Distance <= 37)
    ShowNumber1();
   	else if (Distance > 37 && Distance <= 37*2)
    ShowNumber2();
   	else if (Distance > 37*2 && Distance <= 37*3)
    ShowNumber3();
   	else if (Distance > 37*3 && Distance <= 37*4)
    ShowNumber4();
   	else if (Distance > 37*4 && Distance <= 37*5)
    ShowNumber5();
   	else if (Distance > 37*5 && Distance <= 37*6)
    ShowNumber6();
   	else if (Distance > 37*6 && Distance <= 37*7)
    ShowNumber7();
   	else if (Distance > 37*7 && Distance <= 37*8)
    ShowNumber8();
   	else if (Distance > 37*8 && Distance <= 37*9)
    ShowNumber9();
  	else 
    LedsFlash();
  
}

void ShowLCD(float Distance)
{	
	if ((Distance <= 37) |(Distance > 37 && Distance <= 37*4)){
    	lcd.clear();
      	lcd.setCursor(0, 1);
    	lcd.print("Short distance");
    }	
		    	
  	else if(Distance > 37*4 && Distance <= 37*9){
      	lcd.clear();
      	lcd.setCursor(0, 1);
      	lcd.print("Long distance");}
  	else{
      	lcd.clear();
      	lcd.setCursor(0, 1);
      	lcd.print("Wrong!");}
}

void loop()
{
  	float Distance = DistanceInCm();
	ShowDistance(Distance);
  	ShowLCD(Distance);
  	lcd.setCursor(0, 0);
  	lcd.print(Distance);
  	lcd.print(" cm");
  
  	//1-4:short distance
  	//5-9:long distance
}
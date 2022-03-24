int Trig = 3;
int Echo = 2;
int a = 5, b = 6, c = 7, d = 8,
	e = 9, f = 10, g = 11;

void setup()
{
 	Serial.begin(9600);
  	pinMode(Trig, OUTPUT);
  	pinMode(Echo, INPUT);
  
  	for(int i=5; i <=11; i++)
      pinMode(i, OUTPUT);
}

void ShowNumber0() { 
  for(int i = 5; i <= 11; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(g, HIGH);
}

void ShowNumber1() 
{
  for(int i = 5; i <= 11; i++) {
    digitalWrite(i, HIGH);
  }
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
}

void ShowNumber2() {
  for(int i = 5; i <= 11; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(c, HIGH);
  digitalWrite(f, HIGH);
}

void ShowNumber3() {
  for(int i = 5; i <= 11; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
}

void ShowNumber4() {
  for(int i = 6; i <= 11; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(a, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
}

void ShowNumber5() {
  for(int i = 5; i <= 11; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(b, HIGH);
  digitalWrite(e, HIGH);
}

void ShowNumber6() {
  for(int i = 5; i <= 11; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(b, HIGH);
}

void ShowNumber7() {
  for(int i = 8;i <= 11;i++) {
    digitalWrite(i, HIGH);
  }
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
}

void ShowNumber8() {
  for(int i = 5; i <= 11; i++) {
    digitalWrite(i, LOW);
  }
}

void ShowNumber9() {
  for(int i = 5; i <= 11; i++) {
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
    ShowNumber0();
  
}

void DeBug(float Distance){
	Serial.print(Distance);	
  	Serial.println(" cm");
 	delay(300);
}

void loop()
{
  	float Distance = DistanceInCm();
	ShowDistance(Distance);
    DeBug(Distance);
  	
}

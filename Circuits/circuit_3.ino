int Green = 2, Yellow = 3, Red = 4;
int a = 5, b = 6, c = 7, d = 8,
	e = 9, f = 10, g = 11;

void setup() {
  for(int i = 2; i <= 11; i++) 
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

void ShowLedsNumber() {
  ShowNumber9();
  delay(1000);
  ShowNumber8();
  delay(1000);
  ShowNumber7();
  delay(1000);
  ShowNumber6();
  delay(1000);
  ShowNumber5();
  delay(1000);
  ShowNumber4();
  delay(1000);
  ShowNumber3();
  delay(1000);
  ShowNumber2();
  delay(1000);
  ShowNumber1();
  delay(1000);
  ShowNumber0();
  delay(1000);
}

void loop() {
  digitalWrite(Red, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, HIGH);
  ShowLedsNumber();
  
  digitalWrite(Red, LOW);
  digitalWrite(Yellow, HIGH);
  digitalWrite(Green, LOW);
  ShowLedsNumber();

  digitalWrite(Red, HIGH);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, LOW);
  ShowLedsNumber();
}
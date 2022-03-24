const int LED[] = {0,1,2,3,4,5};
const int PushButton = 8;
int Count = 0;
//int NewCount;
// value to check state of button switch


void setup() {
  for (int i = 0; i <= 5; i++) {
    pinMode(LED[i], OUTPUT);
  }
  pinMode(PushButton, INPUT);
  
}


void ShowLedsNumber(int number)
{
	for (int i = 0; i <= number; i++)
      {
        digitalWrite(LED[i], HIGH);
        delay(50);
      }
}


void LedsOff()
{
  	for (int i = 0; i <= 6; i++)
      digitalWrite(LED[i], LOW);
}  

void LedsFlash(int number)
{
	int i = 0;
  	while (i < 6)
    {
    	ShowLedsNumber(number);
      	delay(100);
      	LedsOff();
      	delay(100);
      	i++;
    }
}

void loop()
{
  
	int RandomNumber = random(0,6);
 	
  	if (digitalRead(8) == HIGH)  
    { 
      ShowLedsNumber(RandomNumber);
      delay(1000);
      LedsFlash(RandomNumber);
    }
   

}
  	
  	
  	

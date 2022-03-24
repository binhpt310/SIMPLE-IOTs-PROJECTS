int LED[] = {0,1,2,3,4,5,6,7,8,9,10,11};
#define Potention_meter A0;

void setup()
{

  pinMode(A0, INPUT);
    for (int i = 0; i <= 11; i++)
      pinMode(LED[i], OUTPUT);
}

void loop()
{
  int AnalogValue = map(analogRead(A0), 0, 1023, 0, 12);
  //The value number off A0 is from 0-1023 
  //map() function: put a number into a different range.
  //take the  from the range 0-1023 to 0-13 (LED).
  for (int i = 0; i <= 11; i++)
  {
    if (i < AnalogValue)
      digitalWrite(i, 1);
    else
      digitalWrite(i, 0);
  }
}
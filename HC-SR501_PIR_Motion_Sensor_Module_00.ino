int ledPin= 13;
int inputPin= 3;  
//Center pin of for signal
//Zener diod for 5 v.


void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
}

void loop(){
  int value= digitalRead(inputPin);

  if (value == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    delay(1000) ;
  }

  else
  {
    digitalWrite(ledPin, LOW);
  }
}
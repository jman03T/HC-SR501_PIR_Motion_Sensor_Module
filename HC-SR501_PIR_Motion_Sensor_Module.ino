//Center pin of for signal.
//Zener diod for 5 v.
const int analogInPin = A0;
const int analogOutPin = 12;
const int ledPin =  LED_BUILTIN;

int sensorValue = 0;
int outputValue = 0;
unsigned long previousMillis = 0;
unsigned long time1 = 0;
bool stat = false;

const long interval = 10001;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(analogOutPin, outputValue);
  if (outputValue >= 100) {
    digitalWrite(ledPin, HIGH);
    previousMillis = millis();
    stat = true;
  }
  if (millis() - previousMillis >= interval) {
    digitalWrite(ledPin, LOW);
    stat = false;
  }
  if (stat) {
    time1 = millis() - previousMillis;
    Serial.println(map(time1, 0, 20000, 0, 20));
  }
  /*
  Serial.print(previousMillis);
  Serial.print("Sensoe = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  delay(200);*/
}

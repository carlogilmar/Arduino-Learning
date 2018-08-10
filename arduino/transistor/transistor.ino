int LEDPin = 2;
int transistorPin = 5;

void setup(){

  pinMode(LEDPin, OUTPUT);
  pinMode(transistorPin, OUTPUT);
 
}

void loop(){

  digitalWrite(LEDPin, HIGH);
  analogWrite(transistorPin, 200);
  delay(1000);
  digitalWrite(LEDPin, LOW);
  analogWrite(transistorPin, 0);
  delay(1000);

}

int buttonPin = 7;
int ledPin = 4;
int buttonState = LOW;

void setup(){ 
  Serial.begin(9600); 
  pinMode(buttonPin, INPUT);  // D7 will receive input from button 
  pinMode(ledPin, OUTPUT);    // D4 will send output to LED 
}

void loop(){ 
  buttonState = digitalRead(buttonPin);  // Read button state 

  // If user presses the push button 
  // Then state will be HIGH 
  if(buttonState == HIGH) 
  { 
    digitalWrite(ledPin, HIGH);   // glow the LED 
    //delay(250);                  // wait for 1 second 
    //digitalWrite(ledPin, LOW);    // switch OFF the glowing LED 
  } 
  delay(1000); 
} 

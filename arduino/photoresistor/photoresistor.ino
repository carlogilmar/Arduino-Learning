const int ledPin = 13;
const int sensorPin = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int valueAnalog = analogRead(sensorPin);
  
  Serial.println(valueAnalog);
  
  if( valueAnalog < 500 ){
    Serial.println("Valor bajo, prendiendo iluminacion");
    digitalWrite(13, HIGH);
  } else {
    Serial.println("Valor alto, apagando iluminación");
    digitalWrite(13, LOW);
  }
  
} 

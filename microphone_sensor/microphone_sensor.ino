void setup()
{
  Serial.begin(9600);    // Iniciamos la puerta serie
}

void loop()
{
  int Lectura = analogRead(A5) ;
  Serial.println( Lectura);
  delay(200) ;
}

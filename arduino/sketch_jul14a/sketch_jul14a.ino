#include "DHT.h"
#include <LiquidCrystal.h>


DHT dht(8, DHT11);
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
 
void setup() {
  //Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
  lcd.print("::carlogilmar::");
  lcd.setCursor(0,1);  
  lcd.print("::alee_rguez::❤");
}
 
void loop() {
  // ESPERAR ENTRE MEDICIONES, NECESARIO PARA EL BUEN FUNCIONAMIENTO

  delay(2000);

  // LEER LA HUMEDAD USANDO EL METRODO READHUMIDITY
  float h = dht.readHumidity();
  // LEER LA TEMPERATURA USANDO EL METRODO READTEMPERATURE
  float t = dht.readTemperature();
 
  // REVISAR QUE LOS RESULTADOS SEAN VALORES NUMERICOS VALIDOS, INDICANDO QUE LA COMUNICACION ES CORRECTA
  if (isnan(h) || isnan(t)) {
    Serial.println("Falla al leer el sensor DHT11!");
    return;
  }
 
  // IMPRIMIR RESULTADO AL MONITOR SERIAL
  lcd.clear(); // Clears the display 
  lcd.print("Humedad:");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0,1);  
  lcd.print("Temp:");
  lcd.print(t);
  lcd.println(" *C ->");

 //lcd.print("Temper"); // Prints "Arduino" on the LCD 
 /*
 delay(3000); // 3 seconds delay 
 lcd.setCursor(2,1); // Sets the location at which subsequent text written to the LCD will be displayed 
 lcd.print("LCD Tutorial"); 
 delay(3000); 
 lcd.clear(); // Clears the display 
 lcd.blink(); //Displays the blinking LCD cursor 
 delay(4000); 
 lcd.setCursor(7,1); 
 delay(3000); 
 lcd.noBlink(); // Turns off the blinking LCD cursor 
 lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written 
 delay(4000); 
 lcd.noCursor(); // Hides the LCD cursor 
 lcd.clear(); // Clears the LCD screen 
 */
}

/*
#include "DHT.h"
 
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
 
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
 
const int DHTPin = 5;     // what digital pin we're connected to
 
DHT dht(DHTPin, DHTTYPE);
 
void setup() {
   Serial.begin(9600);
   Serial.println("DHTxx test!");
 
   dht.begin();
}
 
void loop() {
   // Wait a few seconds between measurements.
   delay(2000);
 
   // Reading temperature or humidity takes about 250 milliseconds!
   float h = dht.readHumidity();
   float t = dht.readTemperature();
 
   if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
   }
 
 
   Serial.print("Humidity: ");
   Serial.print(h);
   Serial.print(" %\t");
   Serial.print("Temperature: ");
   Serial.print(t);
   Serial.print(" *C \n");
}
*/

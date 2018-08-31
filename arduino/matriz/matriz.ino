#include <LedControl.h>

int DIN = 12;
int CS =  11;
int CLK = 10;
int incomingByte = 0;

LedControl lc=LedControl(DIN,CLK,CS,0);

    byte uno[8] = {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18};
    byte dos[8] = {0xff,0xff,0x18,0x18,0x18,0x18,0x18,0x18};
    byte tres[8] = {0xff,0xff,0x1e,0x1c,0x38,0x70,0xff,0xff};
    byte cuatro[8] = {0xff,0xff,0xc0,0xf8,0xf8,0xc0,0xff,0xff};
    byte cinco[8] = {0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xff,0xff};

    byte a[8] = {0x83,0xc6,0x6c,0x38,0x1c,0x36,0x63,0xc1};
    byte b[8] = {0x18,0x18,0x18,0xff,0xff,0x18,0x18,0x18};
    byte c[8] = {0x3c,0x08,0x89,0xf9,0x9f,0x11,0x10,0x38};
    byte d[8] = {0x70,0x11,0x11,0x1f,0xf8,0x88,0x88,0x0e};

void setup(){
 Serial.begin(9600);
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the br1ightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 

   if (Serial.available() > 0) {
    
    incomingByte = Serial.read(); // read the incoming byte:
     Serial.print("leyendo");
     Serial.print(incomingByte);
    if( incomingByte == 49 ) {
      Serial.print("daleee");
            printByte(a);    
    delay(250);
            printByte(b);    
    delay(250);
            printByte(c);    
    delay(250);
            printByte(d);    
    delay(250);
    lc.clearDisplay(0);
    } 
    
  }

}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}


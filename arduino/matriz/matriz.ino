#include <LedControl.h>

int DIN = 12;
int CS =  11;
int CLK = 10;
int incomingByte = 0;

int sensorPin = 0;

LedControl lc=LedControl(DIN,CLK,CS,0);

    //https://gurgleapps.com/tools/matrix

    byte a[8] = {0x83,0xc6,0x6c,0x38,0x1c,0x36,0x63,0xc1};
    byte b[8] = {0x18,0x18,0x18,0xff,0xff,0x18,0x18,0x18};
    byte c[8] = {0x3c,0x08,0x89,0xf9,0x9f,0x11,0x10,0x38};
    byte d[8] = {0x70,0x11,0x11,0x1f,0xf8,0x88,0x88,0x0e};

    //pacman
    byte pacman1[8] = {0x3c,0x7e,0xf4,0xf8,0xf0,0xf8,0x7c,0x3e};
    byte pacman2[8] = {0x3c,0x7e,0xf6,0xff,0xff,0xfe,0x7e,0x3c};

    //hi!
    byte hi1[8] = {0xc3,0xc3,0xc3,0xff,0xff,0xc3,0xc3,0xc3};
    byte hi2[8] = {0x3c,0x7e,0xe7,0xc3,0xc3,0xe7,0x7e,0x3c};
    byte hi3[8] = {0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xff,0xff};
    byte hi4[8] = {0x18,0x3c,0x66,0x66,0x7e,0x7e,0x66,0x66};

    byte song1[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    byte song2[8] = {0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00};
    byte song3[8] = {0x00,0x3c,0x42,0x5a,0x5a,0x42,0x3c,0x00};
    byte song4[8] = {0x42,0xbd,0x42,0x5a,0x5a,0x42,0xbd,0x42};
    byte song5[8] = {0xc3,0xbd,0x42,0x5a,0x5a,0x42,0xbd,0xc3};
    byte song6[8] = {0xff,0xff,0xff,0xe7,0xe7,0xff,0xff,0xff};
    byte song7[8] = {0xff,0xff,0xdb,0xe7,0xe7,0xdb,0xff,0xff};
    byte song8[8] = {0xff,0xff,0xc3,0xc3,0xc3,0xc3,0xff,0xff};
    byte song9[8] = {0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff};
    byte song10[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

        
void setup(){
 Serial.begin(9600);
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the br1ightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 
   
   int valueAnalog = analogRead(sensorPin);
    
   if (Serial.available() > 0) {
    incomingByte = Serial.read(); // read the incoming byte:
     Serial.print("leyendo");
     Serial.print(incomingByte);
    if( incomingByte == 49 ) { playMessage(); }
    if( incomingByte == 50 ) { playHi(); }
    if( incomingByte == 51 ) { playSong1(); }
  }
  
  if( valueAnalog < 500 ){
    playPacman();
  } 

}

void playMessage(){
    printByte(a);    
    delay(150);
    printByte(b);    
    delay(150);
    printByte(c);    
    delay(150);
    printByte(d);    
    delay(150);
    lc.clearDisplay(0);
}

void playPacman(){
    printByte(pacman1);    
    delay(250);
    printByte(pacman2);    
    delay(250);
    printByte(pacman1);    
    delay(250);
    printByte(pacman2);    
    delay(250);
    lc.clearDisplay(0);
}

void playHi(){
    printByte(hi1);    
    delay(250);
    printByte(hi2);    
    delay(250);
    printByte(hi3);    
    delay(250);
    printByte(hi4);    
    delay(250);
    lc.clearDisplay(0);
}

void playSong1(){
    printByte(song1);    
    delay(250);
    printByte(song2);    
    delay(250);
    printByte(song3);    
    delay(250);
    printByte(song4);    
    delay(250);
    printByte(song5);    
    delay(250);
    printByte(song6);    
    delay(250);
    printByte(song7);    
    delay(250);
    printByte(song8);    
    delay(250);
    printByte(song9);    
    delay(250);
    printByte(song10);    
    delay(250);
    lc.clearDisplay(0);
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}


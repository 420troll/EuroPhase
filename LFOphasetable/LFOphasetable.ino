#include <SPI.h>
#include <MCPDAC.h>

    



int sine[120] = {


    0x0, 0x2, 0xb, 0x19, 0x2c, 0x45, 0x64, 0x87, 0xb1, 0xdf,
    0x112, 0x14a, 0x187, 0x1c8, 0x20d, 0x257, 0x2a5, 0x2f6, 0x34c, 0x3a4,
    0x3ff, 0x45d, 0x4be, 0x521, 0x586, 0x5ed, 0x655, 0x6bf, 0x729, 0x794,
    0x7ff, 0x86a, 0x8d5, 0x93f, 0x9a9, 0xa11, 0xa78, 0xadd, 0xb40, 0xba1,
    0xbff, 0xc5a, 0xcb2, 0xd08, 0xd59, 0xda7, 0xdf1, 0xe36, 0xe77, 0xeb4,
    0xeec, 0xf1f, 0xf4d, 0xf77, 0xf9a, 0xfb9, 0xfd2, 0xfe5, 0xff3, 0xffc,
    0xfff, 0xffc, 0xff3, 0xfe5, 0xfd2, 0xfb9, 0xf9a, 0xf77, 0xf4d, 0xf1f,
    0xeec, 0xeb4, 0xe77, 0xe36, 0xdf1, 0xda7, 0xd59, 0xd08, 0xcb2, 0xc5a,
    0xbff, 0xba1, 0xb40, 0xadd, 0xa78, 0xa11, 0x9a9, 0x93f, 0x8d5, 0x86a,
    0x7ff, 0x794, 0x729, 0x6bf, 0x655, 0x5ed, 0x586, 0x521, 0x4be, 0x45d,
    0x3ff, 0x3a4, 0x34c, 0x2f6, 0x2a5, 0x257, 0x20d, 0x1c8, 0x187, 0x14a,
    0x112, 0xdf, 0xb1, 0x87, 0x64, 0x45, 0x2c, 0x19, 0xb, 0x2};
    




  int  i = 0;
  int sensorValue   = 0;
  int rate   = 0;
  int ending = 0;
  int start  = 0;
  int  z = 0;
void setup(){

  // CS on pin 10, no LDAC pin (tie it to ground).
  MCPDAC.begin(10);
  
  // Set the gain to "HIGH" mode - 0 to 4096mV.
  MCPDAC.setGain(CHANNEL_A,GAIN_HIGH);
  
  // Do not shut down channel A, but shut down channel B.
  MCPDAC.shutdown(CHANNEL_A,false);
  MCPDAC.shutdown(CHANNEL_B,true);
 
  pinMode(5, INPUT);  //Set up pins as inputs

}

void loop() {

  // read the analog in value:
  sensorValue  = analogRead(5);

  // map it to the range:
  rate   = map(sensorValue , 0, 1024, 0, 100);
  ending = 120;
  start  = 1;
  

 
  i++;
  
  if(i == ending) i = start;  // Reset the counter to repeat the wave
  if(i == 120) i = 1; 
 // z = map(sine[i], 0, 1024, 1000, 2000);
   
  MCPDAC.setVoltage(CHANNEL_A,sine[i]&0x0fff);
 
  
  delay(rate);
 
 

}

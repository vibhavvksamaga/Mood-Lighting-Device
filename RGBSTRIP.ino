#include<FastLED.h>
#include "Arduino.h"
#define LED_PIN 2
#define NUM_LEDS 20
CRGB leds[NUM_LEDS];
int redVal,greenVal,blueVal;
int arr;
char state;
int len,len2;
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
  FastLED.clear();
  FastLED.show();
  Serial.begin(9600);
}
void romantic()
{
  for(int i=0;i<=NUM_LEDS;i++)
  {
    leds[i]=CRGB(255,0,0);
    FastLED.setBrightness(3*i);
    FastLED.show();
    delay(5);
   }
  /* for(int i=NUM_LEDS;i>=0;i--)
  {
    leds[i]=CRGB(255,0,0);
    FastLED.setBrightness(60-2*i);
    FastLED.show();
    delay(50);
  }*/
}
void sleep()
{
  for(int i=0;i<=NUM_LEDS;i++)
  {
    leds[i]=CRGB(51,25,0);
    FastLED.setBrightness(3*i);
    FastLED.show();
    delay(5);
  }
  /*for(int i=NUM_LEDS;i>=0;i--)
  {
    leds[i]=CRGB(32,42,68);
    FastLED.setBrightness(60-2*i);
    FastLED.show();
    delay(50);
  }*/
}
void chill()
{
  for(int i=0;i<=NUM_LEDS;i++)
  {
    leds[i]=CRGB(148,0,211);
    FastLED.setBrightness(3*i);
    FastLED.show();
    delay(5);
  }
 /* for(int i=NUM_LEDS;i>=0;i--)
  {
    leds[i]=CRGB(148,0,211);
    FastLED.setBrightness(60-2*i);
    FastLED.show();
    delay(50);
  }*/
}
void environment()
{
  for(int i=0;i<=NUM_LEDS;i++)
  {
    leds[i]=CRGB(102,204,0);
    FastLED.setBrightness(3*i);
    FastLED.show();
    delay(5);
  }
  /*for(int i=NUM_LEDS;i>=0;i--)
  {
    leds[i]=CRGB(102,204,0);
    FastLED.setBrightness(60-2*i);
    FastLED.show();
    delay(50);
  }*/
}
void dark()
{
  for(int i=0;i<=NUM_LEDS;i++)
  {
    leds[i]=CRGB(30,0,200);
   FastLED.setBrightness(3*i);
    FastLED.show();
    delay(5);
  }
  
}
void readin()
{
  for(int i=0;i<=NUM_LEDS;i++)
  {
    leds[i]=CRGB(255,204,229);
    FastLED.setBrightness(3*i);
    FastLED.show();
    delay(5);
  }
  /*for(int i=NUM_LEDS;i>=0;i--)
  {
    leds[i]=CRGB(255,204,229);
    FastLED.setBrightness(60-2*i);
    FastLED.show();
    delay(50);
  }*/
}
/*void flow()
{
  for(int i=0;i<=NUM_LEDS;i++)
  {
    leds[i]=CRGB(39,0,29);
    FastLED.setBrightness(3*i);
    FastLED.show();
    delay(5);
  }
  redVal=255;
  greenVal=0;
  blueVal=0;
  for(int i=0;i<255;i++)
  {
    redVal-=10;
    greenVal+=10;
    for(int j=0;j<=NUM_LEDS;j++)
    {
    leds[j]=CRGB(redVal,greenVal,0);
    FastLED.show();
    delay(5);
   }
  }
 redVal=0;
  greenVal=255;
  blueVal=0;
  for(int i=0;i<255;i++)
  {
    greenVal-=10;
    blueVal+=10;
    for(int j=0;j<=NUM_LEDS;j++)
    {
    leds[j]=CRGB(0,greenVal,blueVal);
    FastLED.show();
    delay(5);
   }
  }
 /* redVal=0;
  greenVal=0;
  blueVal=255;
  for(int i=0;i<255;i++)
  {
    blueVal-=10;
    redVal+=10;
    for(int j=0;j<=NUM_LEDS;j++)
    {
    leds[j]=CRGB(redVal,0,blueVal);
    FastLED.show();
    delay(5);
   }
  }
}*/
void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  {
    
    String str=Serial.readString();
    Serial.println(str);
    
  
 
  if(str=="S")
  {
    sleep();
  }

  else if(str=="C")
  {
    chill();
  }
  
  else if(str=="R")
  {
    romantic();
  }
  
  else if(str=="E")
  {
    environment();
  }
  
  else if(str=="D")
  {
    dark();
  }
  
  else if(str=="r")
  {
    readin();
  }
  else if(str=="F")
  {
    
    //flow();
   
  }
  else
  {
    len=str.length();
    
    String newString;
    //arr=str.toInt();
    //Serial.println(arr);
    Serial.println(len);
    newString=str.substring(len-12,len-1);
    Serial.println(newString);
    len2=newString.length();
    for(int i=0;i<=len2;i++)
    {
      Serial.println(newString[i]);
      
    }
    Serial.println (newString);
    char Buf[50];
    newString.toCharArray(Buf,50);
    char* d = strtok(Buf, ",");
    int count=0;
    int arr[4];
    int i=0;
    while (d != NULL) {
        Serial.println (d);
        arr[i]=atoi(d);
        count++;
        i++;
        d = strtok(NULL, ",");
    }
    Serial.println(count);
    if(count==4)
    {
      for(int j=1;j<4;j++)
    {
      Serial.print(arr[j]);
      Serial.print(" ");
    }
    for(int i=0;i<=NUM_LEDS;i++)
    {
    leds[i]=CRGB(arr[1],arr[2],arr[3]);
   FastLED.setBrightness(4*i);
    FastLED.show();
    delay(5);
    } 
    
    }
    else
    {
      for(int j=0;j<3;j++)
    {
      Serial.print(arr[j]);
      Serial.print(" ");
    }
    for(int i=0;i<=NUM_LEDS;i++)
  {
    leds[i]=CRGB(arr[0],arr[1],arr[2]);
   FastLED.setBrightness(4*i);
    FastLED.show();
    delay(5);
  }
    }
 
  }
  }
  }

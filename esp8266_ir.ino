#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#define BLYNK_AUTH_TOKEN "hZEXCnKbDwEv_eZ8JJKVGzURoC5MKP7e"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Redmi Note 9 Pro Max";
char pass[] = "amrutbapa";
// d0,gpio 16
// d1,gpio 5
// d2,gpio 4
// d3,gpio 0
// d5,gpio 14
// d6,gpio 12
// d7,gpio 13
// d8,gpio 15
// rx,gpio 3
// tx,gpio 1
// sd2, gpio 9
// sd3, gpio 10
int lightval = 0;
int lightval2 = 0;
int lightval3 = 0;
int sliderValue = 0;
int sliderValue2 = 0;
int sliderValue3 = 0;
int sliderValue4 = 0;
int sliderValue5 = 0;
int sliderValue6 = 0;
int curt = 0;
int cu1 = 0;
int cu2 = 0;
// int j = 0, k = 0;

#define code_0 33480735
#define code_1 33444015
#define code_2 33478695
#define code_3 33486855
#define code_4 33435855
#define code_5 33468495
#define code_6 33452175
#define code_8 33484815
#define code_9 33462375
#define code_vol_ 33464415
#define code_vol_plus 33448095
#define code_rpt 33427695
#define code_sd 33460335
volatile int f1 = 0;
volatile int f2 = 0;
volatile int f3 = 0;
volatile int f4 = 0;
volatile int f5 = 0;
volatile int f6 = 0;
// an IR detector/demodulator is connected to GPIO pin 2
uint16_t RECV_PIN = 2;//GPIO2 == D4

IRrecv irrecv(RECV_PIN);

decode_results results;
int array[]={0,0,0,0,0,0};

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();  // Start the receiver
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(16, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
}
void loop() {
  if (irrecv.decode(&results)) {
    serialPrintUint64(results.value, DEC);
    Serial.println("results.value");
    // Blynk.run();

    if(results.value == code_8)
    {
      if(array[0] == 1)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      Serial.println("light 1 off ");
      array[0] = 0;
      Blynk.virtualWrite(V0, array[0]);
      }
      else
      {
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("light 1 on ");
      array[0] = 1;
      Blynk.virtualWrite(V0, array[0]);
      }
    }
    if(results.value == code_9)
    {
      if(array[1] == 1)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      Serial.println("light 2 off ");
      array[1] = 0;
      Blynk.virtualWrite(V1, array[1]);
      }
      else
      {
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      Serial.println("light 2 on ");
      array[1] = 1;
      Blynk.virtualWrite(V1, array[1]);
      }
    }
    if(results.value == code_0)
    {
      if(array[2] == 1)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      Serial.println("light 3 off ");
      array[2] = 0;
      Blynk.virtualWrite(V2, array[2]);
      }
      else
      {
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("light 3 on ");
      array[2] = 1;
      Blynk.virtualWrite(V2, array[2]);
      }
    }

    if(results.value == code_1)
    {
      if(f1 == 0)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      Serial.println("  FAN_1_MEDIUM ");
      f1++;
      Blynk.virtualWrite(V4, f1);
      }
      else if(f1 == 1)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_1_FAST ");
      f1++;
      Blynk.virtualWrite(V4, f1);
      }
      else if(f1 == 2)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      Serial.println("  FAN_1_STOP ");
      f1 = 0;
      Blynk.virtualWrite(V4, f1);
      }
    }
    
    if(results.value == code_2)
    {
      if(f2 == 0)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_2_MEDIUM ");
      f2++;
      Blynk.virtualWrite(V5, f2);
      }
      else if(f2 == 1)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      Serial.println("  FAN_2_FAST ");
      f2++;
      Blynk.virtualWrite(V5, f2);
      }
      else if(f2 == 2)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_2_STOP ");
      f2 = 0;
      Blynk.virtualWrite(V5, f2);
      }
    }
    if(results.value == code_3)
    {
      if(f3 == 0)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      Serial.println("  FAN_3_MEDIUM");
      f3++;
      Blynk.virtualWrite(V6, f3);
      }
      else if(f3 == 1)
      {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_3_FAST ");
      f3++;
      Blynk.virtualWrite(V6, f3);
      }
      else if(f3 == 2)
      {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      Serial.println("  FAN_3_STOP ");
      f3 = 0;
      Blynk.virtualWrite(V6, f3);
      }
    }
    if(results.value == code_4)
    {
      if(f4 == 0)
      {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_4_MEDIUM");
      f4++;
      Blynk.virtualWrite(V7, f4);
      }
      else if(f4 == 1)
      {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      Serial.println("  FAN_4_FAST ");
      f4++;
      Blynk.virtualWrite(V7, f4);
      }
      else if(f4 == 2)
      {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_4_SLOW ");
      f4 = 0;
      Blynk.virtualWrite(V7, f4);
      }
    }
    if(results.value == code_5)
    {
      if(f5 == 0)
      {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      Serial.println("  FAN_5_MEDIUM");
      f5++;
      Blynk.virtualWrite(V8, f5);
      }
      else if(f5 == 1)
      {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_5_FAST ");
      f5++;
      Blynk.virtualWrite(V8, f5);
      }
      else if(f5 == 2)
      {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      Serial.println("  FAN_5_SLOW ");
      f5 = 0;
      Blynk.virtualWrite(V8, f5);
      }
    }
    if(results.value == code_6)
    {
      if(f6 == 0)
      {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_6_MEDIUM");
      f6++;
      Blynk.virtualWrite(V9, f6);
      }
      else if(f6 == 1)
      {
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      Serial.println("  FAN_6_FAST ");
      f6++;
      Blynk.virtualWrite(V9, f6);
      }
      else if(f6 == 2)
      {
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_6_STOP ");
      f6 = 0;
      Blynk.virtualWrite(V9, f6);
      }
    }
  
    if(results.value == code_vol_)
    {
      if(cu1 == 1)
      {
        digitalWrite(12, HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);
        cu1 = 0;
        Blynk.virtualWrite(V3, cu1);
        Serial.println("  curatin closing ");
      }
      else if( cu1 == 0)
      {
        digitalWrite(12, HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        cu1 = 1;
        Blynk.virtualWrite(V3, cu1);
        Serial.println("  curatin opening ");
      }
    }
    
    // if(results.value == code_vol_plus)
    // {
    //   if(array[4] == 1)
    //   {
    //   digitalWrite(12, HIGH);
    //   digitalWrite(13, HIGH);
    //   digitalWrite(14, HIGH);
    //   digitalWrite(15, LOW);
    //   digitalWrite(16, LOW);
    //   array[4] = 0;
    //   Serial.println("  curatin 3,4 closing ");
    //   }
    //   else
    //   {
    //   digitalWrite(12, HIGH);
    //   digitalWrite(13, HIGH);
    //   digitalWrite(14, HIGH);
    //   digitalWrite(15, LOW);
    //   digitalWrite(16, HIGH);
    //   array[4] = 1;
    //   Serial.println("  curatin 3,4 opening ");
    //   }
    // }     
  }
    irrecv.resume();  // Receive the next value
  
  delay(200);
  Blynk.run();

}

BLYNK_WRITE(V0)
{
  lightval = param.asInt();
  if(lightval == 1)
  {
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  Serial.println("LIGHT 1 ON");
  }
  else if(lightval == 0)
  {
  digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
  Serial.println("LIGHT 1 OFF"); 
  }
}

BLYNK_WRITE(V1)
{
lightval2 = param.asInt();
  if(lightval2 == 1)
  {
  digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
  Serial.println("LIGHT 2 ON");
  }
  else if(lightval == 0)
  {
  digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
  Serial.println("LIGHT 2 OFF"); 
  }
}

BLYNK_WRITE(V2)
{
lightval3 = param.asInt();
  if(lightval3 == 1)
  {
  digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
  Serial.println("LIGHT 3 ON");
  }
  else if(lightval == 0)
  {
  digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
  Serial.println("LIGHT 3 OFF"); 
  }
}

BLYNK_WRITE(V3)
{
curt = param.asInt();
if(curt == 1)
  {
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("curtain on");
    }
  
  else if(curt == 0)
  {
        digitalWrite(12, HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);
        Serial.println("curtain off "); 
}
}

BLYNK_WRITE(V4) {
  sliderValue = param.asInt();
  if(sliderValue == 1)
  {
    Serial.println("FAN1MEDIUM");
    digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);

  }
  else if(sliderValue == 2)
  {
    Serial.println("FAN1FAST");
    digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);

  }
  else if(sliderValue == 0)
  {
    Serial.println("FAN1STOP");
    digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
  }

}

BLYNK_WRITE(V5) {
  sliderValue2 = param.asInt();
  if(sliderValue2 == 1)
  {
  digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_2_MEDIUM ");

  }
  else if(sliderValue2 == 2)
  {
  digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      Serial.println("  FAN_2_FAST ");
  }
  else if(sliderValue2 == 0)
  {
  digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_2_STOP ");
  }

}

BLYNK_WRITE(V6) {
  sliderValue3 = param.asInt();
  if(sliderValue3 == 1)
  {
  digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      Serial.println("  FAN_3_MEDIUM ");
  }
  else if(sliderValue3 == 2)
  {
  digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_3_FAST ");
  }
  else if(sliderValue3 == 0)
  {
  digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      Serial.println("  FAN_3_STOP ");
  }
}

BLYNK_WRITE(V7) {
  sliderValue4 = param.asInt();
  if(sliderValue4 == 1)
  {
  digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_4_MEDIUM ");
  }
  else if(sliderValue4 == 2)
  {
  digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      Serial.println("  FAN_4_FAST ");
  }
  else if(sliderValue4 == 0)
  {
  digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_4_STOP ");
  }
}

BLYNK_WRITE(V8) {
  sliderValue5 = param.asInt();
  if(sliderValue5 == 1)
  {
    digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      Serial.println("  FAN_5_MEDIUM ");
  }
  else if(sliderValue5 == 2)
  {
  digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_5_FAST ");
  }
  else if(sliderValue5 == 0)
  {
  digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      Serial.println("  FAN_5_STOP ");
  }
}

BLYNK_WRITE(V9) {
  sliderValue6 = param.asInt();
  if(sliderValue6 == 1)
  {
  digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_6_MEDIUM ");  
  }
  else if(sliderValue6 == 2)
  {
  digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
      Serial.println("  FAN_6_FAST ");
  }
  else if(sliderValue6 == 0)
  {
  digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      Serial.println("  FAN_6_STOP ");
  }
}

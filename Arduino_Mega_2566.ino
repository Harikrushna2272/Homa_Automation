#include <IRremote.h>
#include <RBDdimmer.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MQ135.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(14,15,16,17,18,19);
LiquidCrystal_I2C lcd2(0x26, 16, 2);
MQ135 gasSensor(A0);
const int IR_PIN = 52;
const int ANALOG_PIN = A1;
const float K = 0.55;
#define RECV_PIN 3
#define IN1 24
#define IN2 25
#define IN3 26
#define IN4 27
#define IN5 28
#define IN6 29
#define motor_p1 34
#define motor_n1 35
#define motor_p2 36
#define motor_n2 37
#define motor_p3 38
#define motor_n3 39
#define motor_p4 40
#define motor_n4 41
#define limit_11 44
#define limit_12 45
#define limit_21 46
#define limit_22 47
#define limit_31 48
#define limit_32 49
#define limit_41 50
#define limit_42 51
#define outputPin 8
#define outputPin2 9
#define outputPin3 10
#define outputPin4 11
#define outputPin5 12
#define outputPin6 13
#define zerocross 2

int itsONIN[] = {0,0,0};

#define code_1 16753245
#define code_2 16736925
#define code_3 16769565
#define code_4 16720605
#define code_5 16712445
#define code_6 16761405
#define code_7 16769055
#define code_8 16754775
#define code_9 16748655
#define code_1_up 16718055
#define code_1_down 16730805
#define code_2_up 16734885
#define code_2_down 16716015

IRrecv irrecv(RECV_PIN);
decode_results results;

dimmerLamp dimmer(outputPin);
dimmerLamp dimmer2(outputPin2);
dimmerLamp dimmer3(outputPin3);
dimmerLamp dimmer4(outputPin4);
dimmerLamp dimmer5(outputPin5);
dimmerLamp dimmer6(outputPin6);
int outVal = 39;
int preVal = 39;
int outVal2 = 39;
int preVal2 = 39;
int outVal3 = 39;
int preVal3 = 39;
int outVal4 = 39;
int preVal4 = 39;
int outVal5 = 39;
int preVal5 = 39;
int outVal6 = 39;
int preVal6 = 39;

void setup() {
Serial.begin(9600);
irrecv.enableIRIn();
// lcd.begin(16,2);
// pinMode(IR_PIN, OUTPUT);
// digitalWrite(IR_PIN, HIGH);

// dimmer.begin(NORMAL_MODE, OFF);
// dimmer2.begin(NORMAL_MODE, OFF);
// dimmer3.begin(NORMAL_MODE, OFF);
// dimmer4.begin(NORMAL_MODE, OFF);
// dimmer5.begin(NORMAL_MODE, OFF);
// dimmer6.begin(NORMAL_MODE, OFF);
pinMode(outputPin, OUTPUT);
pinMode(outputPin2, OUTPUT);
pinMode(outputPin3, OUTPUT);
pinMode(outputPin4, OUTPUT);
pinMode(outputPin5, OUTPUT);
pinMode(outputPin6, OUTPUT);
// pinMode(zerocross, INPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(IN5, OUTPUT);
pinMode(IN6, OUTPUT); 
pinMode(motor_p1, OUTPUT);
pinMode(motor_n1, OUTPUT);
pinMode(motor_p2, OUTPUT);
pinMode(motor_n2, OUTPUT);
pinMode(motor_p3, OUTPUT);
pinMode(motor_n3, OUTPUT);
pinMode(motor_p4, OUTPUT);
pinMode(motor_n4, OUTPUT);
pinMode(limit_11, INPUT_PULLUP);
pinMode(limit_12, INPUT_PULLUP);
pinMode(limit_21, INPUT_PULLUP);
pinMode(limit_22, INPUT_PULLUP);
pinMode(limit_31, INPUT_PULLUP);
pinMode(limit_32, INPUT_PULLUP);
pinMode(limit_41, INPUT_PULLUP);
pinMode(limit_42, INPUT_PULLUP);

// digitalWrite(IN1, LOW);
// digitalWrite(IN2, LOW);
// digitalWrite(IN3, LOW);
// digitalWrite(IN4, LOW);
// digitalWrite(IN5, LOW);
// digitalWrite(IN6, LOW);

}

void loop() {


if(digitalRead(limit_11) == LOW  )
{
  while(digitalRead(limit_11) == LOW) {
    digitalWrite(motor_p1, LOW);    
    digitalWrite(motor_n1, HIGH);
  }
digitalWrite(motor_p1, LOW);
digitalWrite(motor_n1, LOW);
}

if(digitalRead(limit_21) == LOW  )
{
  while(digitalRead(limit_21) == LOW) {
    digitalWrite(motor_p2, LOW);    
    digitalWrite(motor_n2, HIGH);
  }
digitalWrite(motor_p2, LOW);
digitalWrite(motor_n2, LOW);
}

if(digitalRead(limit_31) == LOW  )
{
  while(digitalRead(limit_31) == LOW) {
    digitalWrite(motor_p3, LOW);    
    digitalWrite(motor_n3, HIGH);
  }
digitalWrite(motor_p3, LOW);
digitalWrite(motor_n3, LOW);
}

if(digitalRead(limit_41) == LOW  )
{
  while(digitalRead(limit_41) == LOW) {
    digitalWrite(motor_p4, LOW);    
    digitalWrite(motor_n4, HIGH);
  }
digitalWrite(motor_p4, LOW);
digitalWrite(motor_n4, LOW);
}


if(digitalRead(limit_12) == LOW  )
{
  while(digitalRead(limit_12) == LOW) {
    digitalWrite(motor_p1, HIGH);    
    digitalWrite(motor_n1, LOW);
  }
digitalWrite(motor_p1, LOW);
digitalWrite(motor_n1, LOW);
}

if(digitalRead(limit_22) == LOW  )
{
  while(digitalRead(limit_22) == LOW) {
    digitalWrite(motor_p2, HIGH);    
    digitalWrite(motor_n2, LOW);
  }
digitalWrite(motor_p2, LOW);
digitalWrite(motor_n2, LOW);
}

if(digitalRead(limit_32) == LOW  )
{
  while(digitalRead(limit_32) == LOW) {
    digitalWrite(motor_p3, HIGH);    
    digitalWrite(motor_n3, LOW);
  }
digitalWrite(motor_p3, LOW);
digitalWrite(motor_n3, LOW);
}

if(digitalRead(limit_42) == LOW  )
{
  while(digitalRead(limit_42) == LOW) {
    digitalWrite(motor_p4, HIGH);    
    digitalWrite(motor_n4, LOW);
  }
digitalWrite(motor_p4, LOW);
digitalWrite(motor_n4, LOW);
}

preVal = outVal;
preVal2 = outVal2;
preVal3 = outVal3;
preVal4 = outVal4;
preVal5 = outVal5;
preVal6 = outVal6;

    

if(irrecv.decode(&results)){
  Serial.println(results.value);

        if(results.value == code_1)
        {
          if(itsONIN[1] == 1)  
          {
            digitalWrite(IN1, LOW);
            // digitalWrite(IN2, LOW);
            itsONIN[1] = 0;
          }
          else
          {
            digitalWrite(IN1, HIGH);
            // digitalWrite(IN2, HIGH);
            itsONIN[1] = 1;
          }  
        } 

        if(results.value == code_2)
        {
          
          if(itsONIN[2] == 1)  
          {
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);
            itsONIN[2] = 0;
          }
          else
          {
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, HIGH);
            itsONIN[2] = 1;
          }   
        }

        if(results.value == code_3)
        {
          if(itsONIN[3] == 1)  
          {
            digitalWrite(IN5, LOW);
            digitalWrite(IN6, LOW);
            itsONIN[3] = 0;
          }
          else
          {
            digitalWrite(IN5, HIGH);
            digitalWrite(IN6, HIGH);
            itsONIN[3] = 1;
          }   
        }


if(results.value == code_4)
{
  if(outVal <= 72)
  {
   dimmer.begin(NORMAL_MODE, ON);
   outVal = outVal+10;

   if(outVal >= 73)
   {
    dimmer.begin(NORMAL_MODE, OFF);
    outVal = 39;
   }
  }
}
    
if(results.value == code_5)
{
  if(outVal2 <= 72)
  {
   dimmer2.begin(NORMAL_MODE, ON);
   outVal2 = outVal2 + 10;
   if(outVal2 >= 73)
   {
    dimmer2.begin(NORMAL_MODE, OFF);
    outVal2 = 39;
   }
  }
}

if(results.value == code_6)
{
  if(outVal3 <= 72)
  {
   dimmer3.begin(NORMAL_MODE, ON);
   outVal3 = outVal3 + 10;
   if(outVal3 >= 73)
   {
    dimmer3.begin(NORMAL_MODE, OFF);
    outVal3 = 39;
   }
  }
}

if(results.value == code_7)
{
  if(outVal4 <= 72)
  {
   dimmer4.begin(NORMAL_MODE, ON);
   outVal4 = outVal4 + 10;

   if(outVal4 >= 73)
   {
    dimmer4.begin(NORMAL_MODE, OFF);
    outVal4 = 39;
   }
  }
}
    
if(results.value == code_8)
{
  if(outVal5 <= 72)
  {
   dimmer5.begin(NORMAL_MODE, ON);
   outVal5 = outVal5 + 10;
   if(outVal5 >= 73)
   {
    dimmer5.begin(NORMAL_MODE, OFF);
    outVal5 = 39;
   }
  }
}

if(results.value == code_9)
{
  if(outVal6 <= 72)
  {
   dimmer6.begin(NORMAL_MODE, ON);
   outVal6 = outVal6 + 10;
   if(outVal6 >= 73)
   {
    dimmer6.begin(NORMAL_MODE, OFF);
    outVal6 = 39;
   }
  }
}
if (preVal != outVal) {
       dimmer.setPower(outVal); 
      }
      if (preVal2 != outVal2) {
       dimmer2.setPower(outVal2);
      }
      if (preVal3 != outVal3) {
       dimmer3.setPower(outVal3);
      }
      if (preVal4 != outVal4) {
       dimmer4.setPower(outVal4); 
      }
      if (preVal5 != outVal5) {
       dimmer5.setPower(outVal5);
      }
      if (preVal6 != outVal6) {
       dimmer6.setPower(outVal6);
      }
*/
if (results.value == code_1_up)
       {
       digitalWrite(motor_p1, HIGH);    
       digitalWrite(motor_n1, LOW); 
       digitalWrite(motor_p2, HIGH);    
       digitalWrite(motor_n2, LOW);   
       }
    if (results.value == code_1_down) 
       {
       digitalWrite(motor_p1, LOW);    
       digitalWrite(motor_n1, HIGH);
       digitalWrite(motor_p2, LOW);    
       digitalWrite(motor_n2, HIGH);
       } 
    if (results.value == code_2_up)
       {
       digitalWrite(motor_p3, HIGH);    
       digitalWrite(motor_n3, LOW); 
       digitalWrite(motor_p4, HIGH);    
       digitalWrite(motor_n4, LOW);   
       }
    if (results.value == code_2_down) 
       {
       digitalWrite(motor_p3, LOW);    
       digitalWrite(motor_n3, HIGH);
       digitalWrite(motor_p4, LOW);    
       digitalWrite(motor_n4, HIGH);
       }


      


           
irrecv.resume();     
}

float co2 = gasSensor.getPPM(); 
lcd.setCursor(0, 0); 
lcd.print("CO2 GAS: "); 
lcd.print(co2); 

digitalWrite(IR_PIN, LOW);
delayMicroseconds(320);
int analogValue = analogRead(ANALOG_PIN);
digitalWrite(IR_PIN, HIGH);
float voltage = analogValue * 5.0 / 1024.0;
float concentration = K * (voltage - 0.1);
float pm25 = concentration * 0.5;
float pm10 = concentration * (1/0.5);
lcd2.setCursor(0,0);
lcd2.print("PM2.5: ");
lcd2.print(pm25);
lcd2.print(" ug/m3");
lcd2.setCursor(0,1);
lcd2.print("PM10: ");
lcd2.print(pm10);
lcd2.print(" ug/m3");
delay(200);
*/
}

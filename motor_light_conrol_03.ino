#include <IRremote.h>

#define RECV_PIN 3
#define IN1 22
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

int itsONIN[] = {0,0,0};
//int itsONin[] = {0,0,0,0};//may be for motor driver
//int itsONmotor[] = {0,0,0};//may be for motor
 //the initial state is off(zero)
//1st remain 0 but we can chage other

#define code_1 16753245
#define code_2 16736925
#define code_3 16769565
#define code_4 16720605
#define code_5 16712445
#define code_6 16761405
#define code_7 16769055
#define code_8 16754775
#define code_1_up 16718055
#define code_1_down 16730805
#define code_2_up 16734885
#define code_2_down 16716015


IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
irrecv.enableIRIn();//start IR receiver

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

digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
digitalWrite(IN5, LOW);
digitalWrite(IN6, LOW);

}

void loop() {

//for motor 1
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
  
if(irrecv.decode(&results)){
//  int value = results.value;
  Serial.println(results.value);
//for 3 lights
        if(results.value == code_1)
        {
          if(itsONIN[1] == 1)  
          {
            digitalWrite(IN1, LOW);
            digitalWrite(IN1, LOW);
            itsONIN[1] = 0;
          }
          else
          {
            digitalWrite(IN1, HIGH);
            digitalWrite(IN1, HIGH);
            itsONIN[1] = 1;
          }  
        } 

        if(results.value == code_2)
        {
          if(itsONIN[2] == 1)  
          {
            digitalWrite(IN2, LOW);
            digitalWrite(IN1, LOW);
            itsONIN[2] = 0;
          }
          else
          {
            digitalWrite(IN2, HIGH);
            digitalWrite(IN1, HIGH);
            itsONIN[2] = 1;
          }   
        }

        if(results.value == code_3)
        {
          if(itsONIN[3] == 1)  
          {
            digitalWrite(IN3, LOW);
            digitalWrite(IN1, LOW);
            itsONIN[3] = 0;
          }
          else
          {
            digitalWrite(IN3, HIGH);
            digitalWrite(IN1, HIGH);
            itsONIN[3] = 1;
          }   
        }

// for the curtains
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
        

    if (results.value == code_1_up)
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
         
     Serial.println(results.value);
     //(IR.decodedIRData.decodedRawData, HEX);   
     irrecv.resume();
     
 }

}

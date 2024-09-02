#include <RBDdimmer.h>
#include <MQ135.h>

#define ana_a4 A4 //(window 1/ limit 2)
#define ana_a5 A5 //(window 1/ limit 1)
#define ana_a6 A6 //(window 2/ limit 2)
#define ana_a7 A7 //(window 2/ limit 1)
#define ana_a8 A8 //(window 3/ limit 2)
#define ana_a9 A9//(window 3/ limit 1)
#define ana_a10 A10//(window 4/ limit 1)L
#define ana_a11 A11//(window 4/ limit 2)F

#define IN1 22
// #define IN2 23
#define IN3 24
// #define IN4 25
#define IN5 26
// #define IN6 27
#define motor_p1 28
#define motor_n1 29
#define motor_p2 30
#define motor_n2 31
#define motor_p3 32
#define motor_n3 33
#define motor_p4 34
#define motor_n4 35
#define outputPin 8
#define outputPin2 9
#define outputPin3 10
#define outputPin4 11
#define outputPin5 12
#define outputPin6 13
#define zerocross 2
#define fan_controlling_1 44
#define fan_controlling_2 45
#define fan_controlling_3 46
#define fan_controlling_4 47
#define fan_controlling_5 48

// #define code_1 16753245
// #define code_2 16736925
// #define code_3 16769565
// #define code_4 16720605
// #define code_5 16712445
// #define code_6 16761405
// #define code_7 16769055
// #define code_8 16754775
// #define code_9 16748655
// #define code_1_up 16718055
// IRrecv irrecv(RECV_PIN);
// decode_results results;

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

int window1 = 0;
int window2 = 0;

void setup() {
Serial.begin(9600);
// lcd.begin(16,2);
// lcd2.begin(16,2);
// pinMode(IR_PIN, OUTPUT);
// digitalWrite(IR_PIN, HIGH);

dimmer.begin(NORMAL_MODE, OFF);
dimmer2.begin(NORMAL_MODE, OFF);
dimmer3.begin(NORMAL_MODE, OFF);
dimmer4.begin(NORMAL_MODE, OFF);
dimmer5.begin(NORMAL_MODE, OFF);
dimmer6.begin(NORMAL_MODE, OFF);

pinMode(outputPin, OUTPUT);
pinMode(outputPin2, OUTPUT);
pinMode(outputPin3, OUTPUT);
pinMode(outputPin4, OUTPUT);
pinMode(outputPin5, OUTPUT);
pinMode(outputPin6, OUTPUT);
pinMode(zerocross, INPUT);

pinMode(IN1, OUTPUT);
// pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
// pinMode(IN4, OUTPUT);
pinMode(IN5, OUTPUT);
// pinMode(IN6, OUTPUT); 
pinMode(motor_p1, OUTPUT);
pinMode(motor_n1, OUTPUT);
pinMode(motor_p2, OUTPUT);
pinMode(motor_n2, OUTPUT);
pinMode(motor_p3, OUTPUT);
pinMode(motor_n3, OUTPUT);
pinMode(motor_p4, OUTPUT);
pinMode(motor_n4, OUTPUT);
pinMode(ana_a4, INPUT);
pinMode(ana_a5, INPUT);
pinMode(ana_a6, INPUT);
pinMode(ana_a7, INPUT);
pinMode(ana_a8, INPUT);
pinMode(ana_a9, INPUT);
pinMode(ana_a10, INPUT);
pinMode(ana_a11, INPUT);
pinMode(fan_controlling_1, INPUT);
pinMode(fan_controlling_2, INPUT);
pinMode(fan_controlling_3, INPUT);
pinMode(fan_controlling_4, INPUT);
pinMode(fan_controlling_5, INPUT);

digitalWrite(IN1, LOW);
// digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
// digitalWrite(IN4, LOW);
digitalWrite(IN5, LOW);
// digitalWrite(IN6, LOW);
}

void loop() {

int a = digitalRead(44);
int b = digitalRead(45);
int c = digitalRead(46);
int d = digitalRead(47);
int e = digitalRead(48);
int f = analogRead(ana_a4);//L2
int g = analogRead(ana_a5);//L1
int h = analogRead(ana_a6);//L2
int i = analogRead(ana_a7);//L1
int j = analogRead(ana_a8);//L2
int k = analogRead(ana_a9);//L1
int l = analogRead(ana_a10);//L1
int m = analogRead(ana_a11);//L2

// Serial.println();
// Serial.println(g);
// Serial.println(h);
// Serial.println(i);
// Serial.println(j);

if( f <= 800 )
{
  
  for(int anna1 = 400 ; anna1 < 600 ; anna1++ ) {
    
    digitalWrite(motor_p1, LOW);    
    digitalWrite(motor_n1, HIGH);
    // Serial.println("ok");
  }
digitalWrite(motor_p1, LOW);
// Serial.println("down");
digitalWrite(motor_n1, LOW); 

}

if( g <= 800  )
{
  
  for(int anna2 = 400 ; anna2 < 600 ; anna2++) {
    digitalWrite(motor_p1, HIGH);    
    digitalWrite(motor_n1, LOW);
    Serial.println("ok_2");
  }
digitalWrite(motor_p1, LOW);
digitalWrite(motor_n1, LOW);
  }


if( h <= 800  )
{
  for( int anna3 = 400 ; anna3 < 600 ; anna3++) {
    digitalWrite(motor_p2, LOW);    
    digitalWrite(motor_n2, HIGH);
  }
digitalWrite(motor_p2, LOW);
digitalWrite(motor_n2, LOW);  
}

if( i <= 800  )
{
  for( int anna4 = 400 ; anna4 < 600 ; anna4++) {
    digitalWrite(motor_p2, HIGH);    
    digitalWrite(motor_n2, LOW);
      }
digitalWrite(motor_p2, LOW);
digitalWrite(motor_n2, LOW);
}

if( j <= 800  )
{
  for( int anna5 = 400 ; anna5 < 600 ; anna5++) {
    digitalWrite(motor_p3, LOW);    
    digitalWrite(motor_n3, HIGH);
  }
digitalWrite(motor_p3, LOW);
digitalWrite(motor_n3, LOW);
}
if( k <= 800  )
{
  for( int anna6 = 400 ; anna6 < 600 ; anna6++) {
    digitalWrite(motor_p3, HIGH);    
    digitalWrite(motor_n3, LOW);
  }
digitalWrite(motor_p3, LOW);
digitalWrite(motor_n3, LOW);
}

if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1) 
       {
          if( window1 == 0)
      {
        for(int window2 = 1 ; window2 > 0 ; window2-- )
        {
      //  Serial.println(window2);
      // lcd.setCursor(0,1);
      // lcd.print("CURTAIN OPENING");
       digitalWrite(motor_p1, HIGH);    
       digitalWrite(motor_n1, LOW); 
       digitalWrite(motor_p2, HIGH);    
       digitalWrite(motor_n2, LOW);
       digitalWrite(motor_p3, HIGH);    
       digitalWrite(motor_n3, LOW); 
      //  digitalWrite(motor_p4, HIGH);    
      //  digitalWrite(motor_n4, LOW);   
       Serial.println("curtain 1,2 opening");
       Serial.println("curtain 3,4 opening");
       window2 = 1;
       window1 = 1;
      //  Serial.print(window2);
      }
      }
      }


    else if (a == 1 && b == 1 && c == 0 && d == 1 && e == 0)
       {
        //  window1 = 1;
        //  window2 = 0;
         
        if( window1 == 1)
        {
        
        Serial.println("secondphase");
        for(int window2 = 1 ; window2 > 0 ; window2-- )
        {
      //  lcd.setCursor(0,1);
      //  lcd.print("CURTAIN CLOSING");
       digitalWrite(motor_p1, LOW);    
       digitalWrite(motor_n1, HIGH);
       digitalWrite(motor_p2, LOW);    
       digitalWrite(motor_n2, HIGH);
       Serial.println("curtain 1,2 closign");
       digitalWrite(motor_p3, LOW);    
       digitalWrite(motor_n3, HIGH);
      //  digitalWrite(motor_p4, LOW);    
      //  digitalWrite(motor_n4, HIGH);
       Serial.println("curtain 3,4 closing");
      
       window2 = 1;   
       window1 = 0;
      //  Serial.println(window);
       }
      }
      }

preVal = outVal;
preVal2 = outVal2;
preVal3 = outVal3;
preVal4 = outVal4;
preVal5 = outVal5;
preVal6 = outVal6;

        if(a == 0 && b == 0 && c == 0 && d == 1 && e == 0)
        {
          digitalWrite(IN1, LOW);
          // digitalWrite(IN2, LOW);
          Serial.println(" light 1 off");
        }  
        else if(a == 0 && b == 0 && c == 0 && d == 1 && e == 1)
        {
          digitalWrite(IN1, HIGH);
          // digitalWrite(IN2, HIGH);
          Serial.println(" light 1 on");
        }  
         
        if(a == 0 && b == 0 && c == 1 && d == 0 && e == 0)  
        {
          digitalWrite(IN3, LOW);
          // digitalWrite(IN4, LOW);
          Serial.println(" light 2 off ");
        }
        else if(a == 0 && b == 0 && c == 1 && d == 0 && e == 1)
        {
        digitalWrite(IN3, HIGH);
        // digitalWrite(IN4, HIGH);
        Serial.println("light 2 on ");
        }   
        
        if(a == 0 && b == 0 && c == 1 && d == 1 && e == 0)  
        {
          digitalWrite(IN5, LOW);
          // digitalWrite(IN6, LOW);
          Serial.println("light 3 off ");
        }
        else if(a == 0 && b == 0 && c == 1 && d == 1 && e == 1)
        {
        digitalWrite(IN5, HIGH);
        // digitalWrite(IN6, HIGH);
        Serial.println("light 3 on ");
        }

  
if(a == 0 && b == 1 && c == 0 && d == 0 && e == 0)
{
  dimmer.begin(NORMAL_MODE, ON);
  // Serial.println("fan_1_medium");
  // digitalWrite(outputPin, HIGH);
  outVal = 70 ;
}

if(a == 0 && b == 1 && c == 0 && d == 0 && e == 1)
{
  dimmer.begin(NORMAL_MODE, ON);
  // Serial.println("fan_1_fast");
  outVal = 90;
}

if(a == 0 && b == 1 && c == 0 && d == 1 && e == 0)
{
  dimmer.begin(NORMAL_MODE, OFF);
  // Serial.println("fan_1_stop");
  // digitalWrite(outputPin, LOW);
}

if(a == 0 && b == 1 && c == 0 && d == 1 && e == 1)
{
  dimmer2.begin(NORMAL_MODE, ON);
  // Serial.println("fan_2_medium");
  outVal2 = 70;
  // digitalWrite(outputPin2, HIGH);
}

if(a == 0 && b == 1 && c == 1 && d == 0 && e == 0)
{
  dimmer2.begin(NORMAL_MODE, ON);
  // Serial.println("fan_2_fast");
  outVal2 = 90;
}

if(a == 0 && b == 1 && c == 1 && d == 0 && e == 1)
{
  dimmer2.begin(NORMAL_MODE, OFF);
  // Serial.println("fan_2_stop");
  // digitalWrite(outputPin2, LOW);
}

if(a == 0 && b == 1 && c == 1 && d == 1 && e == 0)
{
  dimmer3.begin(NORMAL_MODE, ON);
  // Serial.println("fan_3_medium");
  outVal3 = 70;
  // digitalWrite(outputPin3, HIGH);
}

if(a == 0 && b == 1 && c == 1 && d == 1 && e == 1)
{
  dimmer3.begin(NORMAL_MODE, ON);
  // Serial.println("fan_3_fast");
  outVal3 = 90;
}

if(a == 1 && b == 0 && c == 0 && d == 0 && e == 0)
{
  dimmer3.begin(NORMAL_MODE, OFF);
  // Serial.println("fan_3_stop");
  // digitalWrite(outputPin3, LOW);
}

if(a == 1 && b == 0 && c == 0 && d == 0 && e == 1)
{
  dimmer4.begin(NORMAL_MODE, ON);
  // Serial.println("fan_4_medium");
  // digitalWrite(outputPin4, HIGH);
  outVal4 = 70;
}

if(a == 1 && b == 0 && c == 0 && d == 1 && e == 0)
{
  dimmer4.begin(NORMAL_MODE, ON);
  // Serial.println("fan_4_fast");
  outVal4 = 90;
}

if(a == 1 && b == 0 && c == 0 && d == 1 && e == 1)
{
  dimmer4.begin(NORMAL_MODE, OFF);
  // digitalWrite(outputPin4, LOW);
  // Serial.println("fan_4_stop");
}

if(a == 1 && b == 0 && c == 1 && d == 0 && e == 0)
{
  dimmer5.begin(NORMAL_MODE, ON);
  // Serial.println("fan_5_medium");
  // digitalWrite(outputPin5, HIGH);
  outVal5 = 70;
}

if(a == 1 && b == 0 && c == 1 && d == 0 && e == 1)
{
  dimmer5.begin(NORMAL_MODE, ON);
  // Serial.println("fan_5_fast");
  outVal5 = 90;
}

if(a == 1 && b == 0 && c == 1 && d == 1 && e == 0)
{
  dimmer5.begin(NORMAL_MODE, OFF);
  // Serial.println("fan_5_stop");
  // digitalWrite(outputPin5, LOW);
}

if(a == 1 && b == 0 && c == 1 && d == 1 && e == 1)
{
  dimmer6.begin(NORMAL_MODE, ON);
  // Serial.println("fan_6_medium");
  // digitalWrite(outputPin6, HIGH);
  outVal6 = 70;
}

if(a == 1 && b == 1 && c == 0 && d == 0 && e == 0)
{
  dimmer6.begin(NORMAL_MODE, ON);
  // Serial.println("fan_6_fast");
  outVal6 = 90;
}

if(a == 1 && b == 1 && c == 0 && d == 0 && e == 1)
{
  dimmer6.begin(NORMAL_MODE, OFF);
  // Serial.println("fan_6_stop");
  // digitalWrite(outputPin6, LOW);
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
           
}

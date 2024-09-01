#include <IRremote.h>
#include <TimerOne.h>
#include <TimerThree.h>
#include <avr/io.h>
#include <avr/interrupt.h>
////FRI 1ST TIMER 42 TO 132  AND FOR 2ND TIMER 100 TO 300
int receiver = 2;    
IRrecv irrecv(receiver);           
decode_results results;            
           
volatile int i=0;               // Variable to use as a counter
volatile int i2=0;
volatile boolean zero_cross=0;  // Boolean to store a "switch" to tell us if we have crossed zero
int AC_pin_1 = 7;                 // Output to triac
int AC_pin_2 = 44;

//int dim4 = 0;
//int dim3 = 128;
int dim2 = 25;                   // led control
int dim = 20;                  // Dimming level (42 - 132)  42 = on, 132 = 0ff                  
int freqStep = 500;    // This is the delay-per-brightness step in microseconds.

//    TIMER FUNCTION

void setup() {   
  irrecv.enableIRIn(); // Start the IR receiver (classic remote)
  pinMode(AC_pin_1, OUTPUT);// Set the SSD pin as output
  pinMode(AC_pin_2, OUTPUT);
//  noInterrupts();
  
  attachInterrupt(1, zero_cross_detect, RISING);    // Attach an Interupt to Pin 2 (interupt 0) for Zero Cross Detection
  pinMode(3, INPUT);                          // Set the SSR pin as output
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
// sei();
  

//TIMER 1
//  Timer1.initialize(freqStep);    // Initialize TimerOne library for the freq we need
//  Timer1.attachInterrupt(FAN_1_CHECK, freqStep);  


////TIMER 0 
//  TCCR0A = 0;           
//  TCCR0B = 0;            
//  TCNT0  = 0;            
//  OCR0A = ;           
//  TCCR0B |= (1 << WGM01); 
//  TCCR0B |= (1 << CS02) | (1 << CS01);
//  TIMSK0 |= (1 << OCIE0A);


////TIMER 2
//  TCCR2A = 0;            // set entire TCCR2A register to 0
//  TCCR2B = 0;            // same for TCCR2B
//  TCNT2  = 0;            // initialize counter value to 0//  OCR2A = 75;           // set compare match register for 75 HZ
//  TCCR2B |= (1 << WGM21); // turn on CTC mode
//  TCCR2B |= (1 << CS22) | (1 << CS21);//set prescaler to 256
//  TIMSK2 |= (1 << OCIE2A);

//  Timer3.initialize(400);
//  Timer3.attachInterrupt(FAN_3_CHECK, 400);

//TIMER 4
TCCR4A = 0;           
TCCR4B = 0; // some time it is optional.           
TCNT4  = 0;            
OCR4A = 8000 ;         //  (F_CPU / 64) * interruptInterval / 1000000  = = 18.75;   and for 256 it will 4.68,    and for pre 1 that will be 1200.
TCCR4A |= (1 << WGM41); 
TCCR4B |= (1 << CS40);// priscale is  
//TCCR4B |= (1 << CS41) | (1 << CS40); // 64 priscale
TIMSK4 |= (1 << OCIE4A);


//TIMER 5
  TCCR5A = 0;           
  TCCR5B = 0;            
  TCNT5  = 0;            
  OCR5A = 8000;
  TCCR5B |= (1 << WGM51);
  TCCR5B |= (1 << CS50);
  TIMSK5 |= (1 << OCIE5A);
  
//TIMER 3 
//  TCCR3A = 0;           
//  TCCR3B = 0;            
//  TCNT3  = 0;            
//  OCR3A = 75;           
//  TCCR3B |= (1 << WGM31); 
//  TCCR3B |= (1 << CS32) | (1 << CS31);
//  TIMSK3 |= (1 << OCIE3A);
  
interrupts(); // enable all interrupts 
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
 
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
}

void zero_cross_detect() 
{    
  zero_cross = true;               // set the boolean to true to tell our dimming function that a zero cross has occured
  i=0;
  i2 =0;
//  Serial.println("now i is equal to zero");
  digitalWrite(AC_pin_1, LOW);
  digitalWrite(AC_pin_2, LOW);
}                                 
// Turn on the TRIAC at the appropriate time
/*
void FAN_1_CHECK() 
{                   
  if(zero_cross == true) 
  {              
    if(i>=dim) 
    {                     
      digitalWrite(AC_pin_1, HIGH);  // turn on light       
      i=0;  // reset time step counternter                         
      zero_cross=false;    // reset zero cross detection
    } 
    else 
    {
      i++;  // increment time step counter                     
    }
  }
  
  
}

Pins 4 and 13: controlled by Timer0
Pins 11 and 12: controlled by Timer1
Pins 9 and10: controlled by Timer2
Pin 2, 3 and 5: controlled by timer 3
Pin 6, 7 and 8: controlled by timer 4
Pin 46, 45 and 44:: controlled by timer 5
 
                                      

void FAN_3_CHECK() 
{                   
  if(zero_cross == true) 
  {              
    if(i2>=dim2) 
    {                     
      digitalWrite(AC_pin_2, HIGH);  // turn on light       
      i2=0;  // reset time step counternter                         
      zero_cross=false;    // reset zero cross detection
    } 
    else 
    {
      i2++;  // increment time step counter                     
    }
  }
}                                      



void dim_check_2() 
{                   
  if(zero_cross == true) 
  {              
    if(i2>=dim) 
    {                     
      digitalWrite(AC_pin_1, HIGH);  // turn on light       
      i2=0;  // reset time step counter                         
      zero_cross=false;    // reset zero cross detection
    } 
    else 
    {
      i2++;  // increment time step counter                     
    }
  }
}                                      
*/

void translateIR() // takes action based on IR code received
{

//  switch(results.value)
//  {
//  case 16753245:  
//    {   
    if (results.value == 16753245) 
    {
      digitalWrite(4, HIGH);
//delay(100);
//digitalWrite(4, LOW);
      dim= dim - 5; // in vechiul sketch era 127
 
       if(dim<=6)
    {
     digitalWrite(4, LOW);
//delay(100);
//digitalWrite(4, LOW);
      dim =23;
    }
    }
//    break;
//}

      if (results.value == 16736925) 
    {
      digitalWrite(5, HIGH);
//delay(100);
//digitalWrite(4, LOW);
      dim2 = dim2 - 5; // in vechiul sketch era 127
 
       if(dim2 <= 6)
    {
     digitalWrite(5, LOW);
//delay(100);
//digitalWrite(4, LOW);
      dim2 =23;
    }
    }

}
  
  /*
  switch(results.value)
  {
  case 16736925:  
    {
      if (dim2>6) 
    {
      digitalWrite(4, HIGH);
delay(200);
digitalWrite(4, LOW);
      dim2= dim2 - 5; // in vechiul sketch era 127
    }
    if(dim2 <= 6)
    {
      digitalWrite(4, HIGH);
delay(200);
digitalWrite(4, LOW);
      dim2 = 23;
    }
    
    }
    break;
  }

//if(1)
//{
//  
//}

   switch(results.value)
   {
  case 16769565:  
    {
      dim=16;  // in vechiul sketch era 1  
//          Serial.println("3st code");         
//          digitalWrite(4, HIGH);
//          delay(200);
//          digitalWrite(4, LOW);
//                
}
    break;

  case 16720605:  
    {
      dim=11;  // in vechiul sketch era 1  
          Serial.println("4st code");
digitalWrite(4, HIGH);
delay(200);
digitalWrite(4, LOW);
    }
    break;

  case 16712445:
    {
      dim=07;  // in vechiul sketch era 1  
      Serial.println("5st code");      
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(4, LOW);
    }
    break;

  case 16761405:
    {
      dim=0;  // in vechiul sketch era 1  
      Serial.println("5st code");      
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(4, LOW);
    }
    break;

  case 16769055:
    {
      dim=18;  // in vechiul sketch era 1  
      Serial.println("5st code");      
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(4, LOW);
    }
    break;

  case 16754775:
    {
      dim=27;  // in vechiul sketch era 1  
      Serial.println("5st code");      
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(4, LOW);
    }
    break;

  case 16748655:
    {
      dim=36;  // in vechiul sketch era 1  
      Serial.println("5st code");      
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(4, LOW);
    }
    break;

  case 16750695:
    {
      dim=45;  // in vechiul sketch era 1  
      Serial.println("5st code");      
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(4, LOW);
    }
    break;

  }

}
*/

  
void loop() 
{  
 if (irrecv.decode(&results)) // have we received an IR signal?
  {
    Serial.println(results.value);

    
    translateIR();
    irrecv.resume(); // receive the next value
    digitalWrite(4, LOW);
   }  
}


ISR(TIMER4_COMPA_vect) {
 
 if(zero_cross == true) 
  {
    if(i>=dim) 
    {                     
      digitalWrite(AC_pin_1, HIGH);  // turn on light       
      i=0;  // reset time step counter                         
      zero_cross=false;    // reset zero cross detection
//    Serial.println("done");
    } 
    else 
    {
//    Serial.println("not done");
      i = i + 1;  // increment time step counter                     
    
    }
  }

}

ISR(TIMER5_COMPA_vect) {
 
 if(zero_cross == true) 
  {
    if(i>=dim2) 
    {                     
      digitalWrite(AC_pin_2, HIGH);  // turn on light       
      i2=0;  // reset time step counter                         
      zero_cross=false;    // reset zero cross detection
//    Serial.println("done");
    } 
    else 
    {
//    Serial.println("not done");
      i2 = i2 + 1;  // increment time step counter                     
    
    }
  }

}

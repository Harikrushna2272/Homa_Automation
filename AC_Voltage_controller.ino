#include <RBDdimmer.h>

#define outputPin 12
#define outputPin2 11
#define outputPin3 10
#define zerocross 2

dimmerLamp dimmer(outputPin);
dimmerLamp dimmer2(outputPin2);
dimmerLamp dimmer3(outputPin3);
int outVal = 39;
int preVal = 39;
int outVal2 = 39;
int preVal2 = 39;
int outVal3 = 39;
int preVal3 = 39;


void setup() {
  // irrecv.enableIRIn(); // Start IR receiver
  dimmer.begin(NORMAL_MODE, OFF);
  dimmer.setState(OFF);
  dimmer2.begin(NORMAL_MODE, OFF);
  dimmer.setState(OFF);
  dimmer3.begin(NORMAL_MODE, OFF);
  dimmer.setState(OFF);
  pinMode(outputPin, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);
  pinMode(zerocross, INPUT);
  Serial.begin(9600);
}

void loop() {
  int a  = digitalRead(zerocross);
  Serial.println(a);
  preVal = outVal;
  preVal2 = outVal2;
  preVal3 = outVal3;
if (irrecv.decode(&results)) {
      unsigned long irCode = results.value;
      Serial.println();

      
if(results.value == 16753245)
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
    
if(results.value == 16736925)
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

   
if(results.value == 16769565)
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
      
      if (preVal != outVal) {
       dimmer.setPower(outVal); // Set the lamp intensity
      }
      if (preVal2 != outVal2) {
       dimmer2.setPower(outVal2);
      }
      if (preVal3 != outVal3) {
       dimmer3.setPower(outVal3);
      }
      
//    delay(50);    
    irrecv.resume(); // Receive the next IR code
}
  

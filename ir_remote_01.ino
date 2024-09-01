#include <IRremote.h>

int RECV_PIN = 26;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
irrecv.enableIRIn();//start IR receiver

}

void loop() {
  // put your main code here, to run repeatedly:
 if(irrecv.decode(&results))
 {
//  unsigned int value = results.value;
 Serial.println(results.value);
 delay(200);
 irrecv.resume();

 }
}

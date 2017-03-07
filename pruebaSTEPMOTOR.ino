
#include <Stepper.h>
Stepper horizontal (50,8,9,10,11); // horizontal step motor
//horizontal.setSpeed(30);

void setup() {

 horizontal.setSpeed(200);
   Serial.begin(9600);
}

void loop() {
  
  horizontal.step(300);
  //delay(1000);
  horizontal.step(-300);
 // delay(1000);

}

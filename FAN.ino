#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


IRrecv irReceiver(2);
decode_results results;

#include <L293D.h>
L293D motor(6,5,4);


void setup() {

  irReceiver.enableIRIn(); 
  Serial.begin(9600);
}


void loop() {

  if (irReceiver.decode(&results)) {
    // le code infrarouge est dans la variable results.value
    irReceiver.resume();


  if (results.value == 16753245) {
  motor.set(200);
  }  
    
  Serial.println(results.value);

   if (results.value == 16738455) {
   motor.set(0);  
      }

  }
}

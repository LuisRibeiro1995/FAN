# FAN

Afficheur heure, date, température, humidité 

Ce projet à été réalisé par [@siham](https://github.com/siham87) et [@wildcat](https://github.com/wildcat7534)

## Video :
[![video](https://img.youtube.com/vi/Jj8H_8Ze6cs/0.jpg)](https://www.youtube.com/watch?v=Jj8H_8Ze6cs)


## **Bibliothéque utilisée**
+ Moteur : [arduino-L293D](https://github.com/tylersweat/arduino-L293D)
+ Recepeteur : [Arduino-IRremote](https://github.com/z3t0/Arduino-IRremote)

## **Matériel**
+ Arduino
+ Moteur à courant continu
+ Recepteur infrarouge (TL1838)
+ Pale de ventilateur
+ Telecommande

## **Montage**

![schema : ](.jpg)

## **Code**

```
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
```

![photo: ](.jpg)

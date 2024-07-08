#include <Arduino.h>
#include "util.h"


Util *util;
bool pinOn = false;

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  util = new Util();
  pinMode(2,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(pinOn){
    digitalWrite(2,LOW);
    pinOn = false;
  }else{
    digitalWrite(2,HIGH);
    pinOn = true;
  }
		Serial.println("helmet");
		String  mystr = "Easy Tiger";

			int key = util->getKey(mystr);
			Serial.println(key);
    
    delay(10000);

  
}


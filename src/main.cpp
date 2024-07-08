#include <Arduino.h>
#include "util.h"
#include <WiFi.h>
#include "volumioRest.h"


//Provide your own WiFi credentials
const char* ssid = "RoodRouter";
const char* password = "";
//String for storing server response
String response = "";



Util *util;
VolumioRest *volRest;
bool pinOn = false;

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  util = new Util();
  volRest = new VolumioRest();
  pinMode(2,OUTPUT);
  //Initiate WiFi connection
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
///////////// WiFi setup /////////////////

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
  ////////////////////test get volumio rest stuff ////////
  String ret = volRest->get("http://crankit.local/api/v1/getState");
  Serial.println(ret);
  ////////////////////////////////////////////
  /*  Testing title number
		Serial.println("helmet");
		String  mystr = "Easy Tiger";

			int key = util->getKey(mystr);
			Serial.println(key);
  */  
    delay(10000);

  
}


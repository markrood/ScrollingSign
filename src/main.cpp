#include <Arduino.h>
#include "util.h"
#include <WiFi.h>
#include "volumioRest.h"
#include "sign.h"

#include "ESPAsyncWebServer.h"
#include "ESPAsyncWiFiManager.h"         //https://gitWiFiManagerhub.com/tzapu/WiFiManager
//#include <WiFiManager.h>
//#include <WebSerial.h>
#include <ESPmDNS.h>

AsyncWebServer server(80);
DNSServer dns;
void configModeCallback (AsyncWiFiManager *myWiFiManager);

///String for storing server response
String response = "";



Util *util;
VolumioRest *volRest;
Sign *sign;
bool pinOn = false;
String oldRet = "";

bool start = true;
int now = 0;
int startTime = 0;
String ret = "";
String finalStr = "";
int len = 0;
int dur = 0;

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  util = new Util();
  volRest = new VolumioRest();
  sign = new Sign();
  pinMode(2,OUTPUT);
  //Initiate WiFi connection


    ///////////////////Start WiFi ///////////////////////////////////////
  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  AsyncWiFiManager wifiManager(&server, &dns);
  //reset settings - for testing
  //wifiManager.resetSettings();
  //wifiManager.setSTAStaticIPConfig(IPAddress(192,168,1,175), IPAddress(192,168,1,1), IPAddress(255,255,255,0), IPAddress(192,168,1,1), IPAddress(192,168,1,1));
  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wifiManager.setAPCallback(configModeCallback);

  //fetches ssid and pass and tries to connect
  //if it does not connect it starts an access point with the specified name
  //here  "AutoConnectAP"
  //and goes into a blocking loop awaiting configuration
  if (!wifiManager.autoConnect("Wapp_Sign")) {
    Serial.println("failed to connect and hit timeout");
    Serial.println("restarting esp");
    //reset and try again, or maybe put it to deep sleep
    ESP.restart();
    delay(1000);
  }
  delay(50);
  //Serial.print("FreeHeap is :");
  //Serial.println(ESP.getFreeHeap());
  delay(50);
  //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)");

  Serial.println("local ip");
  Serial.println(WiFi.localIP());

  server.begin();



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
        if(start){
            startTime = millis();
            ret = volRest->get("http://crankit.local/api/v1/getState");
            if(ret.equals("")){
              ret = oldRet;
            }
            start = false;
        }else{

            if(millis() - startTime >= dur){
              ret = volRest->get("http://crankit.local/api/v1/getState");
            if(ret.equals("")){
              ret = oldRet;
            }
               start = true;
            }


        }
    
  
  //Serial.println(ret);
  if(ret != oldRet){
    oldRet = ret;
    int dur = volRest->getDuration(); //don't want to call until songs
    dur = dur*1000;
    ////////////////////////////////////////////
    //  Testing title number
      //Serial.print(ret);
      //String  mystr = "After the Gold Rush (Live from Calgary, AL. 2023)";

        int key = util->getKey(ret);
        String name = util->buildDisplayString(key);
        //String keyStr = String(key);

        //Serial.print(",");
        Serial.println(key);
        //ret.concat(name);
        finalStr = ret+" : "+name;
        len = finalStr.length();
        len = len*6;
        len = len*-1;
        String lenStr = String (len);
        Serial.println(lenStr);
        Serial.println(finalStr);
  }       
  sign->display(finalStr,len);

    delay(100);

//sign->display("Howdy",36);
  
  
}

/////////////////////////////////////////////////////////////
void configModeCallback (AsyncWiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  //myWiFiManager->startConfigPortal("ATOAWC");addDailyDoseAmt
  //myWiFiManager->autoConnect("DOSER");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());

}
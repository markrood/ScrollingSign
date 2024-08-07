#ifndef VOLREST_H_
#define VOLREST_H_

#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>



class VolumioRest{
    public:
        VolumioRest(); 
        String get(String str);
        int getDuration();


    private:
        HTTPClient http;
        //JSON document
        StaticJsonDocument<2048> doc;
        //String for storing server response
        String response = "";
        int duration = 0;
};

#endif
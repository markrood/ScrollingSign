#include "volumioRest.h"
#include <HTTPClient.h>
#include <iostream>

VolumioRest::VolumioRest(){

}

String VolumioRest::get(String request){
      //The API URL
  //String request;
  //Start the request
  http.begin(request);
  //Use HTTP GET request
  http.GET();
  //Response from server
  response = http.getString();
    //Parse JSON, read error if any
  DeserializationError error = deserializeJson(doc, response);
// Test if parsing succeeds.
  if (error) {
    std::cerr << "deserializeJson() failed: " << error.c_str() << std::endl;
    return "";
  }  
  const char* value = doc["title"];
  //Print parsed value on Serial Monitor
  // Print values.
  Serial.println(value);
  http.end();
    return value;

}


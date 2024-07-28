#ifndef FBDB_H_
#define FBDB_H_

#include <Arduino.h>
#include <FirebaseESP32.h>


//Provide the token generation process info.
#include <addons/TokenHelper.h>

//Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID "RoodRouter"
#define WIFI_PASSWORD ""

//For the following credentials, see examples/Authentications/SignInAsUser/EmailPassword/EmailPassword.ino

/* 2. Define the API Key */
#define API_KEY "AIzaSyA9Tb-xbeCJzh9pAVq64kFP_mcwA4sbp-g"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://esp32-firebase-example-852b0-default-rtdb.firebaseio.com/" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "mmkkrood@aol.com"
#define USER_PASSWORD "Skippy"


/* This database secret required in this example to get the righs access to database rules */
#define DATABASE_SECRET "DATABASE_SECRET"
class Fbdb{
    private:
        //Define Firebase Data object
        FirebaseData fbdo;

        FirebaseAuth auth;
        FirebaseConfig config;


        bool taskCompleted = false;
        const char* folks[16] = {"MarkDane", "MarkMckay", "MarkJeff", "CaseyKyle", "DaneJeffMckay", "DaneJeff", "JeffKyle", "Casey", "Chris", "Dane", "Eric", "Jeff", "Kyle", "Mark", "McKay", "Nat"};
        int currentLen = 0;
        QueryFilter query;
    private:
        void getKeys();
};
#endif
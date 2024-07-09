#ifndef SIGN_H_
#define SIGN_H_

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 6

 static Adafruit_NeoMatrix matrixx = Adafruit_NeoMatrix(5, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);


const uint16_t colors[] = {
     matrixx.Color(255, 0, 0), matrixx.Color(0, 255, 0), matrixx.Color(0, 0, 255) }; 


class Sign{
    public:
        Sign();
        void display(String str);

    private:
};

#endif
#ifndef SIGN_H_
#define SIGN_H_

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 5

 static Adafruit_NeoMatrix matrixx = Adafruit_NeoMatrix(55, 10, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);




const uint16_t colors[] = {
     matrixx.Color(14, 123, 247), matrixx.Color(242, 19, 78), matrixx.Color(255, 255, 255) }; 


class Sign{
    public:
        Sign();
        void display(String str, int length);

    private:
      int xxxx = 0;
        int piss = 0;
};

#endif
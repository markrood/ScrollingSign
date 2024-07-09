#include "sign.h"
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>




Sign::Sign(){

}

void Sign::display(String str){
int x    = matrixx.width();
int pass = 0;

    matrixx.setCursor(x, 0);
    //matrixx.print(F("Howdy"));
    matrixx.print(str);
    if(--x < -36) {
        x = matrixx.width();
        if(++pass >= 3) pass = 0;
        matrixx.setTextColor(colors[pass]);
    }
  matrixx.show();
}


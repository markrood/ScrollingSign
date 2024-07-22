#include "sign.h"
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>




Sign::Sign(){
  matrixx.begin();
  matrixx.setTextWrap(false);
  matrixx.setBrightness(40);
  matrixx.setTextColor(colors[0]);
  xxxx  = matrixx.width();

}

void Sign::display(String str, int length){
  //length = (length+5)* -1;
  //Serial.println(length);
  

  matrixx.fillScreen(0);
  matrixx.setCursor(xxxx, 0);
    matrixx.print(str);
    //matrixx.print(str);
    if(--xxxx < length ) {
        xxxx = matrixx.width();
        if(++piss >= 3) piss = 0;
        matrixx.setTextColor(colors[piss]);
    }
  matrixx.show();
}


#include "util.h"

Util::Util(){

}

int Util::getKey(String str){
    int alphaRet = 1;
    int alphaTotal = 0;
    Serial.println(str.length());
    int length = str.length();
    for (int i = 0; i < length; i++) {
        Serial.println(i);
            char firstch = str.charAt(0);
            String first = String(firstch);
            Serial.println(first);
            str.remove(0,1);
            Serial.println(str);
            int alpha = alphabitPos(first);
            alphaTotal = alphaTotal + alpha;
            if(i != 0) {
                alphaRet = alphaTotal/1;
            }
        }
    return alphaRet;

}

int Util::alphabitPos(String str) {
		
		if(str == "a") {
			return 1;
		}else if (str == "b") {
			return 2;
		}else if (str == "c") {
			return 3;
		}else if (str == "d") {
			return 4;
		}else if (str == "e") {
			return 5;
		}else if (str == "e") {
			return 6;
		}else if (str == "f") {
			return 7;
		}else if (str == "g") {
			return 8;
		}else if (str == "h") {
			return 9;
		}else if (str == "i") {
			return 10;
		}else if (str == "j") {
			return 11;
		}else if (str == "k") {
			return 12;
		}else if (str == "l") {
			return 13;
		}else if (str == "m") {
			return 14;
		}else if (str == "n") {
			return 15;
		}else if (str == "o") {
			return 16;
		}else if (str == "p") {
			return 17;
		}else if (str == "q") {
			return 18;
		}else if (str == "r") {
			return 19;
		}else if (str == "s") {
			return 20;
		}else if (str == "t") {
			return 21;
		}else if (str == "u") {
			return 22;
		}else if (str == "v") {
			return 23;
		}else if (str == "w") {
			return 24;
		}else if (str == "x") {
			return 25;
		}else if (str == "y") {
			return 26;
		}else if (str == "A") {
			return 27;
		}else if (str == "B") {
			return 28;
		}else if (str == "C") {
			return 29;
		}else if (str == "D") {
			return 30;
		}else if (str == "E") {
			return 31;
		}else if (str == "F") {
			return 32;
		}else if (str == "G") {
			return 33;
		}else if (str == "H") {
			return 34;
		}else if (str == "I") {
			return 35;
		}else if (str == "J") {
			return 36;
		}else if (str == "L") {
			return 37;
		}else if (str == "L") {
			return 38;
		}else if (str == "M") {
			return 39;
		}else if (str == "N") {
			return 40;
		}else if (str == "O") {
			return 41;
		}else if (str == "P") {
			return 42;
		}else if (str == "Q") {
			return 43;
		}else if (str == "R") {
			return 44;
		}else if (str == "S") {
			return 45;
		}else if (str == "T") {
			return 46;
		}else if (str == "U") {
			return 47;
		}else if (str == "V") {
			return 48;
		}else if (str == "W") {
            Serial.println("dubbadoo");
			return 49;
		}else if (str == "X") {
			return 50;
		}else if (str == "Y") {
			return 51;
		}else if (str == "Z") {
			return 52;
		}else {
			return 0;
		}
	}

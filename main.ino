#include <EncButton.h>

Button btn(4);

const int str1 = 13; 
const int str2 = 12; 
const int str3 = 11; 
const int str4 = 10; 

unsigned long previousMillis = 0;
const long interval = 500; 

bool toggleState = false;

bool strobe = 0;
bool pow = 0;

void setup() {
  pinMode(str1, OUTPUT); 
  pinMode(str2, OUTPUT); 
  pinMode(str3, OUTPUT); 
  pinMode(str4, OUTPUT); 
}

void loop() {
  btn.tick();

  unsigned long currentMillis = millis();

  if (btn.hold(3)) strobe = !strobe;
  if (btn.hasClicks(2)) pow = !pow;

  
  if (strobe == 1 && (currentMillis - previousMillis >= interval)) {
        previousMillis = currentMillis;

        toggleState = !toggleState;

        if (toggleState) {
            digitalWrite(str1, HIGH);
            digitalWrite(str3, HIGH);
            digitalWrite(str2, LOW);
            digitalWrite(str4, LOW);
        } else {
            digitalWrite(str1, LOW);
            digitalWrite(str3, LOW);
            digitalWrite(str2, HIGH);
            digitalWrite(str4, HIGH);
        }
    }

  if (pow) {
        digitalWrite(str1, HIGH);
        digitalWrite(str2, HIGH);
        digitalWrite(str3, HIGH);
        digitalWrite(str4, HIGH);
    } else if (!strobe) {  // Если мигание выключено – гасим светодиоды
        digitalWrite(str1, LOW);
        digitalWrite(str2, LOW);
        digitalWrite(str3, LOW);
        digitalWrite(str4, LOW);
    }

}

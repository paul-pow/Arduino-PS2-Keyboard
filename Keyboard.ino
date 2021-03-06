#include "PS2Keyboard.h"

const int DataPin = 3;
const int IRQpin =  2;


PS2Keyboard keyboard;

void setup() {
  delay(1000);
  keyboard.begin(DataPin, IRQpin, PS2Keymap_German);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");
  pinMode (13, OUTPUT);
  pinMode (41, OUTPUT);
}

void loop() {
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == PS2_ENTER) {
      Serial.println();
    } else if (c == PS2_TAB) {
      Serial.print("[Tab]");
      digitalWrite(13, HIGH);
    } else if (c == PS2_ESC) {
      Serial.print("[ESC]");
      digitalWrite(13, LOW);
    } else if (c == PS2_PAGEDOWN) {
      Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      Serial.print("[Left]");
    } else if (c == PS2_RIGHTARROW) {
      Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      Serial.print("[Down]");
    } else if (c == PS2_DELETE) {
      Serial.print("[Del]"); 
    }else {
            // otherwise, just print all normal characters
      Serial.print(c);
    }
    char x = 1;
    if ( c == x)
    {
      Serial.println("Das l wurde gedrückt mit x");
    }
    
    
    Serial.println(strcmp(c, "1")); 
    
    if (strcmp (c,"1") == 1)
    {
      Serial.println("Das l wurde gedrückt");
     }
  
  }

}

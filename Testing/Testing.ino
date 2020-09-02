#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 10 chars and 4 line display

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'D', '0', 'E', 'F'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  lcd.init();                      // initialize the lcd 
  lcd.backlight();                //Turn on Back light
  Serial.begin(9600);
}
  
void loop(){
  lcd.setCursor(0,0);
  char hex = 0;
  hex = customKeypad.getKey();
  
  if(hex == '1'){
    lcd.clear();
    lcd.print(hex);
    Serial.println(hex);
    Serial.write(hex);
    Serial.println();
    //hex = 0;
    delay(500);
    hex= customKeypad.getKey();
    
    if(hex != 0x31){
        lcd.clear();
        lcd.print('A');
        Serial.println('A');
     //   hex = 0;
        delay(500);
        hex= customKeypad.getKey();
      }

      if(hex == '1'){
        lcd.clear();
        lcd.print('B');
        Serial.println('B');
      //  hex = 0;
        delay(500);
        hex= customKeypad.getKey();
      }

      if(hex == '1'){
        lcd.clear();
        lcd.print('C');
        Serial.println('C');
     //   hex = 0;
        delay(500);
        hex= customKeypad.getKey();
      }
  }
      
}

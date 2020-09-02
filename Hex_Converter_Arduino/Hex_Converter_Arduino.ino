#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 10 chars and 4 line display

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {1, 2, 3, 10},
  {4, 5, 6, 11},
  {7, 8, 9, 12},
  {0xF, 0, 14, 13}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();                //Turn on Back light
}
  
void loop(){
  lcd.clear();
  int i, j;
  lcd.setCursor(0,0);
  char num[4];
  
  for(i=3; i >=0;){
    num[i] = customKeypad.getKey();
    if (num[i]){
      lcd.print(num[i--], HEX);
    }
  }
      
  lcd.setCursor(0,1);
  for(j = 3; j >= 0; j--){
      for (i = 3; i >= 0;  i--)
        lcd.print(bitRead(num[j], i));   
          
      lcd.print(" ");
        
  }
  
  delay(5000);
}

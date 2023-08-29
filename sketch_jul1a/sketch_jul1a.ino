#include <Wire.h> 
#include <LCD_I2C.h>
#include "chars1.h"

// https://github.com/blackhack/LCD_I2C
// https://github.com/blackhack/LCD_I2C/blob/master/examples/Hello_World/Hello_World.ino
LCD_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.begin();                     
  lcd.backlight();

  // load my symbols defined
  lcd.createChar(1, b1);
  lcd.createChar(2, b2);
  lcd.createChar(3, b3);
  lcd.createChar(4, b4);
  lcd.createChar(5, b5);
  lcd.createChar(6, b6);
  lcd.createChar(7, b7);
  lcd.createChar(8, b8);
}

int ch = 1;
void loop()
{
  lcd.setCursor(0, 0);
  lcd.write(ch);
  delay(700);
  ch++;
  if (ch > 8) ch=1; 
}
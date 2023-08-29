#include <Wire.h> 
#include <LCD_I2C.h>

// https://github.com/blackhack/LCD_I2C
// https://github.com/blackhack/LCD_I2C/blob/master/examples/Hello_World/Hello_World.ino
LCD_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.begin();                     
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("line1");

  lcd.setCursor(0, 1);
  lcd.print("line2");

  lcd.setCursor(0, 2);
  lcd.print("line3");

  lcd.setCursor(0, 3);
  lcd.print("line4");

}

void loop() {
  //Autoscroll
  lcd.setCursor(5, 0);
  lcd.print(F("Autoscrolling"));
  lcd.setCursor(10, 1);
  lcd.autoscroll();

  for (int i = 0; i < 10; i++)
  {
      lcd.print(i);
      delay(200);
  }

  lcd.noAutoscroll();
  lcd.clear();

  // Scroll left and right
  lcd.setCursor(10, 0);
  lcd.print(F("To the left!"));
  for (int i = 0; i < 10; i++)
  {
      lcd.scrollDisplayLeft();
      delay(200);
  }
  lcd.clear();
  lcd.print(F("To the right!"));
  for (int i = 0; i < 10; i++)
  {
      lcd.scrollDisplayRight();
      delay(200);
  }
  lcd.clear();

  //Cursor
  lcd.setCursor(0, 0);
  lcd.cursor();
  lcd.print(F("Cursor"));
  delay(3000);
  lcd.clear();

  //Cursor blink
  lcd.setCursor(0, 0);
  lcd.blink();
  lcd.print(F("Cursor blink"));
  delay(3000);
  lcd.clear();

  //Blink without cursor
  lcd.setCursor(0, 0);
  lcd.noCursor();
  lcd.print(F("Just blink"));
  delay(3000);
  lcd.noBlink();
  lcd.clear();
}
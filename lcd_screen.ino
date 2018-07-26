#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
/*
 * rs: the number of the Arduino pin that is connected to the RS pin on the LCD
 * en: the number of the Arduino pin that is connected to the enable pin on the LCD
 * d0, d1, d2, d3, d4, d5, d6, d7: the numbers of the Arduino pins that are connected 
 *  to the corresponding data pins on the LCD. d0, d1, d2, and d3 are optional; if omitted, 
 *  the LCD will be controlled using only the four data lines (d4, d5, d6, d7).
*/
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(8, 1);
    lcd.print("Hello world!");
}

void loop() {
    lcd.scrollDisplayRight();
    delay(700);
}
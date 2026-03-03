#include <LiquidCrystal.h>

// pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);      // Initialize LCD
  lcd.print("HELLO!");   // Show on 1st line
  lcd.setCursor(0, 1);   // Move to 2nd line
  lcd.print("ARDUINO LCD");
}

void loop() {
  // nothing to update continuously
}

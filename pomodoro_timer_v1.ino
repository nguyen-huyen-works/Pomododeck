#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long lastTick = 0;
int remaining = 10; // just 10 seconds demo

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Countdown:");
}

void loop() {
  unsigned long now = millis(); // It returns the number of milliseconds since your board was powered on or reset.
  // Hey arduino, check the stowatch time right now and save it to now! 

  // Check if 1 second passed
  if (now - lastTick >= 1000) {
    lastTick = now;       // remember this time
    if (remaining > 0) {
      remaining--;        // subtract 1 second
      lcd.setCursor(0,1);
      lcd.print("Time: ");
      lcd.print(remaining);
      lcd.print("   ");   // spaces to clear old digits
    }
  }
}

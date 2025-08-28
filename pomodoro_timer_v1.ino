#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // tell Arduino which pins connect to LCD

unsigned long lastTick = 0;  // saves the last time we updated the countdown
int remaining = 10;          // countdown starts at 10 seconds

void setup() {
  lcd.begin(16, 2);          // initialize LCD as 16x2
  lcd.setCursor(0,0);        // position at first row, first column
  lcd.print("Countdown:");   // print title
}

void loop() {
  unsigned long now = millis();  
  // millis() = built-in stopwatch (time since Arduino turned on)

  // check if 1 second passed since last update
  if (now - lastTick >= 1000) {
    lastTick = now;   // reset "stopwatch" to this moment
    
    if (remaining > 0) {
      remaining--;    // subtract 1 second
      lcd.setCursor(0,1);  // move to 2nd row
      lcd.print("Time: ");
      lcd.print(remaining);
      lcd.print("   ");    // clears old numbers (like 10 -> 9)
    }
  }
}


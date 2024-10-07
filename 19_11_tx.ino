#include <string.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int switchPin = 2; // Switch connected to pin 2
int ledPin = 3;    // LED connected to pin 3

void setup() {
  pinMode(switchPin, INPUT_PULLUP); // Internal pull-up resistor for the switch
  pinMode(ledPin, OUTPUT);
  lcd.begin(20, 4);
  Serial.begin(9600);
}

void loop() {
  int switchState = digitalRead(switchPin);

  if (switchState == LOW) {
    // Switch is pressed, turn on the LED
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Switch Pressed");
    digitalWrite(ledPin, HIGH);
  } else {
    // Switch is released, turn off the LED
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Switch Released");
    digitalWrite(ledPin, LOW);
  }

  delay(100); // Add a short delay to avoid reading the switch state too quickly
}

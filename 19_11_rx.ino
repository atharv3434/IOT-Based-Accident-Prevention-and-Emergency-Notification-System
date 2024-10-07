#include <string.h>
#include <LiquidCrystal.h>
#include <TinyGPS.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
TinyGPS gps;

int ledPin = 5; // LED control
int switchPin = 2; // Replace with the pin connected to the switch
int switchPin1 = 3; 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP); // Internal pull-up resistor for the switch
  pinMode(switchPin1, INPUT_PULLUP);
  lcd.begin(20, 4);
  Serial.begin(9600);
}

void loop() {
  String readString;
  String Q;

  // Check Serial Port
  while (Serial.available()) {
    delay(1);
    if (Serial.available() > 0) {
      char c = Serial.read();
      if (isControl(c)) {
        break;
      }
      readString += c;
    }
  }

  Q = readString;

  int switchState = digitalRead(switchPin);
  int switchState1 = digitalRead(switchPin1);
  if (switchState == LOW ) {
    // Switch is pressed, show location
    lcd.clear();
    lcd.setCursor(0, 3);
    lcd.print("location send");
    showLocation();
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    // Switch is released, turn off LED
    lcd.clear();
    lcd.setCursor(0, 3);
    lcd.print("               ");
    digitalWrite(ledPin, LOW); // Turn off the LED
  }

  if (switchState1== 1 ) {
    // Switch is pressed, show location
   // lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("denger go slow");
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    // Switch is released, turn off LED
  //  lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("               ");
    digitalWrite(ledPin, LOW); // Turn off the LED
  }
  delay(100); // Add a short delay to avoid reading the switch state too quickly
}

void showLocation() {
  // Your GPS code to fetch and display location
  float lat, lon;
  // Assuming getGPSData() returns the latitude and longitude
  getGPSData(lat, lon);

  lcd.setCursor(0, 1);
  lcd.print("Latitude: ");
  lcd.print(lat, 6);
  lcd.setCursor(0, 2);
  lcd.print("Longitude: ");
  lcd.print(lon, 6);
}

void getGPSData(float &lat, float &lon) {
  // Your GPS data fetching logic here
  // Example: Using dummy values for latitude and longitude
  lat = 37.7749;
  lon = -122.4194;
  // while (Serial.available() > 0) {
  //   if (gps.encode(Serial.read())) {
  //     gps.f_get_position(&lat, &lon);
  //     return true;
  //   }
  // }
  // return false;
}

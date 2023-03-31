#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C addres is 0x27, 16 rijen en 2 lagen

Servo myservo;  // stel de servo in

int pos = 0;    // maak een variabele voor de positie en zet de waarde op 0

void setup() {
  myservo.attach(9);  // geef aan dat de arduino zich op pin 0 bevind
  Serial.begin(9600);
  lcd.init(); // stel het lcd-scherm in
  lcd.backlight();
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // ga van 0 naar 180 graden in stappen van 1 graden
    Serial.print("Dit is de actuele positie: ");
    Serial.println(pos);
   
  lcd.clear();                  // haal de tekst van het lcd-scherm weg
  lcd.setCursor(0, 0);          // zet de lcd-cursor linksboven
  lcd.print("Huidige positie: ");        // verander de tekst op het lcd-scherm
  lcd.setCursor(0, 1);          // zet de lcd-cursor 1 vakje verder
  lcd.print(pos); // laat de actuele positie weten
    myservo.write(pos);              // laat de servo naar de waarde van de variabele pos gaan
    delay(240000);                       // Dit is dus 240 seconden en daarmee 4 minuten. Elke 4 min +1 x 180 = 720 minuten = 12 uur
    
  }
  for (pos = 180; pos >= 0; pos -= 1) { // gaat van 180 naar 0 graden
    myservo.write(pos);              // laat de servo naar de waarde van de variabele pos gaan
    delay(15);                       // wacht 15 ms om de servo de tijd te geven om te draaien
  }
}

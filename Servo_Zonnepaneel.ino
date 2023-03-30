#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  lcd.init(); // initialize the lcd
  lcd.backlight();
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Serial.print("Dit is de actuele positie: ");
    Serial.println(pos);
   
  lcd.clear();                  // clear display
  lcd.setCursor(0, 0);          // move cursor to   (0, 0)
  lcd.print("Huidige positie: ");        // print message at (3, 0)
  lcd.setCursor(0, 1);          // move cursor to   (0, 1)
  lcd.print(pos); // print message at (0, 1)
  //delay(2000);                  // display the above for two seconds
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(240000);                       // Dit is dus 240 seconden en daarmee 4 minuten. Elke 4 min +1 x 180 = 720 minuten = 12 uur
    
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo myservo;
int val;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  myservo.attach(9);
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initialisierung...");

  delay(2000);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  val = analogRead(5);
  val = map(val, 0, 1023, 180, 0);

  Serial.println(val);
  myservo.write(val);
  delay(50);
}

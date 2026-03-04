#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>

  LiquidCrystal_I2C  lcd(0x27,16,2);
  DHT dht(13,DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("temp:");
  lcd.setCursor(0,1);
  lcd.print("hum:");
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)){
    lcd.setCursor(6,0);
    lcd.print("passed");
    lcd.setCursor(5,1);



    lcd.print("failed");
  }

  else{
    Serial.print(h);
    Serial.print(t);
    lcd.setCursor(6,0);
    lcd.print(h);
    lcd.setCursor(5,1);
    lcd.print(t);
  }
}
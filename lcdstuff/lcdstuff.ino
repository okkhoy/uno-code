#include <I2CIO.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#include <Wire.h>  // Comes with Arduino IDE
// Get the LCD I2C Library here: 
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
// Move any other LCD libraries to another folder or delete them
// See Library "Docs" folder for possible commands etc.
#include <LiquidCrystal_I2C.h>

#include "DHT.h"

#define DHTPIN 12  

DHT dht(DHTPIN, DHTTYPE);

/*-----( Declare Constants )-----*/
/*-----( Declare objects )-----*/
// set the LCD address to 0x27 for a 16 chars 2 line display
// A FEW use address 0x3F
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);  // Used to type in characters

  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight

// ------- Quick 3 blinks of backlight  -------------
  for(int i = 0; i < 2; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on  

  lcd.clear();
  lcd.setCursor(0,0); //Start at character 0 on line 0

  dht.begin();
}

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.write("Failed to read DHT!");
    return;
  }

  delay(100);
  // clear the screen
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("Temp: ");
  lcd.write(t);
  lcd.write("C");
  lcd.write("  ");
  lcd.write(f);
  lcd.write("F");
  lcd.setCursor(0,1);
  lcd.write("Humidity: ");
  lcd.write(h);
  

}

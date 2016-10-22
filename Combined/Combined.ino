#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
//#include "DHT.h"
#include <DS3232RTC.h>        //http://github.com/JChristensen/DS3232RTC
#include <TimeLib.h>             //http://playground.arduino.cc/Code/Time
#define DHTPIN 12     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
//DHT dht(DHTPIN, DHTTYPE);

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);  // Used to type in characters
//  dht.begin();
  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
  lcd.backlight();
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Hello, world!");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("Hi");
  delay(100);  
  setSyncProvider(RTC.get);
  Serial.print("RTC Sync\n");
  if (timeStatus() != timeSet) Serial.print(" FAIL!\n");
  lcd.clear();
}


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
    static time_t tLast;
    time_t t;
    tmElements_t tm;

  t = now();
  delay(1000); 
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
 // float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
//  float temp = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
//  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
//  if (isnan(h) || isnan(temp) || isnan(f)) 
//  {
//    Serial.println("Failed to read from DHT sensor!");
//  }
//  else
  {
    
    lcd.setCursor(0,0); //Start at character 4 on line 0
    lcd.print("H:");
   // lcd.print(h);
    delay(100);
    lcd.print("  ");
    lcd.print("T:");
   // lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print(hour(t));
    lcd.print(":");
    lcd.print(minute(t));
    lcd.print(":");
    lcd.print(second(t));
    lcd.print(" ");
    lcd.print(day(t));
    lcd.print("/");
    lcd.print(month(t));
    lcd.print("/");
    lcd.print(year(t));   
    Serial.print(hour(t));
    Serial.print(":");
    Serial.print(minute(t));
    Serial.print(":");
    Serial.print(second(t));
    Serial.print("  ");
    Serial.print(day(t));
    Serial.print("/");
    Serial.print(month(t));
    Serial.print("/");
    Serial.print(year(t)); 
    Serial.print("\n");
    delay(100); 
  }
    
    //check for input to set the RTC, minimum length is 12, i.e. yy,m,d,h,m,s
    if (Serial.available() >= 12) {
        //note that the tmElements_t Year member is an offset from 1970,
        //but the RTC wants the last two digits of the calendar year.
        //use the convenience macros from Time.h to do the conversions.
        int y = Serial.parseInt();
        if (y >= 100 && y < 1000)
            Serial.print("Error: Year must be two digits or four digits!\n");
        else {
            if (y >= 1000)
                tm.Year = CalendarYrToTm(y);
            else    //(y < 100)
                tm.Year = y2kYearToTm(y);
            tm.Month = Serial.parseInt();
            tm.Day = Serial.parseInt();
            tm.Hour = Serial.parseInt();
            tm.Minute = Serial.parseInt();
            tm.Second = Serial.parseInt();
            t = makeTime(tm);
            RTC.set(t);        //use the time_t value to ensure correct weekday is set
            setTime(t);        
            Serial.print("RTC set to: \n");
            //dump any extraneous input
            while (Serial.available() > 0) Serial.read();
        }
    }
    
}/* --(end main loop )-- */


/* ( THE END ) */


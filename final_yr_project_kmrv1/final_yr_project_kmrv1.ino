/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int in[4] = {7,8,9,10};
int maxlim = 10;
int OutPins[4] = {3,5,6,2};
int isum = 0;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  pinMode(in[0], OUTPUT);
  digitalWrite(in[0], LOW);
  pinMode(in[1], OUTPUT);
  digitalWrite(in[1], LOW);
  pinMode(in[2], OUTPUT);
  digitalWrite(in[2], LOW);
  pinMode(in[3], OUTPUT);
  digitalWrite(in[3], LOW);
  Serial.begin(9600);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  //lcd.print(millis() / 1000);
  int i=0;
  while(isum<=maxlim && i<4)
  {
    lcd.clear();
    lcd.print("--DSM Running!--");
    lcd.setCursor(0,1);
    if((isum + OutPins[i])<=maxlim)
    {
      digitalWrite(in[i], HIGH);
  	  isum += OutPins[i];
      lcd.print(i+1);
      lcd.print(" Turned ON");
    }
    else
    {
        lcd.print(i+1);
    	lcd.print(" Turned OFF");
    }
    i += 1;
    delay(3000);
  }
  lcd.clear();
  lcd.print("------END------");
  delay(10000);
}
 
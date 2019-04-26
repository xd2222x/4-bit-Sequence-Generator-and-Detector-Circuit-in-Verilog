
#include<LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String a;
int temp=0;

void setup() {


  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6,INPUT);


  lcd.begin(16, 2);
  // Print a message to the LCD.
 lcd.print("Random Sequence is ");

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps


}

void loop() {
  temp=0;
  int a=digitalRead(2);
  Serial.println(a);
   lcd.setCursor(0,1);
 lcd.print(a);
 
  int b=digitalRead(3);
    lcd.setCursor(1,1);
 lcd.print(b);

 
  int c=digitalRead(4);
    lcd.setCursor(2,1);
 lcd.print(c);

 
  int d=digitalRead(5);
   lcd.setCursor(3,1);
 lcd.print(d);

 
  //Serial.println(String(temp));
  int e=digitalRead(6);
  lcd.setCursor(14,1);
  lcd.print(e);

  
  //delay(100);
    
}

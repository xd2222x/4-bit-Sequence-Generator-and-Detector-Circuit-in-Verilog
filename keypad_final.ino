
#include <Keypad.h>


float v1 = 0;
float v2 = 0;
int a, b, c, d;
int bits[4];
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'.', '0', '#'}
};

byte rowPins[ROWS] = {10, 8 , 7, 13};
byte colPins[COLS] = { 9, 11 , 12};
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}


byte value = 0;

void loop() {
  char key = kpd.getKey();
  if (key != NO_KEY)
  {
    if ( (key >= '0') && (key <= '9') )
    {
      value = value * 10;
      value = value + key - '0';
    }
    if ( key == '#' )
    {
      //do stuff with value
      //for demonstration purposes, for now we'll just print it
      delay(1000);
      if (value <= 15) {
        Serial.print("The data is : ");
        Serial.println(value);
       
        int data = value;
        for (int c = 3; c >= 0; c--)
        {
          int k = data >> c;

          if (k & 1) {
            bits[c] = 1;
            //Serial.println(bits[c]);
          }
          else {
            bits[c] = 0;
            //Serial.println(bits[c]);
          }
        }
     
         Serial.print("Bits sent to fpga board:");
        Serial.print(bits[3]);
         Serial.print(bits[2]);
          Serial.print(bits[1]);
           Serial.println(bits[0]);
      }
      else {
        Serial.println("Plaese enter a value less than 16!!");

      }




      value = 0; //Now reset ready for next input
    }
  }
  //delay(1000);
 // Serial.print("Bits sent to arduino: ");
  //Serial.print(bits[3]);
  digitalWrite(5, bits[3]);

  //Serial.print(bits[2]);
  digitalWrite(4, bits[2]);

  //Serial.print(bits[1]);
  digitalWrite(3, bits[1]);

  //Serial.println(bits[0]);
  digitalWrite(2, bits[0]);
  // delay(500);
}


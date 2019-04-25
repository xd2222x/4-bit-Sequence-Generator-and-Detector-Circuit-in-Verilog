void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  int a,b,c,d,temp;
  // put your main code here, to run repeatedly:
  
  delay(2000);
  Serial.println("Enter the input bits:");
  
  
  if (Serial.available() > 0) {
    String s = Serial.readString();
    int data = s.toInt();
    Serial.println("Bits sent to fpga board:");
    Serial.print(data);
    
    Serial.print("\n\n\n");
     a= data%10;
     temp=data/10;
     
     Serial.println(a);
     digitalWrite(2,a);
     b=temp%10;
     temp=temp/10;
     Serial.println(b);
      digitalWrite(3,b);
     c=temp%10;
     temp=temp/10;
     Serial.println(c);
      digitalWrite(4,c);
     d=temp%10;
     temp=temp/10;
     Serial.println(d);
      digitalWrite(5,d);
    
    }
    
    
  

}

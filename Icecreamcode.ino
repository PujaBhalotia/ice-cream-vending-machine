#include <Wire.h>
#include <LiquidCrystal_I2C.h> // need to install
const int coin = 2;
boolean insert = false;
volatile int pulse = 0;
unsigned long balance;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int m;
int x;
int y;
int z;
int van=3;
int cho=4;
int stra=5;
int m1=6;
int m2=7;
int m3=8;
int m4=9;
int m5=10;
int m6=11;
int relay=12;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  //Turn on the backlight.
  lcd.backlight();
  pinMode(van, INPUT);
  pinMode(cho, INPUT);
  pinMode(stra, INPUT);
   pinMode(m1, OUTPUT);
   pinMode(m2, OUTPUT);
   pinMode(m3, OUTPUT);
   pinMode(m4, OUTPUT);
   pinMode(m5, OUTPUT);
   pinMode(m6, OUTPUT);
   pinMode(relay, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), coinInterrupt, RISING);
  delay(1000);

}

void loop() {
    
  int a=digitalRead(van);
  
 if((a==1)&& (m==3))
{
   m=0;
  Serial.println("van");
    lcd.clear();
   lcd.setCursor(0,0 );
  lcd.print("You Selected");
  lcd.setCursor(0, 1);
  lcd.print("Vanilla Flavour");
  delay(100);
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    delay(2000);
   
     digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
     
      delay(100);
      digitalWrite(relay, HIGH);
      delay(1000);
      digitalWrite(relay, LOW);
      delay(1000);
   
}
  
   
  
  int c=digitalRead(stra);
   
  if((c==1)&& (m==3)) 
{
  
  Serial.println("str");
   lcd.clear();
   lcd.setCursor(0,0 );
  lcd.print("you selected");
  lcd.setCursor(0, 1);
  lcd.print("strawberry flavour");
  delay(100);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
    delay(2000);
     digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
  delay(100);
   delay(100);
      digitalWrite(relay, HIGH);
      delay(1000);
      digitalWrite(relay, LOW);
      delay(1000);
    
 
}


int b=digitalRead(cho);
if((b==1)&& (m==3))
{
  
 Serial.println("cho");
    lcd.clear();
   lcd.setCursor(0,0 );
  lcd.print("you selected");
  lcd.setCursor(0, 1);
  lcd.print("choco flavour");
  delay(100);
    digitalWrite(m5, LOW);
    digitalWrite(m6, HIGH);
    delay(2000);
   
     digitalWrite(m5, LOW);
      digitalWrite(m6, LOW);
      delay(100); 
    delay(100);
      digitalWrite(relay, HIGH);
      delay(1000);
      digitalWrite(relay, LOW);
      delay(1000);
    
}

 
  // put your main code here, to run repeatedly:
 
 if ((a==0)&& (b==0)&& (c==0)&& (m==0))
{
  lcd.clear();
   lcd.setCursor(0,0 );
  lcd.print("ICE CREAM");
  lcd.setCursor(0, 1);
  lcd.print("VENDING MACHINE");
  delay(100);
  
  }
  Serial.print("m= ");
  Serial.println(m);
   
  if (insert) {
    insert = false;
    //Serial.println("coin detected!");
   
    Serial.println(coin);
    
    delay(10);
   
    
m=3;
x=0;
y=0;
z=0;
Serial.println("mhigh");
  } 
  else if (m==3)
  {
    lcd.clear();
   lcd.setCursor(0,0 );
  lcd.print("Coin Accepted");
  lcd.setCursor(0, 1);
  lcd.print("Select Flavour");
  delay(100);
    }
  
 
}

//interrupt
void coinInterrupt() {
  pulse++ ;
  insert = true;
}
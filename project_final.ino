#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup()
{
lcd.begin(16, 2);
lcd.clear();

Serial.begin(9600);

pinMode(12, INPUT);
digitalWrite(12, HIGH);
pinMode(13, INPUT);
digitalWrite(13, HIGH);
pinMode(11, OUTPUT);

}
double i = 0;
double a = millis();
double c ;
int h,m,s;
void loop()
{
  lcd.clear();
 lcd.print("1.Stopwatch");
  lcd.setCursor(0,1);
  lcd.print("2.Timer");
  lcd.clear();
  int value1=digitalRead(13);
if(value1==LOW )
{
  int a = 60;
  while(a>=0){
  lcd.print(a);
  delay(1000);
  lcd.setCursor(0,0);
  a--;
  }
  lcd.print("TIME UP!");
  digitalWrite(11,HIGH);
  delay(3000);
  digitalWrite(11,LOW);
}
  int value=digitalRead(12);
  
  if(value==LOW)
{
  //char keypressed = kpd.getKey();

 
 // Serial.print (keypressed);
  
  //Serial.print("In");
  //lcd.setCursor(0,0);
  //lcd.clear();
  //Serial.print("[2J");
 //lcd.setCursor(0,0);
 lcd.clear();
//lcd.print("press start");
delay(100);

if(digitalRead(12) == LOW)
{

lcd.clear();
a = millis();
while(digitalRead(13) == HIGH)
{

c = millis();
i = (c - a) / 1000;
lcd.print(i);
lcd.setCursor(7,0);
lcd.print("Sec's");
lcd.setCursor(0,0);
Serial.println(c);
Serial.println(a);
Serial.println(i);
Serial.println("......");
delay(100);
}

if(digitalRead(13) == LOW)
{
while(digitalRead(12) == HIGH)
{
lcd.setCursor(0,0);
//r=i/60;
//rem=i-60*r;
h=(i/3600);
m=(i-(3600*h))/60;
s=(i-(3600*h)-(m*60));
lcd.print("hour:min:sec");
//lcd.print(i);
lcd.setCursor(0,1);
lcd.print("");
lcd.print(h);
lcd.print(":");
lcd.print(m);
lcd.print(":");
lcd.print(s);
lcd.setCursor(0,0);
delay(3000);
break;
}
}
}
}

}

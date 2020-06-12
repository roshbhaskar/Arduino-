
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,7,6,5,4);
const byte Rows= 4; //number of rows on the keypad i.e. 4
const byte Cols= 4; //number of columns on the keypad i,e, 4
//we will definne the key map as on the key pad:
int X=0,Y=0;
char keymap[Rows][Cols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rPins[Rows]= {0,1,2,3}; //Rows 0 to 3
byte cPins[Cols]= {10,11,12,13}; //Columns 0 to 3
Keypad kpd= Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);
void setup()
{
lcd.begin(16,2);
}
void loop()
{
 while(X<16)
 {
 char keypressed = kpd.getKey();
if (keypressed != NO_KEY)
{
//Serial.print (keypressed);
lcd.setCursor(X,Y);
//text to print
lcd.print(keypressed);
X=X+1;
if(X==16)
{
Y=1;
X=0;
}
}
//delay(100);
}
}

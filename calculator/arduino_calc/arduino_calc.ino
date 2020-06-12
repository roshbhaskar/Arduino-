#include <Keypad.h>
int digit1 = 0;  
int digit2 = 0;
int total = 0;
char keypressed;
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

byte rPins[Rows]= {13,12,11,10}; //Rows 0 to 3
byte cPins[Cols]= {3,2,1,0}; //Columns 0 to 3
Keypad kpd= Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);


void setup()
{
lcd.begin(16,2);
}//end of setup()


void loop()
{

keypressed = kpd.getKey();
switch(keypressed)
{
    case '0' ... '9':
    digit1 = digit1 * 10 + (keypressed - '0');
    lcd.print(digit1);
    break;
  case 'A':
    digit1 = (total != 0 ? total : digit1);
    lcd.print("+");
    digit2 = SecondNumber();
    total = digit1 + digit2;
    lcd.print("=");
    lcd.print(total);
    digit1 = 0, digit2 = 0;
    break;
  case 'B':
    digit1= (total != 0 ? total : digit1);
    lcd.print("-");
    digit2 = SecondNumber();
    total = digit1 - digit2;
    lcd.print("=");
    lcd.print(total);
    digit1 = 0, digit2 = 0;
    break;
  case 'C':
    digit1= (total != 0 ? total : digit1);
    lcd.print("*");
    digit2 = SecondNumber();
    total = digit1 * digit2;
    lcd.print("=");
    lcd.print(total);
    digit1 = 0, digit2 = 0;
    break;
  case 'D':
    digit1= (total != 0 ? total : digit1);
    lcd.print("/");
    digit2 = SecondNumber();
   total = digit1 / digit2;
   lcd.print("=");
    lcd.print(total);
    digit1 = 0, digit2 = 0;
    break;
  case '*':
    lcd.clear();
    total = 0;
    break;
}//end of switch()
}//end of loop()

long SecondNumber()
{
  while(1)
  {
    keypressed = kpd.getKey();
    if(keypressed >= '0' &&  keypressed<= '9')
    {
      digit2 = digit2 * 10 + (keypressed - '0');
      lcd.print(digit2);
    }
    if(keypressed == '#') break;  //return second;
  }
return digit2; 
}//end of secondnumber()00

#include <LiquidCrystal_I2C.h>

#define printDelay 10
#define KEY 3
#define BUT 2
#define RES 4

//Устанавливаем ЖК-дисплей по адресу 0x27, 16 символов и 2 строки

/*
 * SDA -> A4
 * SCL -> A5
 * BUT -> D3
 * KEY -> D2
 */
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte D[] = {
  B00000,
  B00000,
  B00110,
  B01010,
  B01010,
  B11111,
  B10001,
  B00000
};

byte L[] = {
  B00000,
  B00000,
  B00111,
  B01001,
  B01001,
  B01001,
  B10001,
  B00000
};

byte T[] = {
  B00000,
  B00000,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00000
};

byte MZ[] = {
  B00000,
  B00000,
  B10000,
  B10000,
  B11110,
  B10001,
  B11110,
  B00000
};

byte Z[] = {
  B00000,
  B00000,
  B01110,
  B10001,
  B00110,
  B10001,
  B01110,
  B00000
};

byte B[] = {
  B00011,
  B01100,
  B10000,
  B11110,
  B10001,
  B10001,
  B01110,
  B00000
};

byte I[] = {
  B00000,
  B00000,
  B10001,
  B10011,
  B10101,
  B11001,
  B10001,
  B00000
};

byte N[] = {
  B00000,
  B00000,
  B10001,
  B10001,
  B11111,
  B10001,
  B10001,
  B00000
};

void setup()
{
  digitalWrite(RES, HIGH);
  pinMode(RES, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);

  lcd.createChar(0, D);
  lcd.createChar(1, L);
  lcd.createChar(2, T);
  lcd.createChar(3, MZ);
  lcd.createChar(4, Z);
  lcd.createChar(5, B);
  lcd.createChar(6, I);
  lcd.createChar(7, N);
  
  
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  while(digitalRead(KEY)){}
  
  Serial.begin(9600);
  printSdelat();
}
 
 
void loop(){
  for(int i = 0; i < 16; ++i){
      lcd.setCursor(i,1);
      lcd.print("#");

      lcd.setCursor(i-1,1);
      lcd.print("#");
      lcd.setCursor(i+1,1);
      lcd.print("#");

      lcd.setCursor(i-2,1);
      lcd.print("#");
      lcd.setCursor(i+2,1);
      lcd.print("#");

      delay(20);
      lcd.setCursor(i-2,1);
      lcd.print(" ");
      lcd.setCursor(i+2,1);
      lcd.print(" ");
      delay(20);
      lcd.setCursor(i-1,1);
      lcd.print(" ");
      lcd.setCursor(i+1,1);
      lcd.print(" ");
      delay(20);
      lcd.setCursor(i,1);
      lcd.print(" ");
      
      if(!digitalRead(BUT)){
        accepting();
      }
    }
}

void LCDclear2(){
  lcd.setCursor(0,1);
  lcd.print("                ");
}

void LCDclear(){
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}

void accepting(){
  LCDclear2();
  bool notAccept = 0;
  for(int i = 0; i < 16; ++i){
    lcd.setCursor(i,1);
    lcd.print("#");
    delay(100);
    if(digitalRead(BUT)){
      notAccept = 1;
      break;
    }
  }
  if(notAccept){
    LCDclear2();
    return;
  }
  LCDclear();
  delay(100);
  printBudet();
}

void printBudet(){
  lcd.setCursor(2,0);
  lcd.write(4);
  delay(printDelay);
  lcd.setCursor(3,0);
  lcd.print("ae");
  delay(printDelay);
  lcd.setCursor(5,0);
  lcd.write(5);
  delay(printDelay);
  lcd.setCursor(6,0);
  lcd.write(6);
  delay(printDelay);
  lcd.setCursor(7,0);
  lcd.print("c");
  delay(printDelay);
  lcd.setCursor(8,0);
  lcd.write(3);
  delay(printDelay);

  lcd.setCursor(10,0);
  lcd.write(5);
  delay(printDelay);
  lcd.setCursor(11,0);
  lcd.print("y");
  delay(printDelay);
  lcd.setCursor(12,0);
  lcd.write(0);
  delay(printDelay);
  lcd.setCursor(13,0);
  lcd.print("e");
  delay(printDelay);
  lcd.setCursor(14,0);
  lcd.write(2);
  delay(printDelay);

  lcd.setCursor(4,1);
  lcd.print("c");
  delay(printDelay);
  lcd.setCursor(5,1);
  lcd.write(0);
  delay(printDelay);
  lcd.setCursor(6,1);
  lcd.print("e");
  delay(printDelay);
  lcd.setCursor(7,1);
  lcd.write(1);
  delay(printDelay);
  lcd.setCursor(8,1);
  lcd.print("a");
  delay(printDelay);
  lcd.setCursor(9,1);
  lcd.write(7);
  delay(printDelay);
  lcd.setCursor(10,1);
  lcd.print("o!");
  delay(printDelay);

  while(!digitalRead(KEY)){}
  digitalWrite(RES, LOW);
}

void printSdelat(){
  lcd.setCursor(0,0);
  lcd.print("C");
  delay(printDelay);
  lcd.setCursor(1,0);
  lcd.write(0);
  delay(printDelay);
  lcd.setCursor(2,0);
  lcd.print("e");
  delay(printDelay);
  lcd.setCursor(3,0);
  lcd.write(1);
  delay(printDelay);
  lcd.setCursor(4,0);
  lcd.print("a");
  delay(printDelay);
  lcd.setCursor(5,0);
  lcd.write(2);
  delay(printDelay);
  lcd.setCursor(6,0);
  lcd.write(3);
  delay(printDelay);

  lcd.setCursor(8,0);
  lcd.write(4);
  delay(printDelay);
  lcd.setCursor(9,0);
  lcd.print("ae");
  delay(printDelay);
  lcd.setCursor(11,0);
  lcd.write(5);
  delay(printDelay);
  lcd.setCursor(12,0);
  lcd.write(6);
  delay(printDelay);
  lcd.setCursor(13,0);
  lcd.print("c");
  delay(printDelay);
  lcd.setCursor(14,0);
  lcd.write(3);
  delay(printDelay);
  
  lcd.setCursor(15,0);
  lcd.print("?");
  delay(printDelay);
}

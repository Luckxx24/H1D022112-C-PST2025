#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// put function declarations here:
int SDA_pin = D3;
int SCL_pin = D2;
LiquidCrystal_I2C lcd(0x27,16,1);  //mengisi alamat i2c yang sudah ditemukan sebelumnya 


void setup() 
{
  // put your setup code here, to run once:
  Wire.begin(SDA_pin,SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("halo dunia");
  lcd.setCursor(0,1);
  lcd.print("halo siang");


}

void loop() 
{
  // put your main code here, to run repeatedly:
  lcd.scrollDisplayLeft();
  delay(300);
}


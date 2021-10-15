#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Display{
    private:
        LiquidCrystal_I2C *lcd;
    public:
    Display(void);
    void print_edit_select_prox(void);
    Display::print_mais_select_menos(void)
};

Display::Display(void){
    this->lcd = new LiquidCrystal_I2C(PCF8574_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);
    this->lcd.begin(20, 4, LCD_5x8DOTS, D2, D1);
    this->lcd.setCursor(5, 1);
    this->lcd.print("TermoTecno"); //(F()) saves string to flash & keeps dynamic memory free
    delay(2000);
    this->lcd.clear();
}

Display::print_edit_select_prox(void){
    this->lcd.setCursor(0, 3);
    this->lcd.print(F("edit"));
    this->lcd.setCursor(7, 3);
    this->lcd.print(F("selec"));
    this->lcd.setCursor(17, 3);
    this->lcd.print(F("prox"));
}

Display::print_mais_select_menos(void){
    this->lcd.setCursor(3, 3);
    this->lcd.print(F("-"));
    this->lcd.setCursor(7, 3);
    this->lcd.print(F("selec"));
    this->lcd.setCursor(17, 3);
    this->lcd.print(F("+"));
}


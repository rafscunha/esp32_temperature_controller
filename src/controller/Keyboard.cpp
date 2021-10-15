#include <Arduino.h>
#define BR D7
#define BL D6
#include <LiquidCrystal_I2C.h>

class Keyboard{
    int getOptionSelect(void);
    int gerValue(int coluna, int linha, int value,  LiquidCrystal_I2C *lcd){

    }
}

int Keyboard::getOptionSelect(){
    int select = 0;
    int flag_get_time = 0;
    int time_init;
    int last_est_BL = 0;
    int last_est_BR = 0;
    while(select == 0){
        //botão BL
        if(digitalRead(BL) == HIGH){
            if(flag_get_time == 0) {
                time_init = millis();
                flag_get_time = 1;
            }
            last_est_BL = 1;
            if(((millis()-time_init) > 500)&&(flag_get_time)){
                return 11;
            }
        }
        if((digitalRead(BL) == LOW)&&(last_est_BL == 1)&&(last_est_BR == 0)&&(digitalRead(BR) == LOW)){
            return 1;
        }
        //botão BR
        if(digitalRead(BR) == HIGH){
            if(flag_get_time == 0) {
                time_init = millis();
                flag_get_time = 1;
            }
            last_est_BR = 1;
            if(((millis()-time_init) > 500)&&(flag_get_time)){
                return 22;
            }
        }
        if((digitalRead(BL) == LOW)&&(last_est_BL == 0)&&(last_est_BR == 1)&&(digitalRead(BR) == LOW)){
        return 2;
        }
        
        if((digitalRead(BR) == HIGH)&&(digitalRead(BL) == HIGH)){
        return 3;
        }
        delay(10);
        
    }
    return 0;
}

Keyboard::getValue(int coluna, int linha, int value,  LiquidCrystal_I2C *lcd){
    int select = 0;
    lcd.setCursor(coluna, linha);
    lcd.print(value);
    while(select == 0){
        int op = getOpSelect();
        if(op == 1) value--;
        if(op == 11) value -= 20;
        if(op == 2) value++;
        if(op == 22) value += 20;
        if(op == 3) select = 1;
        lcd.setCursor(coluna, linha);
        lcd.print(F("   "));
        lcd.setCursor(coluna, linha);
        lcd.print(value);
        delay(10);
    }
    lcd.noCursor();
    return value;

}
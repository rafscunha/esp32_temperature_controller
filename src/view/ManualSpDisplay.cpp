#include "Display.cpp"

class ManualSpDisplay: public Display{

    public:
        ManualSpDisplay(int temperature):Display(void){
            this->temperature = temperature;
        }
        
        void show(int temperature){
        /*
        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
            M o d o   -   M a n u a l
        
        T E M P E R A T U R A :   X X X X   º C
        e d i t        s e l e c         p r o x
        */
            this->lcd.clear();
            this->lcd.setCursor(3, 0);
            this->lcd.print(F("MODO - Manual"));
            this->lcd.setCursor(0, 2);
            this->lcd.print(F("Temperatura: "));
            this->lcd.setCursor(13, 2);
            this->lcd.print(this->temperature);
            this->lcd.setCursor(18, 2);
            this->lcd.print((char)223);
            this->lcd.setCursor(19, 2);
            this->lcd.print(F("C"));
            this->print_edit_select_prox();
        }

        void edit(int temperature){
            this->lcd.clear();
            this->lcd.setCursor(2, 0);
            this->lcd.print(F("EDITAR - Manual"));
            this->lcd.setCursor(0, 2);
            this->lcd.print(F("Temperatura: "));
            this->print_mais_select_menos();

        }

};


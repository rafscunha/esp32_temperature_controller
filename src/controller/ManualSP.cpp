
#include "../services/MemoryEEPROM.cpp"
#include "../view/ManualSpDisplay.cpp"
#include "Keyboard.cpp"

class ManualSP: public MemoryEEPROM, public ManualSpDisplay, public Keyboard{
    private:
        int temperature;

    public:
    
    ManualSP(void):ManualSpDisplay(this->getTemperatureEstatic()){
        this->temperature = this->getTemperatureEstatic();
    }


    void edit(void){
        this->edit();
        this->temperature = this->getValue(13,2, this->temperature, this->lcd);
        this->setTemperatureEstatic(this->temperature);
    }

    int menu(void){
        int here = 1;
        int mode = 1;
        int run = 0;
        while(here){
            switch(mode){
                case 1: //Visuzalizar
                    this->show(void);
                    break;
                case 2: // Editar
                    this->edit();
                    break;
            }
            int op = this->getOptionSelect();
            if((op == 1) || (op == 11)){ // ESQUERDO - EDIT
                mode = 2;
                
            }else if((op == 2) || (op == 22)){ // DIREITO - CHANGE PROX
                here = 0;
                
            }else{ // OS DOIS - SELECT
                run = 1;
                here = 0;
            }

        }
        return run;
    }

}
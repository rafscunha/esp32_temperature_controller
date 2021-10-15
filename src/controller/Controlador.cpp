#include "../model/Program.cpp"
#include "../services/MemoryEEPROM.cpp"
#include "Keyboard.cpp"
#include "ManualSP.cpp"

class Controlador{
    private:
        MemoryEEPROM *memoria;
        Program *rampa;
        Keyboard *teclado;
        ManualSP *control_manual;
        int optionSelected = 1;
        int temperature_estatica;
    
    public:
        void Controlador(void){
            this->memoria = new MemoryEEPROM;
            this->rampa = new Program(this->memoria->getProgram());
            this->temperature_estatica = this->memoria->getTemperatureEstatic();
            this->teclado = new Keyboard;
            this->control_manual = new ManualSP;
            //Incluir todas as verificações dos 'periféricos' aqui
        }

        void run(void){
            int selectable = 1;
            int run = 1;
            int mode = 0; // 0-> Nenhum mode selecionado / 1-> Modo manual / 2-> Modo Rampa
            while(run){
                int op = 0;

                switch (this->optionSelected)){
                case 1:
                    //MENU DA TEMPERATURA ATUAL
                    this->optionSelected = 2;
                    mode = 0;
                    break;
                case 2://implementado - não testado
                    op = this->control_manual->menu();
                    if(op == 1){
                        this->optionSelected = 4;
                        mode = 1;
                    }else{
                        this->optionSelected = 3;
                        mode = 0;
                    }
                    break;
                case 3:
                    //MENU DO PROGRAMA COM RAMPA
                    if(op == 1){
                        this->optionSelected = 4;
                        mode = 2;
                    }else{
                        this->optionSelected = 1;
                        mode = 0;
                    }
                    break;
                case 4;
                    //EXECUÇÃO DO PROGRAMA segundo o mode
                    this->optionSelected = 2;
                    break;

                }

            }
        }

};
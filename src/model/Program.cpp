#include <stdlib.h>
#include "Section.cpp"

class Program{
    private:
        Section *rampa[4];
        int position = 0;
        
    public:
        Program(void);
        Program(int *matrix);
        void setProgramMatrix(int *matrix);
        int *getProgramMatrix(void);
        int getTemperatureInTime(int time);
        ~Program(void);

};
//------------------------------------------------------------------------------------------------------------------------------------
Program::Program(){
    for(int i=0; i <5;i++){
        rampa[i] = NULL;
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
Program::Program(int *matrix){
    for(int i=0;i<4;i++){
        //printf("%d - %d - %d - %d \n", matrix[2*i], matrix[2*i+1], matrix[(2+2*i)], matrix[(2+2*i)+1]);
        this->rampa[i] = new Section(matrix[2*i], matrix[2*i+1], matrix[(2+2*i)], matrix[(2+2*i)+1]);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void Program::setProgramMatrix(int *matrix){
    if(rampa[0] != NULL){
        for(int i ; i<5 ; i++){
            delete rampa[i];
            rampa[i] = NULL;
        }
    }
    for(int i=0;i<5;i++){
        
        this->rampa[i] = new Section(matrix[2*i], matrix[2*i+1], matrix[(2+2*i)], matrix[(2+2*i)+1]);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
int *Program::getProgramMatrix(void){
    int *matrix = (int*)malloc(sizeof(int[10]));
    //int matrix[5][2];

    matrix[0]=this->rampa[0]->getTimeStart();
    matrix[1]=this->rampa[0]->getTemperatureStart();

    for(int i=1;i<=5;i++){
        for(int j=0; j<2 ; j++){
            if(j==0){
                matrix[2*i+j] = this->rampa[i-1]->getTimeEnd();
            }else{
                matrix[2*i+j] = this->rampa[i-1]->getTemperatureEnd();
            }
        }
    }
    return matrix;
}
//------------------------------------------------------------------------------------------------------------------------------------

int Program::getTemperatureInTime(int time){
    int temperature = 0;
    //printf("temp fim: %ds  - ",this->rampa[3]->getTemperatureEnd());
    if(this->rampa[3]->getTimeEnd() < time){
        return -273;
    }else{
        if(this->position > 4) return -273;
        if(this->rampa[this->position]->getTimeEnd() < time) this->position++;

        temperature = this->rampa[this->position]->getTemperaturaInTime(time);
    }
    return temperature;
    
}
//------------------------------------------------------------------------------------------------------------------------------------
Program::~Program(){
    if(rampa[0] != NULL){
        for(int i ; i<5 ; i++){
            delete rampa[i];
        }
    }
}
//#include <iostream>
#include <cstddef> 
#include "Point.cpp"


class Section{
    private:
        Point *start;
        Point *end;
        float coef_angular;
        float coef_linear;
        float computeCoefAngular(void);
        float computeCoefLinear(void);
        void reComputerCoefs(void);
    public:
        Section(void);
        Section(Point *start, Point *end);
        Section(int start_time, int start_temperature, int end_time, int end_temperature);
        int getTemperatureStart(void);
        int getTemperatureEnd(void);
        int getTimeStart(void);
        int getTimeEnd(void);
        float getCoefAngular(void);
        float getCoefLinear(void);
        float getTemperaturaInTime(int time);
        ~Section(void);
};

//PRIVATES FUNCION
float Section::computeCoefAngular(void){
    if(this->start->getTemperature() == this->end->getTemperature()){
        return 0;
    }else{
        return (float(this->end->getTemperature() - this->start->getTemperature())/float(this->end->getTime() - this->start->getTime()));
    }
}
//------------------------------------------------------------------------------------------------------------------------------------

float Section::computeCoefLinear(void){
    printf("tempo incial: %d\n", this->start->getTime());
    return (this->start->getTemperature() - this->coef_angular * this->start->getTime());
}

void Section::reComputerCoefs(void){
    this->coef_angular = this->computeCoefAngular();
    this->coef_linear = this->computeCoefLinear();
}
//------------------------------------------------------------------------------------------------------------------------------------

//PUBLIC FUNCION
Section::Section(void){
    this->start = NULL;
    this->end = NULL;
    this->coef_angular = 0;
    this->coef_linear = 0;
}
//------------------------------------------------------------------------------------------------------------------------------------
Section::Section(Point *start, Point *end){
    this->start = start;
    this->end = end;
    this->coef_angular = this->computeCoefAngular();
    this->coef_linear = this->computeCoefLinear();
}
//------------------------------------------------------------------------------------------------------------------------------------
Section::Section(int start_time, int start_temperature, int end_time, int end_temperature){
    this->start = new Point(start_time, start_temperature);
    this->end = new Point(end_time, end_temperature);
    this->coef_angular = this->computeCoefAngular();
    this->coef_linear = this->computeCoefLinear();
    //printf("t1: %ds T1:%dC |t2: %ds T2:%dC |CA: %f CL:%f \n",start_time,  start_temperature, end_time, end_temperature,this->coef_angular, this->coef_linear);
}
//------------------------------------------------------------------------------------------------------------------------------------

int Section::getTemperatureStart(void){
    return this->start->getTemperature();
}
//------------------------------------------------------------------------------------------------------------------------------------
int Section::getTemperatureEnd(void){
    return this->end->getTemperature();
}
//------------------------------------------------------------------------------------------------------------------------------------
int Section::getTimeStart(void){
    return this->start->getTime();
}
//------------------------------------------------------------------------------------------------------------------------------------
int Section::getTimeEnd(void){
    return this->end->getTime();
}
//------------------------------------------------------------------------------------------------------------------------------------
float Section::getCoefAngular(void){
    return this->coef_angular;
}
//------------------------------------------------------------------------------------------------------------------------------------
float Section::getCoefLinear(void){
    return this->coef_linear;
}
//------------------------------------------------------------------------------------------------------------------------------------
float Section::getTemperaturaInTime(int time){
    return (time * this->coef_angular + this->coef_linear);
}
//------------------------------------------------------------------------------------------------------------------------------------
Section::~Section(){
    delete this->start;
    delete this->end;
}
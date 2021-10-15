#include <stdio.h>
class Point{
    private:
        int temperature;//Temperatura em Celsius [C]
        int time;//Tempo em segundos [s]
    public:
        Point(int temperature, int time);
        int getTemperature(void);
        int getTime(void);
        void setTemperature(int temperature);
        void setTime(int time);
};
//------------------------------------------------------------------------------------------------------------------------------------
Point::Point(int time, int temperature){
    this->temperature = temperature;
    this->time = time;
    //printf("t:%ds / T:%dC\n", this->time,this->temperature);
}
//------------------------------------------------------------------------------------------------------------------------------------
int Point::getTemperature(void){
    return this->temperature;
}
//------------------------------------------------------------------------------------------------------------------------------------
int Point::getTime(void){
    return this->time;
}
//------------------------------------------------------------------------------------------------------------------------------------
void Point::setTemperature(int temperature){
    this->temperature = temperature;
}
//------------------------------------------------------------------------------------------------------------------------------------
void Point::setTime(int time){
    this->time = time;
}
#include <EEPROM.h>

#define EEPROM_BYTE 64

class MemoryEEPROM{
    private:
        void save(int addr, int value);
        int *get(int addr);
    public:
        void saveProgram(int *matrix[10]);
        int *getProgram();
        int getTemperatureEstatic();
        void setTemperatureEstatic(int value);
};
//------------------------------------------------------------------------------------------------------------------------------------
void MemoryEEPROM::save(int addr, int value){
    EEPROM.begin(EEPROM_BYTE);
    EEPROM.write(addr, value);
    EEPROM.end();
}
//------------------------------------------------------------------------------------------------------------------------------------
int MemoryEEPROM::get(int addr){
    EEPROM.begin(EEPROM_BYTE);
    int result = EEPROM.read(addr);
    EEPROM.end();
    return result;
}
//------------------------------------------------------------------------------------------------------------------------------------
void MemoryEEPROM::saveProgram(int *matrix[10]){
    for (int i=0; i<10 ;i++){
        this->save(i, matrix[0]);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
int *MemoryEEPROM::getProgram(){
    int *matrix = (int*)malloc(sizeof(int[10]));
    for (int i=0; i<10 ;i++){
        matrix[i] = this->get(i);
    }
    return matrix;
}
//------------------------------------------------------------------------------------------------------------------------------------
int MemoryEEPROM::getTemperatureEstatic(){
    return this->get(10);
}
//------------------------------------------------------------------------------------------------------------------------------------
void MemoryEEPROM::setTemperatureEstatic(int value){
    this->set(10, value);
}
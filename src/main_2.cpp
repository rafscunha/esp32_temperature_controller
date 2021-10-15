#include "model/Program.cpp"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void){
    int matriz_pontos[10] = {0,25,5,125,10,125,15,225,20,100};
    Program rampa(matriz_pontos);

    clock_t t_init = clock();
    int tempo = 0;
    int temperatura = 0;

    for(;temperatura != -273;){
        tempo = int((clock() - t_init)/CLOCKS_PER_SEC);
        temperatura = rampa.getTemperatureInTime(tempo);
        sleep(1);
        printf("Tempo: %ds - Temperatura: %d C\n", tempo, temperatura);
    }
}
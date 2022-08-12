#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main() {
    double sus[4]={6.30,11.00,0.63,12.47};
    char hospital,paciente;
    int opcao,vias=0;
    printf("Digite o nome de onde consultou: ");
    hospital = strings();
    printf("Digite o seu nome: ");
    paciente = strings();

    printmenu();
    opcao=selectmenu();
    if(opcao>=3){
        printf("quantas vias de medicamentos: \n");
        printf("deseja ver quais vias de medicamento existem? \n");
        if(verificaresposta()==1){
            viasmedicamento();
        }
        vias=aplicado();
        sus[2]=sus[2]*(double)vias;
    }
    else{
        sus[2]=sus[2]*(double)vias;
    }
    printf("Você consultou no %s\n",hospital);
    printf("caro %s, o hospital ira receber R$ %.2f",paciente,somadosvaloressus(opcao,vias,sus));
}
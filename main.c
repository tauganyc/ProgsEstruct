#include <stdio.h>
#include "lib.h"

int main() {
    int question,controle,vias;
    printf("Voce passou por uma consulta? \n");
    controle=verificaresposta();
    if(controle==1){
        double resposta;
        printf("voce foi medicado?\n");
        controle=verificaresposta();
        if(controle==1){
            printf("quantas quantas vias de medicamento?\n");
            scanf("%i",&vias);
            resposta=somadosvaloressus(2,vias);
            printf("%.2lf",resposta);
        }
        else{
            resposta=somadosvaloressus(1,0);
            printf("%.2lf",resposta);
        }
    }
    else{
        printf("você nao passou por uma consulta");
    }
}
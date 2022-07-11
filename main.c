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
            printf("Deseja ver as principais vias de aplicacao de medicamentos?\n");
            int pergunta=verificaresposta();
            if(pergunta==1){
                viasmedicamento();
            }
            scanf("%i",&vias);
            controle=verificaresposta();
            if(controle==1){
                printf("voce ficou em um periodo de observacao\n");
                resposta=somadosvaloressus(3,vias);
                printf("%.2lf",resposta);

            }
            else{
                resposta=somadosvaloressus(2,vias);
                printf("%.2lf",resposta);
            }
        }
        else{
            resposta=somadosvaloressus(1,0);
            printf("%.2lf",resposta);
        }
    }
    else{
        printf("voce nao passou por uma consulta");
    }
}
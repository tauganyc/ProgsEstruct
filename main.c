#include <stdio.h>
#include "lib.h"

int main() {
    float sus[4]={6.30,11.00,0.63,12.47};
    char* hospital;
    char* paciente;
    int opcao,vias=0;
    createDir("instituicao");
    createDir("pacientes");
    do {
        printf("você é:\n");
        printf("0 - Instituicao hospitalar\n");
        printf("1 - Paciente\n");
        if(verificaresposta()==0){
            limpaInput();
            printf("Digite o nome da instituicao: ");
            hospital = strings();
            valorinstituicao(sus,hospital);

        }else{
            limpaInput();
            printf("Digite o nome de onde consultou: ");
            hospital = strings();
            printf("Digite o seu nome: ");
            paciente = strings();

            printmenu();
            opcao = selectmenu();
            if (opcao >= 3) {
                printf("quantas vias de medicamentos: \n");
                printf("deseja ver quais vias de medicamento existem? \n");
                printf("digite 1 para sim e 0 para não\n");
                if (verificaresposta() == 1) {
                    viasmedicamento();
                }
                vias = aplicado();
                sus[2] = sus[2] * (float) vias;
            } else {
                sus[2] = sus[2] * (float) vias;
            }
            printf("Você consultou no %s\n", hospital);
            printf("caro %s, o hospital ira receber R$ %.2f", paciente, somadosvaloressus(opcao, vias, sus));
        }
        printf("\n voce quer fazer novamente?\n");
        printf("digite 1 para sim e 0 para não\n");
    } while (verificaresposta() == 1);
}

//
// Created by taugany on 04/07/22.
//

#include <stdio.h>
#include <malloc.h>
#include "funcoes.h"
#define MAX_SIZE 512

void limpaInput() {
    int c;
    while ( (c = getchar()) != '\n' && c != EOF ) { }
}
int aplicado(void){
    int vias;
    printf("digite o numero de vias que foi aplicado em voce: ");
    printf("digite de 0 ate 10\n");
    scanf("%i",&vias);
    if(vias>=0&&vias<=10){
        return vias;
    }
    else{
        printf("digite um valor valido\n");
        aplicado();
    }
}
void viasmedicamento(){
    printf("as principais vias de aplicacao sao:\n");
    printf("Oral\nSublingual\nintravenosa\nintramuscular\nsubcutanea\nrespiratoria\ntopica\nOcular\nnazal\nauricular\n");
}
double somadosvaloressus(int opcao,int vias,double* valoressus){
    float totalsus;
    totalsus=0;
    for(int i=0;i<opcao-1;i++){
        totalsus=totalsus+valoressus[i];
    }
    return totalsus;

}
int verificaresposta(){
    int x;
    printf("digite 1 para sim e 0 para não\n");
    scanf("%i",&x);
    if(x==1||x==0){
        return x;
    }
    else{
        printf("digite um valor valido\n");
        return verificaresposta();
    }
  }
  int strlen(char *str){
    int i=0;
      while (str[i]!='\0'){
          i++;
      }
      return i;
}
string strings(){
    // Pega o nome e coloca em um buffer
    char buffer[MAX_SIZE];
    fgets(buffer, MAX_SIZE, stdin);

    // Descobre o tamanho da string (contando o \0)
    int tam = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        tam++;
        // Chegou no final da string, sai do loop
        if ((buffer[i] == '\r') || (buffer[i] == '\n') || (buffer[i] == '\0')) {
            buffer[i] = '\0';
            break;
        }
    }
    fflush(stdin);

    // Aloca espaço pro nome
    char* nome = malloc(tam * sizeof(char));

    // Copia do buffer, pro nome
    for (int i = 0; i < tam; ++i) {
        nome[i] = buffer[i];
    }
    return nome;
}
void printmenu(void){
    printf("- - - - - - - - - - - - - - - - - - - - \n");
    printf("informe ate qual etapa voce foi durante o seu tempo na instituicao:\n");
    printf("0 - se foi embora ou nao foi a intituicao\n");
    printf("1 - triagem da enfermagem\n");
    printf("2 - consulta medica\n");
    printf("3 - tomou medicacao\n");
    printf("4 - ficou em observacao\n");
    printf("- - - - - - - - - - - - - - - - - - - - \n");
}
int validamenu(int etapa){
    int opcoes[5]={0,1,2,3,4};
    for (int i = 0; i < 5; ++i) {
        if(etapa==opcoes[i]){
            return 1;
        }
    }
    return 0;
}
int selectmenu(void) {
    int op;
        printf("Digite a opcao: ");
        scanf(" %i", &op);
        if (!validamenu(op)) {
            printf("Opcao invalida\n\n");
            printmenu();
            selectmenu();
        }
        return op;
}
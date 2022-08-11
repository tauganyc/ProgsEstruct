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

void viasmedicamento(){
    printf("as principais vias de aplicacao sao:\n");
    printf("Oral\nSublingual\nintravenosa\nintramuscular\nsubcutanea\nrespiratoria\ntopica\nOcular\nnazal\nauricular\n");
}
void escolha(){
    printf("digite 1 para sim e 0 para nao");
}
double somadosvaloressus(int a,int via){
    double totalsus;
    totalsus=0;
    double sus[2]={11.30,0.63};
        sus[1]=sus[1]*via;
    for(int i=0;i<a;i++){
        totalsus=totalsus+sus[i];
    }
    return totalsus;

}
double somadosvaloresprivado(int a){
    double totalprivado;
    totalprivado=0;
    double privado[2]={100.00,200.00};
    for(int i=0;i<a;i++){
        totalprivado=totalprivado+privado[i];
    }
    return totalprivado;
}
double verificapergunta(int mark,int vias){
    int modificador = -1;
    double totalSUS;
    while (modificador != 1 || modificador != 0) {
        escolha();
        scanf("%i", &modificador);
        if (modificador == 1) {
            totalSUS = somadosvaloressus(mark, vias);
            printf("%lf\n", totalSUS);
            return totalSUS;
        }
        else if(modificador==0) {
            return 0;
        }
        else { printf("digite o valor correto\n") ;}
    }
}
int verificaresposta(){
    int x=-1;
    printf("digite 1 para sim e 0 para não\n");
    scanf("%i",&x);
    if(x==1||x==0){
        return x;
    }
    while(x!=1||x!=0){
        printf("digite um valor valido\n");
        scanf("%i",&x);
        if(x==1||x==0){
            return x;
        }
    }
  }
  int strlen(char *str){
    int i=0;
      while (str[i]!='\0'){
          i++;
      }
      return i;
}
string stringalocada(){
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
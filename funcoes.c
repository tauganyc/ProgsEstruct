//
// Created by taugany on 04/07/22.
//

#include <stdio.h>
#include <malloc.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
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
        return aplicado();
    }
}
void viasmedicamento(){
    printf("as principais vias de aplicacao sao:\n");
    printf("Oral\nSublingual\nintravenosa\nintramuscular\nsubcutanea\nrespiratoria\ntopica\nOcular\nnazal\nauricular\n");
}
float somadosvaloressus(int opcao,int vias,float* valoressus){
    float totalsus;
    totalsus=0;
    for(int i=0;i<opcao;i++){
        totalsus=totalsus+valoressus[i];
    }
    return totalsus;

}
int verificaresposta(){
    int x;
    scanf("%i",&x);
    if(x==1||x==0){
        return x;
    }
    else{
        printf("digite um valor valido\n");
        return verificaresposta();
    }
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
            return selectmenu();
        }
        return op;
}
int valorinstituicao(float* valoressus, string hospital){
    int valor[4];
    float totalvalor;
    totalvalor=0;
    printf("Digite a quantidade de triagens: ");
    scanf("%i",&valor[0]);
    printf("Digite a quantidade de consultas medicas: ");
    scanf("%i",&valor[1]);
    printf("Digite a quantidade de administracoes de medicamento: ");
    scanf("%i",&valor[2]);
    printf("Digite a quantidade de consultas com observacao: ");
    scanf("%i",&valor[3]);

    for(int i=0;i<4;i++){
        valoressus[i]=valoressus[i]*valor[i];
        totalvalor=totalvalor+valoressus[i];
    }
    printf("Nome da instituicao: %s\n", hospital);
    printf("Triagens = %.2lf\n",valoressus[0]);
    printf("Consultas medicas = %.2lf\n",valoressus[1]);
    printf("Administracoes de medicamento = %.2lf\n",valoressus[2]);
    printf("Consultas com observacao = %.2lf\n",valoressus[3]);
    printf("Total a receber = %.2lf",totalvalor);
    char* diretorio=strcat("\\instituicao\\",hospital);
    char* triagens=strcat("triagens = ",valor[0]);
    string consultasmedicas=strcat("consultas medicas = ",valor[1]);
    string administracoesmedicamento=strcat("administracoes de medicamento = ",valor[2]);
    string consultasobservacao=strcat("consultas com observacao = ",valor[3]);
    string totalreceber=strcat("total a receber = ",totalvalor);
    saveFile(diretorio,triagens);
    saveFile(diretorio,consultasmedicas);
    saveFile(diretorio,administracoesmedicamento);
    saveFile(diretorio,consultasobservacao);
    saveFile(diretorio,totalreceber);
    return 0;

}


void createDir(char *path) {
    struct stat st = {0};
    if (stat(path, &st) == -1) {
        mkdir(path, 0700);
    }
}

int saveFile(char *path, char *data) {
    FILE *file;
    if ((file = fopen(path, "a")) == NULL) {
        file = fopen(path, "w");
    }
    file=fopen(path,"a");
    fprintf(file, "%s", data);
    fclose(file);
}

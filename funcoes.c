//
// Created by taugany on 04/07/22.
//

#include <stdio.h>
#include "funcoes.h"
float soma(a,b){
    return a+b;
}
void escolha(){
    printf("digite 1 para sim e 0 para não");
}
double somadosvalores(){
    double totalsus,totalprivado;
    totalsus=0;
    totalprivado=0;
    double sus[2]={10.00,20.00};
    double privado[2]={100.00,200.00};
    for(int i=0;i<mark;i++){
        totalsus=totalsus+sus[i];
        totalprivado=totalprivado+privado[i];
    }
    return totalsus,totalprivado,totalsus+totalprivado;
}

#include <stdio.h>
#include "lib.h"

int main() {
    int a,mark;
    printf("Voce passou por uma consulta?\n");
    escolha();
    scanf("%i",&a);
    if (a == 1) {
        mark=1;
        double d,e,f;
        somadosvalores(d, e, f);
        printf("%lf",d);
    }

    else if (a == 0) {
        printf("então você não passou por uma unidade de saude privada ou publica\n");
    } else {
        printf("digite o valor correto\n");
    }
    return 0;
}

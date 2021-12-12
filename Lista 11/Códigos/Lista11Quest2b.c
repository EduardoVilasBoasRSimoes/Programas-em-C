#include <stdio.h>

int Divisores(int numero){
    if(numero - (numero%10)*2 < 100){
        return numero - (numero%10)*2;
    }
    return Divisores((numero - (numero%10)*2)/10);
}

int main(){
    int Numero;
    scanf("%d", &Numero);
    if(Divisores(Numero)%7 == 0){
        printf("Eh divisor de 7");
    } else {
        printf("Nao eh divisor de 7");
    }
    return 0;
}

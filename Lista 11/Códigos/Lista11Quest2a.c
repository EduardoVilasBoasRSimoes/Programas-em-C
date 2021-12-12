#include <stdio.h>

int L[1000];
int Divs;

int Pares(int I, int F){
    if(I > F){
        return 0;
    } else if(I == F){
        return L[F];
    }
    return Pares(I + 2, F) + L[I];
}

int Impares(int I, int F){
    if(I > F){
        return 0;
    } else if(I == F){
        return L[F];
    }
    return Impares(I + 2, F) + L[I];
}

void Divisores(int N){
    if((Pares(0, N - 1) - Impares(1, N - 1)) % 11 == 0){
        Divs = 1;
    } else {
        Divs = 0;
    }
}

void vetorizar(int Numero, int N){
    int i = N - 1;
    while(Numero > 0){
        L[i] = Numero%10;
        Numero = Numero/10;
        i--;
    }

}

int main(){
    int Numero, N;
    scanf("%d", &N);
    scanf("%d", &Numero);
    vetorizar(Numero, N);
    Divisores(N);
    if(Divs == 1){
        printf("Eh divisor de 11");
    } else {
        printf("Nao eh divisor de 11");
    }
    return 0;
}

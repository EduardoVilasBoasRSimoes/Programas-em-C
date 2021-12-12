#include <stdio.h>

#define N 4

struct racional {
    int num, den;
};

struct racional R[N] = {
    {2, 3},
    {9, 7},
    {5, 14},
    {23, 17}
};

struct racional S[N];

int maior (struct racional r1, struct racional r2){
    int O;
    O = r1.den*r2.den;
    return r1.num*(O/r1.den);
}

int comparaR(struct racional r1, struct racional r2){
    if(maior(r1, r2) == maior(r2, r1)){
        return 0;
    } else if(maior(r1, r2) > maior(r2, r1)){
        return 1;
    } else if(maior(r2, r1) < maior(r2, r1)){
        return -1;
    }
}

void ordenar_struct(){
    int i, j, A;
    for(i = 0; i < N; i++){
        A = 0;
        for(j = 0; j < N; j++){
            if(comparaR(R[i], R[j]) == 1){
                A++;
            }
        }
        S[A] = R[i];
    }
    for(i = 0; i < N; i++){
        R[i] = S[i];
    }
}

void imprimir(){
    int i;
    for(i = 0; i < N; i++){
        printf("%4d ", R[i].num);
    }
    printf("\n");
    for(i = 0; i < N; i++){
        printf("%4d ", R[i].den);
    }
    printf("\n\n");
}

int main(){
    imprimir();
    ordenar_struct();
    imprimir();
}

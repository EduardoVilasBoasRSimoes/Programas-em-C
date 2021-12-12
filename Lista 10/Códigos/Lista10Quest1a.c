#include <stdio.h>

#define N 10

int L[N];

void inicio(){
    int i;
    srand(1);
    for(i = 0; i < N; i++){
        L[i] = rand() % 100 + 1;
    }
}

void pos_aleatoria(int i){
    int pos, aux;
    srand(i);
    pos = rand() % 10;
    aux = L[0];
    L[0] = L[pos];
    L[pos] = aux;
}

int main(){
    int i;
    inicio();
    for(i = 0; i < N; i++){
        printf("%4d ", L[i]);
    }
    printf("\n\n");
    for(i = 0; i < 1000; i++){
        pos_aleatoria(i);
    }
    for(i = 0; i < N; i++){
        printf("%4d ", L[i]);
    }
}

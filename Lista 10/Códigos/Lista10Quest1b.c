#include <stdio.h>

#define N 10

int L[N], A[N];

void inicio(){
    int i;
    srand(1);
    for(i = 0; i < N; i++){
        L[i] = rand() % 100 + 1;
    }
}

void pos_aleatoria(int i){
    int pos, aux, j, k = 0;
    srand(i);
    pos = rand() % 10;
    for(j = pos; j < N; j++){
        A[k] = L[j];
        k++;
    }
    for(j = 0; j < pos; j++){
        A[k] = L[j];
        k++;
    }
    for(j = 0; j < N; j++){
        L[j] = A[j];
    }
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


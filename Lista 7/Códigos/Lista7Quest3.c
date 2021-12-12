#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20000

int L[N];
int L1[N/2];
int L2[N/2];

void inicializacao(int n){
    int i, j = 0;
    for(i = n - 1; i >= 0; i--){
        L[i] = j;
        j++;
    }
}

int main(){
    int i, j, k, A, B, aux = 0;
    clock_t t1, t2;
    i = 0;
    t1 = clock();
    inicializacao(N);
    while(i < N/2){
        j = 0;
        A = 0;
        B = 0;
        while(j < N/2){
            if(L[i] > L[j]){
                A++;
            }
            if(L[i + N/2] > L[j + N/2]){
                B++;
            }
            j++;
        }
        L1[A] = L[i];
        L2[B] = L[i + N/2];
        i++;
    }
    i = 0;
    while(i < N/2){
        aux = 0;
        for(j = 0; j < N/2; j++){
            if(L1[i] > L1[j]){
                aux++;
            }
            if(L1[i] > L2[j]){
                aux++;
            }
        }
        L[aux] = L1[i];
        aux = 0;
        for(j = 0; j < N/2; j++){
            if(L2[i] > L2[j]){
                aux++;
            }
            if(L2[i] > L1[j]){
                aux++;
            }
        }
        L[aux] = L2[i];
        i++;
    }
    for(i = 0; i < N; i++){
        printf("%d ", L[i]);
    }
    t2 = clock();
    printf("\nTempo de execucao do metodo da intercalacao: %lu", t2 - t1);

}

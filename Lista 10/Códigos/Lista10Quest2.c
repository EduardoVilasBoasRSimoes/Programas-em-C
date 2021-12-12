#include <stdio.h>
#include <time.h>

#define N 10000

int L[N];

void iniciar(){
    int i, x = 0;
    for(i = 0; i < N; i++){
        x = x + rand() % 100;
        L[i] = x;
    }
}

int buscar(int x, int n){
    int i;
    i = 0;
    while(L[i] != x && i < n){
        i++;
    }
    if(i == n){
        printf("%d nao esta na lista\n\n", x);
    } else {
        printf("%d esta na posicao %d da lista\n\n", x, i);
    }
}

void inserir(int x, int n){
    int i = 0, j;
    while(L[i] < x && i < n){
        i++;
    }
    for(j = n; j >= i; j--){
        L[j + 1] = L[j];
    }
    L[i] = x;
}

void remover(int x, int n){
    int i = 0, j;
    while(L[i] != x && i < n){
        i++;
    }
    if(i == n - 1){
        for(j = i; j < n; j++){
            L[j] = L[j + 1];
        }
    } else {
        printf("%d nao esta na lista\n\n", x);
    }
}

void imprimir(int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%4d ", L[i]);
    }
    printf("\n\n");
}

int main(){
    int x;
    clock_t t1, t2;
    t1 = clock();
    iniciar();
    imprimir(N);
    buscar(7, N);
    inserir(7, N);
    remover(12, N + 1);
    imprimir(N);
    t2 = clock();
    printf("%lu", t2 - t1);
}

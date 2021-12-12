#include <stdio.h>
#include <time.h>

#define M 100
#define N 100

int L[M][N], I[M], A, B;

void inicializar(){
    int i, j;
    for(i = 0; i < M; i++){
        srand(i);
        for(j = 0; j < N; j++){
            L[i][j] = rand() % 100 + 1;
        }
    }
}

void inicializarI(){
    int i;
    for(i = 0; i < M; i++){
        I[i] = N - 1;
    }
}

int menorI(){
    int i, menor = 1000, C;
    for(i = 0; i < M; i++){
        if(I[i] < menor){
            menor = I[i];
            C = i;
        }
    }
    return C;
}

//-----------------------------------------

void ordenar_listas(){
    int i;
    for(i = 0; i < M; i++){
        ordenar(i);
    }
}

void ordenar(int Eme){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = N - 1; j > 0; j--){
            if(L[Eme][j - 1] > L[Eme][j]){
                trocar(Eme, j, j - 1);
            }
        }
    }
}

void trocar(int Eme, int T1, int T2){
    int aux;
    aux = L[Eme][T1];
    L[Eme][T1] = L[Eme][T2];
    L[Eme][T2] = aux;
}

//-----------------------------------------



int buscar(int x){
    int i, j;
    for(i = 0; i < M; i++){
        for(j = 0; j <= I[i]; j++){
            if(L[i][j] == x){
                A = i;
                B = j;
                return 1;
            }
        }
    }
    return 0;
}

//-----------------------------------------

void inserir(int x){
    int i, j;
    if(buscar(x) == 0){
        i = menorI();
        for(j = 0; j <= I[i]; j++){
            if(L[i][j] > x){
                deslocarI(i, j);
                I[i]++;
                L[i][j] = x;
                break;
            } else if(j == I[i]){
                I[i]++;
                L[i][j + 1] = x;
                break;
            }
        }
    } else {
        printf("%d ja esta na lista\n\n", x);
    }
}

void deslocarI(int i, int j){
    int k;
    for(k = I[i]; k >= j; k--){
        L[i][k + 1] = L[i][k];
    }
}

//-----------------------------------------

void remover(int x){
     int j;
    if(buscar(x) == 1){
        deslocarR(A, B);
        I[A]--;
    } else {
        printf("%d nao esta na lista\n\n", x);
    }
}

void deslocarR(int i, int j){
    int k;
    for(j = B; j <= I[A]; j++){
        L[A][j] = L[A][j + 1];
    }
}

//-----------------------------------------

void imprimir(){
    int i, j;
    for(i = 0; i < M; i++){
        for(j = 0; j <= I[i]; j++){
            printf("%d ", L[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

//-----------------------------------------

int main(){
    clock_t t1, t2;
    t1 = clock();
    inicializar();
    inicializarI();
    imprimir();
    ordenar_listas();
    inserir(10);
    remover(17);
    imprimir();
    t2 = clock();
    printf("%lu", t2 - t1);
}


// A lista ordenada, para realizar as mesmas operações com uma lista de tamanho 10000, faz em 798,
// enquanto a lista de listas, M = 100 e N = 100, faz em 638


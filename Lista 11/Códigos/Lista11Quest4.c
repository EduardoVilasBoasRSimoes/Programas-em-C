#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20000

int A[N];

void inicializacao(int n){
    int i, j = 0;
    for(i = n - 1; i >= 0; i--){
        A[i] = j;
        j++;
    }
}

void particiona(int I, int F){
    int i, j, x = A[I], aux, n, o = 0;
    for(i = I + 1; i < F; i++){
        if(x >= A[i]){
            n = A[i];
            for(j = i; j > I; j--){
                A[j] = A[j - 1];
            }
            A[I] = n;
            o++;
        }
    }
    if(o != 0 && o != F - 1){
        particiona(I, o);
        particiona(o + 1, F);
    } else if(F >= 2 && I < F){
        if(o == F - 1 && o != 0){
            particiona(I, o);
        } else if(o == 0 && o != F - 1){
            particiona(I + 1, F);
        }
    }
}

int main(){
    clock_t t1, t2;
    int i;
    double time;
    t1 = clock();
    inicializacao(N);
    printf("\n\n");
    particiona(0, N);
    printf("\n\n");
    for(i = 0; i < N; i++){
        printf("%d ", A[i]);
    }
    t2 = clock();
    printf("\nTempo de execucao do metodo quicksort: %lu", t2 - t1);
}

// Para N = 20000, o método quick sort faz no tempo 1.231 s e o método da
// intercalação, programa da questão 3 da lista 7, faz no tempo 1.207 s;

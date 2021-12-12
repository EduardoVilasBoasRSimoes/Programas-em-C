#include <stdio.h>
#define N 10

int A[N] = {1, 2, 3, 4, 6, 7, 0, 0, 0, 0};
int x = 5;

void inserir(int I, int F, int x){
    int i, O = 0;
    if(x >= A[I]){
        if(x < A[I + 1]){
            for(i = F; i >= I + 1; i--){
                A[i + 1] = A[i];
            }
            A[I + 1] = x;
            O = 1;
        }
    }
    if(x < A[I]){
        for(i = F; i >= I; i--){
                A[i + 1] = A[i];
            }
            A[I] = x;
            O = 1;
    }
    if(O == 0){
        inserir(I + 1, F, x);
    }
}

int main(){
    int i = N - 1, F;
    while(A[i] == 0){
        i--;
    }
    F = i;
    inserir(0, F, x);
    for(i = 0; i < N; i++){
        printf("%d ", A[i]);
    }
}

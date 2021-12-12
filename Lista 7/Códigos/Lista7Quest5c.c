#include <stdio.h>

int main(){
    int L[10] = {1, 4, 7, 8, 3, 9, 10, 5, 2, 6};
    int i, j, aux, N = 10;
    for(i = 0; i < N - 1; i++){
        for(j = N - 1; j >= i + 1; j--){
            if(L[j] % 2 == 0){
                aux = L[j];
                L[j] = L[j - 1];
                L[j - 1] = aux;
            }
        }
    }
    for(i = 0; i < N - 1; i++){
        for(j = N - 1; j >= i + 1; j--){
            if(L[j] < L[j - 1] && L[j] % 2 == 0){
                aux = L[j];
                L[j] = L[j - 1];
                L[j - 1] = aux;
            }
        }
    }
    for(i = 0; i < N - 1; i++){
        for(j = N - 1; j >= i + 1; j--){
            if(L[j] % 2 == 1){
                aux = L[j];
                L[j] = L[j - 1];
                L[j - 1] = aux;
            }
        }
    }
    for(i = 0; i < N - 1; i++){
        for(j = N - 1; j >= i + 1; j--){
            if(L[j] < L[j - 1] && L[j] % 2 == 1){
                aux = L[j];
                L[j] = L[j - 1];
                L[j - 1] = aux;
            }
        }
    }
    for(i = 0; i < N; i++){
        printf("%d  ", L[i]);
    }
}

#include <stdio.h>

int main(){
    int L[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, j, aux, N = 10;
    for(i = 0; i < N - 1; i++){
        for(j = N - 1; j >= i + 1; j--){
            if(L[j] % 3 == 0){
                aux = L[j];
                L[j] = L[j - 1];
                L[j - 1] = aux;
            }
        }
    }
    for(i = 0; i < N - 1; i++){
        for(j = N - 1; j >= i + 1; j--){
            if(L[j] < L[j - 1] && L[j] % 3 == 0){
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

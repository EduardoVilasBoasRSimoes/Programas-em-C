#include <stdio.h>

int main(){
    int L1[10] = {3, 1, 2, 5, 4, 7, 6, 8, 10, 12};
    int L2[10] = {15, 9, 11, 14, 13, 18, 16, 17, 20, 19};
    int L[20];
    int i, j, k, aux = 0, N = 10;
    i = 0;
    while(i < N){
        aux = 0;
        for(j = 0; j < N; j++){
            if(L1[i] > L1[j]){
                aux++;
            }
            if(L1[i] > L2[j]){
                aux++;
            }
        }
        L[aux] = L1[i];
        aux = 0;
        for(j = 0; j < N; j++){
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
    for(k = 0; k < 2*N; k++){
        printf("%d ", L[k]);
    }
}

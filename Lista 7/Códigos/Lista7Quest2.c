#include <stdio.h>

int main(){
    int L[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int i, x, A, N = 15;
    i = 0;
    while(i < N){
        x = rand() % 2;
        if(x == 0 && i != 0){
            A = L[i - 1];
            L[i - 1] = L[i];
            L[i] = A;
        } else if(x == 1 && i != N - 1){
            A = L[i + 1];
            L[i + 1] = L[i];
            L[i] = A;
        } else if(x == 0 && i == 0){
            A = L[N - 1];
            L[N - 1] = L[i];
            L[i] = A;
        } else if(x == 1 && i == N - 1){
            A = L[0];
            L[0] = L[i];
            L[i] = A;
        }
        i++;
    }
    for(i = 0; i < N; i++){
        printf("%d  ", L[i]);
    }
}

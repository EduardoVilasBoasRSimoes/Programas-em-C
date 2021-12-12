#include <stdio.h>

int main(){
    int L[10] = {14, 8, 10, 16, 20, 200, 7, 15, 9, 1, 14};
    int M[10];
    int i, x, A, B, aux, N = 10;
    scanf("%d", &x);
    i = 0;
    A = 0;
    B = N - 1;
    while(i < N){
        if(L[i] < x){
            M[A] = L[i];
            A++;
        } else if(L[i] > x){
            M[B] = L[i];
            B--;
        } else {
            aux = L[i];
        }
        i++;
    }
    M[A] = aux;
    for(i = 0; i < N; i++){
        printf("%d  ", M[i]);
    }
}

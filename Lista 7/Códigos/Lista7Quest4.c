#include <stdio.h>

int main(){
    int L[10] = {14, 8, 10, 16, 20, 200, 7, 15, 9, 1};
    int N[10];
    int i, j, x, A, B, a, aux;
    int O = 10;
    scanf("%d", &x);
    i = 0;
    A = 0;
    B = 9;
    while(i < O){
        if(L[i] < x){
            N[A] = L[i];
            A++;
        } else if(L[i] > x){
            N[B] = L[i];
            B--;
        } else {
            aux = L[i];
        }
        i++;
    }
    if(aux == x){
        N[A] = aux;
    }
    for(i = 0; i < A; i++){
        a = 0;
        for(j = 0; j < A; j++){
            if(N[i] > N[j]){
                a++;
            }
        }
        L[a] = N[i];
    }
    for(i = A; i < O; i++){
        a = 0;
        for(j = A; j < O; j++){
            if(N[i] > N[j]){
                a++;
            }
        }
        L[a + A] = N[i];
    }
    for(i = 0; i < O; i++){
        printf("%d  ", L[i]);
    }
}

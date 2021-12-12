#include <stdio.h>

int main(){
    int L[14] = {15, 9, 12, 24, 21, 14, 11, 8, 17, 43, 91, 4, 20, 15};
    int i, j, A = 0, B = 0, N = 14, aux = 0;
    for(i = 0; i < N; i++){
        if(L[i] < L[i + 1] || i == N - 1){
            if(A == 0){
                B = 1;
            } else {
                A = 0;
                for(j = i; j >= aux; j--){
                    printf("%d ", L[j]);
                }
                aux = i + 1;
                printf("\n");
                if(aux == N - 1){
                    printf("%d", L[N - 1]);
                }
            }
        } else if(L[i] > L[i + 1] || i == N - 1){
            if(B == 0){
                A = 1;
            } else {
                B = 0;
                for(j = i; j >= aux; j--){
                    printf("%d ", L[j]);
                }
                aux = i + 1;
                printf("\n");
                if(aux == N - 1){
                    printf("%d", L[N - 1]);
                }
            }
        }
    }
}

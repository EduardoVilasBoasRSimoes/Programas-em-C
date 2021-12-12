#include <stdio.h>

int main(){
    int L[14] = {15, 9, 12, 24, 21, 14, 11, 8, 17, 43, 91, 4, 20, 15};
    int i, A = 0, B = 0, N = 14;
    for(i = 0; i < N; i++){
        if(L[i] < L[i + 1]){
            if(A == 0){
                printf("%d ", L[i]);
                B = 1;
            } else {
                printf("%d", L[i]);
                printf("\n");
                A = 0;
            }
        } else if(L[i] > L[i + 1]){
            if(B == 0){
                printf("%d ", L[i]);
                A = 1;
            } else {
                printf("%d", L[i]);
                printf("\n");
                B = 0;
            }
        }
    }
}

#include <stdio.h>

int main(){
    int L[10] = {0, 2, 0, 0, 0, 2, 1, 2, 1, 2};
    int i = 0, A = 0, B = 0, C = 0;
    while(i < 10){
        if(L[i] == 0){
            A++;
        } else if(L[i] == 1){
            B++;
        } else {
            C++;
        }
        i++;
    }
    for(i = 0; i < A; i++){
        L[i] = 0;
    }
    for(i = A; i < A + B; i++){
        L[i] = 1;
    }
    for(i = A + B; i < A + B + C; i++){
        L[i] = 2;
    }
    for(i = 0; i < 10; i++){
        printf("%d  ", L[i]);
    }
}

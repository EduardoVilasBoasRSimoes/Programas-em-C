#include <stdio.h>

int main(){
    int L[20] = {2, 1, 3, 1, 5, 6, 1, 1, 9, 1, 1, 34, 15, 1, 1, 6, 7, 3, 8, 1};
    int i, j, x, A, aux = 0;
    scanf("%d", &x);
    i = 0;
    while(i < 20){
        if(L[i] == x){
            A = L[aux];
            L[aux] = L[i];
            L[i] = A;
            aux++;
        }
        i++;
    }
    for(j = 0; j < 20; j++){
        printf("%d ", L[j]);
    }
}

#include <stdio.h>

int main(){
    int L[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pos, x, i, j, A, aux;
    scanf("%d %d", &pos, &x);
    L[pos] = x;
    i = 0;
    while(i < 10){
        A = 0;
        for(j = 0; j < 10; j++){
            if(L[i] > L[j]){
                A++;
            }
        }
        aux = L[A];
        L[A] = L[i];
        L[i] = aux;
        i++;
    }
    for(i = 0; i < 10; i++){
        printf("%d  ", L[i]);
    }
}

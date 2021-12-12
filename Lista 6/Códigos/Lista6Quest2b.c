#include <stdio.h>

int main(){
    int L[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, j, x;
    scanf("%d", &x);
    i = 0;
    while(i < 10){
        for(j = i + 1; j < 10; j++){
            if(L[i] + L[j] == x){
                printf("%d e %d\n", L[i], L[j]);
            }
        }
        i++;
    }
}

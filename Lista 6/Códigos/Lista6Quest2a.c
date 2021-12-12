#include <stdio.h>

int main(){
    int L[10] = {1, 2, 5, 10, 30, 60, 240, 480, 6, 1000};
    int i, j;
    i = 0;
    while(i < 10){
        for(j = 0; j < 10; j++){
            if(L[i]*2 == L[j]){
                printf("%d\n", L[i]);
            }
        }
        i++;
    }
}

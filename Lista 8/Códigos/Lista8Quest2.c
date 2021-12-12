#include <stdio.h>

int main(){
    int A[3][3] = {{1, 3, 6},
                    {2, 7, 8},
                    {3, 6, 2}};
    int i, j, aux, B = 0, det = 0;
    for(i = 0; i < 3; i++){
        aux = 1;
        for(j = 0; j < 3; j++){
            aux *= A[j][B];
            if(B == 2){
                B = 0;
            } else{
                B++;
            }
        }
        B++;
        det += aux;
    }
    B = 0;
    for(i = 0; i < 3; i++){
        aux = 1;
        for(j = 0; j < 3; j++){
            aux *= A[j][B];
            if(B == 0){
                B = 2;
            } else{
                B--;
            }
        }
        B++;
        det -= aux;
    }
    printf("%d", det);
}

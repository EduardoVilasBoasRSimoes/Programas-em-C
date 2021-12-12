#include <stdio.h>

int main(){
    int A[4][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}};
    int E[3][3];
    int i, j, k, aux, aux1 = 0, B = 1, C, D, det = 0, DET = 0;
    for(k = 0; k < 4; k++){
        C = 0;
        for(i = 0; i < 4; i++){
            D = 0;
            if(i != 0){
                for(j = 0; j < 4; j++){
                    if(j != aux1){
                        E[C][D] = A[i][j];
                        D++;
                    }
                }
                C++;
            }
        }
        B = 0;
        det = 0;
        for(i = 0; i < 3; i++){
            aux = 1;
            for(j = 0; j < 3; j++){
                aux *= E[j][B];
                if(B == 2){
                    B = 0;
                } else {
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
                aux *= E[j][B];
                if(B == 0){
                    B = 2;
                } else {
                    B--;
                }
            }
            B++;
            det -= aux;
        }
        if(k == 0 || k == 2){
            DET += det*A[0][aux1];
        } else {
            DET -= det*A[0][aux1];
        }
        aux1++;
    }
    printf("%d", DET);
}

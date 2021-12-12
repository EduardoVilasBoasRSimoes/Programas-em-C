#include <stdio.h>

int main(){
    double A[2][2] = {{1, 2},
                    {3, 4}};
    double B[2][3];
    double C[2][3];
    int i, j;
    double x, y, z, w;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            if(j != 2){
                B[i][j] = A[i][j];
                C[i][j] = A[i][j];
            } else {
                if(i == 0){
                    B[i][j] = 1;
                    C[i][j] = 1;
                } else {
                    B[i][j] = 0;
                    C[i][j] = 0;
                }
            }
        }
    }
    for(j = 0; j < 3; j++){
        if(B[1][0] != 0){
            C[1][j] = C[1][j] * (-1)*B[0][0]/B[1][0];
            C[1][j] += B[0][j];
        } else {
            C[1][j] = B[1][j];
        }
    }
    z = C[1][2]/C[1][1];
    x = (1 - C[0][1]*z)/C[0][0];
    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            if(j != 2){
                B[i][j] = A[i][j];
                C[i][j] = A[i][j];
            } else {
                if(i == 0){
                    B[i][j] = 0;
                    C[i][j] = 0;
                } else {
                    B[i][j] = 1;
                    C[i][j] = 1;
                }
            }
        }
    }
    for(j = 0; j < 3; j++){
        if(B[1][0] != 0){
            C[1][j] = C[1][j] * (-1)*B[0][0]/B[1][0];
            C[1][j] += B[0][j];
        } else {
            C[1][j] = B[1][j];
        }
    }
    w = C[1][2]/C[1][1];
    y = (- C[0][1])*w/C[0][0];
    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
}

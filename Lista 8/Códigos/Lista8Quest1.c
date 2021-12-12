#include <stdio.h>

int main(){
    int M, N, i, j, k, aux = 0;
    scanf("%d%d", &M, &N);
    int A[M][N], B[N][M], C[M][M];
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            A[i][j] = i + j + 1;
            B[j][i] = i + 1;
        }
    }
    for(i = 0; i < M; i++){
        for(j = 0; j < M; j++){
            aux = 0;
            for(k = 0; k < N; k++){
                 aux = aux + A[i][k] * B[k][j];
            }
            C[i][j] = aux;
        }
    }
    for(i = 0; i < M; i++){
        for(j = 0; j < M; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

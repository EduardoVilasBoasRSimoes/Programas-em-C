#include <stdio.h>

int main(){
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int det;
    det = (A[1][1]*A[2][2] - A[1][2]*A[2][1])*A[0][0] - (A[1][0]*A[2][2] - A[1][2]*A[2][0])*A[0][1] + (A[1][0]*A[2][1] - A[1][1]*A[2][0])*A[0][2];
    printf("%d", det);
}

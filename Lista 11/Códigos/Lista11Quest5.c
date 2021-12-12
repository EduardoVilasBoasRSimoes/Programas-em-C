#include <stdio.h>

#define N 10

void Move_from_A(int n){
    printf("Mover disco %d de A para C\n", n);
}

void Move_to_B(int I, int n){
    if(I < n - 1){
        printf("%d, ", I);
        Move_to_B(I+1, n);
    } else if(I == n - 1){
        printf("%d ", I);
        Move_to_B(I+1, n);
    }
}

void Move_to_C(int I, int n){
    if(I < n - 1){
        printf("%d, ", I);
        Move_to_C(I+1, n);
    } else if(I == n - 1){
        printf("%d ", I);
        Move_to_C(I+1, n);
    }
}

int main(){
    printf("Mover discos ");
    Move_to_B(1, N);
    printf("de A para B (Com o auxilio de C)\n");
    Move_from_A(N);
    printf("Mover discos ");
    Move_to_C(1, N);
    printf("de B para C (Com o auxilio de A)\n");
}

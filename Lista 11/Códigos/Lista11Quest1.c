#include <stdio.h>

int Fibonacci(int n){
    if(n == 0){
        return 0;
    } else if(n == 1){
        return 1;
    }
    return Fibonacci(n - 2) + Fibonacci(n - 1);
}

int main(){
    int N;
    scanf("%d", &N);
    printf("%d", Fibonacci(N));
}

// O maior número de Fibonacci que consigo calcular no meu
// programa é quando N = 46, ou seja, 1836311903

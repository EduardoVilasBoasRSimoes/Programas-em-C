#include <stdio.h>

struct racional {
    int num, den;
};

struct racional R;

struct racional somaR (struct racional r1, struct racional r2){
    R.den = r1.den*r2.den;
    R.num = r1.num*(R.den/r1.den) + r2.num*(R.den/r2.den);
}

struct racional subtracaoR (struct racional r1, struct racional r2){
    R.den = r1.den*r2.den;
    R.num = r1.num*(R.den/r1.den) - r2.num*(R.den/r2.den);
}

struct racional multiplicacaoR (struct racional r1, struct racional r2){
    R.num = r1.num*r2.num;
    R.den = r1.den*r2.den;
}

struct racional divisaoR (struct racional r1, struct racional r2){
    R.num = r1.num*r2.den;
    R.den = r1.den*r2.num;
}

struct racional simplificaR (struct racional r1, struct racional r2){
    int mdc1 = MDC(r1.num, r1.den), mdc2 = MDC(r2.num, r2.den);
    r1.den /= mdc1;
    r2.den /= mdc2;
    r1.num /= mdc1;
    r2.num /= mdc2;
    printf("%4d %4d\n", r1.num, r2.num);
    printf("%4d %4d\n\n", r1.den, r2.den);
}

int MDC(a, b){
    if(b == 0){
        return a;
    }
    return MDC(b, a%b);
}

void imprimir_termos(struct racional r1, struct racional r2){
    printf("%4d %4d\n", r1.num, r2.num);
    printf("%4d %4d\n\n", r1.den, r2.den);
}

void imprimir_result(struct racional r1){
    printf("%4d\n", r1.num);
    printf("%4d\n\n", r1.den);
}

int main(){
    struct racional r1;
    r1.num = 12;
    r1.den = 24;
    struct racional r2;
    r2.num = 6;
    r2.den = 13;
    imprimir_termos(r1, r2);
    somaR(r1, r2);
    imprimir_result(R);
    subtracaoR(r1, r2);
    imprimir_result(R);
    multiplicacaoR(r1, r2);
    imprimir_result(R);
    divisaoR(r1, r2);
    imprimir_result(R);
    simplificaR(r1, r2);
}

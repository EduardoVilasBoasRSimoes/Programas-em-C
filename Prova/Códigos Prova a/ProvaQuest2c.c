#include <stdio.h>

void Multiplos_de_k(int k, int i){  //Fun��o recursiva que ir� imprimir os mult�plos de k.
    if(i == 0){                     // Quando chegar a 0, sair da fun��o.
        return;
    }
    if(i % k == 0){                 // imprimir na tela os numeros multiplos de k.
        printf("%d ", i);
    }
    Multiplos_de_k(k, i - 1);       // Chamar denovo a fun��o para i - 1 (obs: quando chegar em 0, ele para).
}

int main(){
    int k;
    scanf("%d", &k);                // Inserir o valor de k.
    Multiplos_de_k(k, 100);         // Chamar a fun��o come�ando com i = 100;
}


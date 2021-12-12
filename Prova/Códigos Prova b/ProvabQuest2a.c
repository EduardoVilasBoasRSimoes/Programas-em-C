#include <stdio.h>
#include <string.h>
#define N 8
#define M 9

struct pessoa{
    char nome[50];
    int codigo;
};

struct amizade{
    int cod1;
    int cod2;
};

struct pessoa P[N] = { {"maria", 27},  // Vetor Struct Exemplo.
                       {"pedro", 17},
                       {"ana", 14},
                       {"ivo", 31},
                       {"maria", 11},
                       {"juca", 44},
                       {"bia", 28},
                       {"pedro", 51} };

struct amizade A[M] = { {17, 27},   // Vetor Struct Exemplo.
                        {27, 11},
                        {31, 14},
                        {28, 31},
                        {44, 51},
                        {14, 44},
                        {28, 27},
                        {51, 17},
                        {44, 28} };

int Amigos[M], k = 0; // Vetor Amigos guardar� os codigos que tem amizade com o n�mero inserido na Main e k auxiliar� nas suas posi��es.

void Achar_Amigos(int n){   // Fun��o que, dado um n�mero pela Main, procura suas correspond�ncias no vetor struct amizade A.cod1 e A.cod2,
    int i;                 // de modo que guarda os valores amigos no vetor Amigos.
    for(i = 0; i < M; i++){
        if(n == A[i].cod1){
            Amigos[k] = A[i].cod2;
            k++;
        } else if(n == A[i].cod2){
            Amigos[k] = A[i].cod1;
            k++;
        }
    }
}

void Imprimir_Nome(int n){ // Baseado no n�mero dado pela Main, essa fun��o imprime o nome correspondente a esse valor no vetor struct pessoa P
    int i;
    for(i = 0; i < N; i++){
        if(n == P[i].codigo){
            printf("%s: ", P[i].nome);
        }
    }
}

void Imprimir_Amigos(){  // Baseado no vetor Amigos, que ja esta preenchido, essa fun��o imprime o nome dos amigos ao achar as correspond�ncias dos valores do vetor
   int i, j;            // com os codigos do vetor P.
    for(i = 0; i < k; i++){
        for(j = 0; j < N; j++){
            if(Amigos[i] == P[j].codigo && i != k - 1){
                printf("%s, ", P[j].nome);
            } else if(Amigos[i] == P[j].codigo && i == k - 1){
                printf("%s", P[j].nome);
            }
        }
    }
}

int main(){
    int Num, i;
    scanf("%d", &Num);    // Num � o codigo da pessoa cujos amigos quer se achar.
    Achar_Amigos(Num);   // Chama essa fun��o para encontrar os amigos desse numero.
    Imprimir_Nome(Num); // Imprime o nome correspondente ao c�digo.
    Imprimir_Amigos(); // Imprime os amigos achados.
}

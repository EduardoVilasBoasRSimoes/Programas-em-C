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

int Amigos[M], k = 0; // Vetor Amigos guardará os codigos que tem amizade com o número inserido na Main e k auxiliará nas suas posições.

void Achar_Amigos(int n){   // Função que, dado um número pela Main, procura suas correspondências no vetor struct amizade A.cod1 e A.cod2,
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

void Imprimir_Nome(int n){ // Baseado no número dado pela Main, essa função imprime o nome correspondente a esse valor no vetor struct pessoa P
    int i;
    for(i = 0; i < N; i++){
        if(n == P[i].codigo){
            printf("%s: ", P[i].nome);
        }
    }
}

void Imprimir_Amigos(){  // Baseado no vetor Amigos, que ja esta preenchido, essa função imprime o nome dos amigos ao achar as correspondências dos valores do vetor
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
    scanf("%d", &Num);    // Num é o codigo da pessoa cujos amigos quer se achar.
    Achar_Amigos(Num);   // Chama essa função para encontrar os amigos desse numero.
    Imprimir_Nome(Num); // Imprime o nome correspondente ao código.
    Imprimir_Amigos(); // Imprime os amigos achados.
}

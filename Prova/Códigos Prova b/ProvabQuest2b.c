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

int AmigosA[M], AmigosB[M], AmigosC[M], k = 0, l = 0, m = 0;  // Os vetores AmigosA e AmigosB guardarão os codigos dos amigos da primeira
                                                             // e segunda pessoa, respectivamente. Enquanto AmigosC guardará apenas os amigos iguais entre A e B.
void Achar_AmigosA(int n){          // Função que, dado o primeiro número pela Main, procura suas correspondências no vetor struct amizade A.cod1 e A.cod2
    int i;                         // de modo que guarda os valores amigos no vetor AmigosA, que tem k como um auxiliador no seu preenchimento.
    for(i = 0; i < M; i++){
        if(n == A[i].cod1){
            AmigosA[k] = A[i].cod2;
            k++;
        } else if(n == A[i].cod2){
            AmigosA[k] = A[i].cod1;
            k++;
        }
    }
}

void Achar_AmigosB(int n){         // Função que, dado o segundo número pela Main, procura suas correspondências no vetor struct amizade A.cod1 e A.cod2
    int i;                        // de modo que guarda os valores amigos no vetor AmigosB, que tem l como um auxiliador no seu preenchimento.
    for(i = 0; i < M; i++){
        if(n == A[i].cod1){
            AmigosB[l] = A[i].cod2;
            l++;
        } else if(n == A[i].cod2){
            AmigosB[l] = A[i].cod1;
            l++;
        }
    }
}

void Imprimir_Nomes(int n1, int n2){  // Função que, quando chamada, imprime os nomes dos que correspondem aos códigos inseridos na main.
    int i;
    for(i = 0; i < N; i++){
        if(n1 == P[i].codigo){
            printf("%s e ", P[i].nome);
        }
    }
    for(i = 0; i < N; i++){
        if(n2 == P[i].codigo){
            printf("%s: ", P[i].nome);
        }
    }
}

void Achar_Amigos_correspondentes(){   // Por meio dos vetores AmigosA e AmigosB, essa função verifica os códigos que estão nos dois vetores,
    int i, j;                         // assim ele encontra os amigos em comum e os passa para o vetor AmigosC, que tem m como um auxiliador no seu preenchimento.
    for(i = 0; i < k; i++){
        for(j = 0; j < l; j++){
            if(AmigosA[i] == AmigosB[j]){
                AmigosC[m] = AmigosA[i];
                m++;
            }
        }
    }
}

void Imprimir_Amigos(){          // Baseado em AmigosC, que está com os códigos dos amigos em comum, essa função encontra os codigos correspondentes no vetor struct
   int i, j;                    // pessoa P e imprime seus nomes.
    for(i = 0; i < m; i++){
        for(j = 0; j < N; j++){
            if(AmigosC[i] == P[j].codigo && i != m - 1){
                printf("%s, ", P[j].nome);
            } else if(AmigosC[i] == P[j].codigo && i == m - 1){
                printf("%s", P[j].nome);
            }
        }
    }
}

int main(){
    int n1, n2;
    scanf("%d%d", &n1, &n2);             // Códigos das duas pessoas cujos amigos quer se encontar são inseridos.
    Achar_AmigosA(n1);                  // Se encontra os amigos do primeiro código.
    Achar_AmigosB(n2);                 // Se encontra os amigos do segundo código.
    Imprimir_Nomes(n1, n2);           // Imprime os nomes dos dois códigos inseridos no começo da função.
    Achar_Amigos_correspondentes();  // Encontra os amigos em comum entre os dois códigos inseridos no começo da função.
    Imprimir_Amigos();              // Imprime os nomes desses amigos em comum.
}

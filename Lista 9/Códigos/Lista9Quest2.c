#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

enum tipo {Cachorro, Gato, Tartaruga, Peixe, Passaro};

struct Pets {
    char nome[50];
    enum tipo tipo;
};

struct Pets A[N] =
{
    {"Lulu", Cachorro},
    {"Sansao", Passaro},
    {"Miau", Gato},
    {"Donatello", Tartaruga},
    {"Toto", Cachorro},
    {"Glub", Peixe},
    {"Pitoco", Passaro}
};

int F = 7;

int main(){
    int i, j;
    char Alfa[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    printf("Os cachorros:\n");
    for(i = 0; i < 26; i++){
        for(j = 0; j < N; j++){
            if(A[j].nome[0] == Alfa[i] && A[j].tipo == Cachorro){
                printf("%s\n", A[j].nome);
            }
        }
    }
    printf("\nOs gatos:\n");
    for(i = 0; i < 26; i++){
        for(j = 0; j < N; j++){
            if(A[j].nome[0] == Alfa[i] && A[j].tipo == Gato){
                printf("%s\n", A[j].nome);
            }
        }
    }
    printf("\nOs tartarugas:\n");
    for(i = 0; i < 26; i++){
        for(j = 0; j < N; j++){
                if(A[j].nome[0] == Alfa[i] && A[j].tipo == Tartaruga){
                printf("%s\n", A[j].nome);
            }
        }
    }
    printf("\nOs peixes:\n");
    for(i = 0; i < 26; i++){
        for(j = 0; j < N; j++){
            if(A[j].nome[0] == Alfa[i] && A[j].tipo == Peixe){
                printf("%s\n", A[j].nome);
            }
        }
    }
    printf("\n\Os passaros:\n");
    for(i = 0; i < 26; i++){
        for(j = 0; j < N; j++){
            if(A[j].nome[0] == Alfa[i] && A[j].tipo == Passaro){
                printf("%s\n", A[j].nome);
            }
        }
    }
}

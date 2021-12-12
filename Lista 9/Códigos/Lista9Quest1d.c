#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

enum especie {Cachorro, Gato, Escorpiao, Cobra, Passaro};
enum pulgas {Sim, Nao};

struct animais {
    char nome[50], dono[50], pai[50], mae[50];
    enum especie especie;
    enum pulgas pulgas;
    int idade;
};

struct animais A[N] =
{
    {"Lulu", "Carlos", "Sansao", "Toto", Cachorro, Sim, 11},
    {"auau", "Luis", "Sansao", "Rosa", Cachorro, Sim, 7},
    {"Lulu", "Fernando", "Aracne", "Jadis", Passaro, Nao, 2},
    {"Cleopatra", "Sansao", "Felix", "Felina", Gato, Sim, 9},
    {"Lulu", "Joao", "Mamba", "Poison", Cobra, Nao, 5},
    {"Pitoco", "Joao", "Piupiu", "Biquinha", Passaro, Nao, 3}
};

int F = 6;

int main(){
    int i, j, P;
    char aux[200];
    for(i = 0; i < F; i++){
        for(j = i + 1; j < F; j++){
            if(strncmp(A[i].dono, A[j].dono, strlen(A[i].dono)) == 0){
                if((A[i].especie == Passaro ||
                    A[j].especie == Passaro) &&
                   (A[i].especie == Cobra ||
                    A[j].especie == Cobra)){
                    P++;
                }
            }
        }
    }
    printf("%d\n", P);
}

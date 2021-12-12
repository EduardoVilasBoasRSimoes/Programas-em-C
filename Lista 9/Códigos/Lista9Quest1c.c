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
    {"Lulu", "Fernando", "Aracne", "Jadis", Escorpiao, Nao, 2},
    {"Cleopatra", "Sansao", "Felix", "Felina", Gato, Sim, 9},
    {"Lulu", "Joao", "Mamba", "Poison", Cobra, Nao, 5},
    {"Pitoco", "Dudu", "Piupiu", "Biquinha", Passaro, Nao, 3}
};

int F = 6;

int main(){
    int i, G = 0, C = 0;
    for(i = 0; i < F; i++){
        if(A[i].pulgas == Sim && A[i].especie == Cachorro){
            C++;
        } else if(A[i].pulgas == Sim && A[i].especie == Gato){
            G++;
        }
    }
    if(G > C){
        printf("Existem mais gatos com pulgas\n");
    } else if(G < C){
        printf("Existem mais cachorros com pulgas\n");
    } else{
        printf("Existem igualmente gatos e cachorros com pulgas\n");
    }
}

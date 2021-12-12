#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

enum especie {Cachorro, Passaro, Gato, Escorpiao, Cobra};
enum pulgas {Sim, Nao};

struct animais{
    char nome[50], dono[50], pai[50], mae[50];
    enum especie especie;
    enum pulgas pulgas;
    int idade;
};

struct animais A[N] = {
    {"Lulu", "Carlos", "Sansao", "Toto", Cachorro, Sim, 11},
    {"auau", "Luis", "Sansao", "Rosa", Cachorro, Sim, 7},
    {"Lulu", "Fernando", "Aracne", "Jadis", Escorpiao, Nao, 2},
    {"Cleopatra", "Amanda", "Felix", "Felina", Gato, Sim, 9},
    {"Lulu", "Joao", "Mamba", "Poison", Cobra, Nao, 5},
    {"Pitoco", "Dudu", "Piupiu", "Biquinha", Passaro, Nao, 3}
};

int F = 6;

int main(){
    int i, j, aux = 0;
    for(i = 0; i < F; i++){
        for(j = i; j < F; j++){
            if(strncmp(A[i].nome, A[j].nome, strlen(A[i].nome)) == 0 &&
               A[i].especie != A[j].especie && (j != aux || j == 0)){
                if(A[i].especie == Cachorro && aux == 0){
                    printf("Cachorro ");
                    printf("%s\n\n", A[i].nome);
                } else if(A[i].especie == Gato && aux == 0){
                    printf("Gato ");
                    printf("%s\n\n", A[i].nome);
                } else if(A[i].especie == Escorpiao && aux == 0){
                    printf("Escorpiao ");
                    printf("%s\n\n", A[i].nome);
                } else if(A[i].especie == Cobra && aux == 0){
                    printf("Cobra ");
                    printf("%s\n\n", A[i].nome);
                } else if(A[i].especie == Passaro && aux == 0){
                    printf("Passaro ");
                    printf("%s\n\n", A[i].nome);
                }
                if(A[j].especie == Cachorro){
                    printf("Cachorro ");
                } else if(A[j].especie == Gato){
                    printf("Gato ");
                } else if(A[j].especie == Escorpiao){
                    printf("Escorpiao ");
                } else if(A[j].especie == Cobra){
                    printf("Cobra ");
                } else if(A[j].especie == Passaro){
                    printf("Passaro ");
                }
                printf("%s\n\n", A[j].nome);
                aux = j;
            }
        }
    }
}

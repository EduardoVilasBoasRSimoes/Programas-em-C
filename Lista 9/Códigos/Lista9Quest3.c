#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

enum tipo {Cachorro, Gato, Escorpiao, Cobra, Passaro};
enum pulgas {Sim, Nao};
enum sexo {Macho, Femea};

struct animais {
    char nome[50], dono[50], pai[50], mae[50];
    enum tipo tipo;
    enum pulgas pulgas;
    int idade;
    enum sexo sexo;
};

struct animais A[N] =
{
    {"Lulu", "Carlos", "Sansao", "Toto", Cachorro, Sim, 11, Macho},
    {"Auau", "Luis", "Sansao", "Rosa", Cachorro, Sim, 7, Femea},
    {"Rei", "Fernando", "Aracne", "Jadis", Escorpiao, Nao, 2, Macho},
    {"Cleopatra", "Sansao", "Felix", "Felina", Gato, Sim, 9, Femea},
    {"Naja", "Joao", "Mamba", "Poison", Cobra, Nao, 5, Femea},
    {"Pitoco", "Dudu", "Piupiu", "Biquinha", Passaro, Nao, 16, Macho},
    {"Toto", "Chris", "Auau", "Nina", Cachorro, Nao, 4, Macho},
    {"Didinha", "Rick", "Lulu", "Toto", Cachorro, Sim, 2, Femea},
    {"Nininha", "Jonas", "Lulu", "Didinha", Cachorro, Sim, 7, Femea},
    {"Xray", "Julio", "Pitoco", "Felina", Gato, Nao, 10, Femea},
    {"Cascudo", "Fernando", "Brog", "Naja", Escorpiao, Nao, 2, Macho}
};

int F = 11;

int main(){
    int i, j;
    for(i = 0; i < F; i++){
        for(j = 0; j < F; j++){
            if(strncmp(A[i].pai, A[j].nome, strlen(A[j].nome)) == 0){
                if(A[j].sexo == Femea){
                    printf("Erro nas listas %d e %d: %s eh pai de %s, mas eh femea\n", i + 1, j + 1, A[j].nome, A[i].nome);
                }
            }
            if(strncmp(A[i].mae, A[j].nome, strlen(A[j].nome)) == 0){
                if(A[j].sexo == Macho){
                    printf("Erro nas listas %d e %d: %s eh mae de %s, mas eh macho\n", i + 1, j + 1, A[j].nome, A[i].nome);
                }
            }
            if(strncmp(A[i].pai, A[j].nome, strlen(A[j].nome)) == 0){
                if(A[j].idade < A[i].idade){
                    printf("Erro nas listas %d e %d: %s tem %d anos, mas eh pai de %s que tem %d anos\n", i + 1, j + 1, A[j].nome, A[j].idade, A[i].nome, A[i].idade);
                }
            }
            if(strncmp(A[i].mae, A[j].nome, strlen(A[j].nome)) == 0){
                if(A[j].idade < A[i].idade){
                    printf("Erro nas listas %d e %d: %s tem %d anos, mas eh mae de %s que tem %d anos\n", i + 1, j + 1, A[j].nome, A[j].idade, A[i].nome, A[i].idade);
                }
            }
            if(strncmp(A[i].pai, A[j].nome, strlen(A[j].nome)) == 0){
                if(A[j].tipo != A[i].tipo){
                    printf("Erro nas listas %d e %d: %s eh pai de %s, mas ambos nao sao da mesma especie\n", i + 1, j + 1, A[j].nome, A[i].nome);
                }
            }
            if(strncmp(A[i].mae, A[j].nome, strlen(A[j].nome)) == 0){
                if(A[j].tipo != A[i].tipo){
                    printf("Erro nas listas %d e %d: %s eh pai de %s, mas ambos nao sao da mesma especie\n", i + 1, j + 1, A[j].nome, A[i].nome);
                }
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

enum especie {Cachorro, Gato, Lhama};

struct animais {
    enum especie especie;
    char nome[50], pai[50], mae[50];
};

struct animais A[N] = {
    {Cachorro, "Sansao", "Toto", "Lulu"},
    {Cachorro, "Auau", "Citus", "Nana"},
    {Cachorro, "Lulu", "Bolt", "Nina"},
    {Cachorro, "Citus", "Helio", "Lucia"},
    {Cachorro, "Toto", "Rufus", "Auau"}
};

int F = 5;

int Ancestrais(int ind){
    int i, j;
    for(j = 0; j < F; j++){
        if(strncmp(A[j].nome, A[ind].pai, strlen(A[j].nome)) == 0){
            return Ancestrais(j);
        } else {
            return ind;
        }
    }
}

int main(){
    int i, j;
    char E[50];
    char B[50];
    printf("%d", Ancestrais(0));
}

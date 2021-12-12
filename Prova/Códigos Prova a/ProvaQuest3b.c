#include <stdio.h>
#define N 20    // N é o número de elementos do vetor exemplo da questão.

int L[N] = {1, 2, 3, 4, 7, 6, 5, 8, 9, 10, 14, 13, 12, 11, 15, 20, 19, 18, 17, 16};  // Vetor exemplo.
int Laux[N];                                                                         // Vetor Auxiliar.

void desinverter(int A, int B){        // Função que desinverte os termos invertidos na lista L. A é o começo e B é o fim das posições invertidas.
    int i, k = 0;
    for(i = 0; i < A; i++){            // Colocar os termos que estão ordenados na lista auxiliar.
        Laux[i] = L[i];
        k++;                           // k ajuda no momento de desinverter.
    }
    for(i = B; i >= A; i--){           // Desinverter e colocar os termos desinvertidos na lista auxiliar.
        Laux[k] = L[i];
        k++;
    }
    for(i = 0; i <= B; i++){           // Passar os valores ordenados para a lista L.
        L[i] = Laux[i];
    }
}

int main(){
    int i, j, A, B;
    for(i = 0; i < N - 1; i++){         // Passar pela lista L.
        if(L[i] > L[i + 1]){            // Se encontrar algum elemento que seja maior do que o proximo, significa um intervalo invertido, então:
            A = i;                      // Atribuir a primeira posição do intervalo a A.
            for(j = i; j < N - 1; j++){ // Passar pela lista L partindo de A;
                if(L[j] < L[j + 1]){    // Se encontrar algum elemento que seja menor do que o proximo, significa o fim do intervalo invertido, então:
                    B = j;              // Atribuir a ultima posição do intervalo a B e sair do "for".
                    break;
                } else if(j + 1 == N - 1){ // Se chegar ao final da lista L, significa que o intervalo invertido termina na ultima posição da lista.
                    B = j + 1;             // B recebe j + 1 e sai do "for".
                    break;
                }
            }
            desinverter(A, B);             // Tendo a primeira e ultima posição do intervalo invertido, chamar a função desinverter para ordenar esse intervalo.
        }
    }
    for(i = 0; i < N; i++){                // Após passar pela lista toda, L esta totalmente ordenada, então basta imprimi-la.
        printf("%d ", L[i]);
    }
}

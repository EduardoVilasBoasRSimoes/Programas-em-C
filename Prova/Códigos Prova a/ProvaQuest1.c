#include <stdio.h>

int main(){
    int i = 0, j = 0, k = 0;            // i percorrerá L1, j percorrerá L2 e k indicará o numero de elementos do vetor L dos valores iguais.
    int L1[6] = {2, 5, 11, 19, 22, 25}; //Listas Exemplo.
    int L2[6] = {5, 7, 11, 15, 25, 31}; //Listas Exemplo.
    int L[6];
    int N = 6;
    while(i != N && j != N){            //Enquanto i e j não chegaram ao final da lista:
        if(L1[i] == L2[j]){             // Se os valores das listas forem iguais, adiciona esse valor em L e aumenta k, caso
            L[k] = L1[i];               // i ja tenha chegado no fim, não aumenta i, caso contrário aumenta, mesmo raciocínio com j.
            k++;
            if(i != N){
                i++;
            }
            if(j != N){
                j++;
            }
        } else if(L1[i] > L2[j] && j != N){  //Se L1 for maior que L2, então L2 precisa andar, ou seja, j precisa aumentar, se não tiver chegado ao fim.
            j++;
        } else if(L1[i] < L2[j] && i != N){ //Se L1 for menor que L2, então L1 precisa andar, ou seja, i precisa aumentar, se não tiver chegado ao fim.
            i++;
        }
    }
    for(i = 0; i < k; i++){                 // Assim, a lista L dos valores iguais de L1 e L2 está pronta e basta imprimi-la.
        printf("%d ", L[i]);
    }
}

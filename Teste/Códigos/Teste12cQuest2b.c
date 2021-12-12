#include <stdio.h>

int main(){
    char T[500] = {"apa capasapa depe papapelpel"};
    char Tr[500];
    int i, j, tamT, tamTr, aux = 0, A = 0, B;
    tamT = strlen(T);
    for(i = 0; i < tamT; i++){
        if(T[i] == 'p'){
            B = 0;
            if(T[i - 1] != ' '){
                for(j = aux; j < i; j++){
                    Tr[A] = T[j];
                    A++;
                }
                Tr[A] == ' ';
            }
        }
        if(T[i] == Tr[A - 1] && B == 0){
            aux = i + 1;
            B = 1;
        }
    }
    tamTr = strlen(Tr);
    for(i = 0; i < tamTr; i++){
        printf("%c", Tr[i]);
    }
}

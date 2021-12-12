#include <stdio.h>

int main(){
    char T[500] = {"A casa de papel"};
    char Tr[500];
    int i, tamT, tamTr, aux = 0;
    tamT = strlen(T);
    T[tamT] = ' ';
    for(i = 0; i < tamT; i++){
        if(T[i] == 'a' || T[i] == 'e' || T[i] == 'i' || T[i] == 'o' || T[i] == 'u'
           || (T[i] == 'A' || T[i] == 'E' || T[i] == 'I' || T[i] == 'O' || T[i] == 'U')){
            if((T[i - 1] == ' ' || i == 0) &&
               (T[i + 1] == ' ' || i == tamT - 1
                || (T[i + 1] != 'a' && T[i + 1] != 'e' && T[i + 1] != 'i' && T[i + 1] != 'o' && T[i + 1] != 'u'))){
                Tr[aux] = T[i];
                Tr[aux + 1] = 'p';
                if(T[i] == 'A'){
                    Tr[aux + 2] = 'a';
                } else if(T[i] == 'E'){
                    Tr[aux + 2] = 'e';
                } else if(T[i] == 'I'){
                    Tr[aux + 2] = 'i';
                } else if(T[i] == 'O'){
                    Tr[aux + 2] = 'o';
                } else if(T[i] == 'U'){
                    Tr[aux + 2] = 'u';
                } else{
                    Tr[aux + 2] = T[i];
                }
                if(T[i + 1] == ' '){
                    Tr[aux + 3] = ' ';
                    aux = aux + 4;
                } else {
                    aux = aux + 3;
                }
            } else if((T[i - 2] == 'a' || T[i - 2] == 'e' || T[i - 2] == 'i'  || T[i - 2] == 'o' || T[i - 2] == 'u' || T[i - 2] == ' ')
                      && (T[i - 1] != 'a' && T[i - 1] != 'e' && T[i - 1] != 'i' && T[i - 1] != 'o' && T[i - 1] != 'u')
                      && T[i + 1] == ' '){
                Tr[aux] = T[i - 1];
                Tr[aux + 1] = T[i];
                Tr[aux + 2] = 'p';
                Tr[aux + 3] = T[i];
                if(T[i + 1] == ' '){
                    Tr[aux + 4] = ' ';
                    aux = aux + 5;
                } else {
                    aux = aux + 4;
                }
            } else if((T[i - 1] != 'a' && T[i - 1] != 'e' && T[i - 1] != 'i' && T[i - 1] != 'o' && T[i - 1] != 'u')
                      && (T[i + 1] == 'n' && T[i + 2] == 's')
                      && ((T[i + 3] != 'a' && T[i + 3] != 'e' && T[i + 3] != 'i' && T[i + 3] != 'o' && T[i + 3] != 'u') || T[i + 3] == ' ')){
                Tr[aux] = T[i - 1];
                Tr[aux + 1] = T[i];
                Tr[aux + 2] = T[i + 1];
                Tr[aux + 3] = T[i + 2];
                Tr[aux + 4] = 'p';
                Tr[aux + 5] = T[i];
                Tr[aux + 6] = T[i + 1];
                Tr[aux + 7] = T[i + 2];
                if(T[i + 3] == ' '){
                    Tr[aux + 8] = ' ';
                    aux = aux + 9;
                } else {
                    aux = aux + 8;
                    }
                } else if((T[i - 2] == 'a' || T[i - 2] == 'e' || T[i - 2] == 'i'  || T[i - 2] == 'o' || T[i - 2] == 'u' || T[i - 2] == ' ')
                    && (T[i - 1] != 'a' && T[i - 1] != 'e' && T[i - 1] != 'i' && T[i - 1] != 'o' && T[i - 1] != 'u')
                    && (T[i + 1] != 'a' && T[i + 1] != 'e' && T[i + 1] != 'i' && T[i + 1] != 'o' && T[i + 1] != 'u')
                    && (T[i + 2] != ' ' && T[i + 2] != T[i + 1])){
                Tr[aux] = T[i - 1];
                Tr[aux + 1] = T[i];
                Tr[aux + 2] = 'p';
                Tr[aux + 3] = T[i];
                if(T[i + 2] == ' '){
                    Tr[aux + 4] = ' ';
                    aux = aux + 5;
                } else {
                    aux = aux + 4;
                }
            } else if((T[i - 1] != 'a' && T[i - 1] != 'e' && T[i - 1] != 'i' && T[i - 1] != 'o' && T[i - 1] != 'u')
                      && (T[i + 1] == 'a' || T[i + 1] == 'e' || T[i + 1] == 'i' || T[i + 1] == 'o' || T[i + 1] == 'u')
                      && (T[i + 2] != 'a' && T[i + 2] != 'e' && T[i + 2] != 'i' && T[i + 2] != 'o' && T[i + 2] != 'u')
                      && ((T[i + 3] != 'a' && T[i + 3] != 'e' && T[i + 3] != 'i' && T[i + 3] != 'o' && T[i + 3] != 'u') || T[i + 3] == ' ')){
                Tr[aux] = T[i - 1];
                Tr[aux + 1] = T[i];
                Tr[aux + 2] = T[i + 1];
                Tr[aux + 3] = T[i + 2];
                Tr[aux + 4] = 'p';
                Tr[aux + 5] = T[i];
                Tr[aux + 6] = T[i + 1];
                Tr[aux + 7] = T[i + 2];
                if(T[i + 3] == ' '){
                    Tr[aux + 8] = ' ';
                    aux = aux + 9;
                } else {
                    aux = aux + 8;
                }
            } else if((T[i - 1] != 'a' && T[i - 1] != 'e' && T[i - 1] != 'i' && T[i - 1] != 'o' && T[i - 1] != 'u')
                    && (T[i + 1] == 'a' || T[i + 1] == 'e' || T[i + 1] == 'i' || T[i + 1] == 'o' || T[i + 1] == 'u')
                    && (T[i + 2] == 'a' || T[i + 2] == 'e' || T[i + 2] == 'i' || T[i + 2] == 'o' || T[i + 2] == 'u')
                    && ((T[i + 3] != 'a' && T[i + 3] != 'e' && T[i + 3] != 'i' && T[i + 3] != 'o' && T[i + 3] != 'u') || T[i + 3] == ' ')){
                Tr[aux] = T[i - 1];
                Tr[aux + 1] = T[i];
                Tr[aux + 2] = T[i + 1];
                Tr[aux + 3] = T[i + 2];
                Tr[aux + 4] = 'p';
                Tr[aux + 5] = T[i];
                Tr[aux + 6] = T[i + 1];
                Tr[aux + 7] = T[i + 2];
                if(T[i + 3] == ' '){
                    Tr[aux + 8] = ' ';
                    aux = aux + 9;
                } else {
                    aux = aux + 8;
                }
            } else if((T[i - 1] != 'a' && T[i - 1] != 'e' && T[i - 1] != 'i' && T[i - 1] != 'o' && T[i - 1] != 'u')
                    && (T[i + 1] == 'a' || T[i + 1] == 'e' || T[i + 1] == 'i' || T[i + 1] == 'o' || T[i + 1] == 'u')
                    && ((T[i + 2] != 'a' && T[i + 2] != 'e' && T[i + 2] != 'i' && T[i + 2] != 'o' && T[i + 2] != 'u') || T[i + 2] == ' ')){
                Tr[aux] = T[i - 1];
                Tr[aux + 1] = T[i];
                Tr[aux + 2] = T[i + 1];
                Tr[aux + 3] = 'p';
                Tr[aux + 4] = T[i];
                Tr[aux + 5] = T[i + 1];
                if(T[i + 2] == ' '){
                    Tr[aux + 6] = ' ';
                    aux = aux + 7;
                } else {
                    aux = aux + 6;
                }
            } else if((T[i - 2] == 'a' || T[i - 2] == 'e' || T[i - 2] == 'i'  || T[i - 2] == 'o' || T[i - 2] == 'u' || T[i - 2] == ' ')
                    && (T[i - 1] != 'a' && T[i - 1] != 'e' && T[i - 1] != 'i' && T[i - 1] != 'o' && T[i - 1] != 'u')
                    && (T[i + 1] != 'a' && T[i + 1] != 'e' && T[i + 1] != 'i' && T[i + 1] != 'o' && T[i + 1] != 'u')
                    && ((T[i + 2] != 'a' && T[i + 2] != 'e' && T[i + 2] != 'i' && T[i + 2] != 'o' && T[i + 2] != 'u' && T[i + 2] == T[i + 1]) || T[i + 2] == ' ')){
                Tr[aux] = T[i - 1];
                Tr[aux + 1] = T[i];
                Tr[aux + 2] = T[i + 1];
                Tr[aux + 3] = 'p';
                Tr[aux + 4] = T[i];
                Tr[aux + 5] = T[i + 1];
                if(T[i + 2] == ' '){
                    Tr[aux + 6] = ' ';
                    aux = aux + 7;
                } else {
                    aux = aux + 6;
                }
            } else if((T[i - 2] != 'a' && T[i - 2] != 'e' && T[i - 2] != 'i' && T[i - 2] != 'o' && T[i - 2] != 'u' && T[i - 2] !=' ')
                      && (T[i - 1] != 'a' && T[i - 1] != 'e' && T[i - 1] != 'i' && T[i - 1] != 'o' && T[i - 1] != 'u')
                      && ((T[i + 1] != 'a' && T[i + 1] != 'e' && T[i + 1] != 'i' && T[i + 1] != 'o' && T[i + 1] != 'u') || T[i + 1] == ' ')){
                Tr[aux] = T[i - 2];
                Tr[aux + 1] = T[i - 1];
                Tr[aux + 2] = T[i];
                Tr[aux + 3] = 'p';
                Tr[aux + 4] = T[i - 1];
                Tr[aux + 5] = T[i];
                if(T[i + 1] == ' '){
                    Tr[aux + 6] = ' ';
                    aux = aux + 7;
                } else {
                    aux = aux + 6;
                }
            } else if(T[i - 1] == 'h' && (T[i - 2] == 'n' || T[i - 2] == 'l')){
                Tr[aux] = T[i - 2];
                Tr[aux + 1] = T[i - 1];
                Tr[aux + 2] = T[i];
                Tr[aux + 3] = 'p';
                Tr[aux + 4] = T[i - 3];
                Tr[aux + 5] = T[i - 2];
                Tr[aux + 6] = T[i - 1];
                Tr[aux + 7] = T[i];
                if(T[i + 1] == ' '){
                    Tr[aux + 8] = ' ';
                    aux = aux + 9;
                } else {
                    aux = aux + 8;
                }
            }
        }
    }
    tamTr = strlen(Tr);
    for(i = 0; i < tamTr; i++){
        printf("%c", Tr[i]);
    }
}

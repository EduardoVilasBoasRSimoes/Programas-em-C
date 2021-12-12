#include <stdio.h>
#define N 4          // Tamanho da matriz N x N.

int A[N][N] = { {8, 9, 0, 0},    // Matriz exemplo.
                {0, 10, 0, 0},
                {3, 4, 1, 2},
                {6, 7, 0, 5} };
int B[N][N];                     // Matrizes auxiliares.
int C[N][N];
int TrocaLinhas[N], TrocaColunas[N], k = 0, l = 0; // Esses vetores guardarão os movimentos ocorridos para retornar ao estado triangularizado e
                                                  // k e l indicarão seus tamanhos
struct PosZeros {
    int Quantidade_de_zeros, Poscicao_dos_zeros;   // Por meio de uma analise rápida, percebe-se que a coluna 0 tem N-1 zeros, a coluna 1 tem N - 2 zeros e assim
};                                                // por diante, então esse struct foi criado para guardar essas duas informações,
                                                 // dessa forma, o vetor Vet guardará o numero de zeros em uma coluna e a posição que ela deve assumir,
struct PosZeros Vet[N];                         // Assim sendo, ele ajudará bastante na hora das comparações.

void Preencher_struct(){                           // Essa função preenche o struct Vet seguindo a lógica matemática revelada acima:
    int i;                                        // se quantidade de zeros for N - 1, sua posição deveria ser na coluna 0. Se quantidade de zeros for N - 3,
    for(i = 0; i < N; i++){                      // sua posição deveria ser na coluna 2. Se quantidade de zeros for 0, sua posição deveria ser na coluna N - 1.
        Vet[i].Quantidade_de_zeros = N - 1 - i;
        Vet[i].Poscicao_dos_zeros= i;
    }
}

void Verificar_PosCol(int NumZeros, int colunaInicial){    // Essa função troca a posição das colunas da seguinte forma:
    int i, j;                                             // Com o numero de zeros de uma coluna (ambos dados pela Main) ele passa para a
    for(i = 0; i < N; i++){                              // posição certa usando uma matriz auxiliar B, baseado na lógica do vetor struct.
        if(Vet[i].Quantidade_de_zeros == NumZeros){
            for(j = 0; j < N; j++){
                B[j][Vet[i].Poscicao_dos_zeros] = A[j][colunaInicial]; // Vet[i].Poscicao_dos_zeros é a posição da coluna correta baseado no numero de zeros e
            }                                                             // coluna inicial é a posição inicial onde os zeros estavam.
            TrocaColunas[k] = Vet[i].Poscicao_dos_zeros;               // O vetor TrocaColunas recebe a posição final e
            k++;
            TrocaColunas[k] = colunaInicial;                           // a posição inicial.
            k++;
        }
    }
}

void Verificar_PosLin(int NumZeros, int linhaInicial){  // Mesmo raciocionio que a função Verificar_PosCol, porém é aplicado para as linhas e segue a seguinte lógica:
    int i, j;                                          // Se uma linha tem N - 1 zeros, então deve estar na linha N - 1, se tem 0, deve estar na linha 0, então
    for(i = 0; i < N; i++){                           // baseado no numero de zeros e na linha onde estão (ambos dados pela Main), passa para a posição certa usando
        if(i == NumZeros){                           // uma matriz auxiliar C.
            for(j = 0; j < N; j++){
                C[i][j] = B[linhaInicial][j];           // i é a posição da linha correta baseada na lógica acima e a linha inicial é a posição inicial onde os zeros
            }                                              // estavam.
            TrocaLinhas[l] = i;                         // O vetor TrocaLinhas recebe a posição final e
            l++;
            TrocaLinhas[l] = linhaInicial;              // a posição inicial.
            l++;
        }
    }
}                                                     // Após essa transferencia, a matriz C ja esta triangularizado.

void Transmitir_para_A(){                            // Essa função passa a matriz triangularizada C para a matriz inicial A.
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            A[i][j] = C[i][j];
        }
    }
}

void imprimirA(){                               // Essa função imprime a matriz A.
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void imprimir_Trocas(){                          // Essa função imprime as trocas:
    int i;
    for(i = 0; i < k/2; i += 2){
        printf("troca das linhas %d e %d\n", TrocaLinhas[i] + 1, TrocaLinhas[i + 1] + 1); // A posição da linha final e inicial são impressas
    }
    for(i = 0; i < l/2; i += 2){
        printf("troca das colunas %d e %d\n", TrocaColunas[i] + 1, TrocaColunas[i + 1] + 1); // A posição da coluna final e inicial são impressas
    }
}

int main(){
    int i, j, Num_de_Zeros, ColunaInicial, LinhaInicial;
    imprimirA();                // Imprime a matriz A.
    Preencher_struct();        //Chama a função para inicializar o vetor do struct com a lógica achar a posição certa baseado no numero de zeros.
    for(i = 0; i < N; i++){
        Num_de_Zeros = 0;
        for(j = 0; j < N; j++){
            if(A[j][i] == 0){    // Percorre a matrix A contando o numero de zeros em uma só coluna.
                Num_de_Zeros++;
            }
            ColunaInicial = i;     // Marca a posição inicial dessa coluna.
        }
        Verificar_PosCol(Num_de_Zeros, ColunaInicial); // Chama a função que colocará as colunas na posição certa usando uma matriz auxiliar B;
    }
//--------------------------------------------------------------------------
    for(i = 0; i < N; i++){
        Num_de_Zeros = 0;
        for(j = 0; j < N; j++){
            if(A[i][j] == 0){      // Percorre a matrix A contando o numero de zeros em uma só linha.
                Num_de_Zeros++;
            }
            LinhaInicial = i;     // Marca a posição inicial dessa linha.
        }
        Verificar_PosLin(Num_de_Zeros, LinhaInicial); // Chama a função que colocará as linhas na posição certa usando uma matriz auxiliar C;
    }
    Transmitir_para_A(); // Chama a função que passará a matriz triangularizada C para a matriz inicial A.
    imprimirA();        // Imprime a matriz A.
    imprimir_Trocas(); // Imprime os movimentos para voltar a matriz triangularizada.
}

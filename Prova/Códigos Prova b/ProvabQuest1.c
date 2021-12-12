#include <stdio.h>
#define N 4          // Tamanho da matriz N x N.

int A[N][N] = { {8, 9, 0, 0},    // Matriz exemplo.
                {0, 10, 0, 0},
                {3, 4, 1, 2},
                {6, 7, 0, 5} };
int B[N][N];                     // Matrizes auxiliares.
int C[N][N];
int TrocaLinhas[N], TrocaColunas[N], k = 0, l = 0; // Esses vetores guardar�o os movimentos ocorridos para retornar ao estado triangularizado e
                                                  // k e l indicar�o seus tamanhos
struct PosZeros {
    int Quantidade_de_zeros, Poscicao_dos_zeros;   // Por meio de uma analise r�pida, percebe-se que a coluna 0 tem N-1 zeros, a coluna 1 tem N - 2 zeros e assim
};                                                // por diante, ent�o esse struct foi criado para guardar essas duas informa��es,
                                                 // dessa forma, o vetor Vet guardar� o numero de zeros em uma coluna e a posi��o que ela deve assumir,
struct PosZeros Vet[N];                         // Assim sendo, ele ajudar� bastante na hora das compara��es.

void Preencher_struct(){                           // Essa fun��o preenche o struct Vet seguindo a l�gica matem�tica revelada acima:
    int i;                                        // se quantidade de zeros for N - 1, sua posi��o deveria ser na coluna 0. Se quantidade de zeros for N - 3,
    for(i = 0; i < N; i++){                      // sua posi��o deveria ser na coluna 2. Se quantidade de zeros for 0, sua posi��o deveria ser na coluna N - 1.
        Vet[i].Quantidade_de_zeros = N - 1 - i;
        Vet[i].Poscicao_dos_zeros= i;
    }
}

void Verificar_PosCol(int NumZeros, int colunaInicial){    // Essa fun��o troca a posi��o das colunas da seguinte forma:
    int i, j;                                             // Com o numero de zeros de uma coluna (ambos dados pela Main) ele passa para a
    for(i = 0; i < N; i++){                              // posi��o certa usando uma matriz auxiliar B, baseado na l�gica do vetor struct.
        if(Vet[i].Quantidade_de_zeros == NumZeros){
            for(j = 0; j < N; j++){
                B[j][Vet[i].Poscicao_dos_zeros] = A[j][colunaInicial]; // Vet[i].Poscicao_dos_zeros � a posi��o da coluna correta baseado no numero de zeros e
            }                                                             // coluna inicial � a posi��o inicial onde os zeros estavam.
            TrocaColunas[k] = Vet[i].Poscicao_dos_zeros;               // O vetor TrocaColunas recebe a posi��o final e
            k++;
            TrocaColunas[k] = colunaInicial;                           // a posi��o inicial.
            k++;
        }
    }
}

void Verificar_PosLin(int NumZeros, int linhaInicial){  // Mesmo raciocionio que a fun��o Verificar_PosCol, por�m � aplicado para as linhas e segue a seguinte l�gica:
    int i, j;                                          // Se uma linha tem N - 1 zeros, ent�o deve estar na linha N - 1, se tem 0, deve estar na linha 0, ent�o
    for(i = 0; i < N; i++){                           // baseado no numero de zeros e na linha onde est�o (ambos dados pela Main), passa para a posi��o certa usando
        if(i == NumZeros){                           // uma matriz auxiliar C.
            for(j = 0; j < N; j++){
                C[i][j] = B[linhaInicial][j];           // i � a posi��o da linha correta baseada na l�gica acima e a linha inicial � a posi��o inicial onde os zeros
            }                                              // estavam.
            TrocaLinhas[l] = i;                         // O vetor TrocaLinhas recebe a posi��o final e
            l++;
            TrocaLinhas[l] = linhaInicial;              // a posi��o inicial.
            l++;
        }
    }
}                                                     // Ap�s essa transferencia, a matriz C ja esta triangularizado.

void Transmitir_para_A(){                            // Essa fun��o passa a matriz triangularizada C para a matriz inicial A.
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            A[i][j] = C[i][j];
        }
    }
}

void imprimirA(){                               // Essa fun��o imprime a matriz A.
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void imprimir_Trocas(){                          // Essa fun��o imprime as trocas:
    int i;
    for(i = 0; i < k/2; i += 2){
        printf("troca das linhas %d e %d\n", TrocaLinhas[i] + 1, TrocaLinhas[i + 1] + 1); // A posi��o da linha final e inicial s�o impressas
    }
    for(i = 0; i < l/2; i += 2){
        printf("troca das colunas %d e %d\n", TrocaColunas[i] + 1, TrocaColunas[i + 1] + 1); // A posi��o da coluna final e inicial s�o impressas
    }
}

int main(){
    int i, j, Num_de_Zeros, ColunaInicial, LinhaInicial;
    imprimirA();                // Imprime a matriz A.
    Preencher_struct();        //Chama a fun��o para inicializar o vetor do struct com a l�gica achar a posi��o certa baseado no numero de zeros.
    for(i = 0; i < N; i++){
        Num_de_Zeros = 0;
        for(j = 0; j < N; j++){
            if(A[j][i] == 0){    // Percorre a matrix A contando o numero de zeros em uma s� coluna.
                Num_de_Zeros++;
            }
            ColunaInicial = i;     // Marca a posi��o inicial dessa coluna.
        }
        Verificar_PosCol(Num_de_Zeros, ColunaInicial); // Chama a fun��o que colocar� as colunas na posi��o certa usando uma matriz auxiliar B;
    }
//--------------------------------------------------------------------------
    for(i = 0; i < N; i++){
        Num_de_Zeros = 0;
        for(j = 0; j < N; j++){
            if(A[i][j] == 0){      // Percorre a matrix A contando o numero de zeros em uma s� linha.
                Num_de_Zeros++;
            }
            LinhaInicial = i;     // Marca a posi��o inicial dessa linha.
        }
        Verificar_PosLin(Num_de_Zeros, LinhaInicial); // Chama a fun��o que colocar� as linhas na posi��o certa usando uma matriz auxiliar C;
    }
    Transmitir_para_A(); // Chama a fun��o que passar� a matriz triangularizada C para a matriz inicial A.
    imprimirA();        // Imprime a matriz A.
    imprimir_Trocas(); // Imprime os movimentos para voltar a matriz triangularizada.
}

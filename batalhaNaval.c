#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

    char letras[10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};    
    // Tabuleiro
    int tabuleiro [10][10];
    int i, j;
    // Navios
    int naviohori [3]= {3,3,3};
    int navioverti [3]= {3,3,3};
    // Cordenadas
    int linhahori = 2, colunahori = 6;
    int linhavertical = 2, colunavertical = 4;
    // Variavel para só mostrar a tabela se não tiver erro
    int erro = 0;


    // Iniciando tudo com 0 representando água
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionar o Navio horizontal no tabuleiro
    // Verificar se cabe no tabuleiro
    if (colunahori + 3 <= 10)
    {
        int posicionar = 1;
        for (i = 0; i < 3; i++)
        {
            if (tabuleiro [linhahori][colunahori + i] != 0)
            {
                posicionar = 0;
            }   
        }   
    //Posicionr se estiver livre
    if (posicionar)
    {
        for (i = 0; i < 3; i++)
        {
            tabuleiro [linhahori][colunahori + i] = naviohori[i];
        }        
    }else{
        printf("Navio horizontal sobrepoe outro navio!\n");
        erro = 1;
    }
    }else{
        printf("Navio horizontal fora do tabuleiro!\n");
        erro = 1;
    }
 
    // Navi Vertical
      if (linhavertical + 3 <= 10) {

        // Verifica sobreposição
        int posicionar = 1;
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhavertical + i][colunavertical] != 0) {
                posicionar = 0;
            }
        }

        // Posiciona se estiver livre
        if (posicionar) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linhavertical + i][colunavertical] = navioverti[i];
            }
        } else {
            printf("Navio vertical sobrepõe outro navio!\n");
            erro = 1;
        }

    } else {
        printf("Navio vertical fora do tabuleiro!\n");
        erro = 1;
    }
    
    // Mostrando o tabuleiro

    if(erro == 0){
        for (i = 0; i < 10; i++)
    {
        printf("%c ", letras[i]);
        for (j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
    
     return 0;
}

    
   
    
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

   
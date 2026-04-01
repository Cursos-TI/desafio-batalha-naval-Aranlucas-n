#include <stdio.h>

#define linha 10
#define coluna 10

int main(){

    char letras[10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};  
    int numeros []= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    // Tabuleiro
    int tabuleiro [linha][coluna];
    // Navios
    int naviohori [3]= {3,3,3};
    int navioverti [3]= {3,3,3};
    int naviodiagonal [3]= {3,3,3};
    int naviodiagonal2 [3]= {3,3,3};
    // Cordenadas
    int linhahori, colunahori;
    int linhavertical, colunavertical;
    int linhadiagonal1, colunadiagonal1;
    int linhadiagonal2, colunadiagonal2;
    // Variavel para só mostrar a tabela se não tiver erro
    int erro = 0;

    printf("### Jogo de Batalha Naval ###\n\n");

    // Solcitar entrada de dados do usuario
    printf("Digite a linha e a coluna do navio 1 horizontal (0 a 9) dois valores:");
    scanf("%d %d", &linhahori, &colunahori);

    printf("Digite a linha e a coluna do navio 2 vertical (0 a 9) dois valores:");
    scanf("%d %d", &linhavertical, &colunavertical);

    printf("Digite a linha e a coluna do navio 3 diagonal (\\)(0 a 9) dois valores:");
    scanf("%d %d", &linhadiagonal1, &colunadiagonal1);

    printf("Digite a linha e a coluna do navio 4 diagonal (/)(0 a 9) dois valores:");
    scanf("%d %d", &linhadiagonal2, &colunadiagonal2);
   
    printf("\n");



    // Iniciando tudo com 0 representando água
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio 1
    // Posicionar o Navio horizontal no tabuleiro
    // Verificar se cabe no tabuleiro
    if (linhahori >= 0 && linhahori < linha && colunahori >= 0 && colunahori + 2 < coluna){
        int posicionar = 1;
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro [linhahori][colunahori + i] != 0)
            {
                posicionar = 0;
                break;
            }   
        }   
    //Posicionr se estiver livre
    if (posicionar){
        for (int i = 0; i < 3; i++)
        {
            tabuleiro [linhahori][colunahori + i] = naviohori[i];
        }        
    }else{
        printf("Navio 1 horizontal sobrepõe outro navio!\n");
        erro = 1;
    }
    }else{
        printf("Navio 1 horizontal fora do tabuleiro!\n");
        erro = 1;
    }
 
    // Navio 2 Vertical
      if (colunavertical >= 0 && colunavertical < coluna && linhavertical >= 0 && linhavertical + 2 < linha) {

        // Verifica sobreposição
        int posicionar = 1;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhavertical + i][colunavertical] != 0) {
                posicionar = 0;
                break;
            }
        }
        // Posiciona se estiver livre
        if (posicionar) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linhavertical + i][colunavertical] = navioverti[i];
             }
        } else {
            printf("Navio 2 vertical sobrepõe outro navio!\n");
            erro = 1;
        }
    } else {
        printf("Navio 2 vertical fora do tabuleiro!\n");
        erro = 1;
    }

    //Navio 3 diagonal 1
    if(linhadiagonal1 >= 0 && colunadiagonal1 >= 0 && linhadiagonal1 + 2 < linha && colunadiagonal1 +2 < coluna){
        int posicionar = 1;
        for (int i = 0; i < 3; i++){
            if(tabuleiro [linhadiagonal1 + i] [colunadiagonal1 + i] != 0){
                posicionar = 0;
                break;
            }
        } if (posicionar){
            for (int i = 0; i < 3; i++){
                tabuleiro[linhadiagonal1 + i][colunadiagonal1 + i] = naviodiagonal[i];
             }        
        }else{
            printf("Navio 3 diagonal sobrepõe outro navio!\n");
            erro = 1;
        }
    } else{
        printf("Navio 3 diagonal fora do tabuleiro!\n");
        erro = 1;
    }

    //Navio 4 diagonal 2
    if(linhadiagonal2 >= 0 && colunadiagonal2 >=0 && linhadiagonal2 + 2 < linha && colunadiagonal2 - 2 >= 0){
        int posicionar = 1;
        for(int i = 0; i < 3; i++){
            if(tabuleiro[linhadiagonal2 + i][colunadiagonal2 - i] != 0){
                posicionar = 0;
                break;
            }
        }if(posicionar){
            for (int i = 0; i < 3; i++){
                tabuleiro[linhadiagonal2 + i][colunadiagonal2 - i] = naviodiagonal2[i];
            }            
        }else{
            printf("Navio 4 diagonal sobrepõe outro navio!\n");
            erro = 1;
        
        }
    }else{
        printf("Navio 4 diagonal fora do tabuleiro!\n");
        erro = 1;
    }

    //Criando as habilidades
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    //Cone
    for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
        if (j >= 2 - i && j <= 2 + i)
            cone[i][j] = 1;
            else
            cone[i][j] = 0;          
        }
    }

    //Cruz
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i == 2 || j == 2)
            cruz[i][j] = 1;
            else
            cruz[i][j] = 0;
        }
    }
    //Octaedro
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            
            int lin1 = i - 2; int colun1 = j - 2;
            if (lin1 < 0) lin1 = -lin1;
            if (colun1 < 0) colun1 = -colun1;
            
            octaedro[i][j] = (lin1 + colun1 <= 2);
        }
    }
    //Definir as posições

    int linhaCone = 2, colunaCone = 2;
    int linhaCruz = 5, colunaCruz = 5;
    int linhaOct = 7, colunaOct = 7;
    
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            
            int l, c;

            //Cone
            l = linhaCone + i - 2;
            c = colunaCone + j - 2;
            if (l >= 0 && l < linha && c >= 0 && c < coluna){
            if (cone[i][j] == 1 && tabuleiro[l][c] == 0){
                tabuleiro[l][c] = 5;
        } 
      }
            //CRUZ
            l = linhaCruz + i - 2;
            c = colunaCruz + j - 2;

            if (l >= 0 && l < linha && c >= 0 && c < coluna){
            if (cruz[i][j] == 1 && tabuleiro[l][c] == 0){
                tabuleiro[l][c] = 5;
            }
        }

            // OCTAEDRO
            l = linhaOct + i - 2;
            c = colunaOct + j - 2;

            if (l >= 0 && l < linha && c >= 0 && c < coluna){
            if (octaedro[i][j] == 1 && tabuleiro[l][c] == 0){
                tabuleiro[l][c] = 5;
            }
        }
    }
  } 

    // Imprimir o tabuleiro

    if(erro == 0){
        printf("   ");
         for (int i = 0; i < linha; i++){    
            printf("%c ", letras[i]);
    } 
    printf("\n");

        for (int i = 0; i < linha; i++){
            printf("%2d ", numeros[i]);
            for (int j = 0; j < coluna; j++){    
            printf("%d ", tabuleiro[i][j]);
        }
       printf("\n"); 
    }
}
    
     return 0;
}
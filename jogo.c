#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

//info j1
char nomeJ1[15];
char J1;
int j1_posX = 1;
int j1_posY = 1;
int j1_movimentos = 30;
int j1_pontos = 0;
//o jogo
char bolinho = '@';
int bolinhoPosX;
int bolinhoPosY;
char tabuleiro[15][15];
int jogar = 0;

int GetRandom(int min, int max);
void selecionarModoDeJogo();
void jogar1();
void gameOver();
char mainMenu();
void menuComoJogar();
void configurarUmJogador();
void configurarDoisJogadores();
void cabecalho1J();
void desenharTabuleiro();
void novoBolinho();
void configurarUmJogador();
void j1_Input();
void gameOver();

int main(void){
    selecionarModoDeJogo();
    system("cls");
}

int GetRandom(int min, int max){
    int num = (rand() % 
           (max - min + 1)) + min;
    return num;
}

char mainMenu(){
    system("cls");
    printf("==============================================\n");
    printf("|============================================|\n");
    printf("|                    MENU                    |\n");
    printf("==============================================\n");
    printf("| 1 - um jogador                             |\n");
    printf("| 2 - como jogar                             |\n");
    printf("| 0 - sair                                   |\n");
    printf("----------------------------------------------\n");
    printf("|                                            |\n");
    printf("| clube dos mini gaymeiros 2020\xA9             |\n");
    printf("|============================================|\n");
    printf("==============================================\n");
    return getch();
}

void selecionarModoDeJogo(){
    char escolha = mainMenu();
    switch (escolha)
    {
    case '1':
        configurarUmJogador();
        break;
    case '2':
        menuComoJogar();
        break;
    case '0':
        system("cls");
        break;
    default:
        break;
    }
}

void menuComoJogar(){
    system("cls");
    printf("==============================================\n");
    printf("|                   COMO JOGAR               |\n");
    printf("==============================================\n");
    printf("| Setas do teclado para andar                |\n");
    printf("| Pegue o maximo de bolinhos que conseguir   |\n");
    printf("| antes de ficar sem movimentos              |\n");
    printf("|                                            |\n");
    printf("| 0 - voltar                                 |\n");
    printf("==============================================\n");
    if(getch() == 48)
        selecionarModoDeJogo();
}

void novoBolinho(){
    j1_pontos++;
    j1_movimentos += 8;
    bolinhoPosX = GetRandom(2,13);
    bolinhoPosY = GetRandom(2,13);
}

void desenharTabuleiro(){
    cabecalho1J();
    int i = 0;
    int j = 0;
    for(i = 0; i < 15; i++){
        
        for(j = 0; j < 15; j++){
            if(j1_posX == j && j1_posY == i){
                tabuleiro[i][j] = J1;
            }
            else if(i == bolinhoPosX && j == bolinhoPosY){
                tabuleiro[i][j] = bolinho;
            }
            else if(i == 0 || j == 0){
                tabuleiro[i][j] = '#';
            }else if(i == 14 || j == 14){
                tabuleiro[i][j] = '#';
            }
            else{
                tabuleiro[i][j] = '.';
            }
            printf("%c ", tabuleiro[i][j]);
        }
        
        printf("\n");
    }

void configurarUmJogador(){

    system("cls");
    printf("==============================================\n");
    printf("|                   UM JOGADOR               |\n");
    printf("==============================================\n");
    printf("| Insira seu nome:                           |\n");
    fflush(stdin);
    gets(nomeJ1);   
    J1 = toupper(nomeJ1[0]);
    jogar = 1;
    j1_posX = 1;
    j1_posY = 1;
    j1_pontos = 0;
    j1_movimentos = 30;
    jogar1();
}

void jogar1(){
    bolinhoPosX = GetRandom(2, 12);
    bolinhoPosY = GetRandom(2, 12);
    desenharTabuleiro();
    j1_Input();
}

void j1_Input(){

    while(jogar == 1){

        switch (getch())
        {
        case 72:
            //seta para cima
            if(j1_posY > 1){
                j1_movimentos--;
                j1_posY--;
                
                if(j1_movimentos == 0){
                    jogar = 0;
                    gameOver(); 
                } 

                if(j1_posY == bolinhoPosX && j1_posX == bolinhoPosY) novoBolinho();

                desenharTabuleiro();
            }
            break;
        case 80:
            //seta para baixo
            if(j1_posY < 13){
                j1_movimentos--;
                j1_posY++;
                
                if(j1_movimentos == 0){
                    jogar = 0;
                    gameOver(); 
                } 

                if(j1_posY == bolinhoPosX && j1_posX == bolinhoPosY) novoBolinho();

                desenharTabuleiro();
            }
            break;
        case 75:
            //seta para esquerda
            if(j1_posX > 1){
                j1_movimentos--;
                j1_posX--;
                
                if(j1_movimentos == 0){
                    jogar = 0;
                    gameOver();
                } 

                if(j1_posY == bolinhoPosX && j1_posX == bolinhoPosY) novoBolinho();

                desenharTabuleiro();
            }
            break;
        case 77:
            //seta para direita
            if(j1_posX < 13){
                j1_movimentos--;
                j1_posX++;
                
                if(j1_movimentos == 0){
                    jogar = 0;
                    gameOver(); 
                } 

                if(j1_posY == bolinhoPosX && j1_posX == bolinhoPosY) novoBolinho();

                desenharTabuleiro();
            }
            break;
        case 48:
            jogar = 0;
            selecionarModoDeJogo();
            break;
        
        }

    }

}

void cabecalho1J(){
    system("cls");
    printf("==============================================\n");
    printf("| Nome - %s                                 |\n", nomeJ1);
    printf("| pontos - %04d                              |\n", j1_pontos);
    printf("| movimentos restantes - %04d                |\n", j1_movimentos);
    printf("| 0 para sair                                |\n");
}

void gameOver(){
    system("cls");
    printf("==============================================\n");
    printf("|                                            |\n");
    printf("|                   GAME OVER                |\n");
    printf("==============================================\n");
    printf("| 1 - Voltar ao Menu                         |\n");
    printf("| voce fez %04d pontos                   |\n");
    printf("==============================================\n");
    switch (getch())
    {
    case 49:
        selecionarModoDeJogo();
        break;
    default:
        gameOver();
        break;
    }
}

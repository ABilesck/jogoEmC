#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

char nome1[15];
char jogador1;
char nome2[15];
char jogador2;

int main(void){

    printf("Nome 1:\n");
    gets(nome1);
    printf("Nome 2:\n");
    gets(nome2);
    jogador1 = toupper(nome1[0]);
    jogador2 = toupper(nome2[0]);
    if(jogador1 == jogador2)
        jogador2 = toupper(nome2[1]);

    printf("Jogador 1 nome %s - %c\n", nome1, jogador1);
    printf("Jogador 2 nome %s - %c\n", nome2, jogador2);

}
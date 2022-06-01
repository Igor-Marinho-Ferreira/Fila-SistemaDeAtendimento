#ifndef DESIGN_H_INCLUDED
#define DESIGN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

COORD coord={0,0};

void gotoxy(int x, int y){
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void desenha(int x, int y, int largura, int altura)
{
//LINHAS HORIZONTAIS
    int i;
    for(i=x+1; i<largura; i++)
    {
        gotoxy(i,y);
        printf("%c",205); // 205 linha  horizontais na tabela ASCII
    }
    //LINHAS VERTICAIS
    for(i=y+1; i<altura; i++)
    {
        gotoxy(x,i);
        printf("%c",186);  //186 linha verticais na tabela ASCII
        gotoxy(largura,i);
        printf("%c",186);
    }

    /*cantos*/
   gotoxy(largura,y);
   printf("%c",187);
   gotoxy(x,y);
   printf("%c",201);
}

void dicaDeTela(char dica[])
{
    desenha(0,26,126,30);
    gotoxy(20,26);
    printf(" AJUDA ");
    gotoxy(20, 27);
    printf("%s",dica);
}

void desenhaJanela()
{
    desenha(0,0,126,27);
    gotoxy(50,0);
    printf(" SISTEMA DE SENHAS ");
}

void ajustaJanela()
{
    system("MODE con cols=127 lines=30 ");

//Nao permite redimensionar
    SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

#endif
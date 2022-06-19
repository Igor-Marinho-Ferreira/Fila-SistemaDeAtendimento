#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "gerador.h"

void SelecionarMenuPrincipal(){
    int Opcao;
    Senha* senhas = inicializaSenha(); 
	SenhasChamadas* senhasChamadas = inicializaSenhasChamadas();
	int cp = 2; 
	int qtdPrioridade = 0; 
	int qtdNormal = 0; 
    do{
        desenhaJanela();
        dicaDeTela("Digite um numero correspondente a opcao desejada ou 0 (ZERO) para SAIR");
        desenha(24,5,100,20);
        gotoxy(26,5);
        printf(" MENU ");
        gotoxy(26,7);
        printf("1 - Geracao de senha normal");
        gotoxy(26,8);
        printf("2 - Geracao de senha preferencial");
        gotoxy(26,9);
        printf("3 - Chamar senha");
        gotoxy(26,10);
        printf("4 - Senhas em espera");
        gotoxy(26,11);
        printf("0 - Sair");
        gotoxy(24,20);
        printf("Selecione qual o tipo de operacao deseja realizar: ");
        scanf("%d",&Opcao);
        switch (Opcao){
            case 0:
                system("cls");
                gotoxy(0,0);
                printf("ENCERRADO!");
                sleep(1);
                break;
            case 1:
                system("cls");
                gerarSenha(&senhas, qtdNormal, qtdPrioridade,0);
                qtdNormal++;
                sleep(3);
                system("cls");
                break;
            case 2:
                system("cls");
                gerarSenha(&senhas, qtdNormal, qtdPrioridade, 1);
                qtdPrioridade++;
                sleep(3);
                system("cls");
                break;
            case 3:
                system("cls");
                chamar(&senhas, &senhasChamadas, &cp);
                sleep(3);
                system("cls");
                break;
            case 4:
                system("cls");
                listarSenhas(senhas);
                system("pause");
                system("cls");
        }        
    }while (Opcao != 0);
}

#endif
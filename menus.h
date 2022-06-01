#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void SelecionarMenuPrincipal(){
    int Opcao;
    do{
        desenhaJanela();
        dicaDeTela("Digite um numero correspondente a opcao desejada ou 0 (ZERO) para SAIR");
        desenha(24,5,100,20);
        gotoxy(26,5);
        printf(" MENU ");
        gotoxy(26,7);
        printf("1 - Geracao de senha");
        gotoxy(26,8);
        printf("2 - Chamada de senha");
        gotoxy(26,9);
        printf("3 - Listagem da fila");
        gotoxy(26,10);
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
                MenuGsenha();
                break;
            case 2:
                system("cls");
                ChamadaSenha();
                break;
            case 3:
                break;
        }        
    }while (Opcao != 0);
}

void MenuGsenha(){
    int Opcao;
    do{
        desenhaJanela();
        dicaDeTela("Digite um numero correspondente a opcao desejada ou 0 (ZERO) para SAIR");
        desenha(24,5,100,20);
        gotoxy(26,5);
        printf(" MENU ");
        gotoxy(26,7);
        printf("1 - Geracao de senha normal");
        gotoxy(26,8);
        printf("2 - Chamada de senha preferencial");
        gotoxy(26,9);
        printf("0 - Voltar");
        gotoxy(24,20);
        printf("Selecione qual o tipo de operacao deseja realizar: ");
        scanf("%d",&Opcao);
        switch (Opcao){
            case 0:
                system("cls");
                SelecionarMenuPrincipal();
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }        
    }while (Opcao != 0);
}

void ChamadaSenha(){
    int Opcao;
    do{
        desenhaJanela();
        dicaDeTela("Digite um numero correspondente a opcao desejada ou 0 (ZERO) para SAIR");
        desenha(24,5,100,20);
        gotoxy(26,5);
        printf(" MENU ");
        gotoxy(26,7);
        printf("1 - Geracao de senha normal");
        gotoxy(26,8);
        printf("2 - Chamada de senha preferencial");
        gotoxy(26,9);
        printf("0 - Voltar");
        gotoxy(24,20);
        printf("Selecione qual o tipo de operacao deseja realizar: ");
        scanf("%d",&Opcao);
        switch (Opcao){
            case 0:
                system("cls");
                SelecionarMenuPrincipal();
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }        
    }while (Opcao != 0);
}
#endif
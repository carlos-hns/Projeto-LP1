#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Participantes.h"
#include "Uteis.h"
#include "Eventos.h"

void gerar_topo(int colunas, char *frase){

    char *string1 = "*****  ****    **  ******  *****  ******";
    char *string2 = "**     ** **   **  **      **     **    ";
    char *string3 = "***    **  **  **  **      ****   **    ";
    char *string4 = "**     **   ** **  **      **     **    ";
    char *string5 = "*****  **    ****  ******  *****  ******";
    char *string6 = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    int meio1 = calcular_meio(colunas, string1);
    int meio2 = calcular_meio(colunas, string2);
    int meio3 = calcular_meio(colunas, string3);
    int meio4 = calcular_meio(colunas, string4);
    int meio5 = calcular_meio(colunas, string5);
    int meio6 = calcular_meio(colunas, string6);

    gotoxy(meio1, 2);
    puts(string1);

    gotoxy(meio2, 3);
    puts(string2);

    gotoxy(meio3, 4);
    puts(string3);

    gotoxy(meio4, 5);
    puts(string4);

    gotoxy(meio5, 6);
    puts(string5);

    gotoxy(meio6, 9);
    puts(string6);

    int meio = calcular_meio(colunas, frase);
    gotoxy(meio, 8);
    puts(frase);

    gotoxy(0, 11);
}

void menu_principal(int colunas){

    //ENCEC

    char *string1 = "*****  ****    **  ******  *****  ******";
    char *string2 = "**     ** **   **  **      **     **    ";
    char *string3 = "***    **  **  **  **      ****   **    ";
    char *string4 = "**     **   ** **  **      **     **    ";
    char *string5 = "*****  **    ****  ******  *****  ******";
    char *string6 = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    int meio1 = calcular_meio(colunas, string1);
    int meio2 = calcular_meio(colunas, string2);
    int meio3 = calcular_meio(colunas, string3);
    int meio4 = calcular_meio(colunas, string4);
    int meio5 = calcular_meio(colunas, string5);
    int meio6 = calcular_meio(colunas, string6);

    gotoxy(meio1, 2);
    puts(string1);

    gotoxy(meio2, 3);
    puts(string2);

    gotoxy(meio3, 4);
    puts(string3);

    gotoxy(meio4, 5);
    puts(string4);

    gotoxy(meio5, 6);
    puts(string5);

    gotoxy(meio6, 8);
    puts(string6);

    int meio;
    char *string = "1 - PESSOAS";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 12);
    puts(string);

    string = "2 - EVENTOS";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 13);
    puts(string);

    string = "3 - SAIR";
    gotoxy(meio, 14);
    puts(string);

    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);

}

void menu_organizacao(int colunas){

    char *string1 = "*****  ****    **  ******  *****  ******";
    char *string2 = "**     ** **   **  **      **     **    ";
    char *string3 = "***    **  **  **  **      ****   **    ";
    char *string4 = "**     **   ** **  **      **     **    ";
    char *string5 = "*****  **    ****  ******  *****  ******";
    char *string6 = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    int meio1 = calcular_meio(colunas, string1);
    int meio2 = calcular_meio(colunas, string2);
    int meio3 = calcular_meio(colunas, string3);
    int meio4 = calcular_meio(colunas, string4);
    int meio5 = calcular_meio(colunas, string5);
    int meio6 = calcular_meio(colunas, string6);

    gotoxy(meio1, 2);
    puts(string1);

    gotoxy(meio2, 3);
    puts(string2);

    gotoxy(meio3, 4);
    puts(string3);

    gotoxy(meio4, 5);
    puts(string4);

    gotoxy(meio5, 6);
    puts(string5);

    gotoxy(meio6, 8);
    puts(string6);

    int meio;
    char *string = "1 - Congressistas";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 12);
    puts(string);

    string = "2 - Palestrantes";
    gotoxy(meio, 13);
    puts(string);

    string = "3 - Organizadores";
    gotoxy(meio, 14);
    puts(string);

    string = "4 - Voltar";
    gotoxy(meio, 15);
    puts(string);


    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);
}

void menu_congressistas(int colunas){

    char *string1 = "*****  ****    **  ******  *****  ******";
    char *string2 = "**     ** **   **  **      **     **    ";
    char *string3 = "***    **  **  **  **      ****   **    ";
    char *string4 = "**     **   ** **  **      **     **    ";
    char *string5 = "*****  **    ****  ******  *****  ******";
    char *string6 = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    int meio1 = calcular_meio(colunas, string1);
    int meio2 = calcular_meio(colunas, string2);
    int meio3 = calcular_meio(colunas, string3);
    int meio4 = calcular_meio(colunas, string4);
    int meio5 = calcular_meio(colunas, string5);
    int meio6 = calcular_meio(colunas, string6);

    gotoxy(meio1, 2);
    puts(string1);

    gotoxy(meio2, 3);
    puts(string2);

    gotoxy(meio3, 4);
    puts(string3);

    gotoxy(meio4, 5);
    puts(string4);

    gotoxy(meio5, 6);
    puts(string5);

    gotoxy(meio6, 8);
    puts(string6);

    int meio;
    char *string = "1 - Cadastrar Congressista";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 12);
    puts(string);

    string = "2 - Remover Congressista";
    gotoxy(meio, 13);
    puts(string);

    string = "3 - Alterar Dados de um Congressista";
    gotoxy(meio, 14);
    puts(string);

    string = "4 - Listar Congresistas";
    gotoxy(meio, 15);
    puts(string);

    string = "5 - Quantidade Congressistas";
    gotoxy(meio, 16);
    puts(string);

    string = "6 - Inserir Congressista em um Evento";
    gotoxy(meio, 17);
    puts(string);

    string = "7 - Remover Congressista de um Evento";
    gotoxy(meio, 18);
    puts(string);

    string = "8 - Voltar";
    gotoxy(meio, 19);
    puts(string);

    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);
}

void menu_organizadores(int colunas){

    int i;
    for (i=0; i<colunas; i++){
        printf("=");
    }

    int meio = (colunas - strlen("ENEC - ORGANIZADORES")) / 2;
    for (i=0; i < meio; i++){
        printf(" ");
    }

    printf("ENEC - ORGANIZADORES\n");

    for (i=0; i<colunas; i++){
        printf("=");
    }

    printf("\n\n");

    printf("|1| - Cadastrar Organizador\n");
    printf("|2| - Remover Organizador\n");
    printf("|3| - Alterar Dados de um Organizador\n");
    printf("|4| - Listar Organizadores\n");
    printf("|5| - Quantidade Organizadores\n");
    printf("|6| - Voltar\n");
    printf(">>> ");

}

void menu_palestrantes(int colunas){


    int i;
    for (i=0; i<colunas; i++){
        printf("=");
    }

    int meio = (colunas - strlen("ENEC - PALESTRANTES")) / 2;
    for (i=0; i < meio; i++){
        printf(" ");
    }

    printf("ENEC - PALESTRANTES\n");

    for (i=0; i<colunas; i++){
        printf("=");
    }

    printf("\n\n");

    printf("|1| - Cadastrar Palestrante\n");
    printf("|2| - Remover Palestrante\n");
    printf("|3| - Alterar Dados de um Palestrante\n");
    printf("|4| - Listar Palestrantes\n");
    printf("|5| - Quantidade Palestrantes\n");
    printf("|6| - Voltar\n");
    printf(">>> ");
}

main(){

    // ALTERA A COMPOSI플O DA JANELA (COR/TAMANHO)
    system("Color 4F");
    system("mode con:cols=80 lines=30");

    // VARIAVEIS RESPONSAVEIS PELA MOVIMENTA플O NO MENU
    char menu_principal_escolha;
    char menu_organizacao_escolha;
    int menu_congressista_escolha;
    int menu_organizadores_escolha;
    int menu_palestrantes_escolha;

    // VERIFICACA SE OS ARQUIVOS J� FORAM CRIADOS
    FILE *locais;
    locais = fopen("Arquivos\\locais.txt", "rb");
    if (locais == NULL){
        gerar_locais_zerados();
    }

    fclose(locais);

    // LOCAL DE TESTE DA MAIN!

    //inserir_congressista_evento();

    //Sleep(100000);

    // INICIO DO PROGRAMA

    do {
        system("cls");
        menu_principal(80);
        menu_principal_escolha = getch();

        switch(menu_principal_escolha){
        // ESCOLHA ORGANIZACAO
        case '1':
            do {
                system("cls");
                menu_organizacao(80);
                menu_organizacao_escolha = getch();

                switch(menu_organizacao_escolha){
                // ESCOLHA CONGRESSISTA
                case '1':
                    do {
                        system("cls");
                        menu_congressistas(80);
                        menu_congressista_escolha = getch();
                        int saida;

                        switch(menu_congressista_escolha){
                        case '1':
                            system("cls");
                            gerar_topo(80, "CADASTRANDO CONGRESSISTA");
                            saida = cadastrar_congressista();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO");
                            } else if (saida == -2){
                                printf("\n==> LIMITE DE CONGRESSISTAS ATINGIDO");
                            } else if(saida == 0){
                                printf("\n==> CONGRESSISTA CADASTRADO COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '2':
                            system("cls");
                            gerar_topo(80, "REMOVENDO CONGRESSISTA");
                            saida = remover_congressista();

                            if (saida == -1){
                                printf("\n\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO");
                            } else if (saida == -2){
                                printf("\n==> CONGRESSISTAS NAO CADASTRADOS");
                            } else if (saida == 0){
                                printf("\n==> CONGRESSSISTA REMOVIDO COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '3':
                            system("cls");
                            gerar_topo(80, "EDITANDO CONGRESSISTA");
                            saida = editar_congressista();

                            if (saida == -1){
                                printf("\n\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO");
                            } else if (saida == -2){
                                printf("\n==> CONGRESSISTAS NAO CADASTRADOS");
                            } else if (saida == 0){
                                printf("\n==> CONGRESSSISTA EDITADO COM SUCESSO");
                            }

                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        case '4':
                            system("cls");
                            gerar_topo(80, "LISTANDO CONGRESSISTAS");
                             if (listar_congressistas() == -1){
                                printf("\n\n==> CONGRESSISTAS NAO CADASTRADOS");
                             }
                             setbuf(stdin, NULL);
                             getchar();
                             break;
                        case '5':
                            system("cls");
                            gerar_topo(80, "CONGRESSISTAS CADASTRADOS");
                            if (quantidade_congressistas() == 0 || quantidade_congressistas() == -1){
                                printf("\n\n==> CONGRESSISTAS NAO CADASTRADOS");
                            } else {
                                printf("\n\n==> %d CONGRESSISTA(S) CADASTRADO(S)", quantidade_congressistas());
                            }
                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        case '6':
                            printf("OXI");
                        case '7':
                            printf("OXIII");
                        }
                    } while(menu_congressista_escolha != '8');
                    break;
                // ESCOLHA PALESTRANTE
                case '2':
                    do {
                        system("cls");
                        menu_palestrantes(80);
                        scanf("%d", &menu_palestrantes_escolha);

                        switch(menu_palestrantes_escolha){
                        case 1:
                            system("cls");
                            gerar_topo(80, "CADASTRANDO PALESTRANTE");
                            if (cadastrar_palestrante() == -1){
                                printf("==> NAO FOI POSSIVEL CADASTRAR\n");
                            } else {
                                printf("\n==> PALESTRANTE CADASTRADO COM SUCESSO!\n");
                            }
                            Sleep(1000);
                            break;
                        case 2:
                            system("cls");
                            gerar_topo(80, "REMOVER PALESTRANTE");

                            if (remover_palestrante() == -1){
                                printf("\n\n==> PALESTRANTE NAO CADASTRADO!\n");
                            } else {
                                printf("\n\n==> PALESTRANTE REMOVIDO COM SUCESSO!\n");
                            }
                            Sleep(1000);
                            break;
                        case 3:
                            system("cls");
                            gerar_topo(80, "EDITAR PALESTRANTE");
                             if (editar_palestrante() == -1){
                                printf("\n\n==> PALESTRANTES NAO CADASTRADOS!");
                             } else {
                                printf("\n==> PALESTRANTE ALTERADO COM SUCESSO!\n");
                             }

                             setbuf(stdin, NULL);
                             getchar();
                            break;
                        case 4:
                            system("cls");
                            gerar_topo(80, "LISTANDO PALESTRANTES");
                             if (listar_palestrantes() == -1){
                                printf("\n\n==> PALESTRANTES NAO CADASTRADOS!");
                             }
                             setbuf(stdin, NULL);
                             getchar();
                             break;
                        case 5:
                            system("cls");
                            gerar_topo(80, "PALESTRANTES CADASTRADOS");
                            if (quantidade_palestrantes() == 0 || quantidade_palestrantes() == -1){
                                printf("\n\n==> PALESTRANTES NAO CADASTRADOS!");
                            } else {
                                printf("\n\n==> %d PALESTRANTE(S) CADASTRADOS!", quantidade_palestrantes());
                            }
                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        }
                    } while(menu_palestrantes_escolha != 6);
                    break;
                // ESCOLHA ORGANIZADOR
                case '3':
                    do {
                        system("cls");
                        menu_organizadores(80);
                        scanf("%d", &menu_organizadores_escolha);

                        switch(menu_organizadores_escolha){
                        case 1:
                            system("cls");
                            gerar_topo(80, "CADASTRANDO ORGANIZADOR");
                            cadastrar_organizador();
                            printf("\n==> ORGANIZADOR CADASTRADO COM SUCESSO!\n");
                            Sleep(1000);
                            break;
                        case 2:
                            system("cls");
                            gerar_topo(80, "REMOVER ORGANIZADOR");
                             if (remover_organizador() == -1){
                                printf("\n\n==> ORGANIZADORES NAO CADASTRADOS!");
                             }
                            Sleep(1000);
                            break;
                        case 3:
                            system("cls");
                            gerar_topo(80, "EDITAR ORGANIZADOR");
                            // FALTA CRIAR ESSA BEN플O
                             if (editar_organizador() == -1){
                                printf("\n\n==> ORGANIZADORES NAO CADASTRADOS!");
                             }
                             printf("\n==> ORGANIZADOR ALTERADO COM SUCESSO\n");
                             setbuf(stdin, NULL);
                             getchar();
                            break;
                        case 4:
                            system("cls");
                            gerar_topo(80, "LISTANDO ORGANIZADORES");
                             if (listar_organizadores() == -1){
                                printf("\n\n==> ORGANIZADORES NAO CADASTRADOS!");
                             }
                             setbuf(stdin, NULL);
                             getchar();
                             break;
                        case 5:
                            system("cls");
                            gerar_topo(80, "ORGANIZADORES CADASTRADOS");
                            if (quantidade_organizadores() == 0 || quantidade_organizadores() == -1){
                                printf("\n\n==> ORGANIZADORES NAO CADASTRADOS!");
                            } else {
                                printf("\n\n==> %d ORGANIZADOR(ES) CADASTRADOS!", quantidade_organizadores());
                            }
                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        }
                    } while(menu_organizadores_escolha != 6);
                    break;
                }
            } while (menu_organizacao_escolha != '4');
        }
    } while (menu_principal_escolha != '3');




}

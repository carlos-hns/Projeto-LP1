#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Participantes.h"
#include "Uteis.h"
#include "Eventos.h"

void gerar_topo(int colunas, char *frase){

    int i;
    for (i=0; i<colunas; i++){
        printf("=");
    }

    int meio = (colunas - (strlen(frase) + strlen("ENEC - "))) / 2;
    for (i=0; i < meio; i++){
        printf(" ");
    }

    printf("ENEC - %s\n", frase);

    for (i=0; i<colunas; i++){
        printf("=");
    }
}

void menu_principal(int colunas){

    int i;
    for (i=0; i<colunas; i++){
        printf("=");
    }

    int meio = (colunas - strlen("ENEC - MENU PRINCIPAL")) / 2;
    for (i=0; i < meio; i++){
        printf(" ");
    }

    printf("ENEC - MENU PRINCIPAL\n");

    for (i=0; i<colunas; i++){
        printf("=");
    }

    printf("\n\n");

    printf("|1| - ORGANIZACAO\n");
    printf("|2| - EVENTOS\n");
    printf("|3| - SAIR\n");
    printf(">>> ");
}

void menu_organizacao(int colunas){

    int i;
    for (i=0; i<colunas; i++){
        printf("=");
    }

    int meio = (colunas - strlen("ENEC - ORGANIZACAO")) / 2;
    for (i=0; i < meio; i++){
        printf(" ");
    }

    printf("ENEC - ORGANIZACAO\n");

    for (i=0; i<colunas; i++){
        printf("=");
    }

    printf("\n\n");

    printf("|1| - Congressistas\n");
    printf("|2| - Palestrantes\n");
    printf("|3| - Organizadores\n");
    printf("|4| - Voltar\n");
    printf(">>> ");
}

void menu_congressistas(int colunas){

    int i;
    for (i=0; i<colunas; i++){
        printf("=");
    }

    int meio = (colunas - strlen("ENEC - CONGRESSISTAS")) / 2;
    for (i=0; i < meio; i++){
        printf(" ");
    }

    printf("ENEC - CONGRESSISTAS\n");

    for (i=0; i<colunas; i++){
        printf("=");
    }

    printf("\n\n");

    printf("|1| - Cadastrar Congressista\n");
    printf("|2| - Remover Congressista\n");
    printf("|3| - Alterar Dados de um Congressista\n");
    printf("|4| - Listar Congresistas\n");
    printf("|5| - Quantidade Congressistas\n");
    printf("|6| - Voltar\n");
    printf(">>> ");
}

main(){

    system("Color 3F");
    system("mode con:cols=80 lines=30");

    int menu_principal_escolha;
    int menu_organizacao_escolha;
    int menu_congressista_escolha;

    do {
        system("cls");
        menu_principal(80);
        scanf("%d", &menu_principal_escolha);

        switch(menu_principal_escolha){
        // ESCOLHA ORGANIZACAO
        case 1:
            do {
                system("cls");
                menu_organizacao(80);
                scanf("%d", &menu_organizacao_escolha);

                switch(menu_organizacao_escolha){
                // ESCOLHA CONGRESSISTA
                case 1:

                    do {
                        system("cls");
                        menu_congressistas(80);
                        scanf("%d", &menu_congressista_escolha);

                        switch(menu_congressista_escolha){
                        case 1:
                            system("cls");
                            gerar_topo(80, "CADASTRANDO CONGRESSISTA");
                            cadastrar_congressista();
                            Sleep(1000);
                            break;
                        case 2:
                            system("cls");
                            gerar_topo(80, "REMOVER CONGRESSISTA");
                             if (remover_congressista() == -1){
                                printf("\n\n==> CONGRESSISTAS NAO CADASTRADOS!");
                             }
                            Sleep(1000);
                            break;
                        case 3:
                            system("cls");
                            gerar_topo(80, "REMOVER CONGRESSISTA");
                             if (editar_congressista() == -1){
                                printf("\n\n==> CONGRESSISTAS NAO CADASTRADOS!");
                             }
                             setbuf(stdin, NULL);
                             getchar();
                            break;
                        case 4:
                            system("cls");
                            gerar_topo(80, "LISTANDO CONGRESSISTAS");
                             if (listar_congressistas() == -1){
                                printf("\n\n==> CONGRESSISTAS NAO CADASTRADOS!");
                             }
                             setbuf(stdin, NULL);
                             getchar();
                             break;
                        case 5:
                            system("cls");
                            gerar_topo(80, "CONGRESSISTAS CADASTRADOS");
                            if (quantidade_congressistas() == 0 || quantidade_congressistas() == -1){
                                printf("\n\n==> CONGRESSISTAS NAO CADASTRADOS!");
                            } else {
                                printf("\n\n==> %d CONGRESSISTAS CADASTRADOS!", quantidade_congressistas());
                            }
                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        }
                    } while(menu_congressista_escolha != 6);

                //case 2:



                }






            } while (menu_organizacao_escolha != 4);



        }





    } while (menu_principal_escolha != 3);




}

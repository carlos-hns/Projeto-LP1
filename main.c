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
    gotoxy(meio-1, 12);
    puts(string);

    string = "2 - EVENTOS";
    meio = calcular_meio(colunas, string);
    gotoxy(meio-1, 13);
    puts(string);

    string = "3 - SAIR";
    gotoxy(meio-1, 14);
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
    gotoxy(meio-3, 12);
    puts(string);

    string = "2 - Remover Congressista";
    gotoxy(meio-3, 13);
    puts(string);

    string = "3 - Alterar Dados de um Congressista";
    gotoxy(meio-3, 14);
    puts(string);

    string = "4 - Listar Congresistas";
    gotoxy(meio-3, 15);
    puts(string);

    string = "5 - Quantidade Congressistas";
    gotoxy(meio-3, 16);
    puts(string);

    string = "6 - Inserir Congressista em um Evento";
    gotoxy(meio-3, 17);
    puts(string);

    string = "7 - Remover Congressista de um Evento";
    gotoxy(meio-3, 18);
    puts(string);

    string = "8 - Voltar";
    gotoxy(meio-3, 19);
    puts(string);

    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);
}

void menu_organizadores(int colunas){

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
    char *string = "1 - Cadastrar Organizador";
    meio = calcular_meio(colunas, string);
    gotoxy(meio-3, 12);
    puts(string);

    string = "2 - Remover Organizador";
    gotoxy(meio-3, 13);
    puts(string);

    string = "3 - Alterar Dados de um Organizador";
    gotoxy(meio-3, 14);
    puts(string);

    string = "4 - Listar Organizadores";
    gotoxy(meio-3, 15);
    puts(string);

    string = "5 - Quantidade Organizadores";
    gotoxy(meio-3, 16);
    puts(string);

    string = "6 - Voltar";
    gotoxy(meio-3, 17);
    puts(string);


    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);
}

void menu_palestrantes(int colunas){

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
    char *string = "1 - Cadastrar Palestrante";
    meio = calcular_meio(colunas, string);
    gotoxy(meio-3, 12);
    puts(string);

    string = "2 - Remover Palestrante";
    gotoxy(meio-3, 13);
    puts(string);

    string = "3 - Alterar Dados de um Palestrante";
    gotoxy(meio-3, 14);
    puts(string);

    string = "4 - Listar Palestrantes";
    gotoxy(meio-3, 15);
    puts(string);

    string = "5 - Quantidade Palestrantes";
    gotoxy(meio-3, 16);
    puts(string);

    string = "6 - Voltar";
    gotoxy(meio-3, 17);
    puts(string);


    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);
}

void menu_eventos(int colunas){

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
    char *string = "1 - Palestras";
    meio = calcular_meio(colunas, string);
    gotoxy(meio-1, 12);
    puts(string);

    string = "2 - Grupo de Discussao";
    gotoxy(meio-1, 13);
    puts(string);

    string = "3 - Curso";
    gotoxy(meio-1, 14);
    puts(string);

    string = "4 - Oficina";
    gotoxy(meio-1, 15);
    puts(string);


    string = "5 - Voltar";
    gotoxy(meio-1, 16);
    puts(string);

    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);
}

void menu_palestras(int colunas){

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
    char *string = "1 - Cadastrar Palestra";
    meio = calcular_meio(colunas, string);
    gotoxy(meio-3, 12);
    puts(string);

    string = "2 - Remover Palestra";
    gotoxy(meio-3, 13);
    puts(string);

    string = "3 - Alterar Dados de uma Palestra";
    gotoxy(meio-3, 14);
    puts(string);

    string = "4 - Listar Palestras";
    gotoxy(meio-3, 15);
    puts(string);

    string = "5 - Quantidade Palestras";
    gotoxy(meio-3, 16);
    puts(string);

    string = "6 - Voltar";
    gotoxy(meio-3, 17);
    puts(string);


    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);
}

void menu_gp_discussao(int colunas){

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
    char *string = "1 - Cadastrar Grupo de Discussao";
    meio = calcular_meio(colunas, string);
    gotoxy(meio-3, 12);
    puts(string);

    string = "2 - Remover Grupo de Discussao";
    gotoxy(meio-3, 13);
    puts(string);

    string = "3 - Alterar Dados de uma Grupo de Discussao";
    gotoxy(meio-3, 14);
    puts(string);

    string = "4 - Listar Grupos de Discussoes";
    gotoxy(meio-3, 15);
    puts(string);

    string = "5 - Quantidade Grupos de Discussoes";
    gotoxy(meio-3, 16);
    puts(string);

    string = "6 - Voltar";
    gotoxy(meio-3, 17);
    puts(string);


    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);


}

void menu_curso(int colunas){


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
    char *string = "1 - Cadastrar Curso";
    meio = calcular_meio(colunas, string);
    gotoxy(meio-3, 12);
    puts(string);

    string = "2 - Remover Curso";
    gotoxy(meio-3, 13);
    puts(string);

    string = "3 - Alterar Dados de um Curso";
    gotoxy(meio-3, 14);
    puts(string);

    string = "4 - Listar Cursos";
    gotoxy(meio-3, 15);
    puts(string);

    string = "5 - Quantidade Cursos";
    gotoxy(meio-3, 16);
    puts(string);

    string = "6 - Voltar";
    gotoxy(meio-3, 17);
    puts(string);


    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);
}

void menu_oficina(int colunas){

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
    char *string = "1 - Cadastrar Oficina";
    meio = calcular_meio(colunas, string);
    gotoxy(meio-3, 12);
    puts(string);

    string = "2 - Remover Oficina";
    gotoxy(meio-3, 13);
    puts(string);

    string = "3 - Alterar Dados de uma Oficina";
    gotoxy(meio-3, 14);
    puts(string);

    string = "4 - Listar Oficinas";
    gotoxy(meio-3, 15);
    puts(string);

    string = "5 - Quantidade Oficinas";
    gotoxy(meio-3, 16);
    puts(string);

    string = "6 - Voltar";
    gotoxy(meio-3, 17);
    puts(string);


    string = "BY: CARLOS HENRIQUE";
    meio = calcular_meio(colunas, string);
    gotoxy(meio, 25);
    puts(string);
}

main(){

    // ALTERA A COMPOSI플O DA JANELA (COR/TAMANHO)
    system("Color 4F");
    system("mode con:cols=80 lines=30");

    // VARIAVEIS RESPONSAVEIS PELA MOVIMENTA플O NO MENU
    char menu_principal_escolha;
    char menu_organizacao_escolha;
    char menu_congressista_escolha;
    char menu_organizadores_escolha;
    char menu_palestrantes_escolha;

    char menu_evento_escolha;
    char menu_palestra_escolha;
    char menu_gp_discussao_escolha;
    char menu_curso_escolha;
    char menu_oficina_escolha;

    // VERIFICACA SE OS ARQUIVOS J� FORAM CRIADOS
    FILE *locais;
    locais = fopen("Arquivos\\locais.txt", "rb");
    if (locais == NULL){
        gerar_locais_zerados();
    }

    fclose(locais);

    // LOCAL DE TESTE DA MAIN!

    // INICIO DO PROGRAMA
    int saida; // Responsavel por capturar a saida de cada fun豫o

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
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO");
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
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO");
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
                                printf("\n==> CONGRESSISTAS NAO CADASTRADOS");
                             }
                             setbuf(stdin, NULL);
                             getchar();
                             break;
                        case '5':
                            system("cls");
                            gerar_topo(80, " QUANTIDADE CONGRESSISTAS CADASTRADOS");
                            if (quantidade_congressistas() == 0 || quantidade_congressistas() == -1){
                                printf("\n==> CONGRESSISTAS NAO CADASTRADOS");
                            } else {
                                printf("\n==> %d CONGRESSISTA(S) CADASTRADO(S)", quantidade_congressistas());
                            }
                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        case '6':
                            system("cls");
                            gerar_topo(80, "INSCREVER EM UM EVENTO");
                            saida = inserir_congressista_evento();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO");
                            } else if (saida == -2){
                                printf("\n==> CONGRESSISTA NAO CADASTRADO");
                            } else if (saida == -3){
                                printf("\n==> PALESTRA NAO CADASTRADA");
                            } else if (saida == -4){
                                printf("\n==> GRUPO DE DISCUSSAO NAO CADASTRADO");
                            } else if (saida == -5){
                                printf("\n==> CURSO NAO CADASTRADO");
                            } else if (saida == -6) {
                                printf("\n==> OFICINA NAO CADASTRADA");
                            } else if (saida == 0){
                                printf("\n==> CONGRESSISTA CADASTRADO COM SUCESSO");
                            }
                            Sleep(1000);
                            break;
                        case '7':
                            system("cls");
                            gerar_topo(80, "REMOVER DE UM EVENTO");
                            saida = remover_congressista_evento();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO");
                            } else if (saida == -2){
                                printf("\n==> CONGRESSISTA NAO CADASTRADO");
                            } else if (saida == 0){
                                printf("\n==> CONGRESSISTA REMOVIDO DO EVENTO COM SUCESSO");
                            }
                        }
                    } while(menu_congressista_escolha != '8');
                    break;
                // ESCOLHA PALESTRANTE
                case '2':
                    do {
                        system("cls");
                        menu_palestrantes(80);
                        menu_palestrantes_escolha = getch();

                        switch(menu_palestrantes_escolha){
                        case '1':
                            system("cls");
                            gerar_topo(80, "CADASTRANDO PALESTRANTE");
                            saida = cadastrar_palestrante();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else {
                                printf("\n==> PALESTRANTE CADASTRADO COM SUCESSO\n");
                            }
                            Sleep(1000);
                            break;
                        case '2':
                            system("cls");
                            gerar_topo(80, "REMOVER PALESTRANTE");
                            saida = remover_palestrante();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM PALESTRANTES CADASTRADOS\n");
                            } else {
                                printf("\n==> PALESTRANTE REMOVIDO COM SUCESSO\n");
                            }

                            Sleep(1000);
                            break;
                        case '3':
                            system("cls");
                            gerar_topo(80, "EDITAR PALESTRANTE");
                            saida = editar_palestrante();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM PALESTRANTES CADASTRADOS\n");
                            } else {
                                printf("\n==> PALESTRANTE EDITADO COM SUCESSO\n");
                            }

                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        case '4':
                            system("cls");
                            gerar_topo(80, "LISTANDO PALESTRANTES");
                            saida = listar_palestrantes();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM PALESTRANTES CADASTRADOS\n");
                            }

                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        case '5':
                            system("cls");
                            gerar_topo(80, "PALESTRANTES CADASTRADOS");
                            saida = quantidade_palestrantes();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == 0){
                                printf("\n==> NAO EXISTEM PALESTRANTES CADASTRADOS\n");
                            } else {
                                printf("\n\n==> %d PALESTRANTE(S) CADASTRADO(S)", saida);
                            }

                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        }
                    } while(menu_palestrantes_escolha != '6');
                    break;
                // ESCOLHA ORGANIZADOR
                case '3':
                    do {
                        system("cls");
                        menu_organizadores(80);
                        menu_organizadores_escolha = getch();

                        switch(menu_organizadores_escolha){
                        case '1':
                            system("cls");
                            gerar_topo(80, "CADASTRANDO ORGANIZADOR");
                            saida = cadastrar_organizador();

                            if (saida == -1){
                                printf("\n ==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == 0){
                                printf("\n==> ORGANIZADOR CADASTRADO COM SUCESSO\n");
                            }

                            Sleep(1000);
                            break;
                        case '2':
                            system("cls");
                            gerar_topo(80, "REMOVENDO ORGANIZADOR");
                            saida = remover_organizador();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> ORGANIZADORES NAO CADASTRADOS");
                            } else if (saida == 0){
                                printf("\n==> ORGANIZADOR REMOVIDO COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '3':
                            system("cls");
                            gerar_topo(80, "EDITAR ORGANIZADOR");
                            saida = editar_organizador();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> ORGANIZADORES NAO CADASTRADOS");
                            } else if (saida == 0){
                                printf("\n==> ORGANIZADOR ALTERADO COM SUCESSO");
                            }

                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        case '4':
                            system("cls");
                            gerar_topo(80, "LISTANDO ORGANIZADORES");
                            saida = listar_organizadores();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> ORGANIZADORES NAO CADASTRADOS!");
                            }

                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        case '5':
                            system("cls");
                            gerar_topo(80, "ORGANIZADORES CADASTRADOS");
                            saida = quantidade_organizadores();

                            if (saida == 0){
                                printf("\n==> ORGANIZADORES NAO CADASTRADOS!");
                            } else if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else {
                                printf("\n\n==> %d ORGANIZADOR(ES) CADASTRADO(S)", saida);
                            }

                            setbuf(stdin, NULL);
                            getchar();
                            break;
                        }
                    } while(menu_organizadores_escolha != '6');
                    break;
                }
            } while (menu_organizacao_escolha != '4');
        break;
        case '2':
            do {
                system("cls");
                menu_eventos(80);
                menu_evento_escolha = getch();

                switch(menu_evento_escolha){
                // ESCOLHA PALESTRA
                case '1':
                    do {
                        system("cls");
                        menu_palestras(80);
                        menu_palestra_escolha = getch();

                        switch(menu_palestra_escolha){
                        case '1':
                            system("cls");
                            gerar_topo(80, "CADASTRANDO PALESTRA");
                            saida = cadastrar_palestra();

                            if (saida == -1){
                                printf("\n ==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> PALESTRANTES NAO CADASTRADOS\n");
                            } else if (saida == -3){
                                printf("\n==> PROFESSOR J� MINISTRA UM EVENTO");
                            } else if (saida == 0){
                                printf("==> PALESTRA CADASTRADA COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '2':
                            system("cls");
                            gerar_topo(80, "REMOVENDO PALESTRA");
                            saida = remover_palestra();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM PALESTRAS CADASTRADAS");
                            } else if (saida == 0){
                                printf("\n==> PALESTRA REMOVIDA COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '3':
                            break;
                        case '4':
                            system("cls");
                            gerar_topo(80, "LISTAR PALESTRAS");

                            saida = listar_palestras();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM PALESTRAS CADASTRADAS");
                            }
                            getch();
                            break;
                        case '5':
                            system("cls");
                            gerar_topo(80, "QUANTIDADE DE PALESTRAS");
                            saida = quantidade_palestras();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == 0){
                                printf("\n==> NAO EXISTEM PALESTRAS CADASTRADAS");
                            } else {
                                printf("\n\n==> %d PALESTRA(S) CADASTRADA(S)", saida);
                            }
                            getch();
                            break;
                        }


                    } while(menu_palestra_escolha != '6');
                    break;
                // ESCOLHA GP DE DISCUSSAO
                case '2':
                    do {
                        system("cls");
                        menu_gp_discussao(80);
                        menu_gp_discussao_escolha = getch();

                        switch(menu_gp_discussao_escolha){
                        case '1':
                            system("cls");
                            gerar_topo(80, "CADASTRANDO GRUPO DE DISCUSSAO");
                            saida = criar_gp_discussoes();

                            if (saida == -1){
                                printf("\n ==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> PALESTRANTES NAO CADASTRADOS\n");
                            } else if (saida == 0){
                                printf("==> GRUPO DE DISCUSSAO CADASTRADO COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '2':
                            system("cls");
                            gerar_topo(80, "REMOVENDO GRUPO DE DISCUSSAO");
                            saida = remover_gp_discussoes();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM GP DE DISCUSSOES CADASTRADOS");
                            } else if (saida == 0){
                                printf("\n==> GRUPO DE DISCUSSAO REMOVIDO COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '3':
                            break;
                        case '4':
                            system("cls");
                            gerar_topo(80, "LISTAR GRUPOS DE DISCUSSAO");

                            saida = listar_gp_discussao();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM GRUPOS DE DISCUSSAO CADASTRADOS");
                            }

                            getch();
                            break;
                        case '5':
                            system("cls");
                            gerar_topo(80, "QUANTIDADE DE PALESTRAS");
                            saida = quantidade_gp_discussao();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == 0){
                                printf("\n==> NAO EXISTEM GRUPO(S) DE DISCUSSAO(ES) CADASTRADOS");
                            } else {
                                printf("\n\n==> %d GRUPO(S) DE DISCUSSAO(ES) CADASTRADO(S)", saida);
                            }
                            getch();
                            break;
                        }


                    } while(menu_gp_discussao_escolha != '6');
                    break;
                    // ESCOLHA CURSO
                case '3':
                    do {
                        system("cls");
                        menu_curso(80);
                        menu_curso_escolha = getch();

                        switch(menu_curso_escolha){
                        case '1':
                            system("cls");
                            gerar_topo(80, "CADASTRANDO CURSO");
                            saida = cadastrar_curso();

                            if (saida == -1){
                                printf("\n ==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> PALESTRANTES NAO CADASTRADOS\n");
                            } else if (saida == -3){
                                printf("\n==> PROFESSOR J� MINISTRA UM EVENTO");
                            } else if (saida == 0){
                                printf("==> CURSO CADASTRADO COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '2':
                            system("cls");
                            gerar_topo(80, "REMOVENDO CURSO");
                            saida = remover_cursos();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM PALESTRAS CADASTRADAS");
                            } else if (saida == 0){
                                printf("\n==> CURSO REMOVIDO COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '3':
                            break;
                        case '4':
                            system("cls");
                            gerar_topo(80, "LISTAR CURSOS");

                            saida = listar_cursos();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM PALESTRAS CADASTRADAS");
                            }
                            getch();
                            break;
                        case '5':
                            system("cls");
                            gerar_topo(80, "QUANTIDADE DE CURSOS");
                            saida = quantidade_cursos();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == 0){
                                printf("\n==> NAO EXISTEM PALESTRAS CADASTRADAS");
                            } else {
                                printf("\n\n==> %d CURSO(S) CADASTRADA(S)", saida);
                            }
                            getch();
                            break;
                        }

                    } while(menu_curso_escolha != '6');
                    break;
                    // ESCOLHA OFICINA
                case '4':
                    do {
                        system("cls");
                        menu_oficina(80);
                        menu_oficina_escolha = getch();

                        switch(menu_oficina_escolha){
                        case '1':
                            system("cls");
                            gerar_topo(80, "CADASTRANDO OFICINA");
                            saida = cadastrar_oficina();

                            if (saida == -1){
                                printf("\n ==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> PALESTRANTES NAO CADASTRADOS\n");
                            } else if (saida == -3){
                                printf("\n==> PROFESSOR J� MINISTRA UM EVENTO");
                            } else if (saida == 4){
                                printf("==> NAO EXISTEM MAIS VAGAS P/ LOCAIS");
                            } else if (saida == 0){
                                printf("==> OFICINA CADASTRADA COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '2':
                            system("cls");
                            gerar_topo(80, "REMOVENDO OFICINA");
                            saida = remover_oficinas();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM OFICINAS CADASTRADAS");
                            } else if (saida == 0){
                                printf("\n==> OFICINA REMOVIDA COM SUCESSO");
                            }

                            Sleep(1000);
                            break;
                        case '3':
                            break;
                        case '4':
                            system("cls");
                            gerar_topo(80, "LISTAR OFICINAS");

                            saida = listar_oficinas();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == -2){
                                printf("\n==> NAO EXISTEM OFICINAS CADASTRADAS");
                            }
                            getch();
                            break;
                        case '5':
                            system("cls");
                            gerar_topo(80, "QUANTIDADE DE OFICINAS");
                            saida = quantidade_oficinas();

                            if (saida == -1){
                                printf("\n==> HOUVE UM ERRO DE ACESSO AO ARQUIVO\n");
                            } else if (saida == 0){
                                printf("\n==> NAO EXISTEM OFICINAS CADASTRADAS");
                            } else {
                                printf("\n\n==> %d OFICINA(S) CADASTRADA(S)", saida);
                            }
                            getch();
                            break;
                        }

                    } while(menu_oficina_escolha != '6');
                    break;
                }
            } while (menu_evento_escolha != '5');
            break;
        }
    } while (menu_principal_escolha != '3');
}

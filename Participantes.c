#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Participantes.h"
#include "Uteis.h"
#include "Eventos.h"

/*
*       -----------------------
*           CONGRESSISTAS
*       -----------------------
*/

int quantidade_congressistas(){

    FILE *congress;
    int quantidade=0;
    congress = fopen("Arquivos\\congressistas.txt", "rb");

    if (congress == NULL){
        printf("Falha ao carregar o arquivo.\n");
    } else {
        CONGRESSISTA cong;
        while (fread(&cong, sizeof(CONGRESSISTA), 1, congress) == 1){
            quantidade++;
        }
    }
    return quantidade;
}

void listar_congressistas(){

    FILE *congress;
    congress = fopen("Arquivos\\congressistas.txt", "rb");

    if (congress == NULL){
        printf("Falha ao carregar o arquivo.\n");
    } else {
        if (quantidade_congressistas() == 0){
            printf("Nenhum congressista cadastrado.\n");
        } else {
            CONGRESSISTA cong;
            printf("Listando:\n\n");
            while(fread(&cong, sizeof(CONGRESSISTA), 1, congress) == 1){
                printf("ID: %d\n", cong.ID);
                printf("Nome: %s", cong.nome);
                printf("Curso: %s", cong.curso);
                putchar('\n');
            }
        }
        fclose(congress);
    }
}

void cadastrar_congressista(){

    FILE *congress;
    congress = fopen("Arquivos\\congressistas.txt", "ab");

    if (congress == NULL){
        printf("Falha ao carregar o arquivo.\n");
    } else {
        CONGRESSISTA cong;

        if (quantidade_congressistas() >= 300){
            printf("Impossivel Cadastrar, Limite Alacancado.\n");
        } else {
            cong.ID = gerar_id_valido(5);

            printf("Nome: ");
            fgets(cong.nome, 30, stdin);
            strcpy(cong.nome, strupr(cong.nome));
            setbuf(stdin, NULL);

            printf("Curso: ");
            fgets(cong.curso, 30, stdin);
            strcpy(cong.curso, strupr(cong.curso));
            setbuf(stdin, NULL);

            fwrite(&cong, sizeof(CONGRESSISTA), 1, congress);
        }
    }
    fclose(congress);
}

void remover_congressista(){

    FILE *congress;
    FILE *congress2;

    congress = fopen("Arquivos\\congressistas.txt", "rb");
    congress2 = fopen("Arquivos\\temp.txt", "wb");

    if (congress == NULL){
        fclose(congress);
        printf("Falha ao carregar o arquivo.\n");
    } else {
        if (congress2 == NULL){
            fclose(congress2);
            printf("Falha ao carregar o arquivo.\n");
        } else {
            CONGRESSISTA cong;

            int ID;
            scanf("%d", &ID);

            while (fread(&cong, sizeof(CONGRESSISTA), 1, congress) == 1){
                if (ID != cong.ID){
                    fwrite(&cong, sizeof(CONGRESSISTA), 1, congress2);
                }
            }

            // O arquivo só será aberto se não houve falha.
            // Logo só será preciso fechar se ele foi aberto.
            fclose(congress);
            fclose(congress2);
            remove("Arquivos\\congressistas.txt");
            rename("Arquivos\\temp.txt", "Arquivos\\congressistas.txt");
        }
    }
}

// DE CONGRESSISTA BASICO FALTA ALTERAÇÂO
// CONTUDO AO TERMINO DA PARTE DE CADASTRO DE EVENTOS
// ENTRAREMOS COM MAIS FUNCOES

/*
*       -----------------------
*           ORGANIZADORES
*       -----------------------
*/

int quantidade_organizadores(){

    FILE *org;
    int quantidade=0;
    org = fopen("Arquivos\\organizadores.txt", "rb");

    if (org == NULL){
        printf("Falha ao carregar o arquivo.\n");
    } else {
        ORGANIZADOR orga;
        while (fread(&orga, sizeof(ORGANIZADOR), 1, org) == 1){
            quantidade++;
        }
    }
    fclose(org);
    return quantidade;
}

void listar_organizadores(){

    FILE *org;
    org = fopen("Arquivos\\organizadores.txt", "rb");

    if (org == NULL){
        fclose(org);
        printf("Falha ao carregar o arquivo.\n");
    } else {
        ORGANIZADOR orga;
        if (quantidade_organizadores() == 0){
            printf("Nao existem organizadores cadastrados.");
        } else {
            printf("Listando: \n");
            while(fread(&orga, sizeof(ORGANIZADOR),1, org) == 1){
                printf("ID: %d\n", orga.ID);
                printf("Login: %s", orga.login);
                printf("Senha: %s", orga.senha);
                putchar('\n');
            }
        }
        fclose(org);
    }
}

void cadastrar_organizador(){

    FILE *org;
    org = fopen("Arquivos\\organizadores.txt", "ab");

    if (org == NULL){
        fclose(org);
        printf("Falha ao carregar o arquivo.\n");
    } else {
        ORGANIZADOR orga;
        // NUMERO 6 RECEBE UM ID DE ORGANIZADOR
        orga.ID = gerar_id_valido(6);

        printf("Login: ");
        fgets(orga.login, 30, stdin);
        setbuf(stdin, NULL);

        printf("Senha: ");
        fgets(orga.senha, 30, stdin);
        setbuf(stdin, NULL);

        fwrite(&orga, sizeof(ORGANIZADOR), 1, org);
        fclose(org);
    }
}


/*
*       -----------------------
*           PALESTRANTES
*       -----------------------
*/

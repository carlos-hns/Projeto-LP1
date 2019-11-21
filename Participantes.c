#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Participantes.h"
#include "Uteis.h"
#include "Eventos.h"

/*
*   ------------------------------------------------------------------------
*       AVISOS IMPORTANTES PARA MIM MSM!
*       1º FALTAM AS FUNÇÕES DE MODIFICAÇÃO PALESTRANTE/ORGANIZADOR
*
*       2º AS FUNÇÕES ESTÃO SOMENTE NO ESQUELETO (FALTA FAZER AS RESTRIÇÕES DE CADA CLASSE,
*       OU SEJA, AS CONDIÇÕES NÃO FORAM ANTENDIDAS AINDA (EXEMPLO PALESTRANTE SÓ PODE DAR UMA PALESTRA),
*       OU AINDA, NÃO É POSSIVEL REMOVER UM MEMBRO SE ELE FAZ PARTE DE UM PROJETO...
*   -------------------------------------------------------------------------
*/

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
        fclose(congress);
        return -1;
    } else {
        CONGRESSISTA cong;
        while (fread(&cong, sizeof(CONGRESSISTA), 1, congress) == 1){
            quantidade++;
        }
        fclose(congress);
        return quantidade;
    }
}

int listar_congressistas(){

    FILE *congress;
    congress = fopen("Arquivos\\congressistas.txt", "rb");

    if (congress == NULL){
        fclose(congress);
        return -1;
    } else {
        if (quantidade_congressistas() == 0){
            fclose(congress);
            return -1;
        } else {
            CONGRESSISTA cong;
            printf("Listando:\n\n");
            while(fread(&cong, sizeof(CONGRESSISTA), 1, congress) == 1){
                printf("ID: %d\n", cong.ID);
                printf("Nome: %s", cong.nome);
                printf("Curso: %s", cong.curso);
                putchar('\n');
            }

            fclose(congress);
            return 0;
        }
    }
    fclose(congress);
}

int cadastrar_congressista(){

    FILE *congress;
    congress = fopen("Arquivos\\congressistas.txt", "ab");

    if (congress == NULL){
        fclose(congress);
        return -1;
    } else {
        CONGRESSISTA cong;
        if (quantidade_congressistas() >= 300){
            printf("\n\nImpossivel Cadastrar, Limite Alacancado.\n");
        } else {
            cong.ID = gerar_id_valido(5);

            setbuf(stdin, NULL);
            putchar('\n');
            putchar('\n');

            printf("Nome: ");
            fgets(cong.nome, 30, stdin);
            strcpy(cong.nome, strupr(cong.nome));
            setbuf(stdin, NULL);

            printf("Curso: ");
            fgets(cong.curso, 30, stdin);
            strcpy(cong.curso, strupr(cong.curso));
            setbuf(stdin, NULL);

            fwrite(&cong, sizeof(CONGRESSISTA), 1, congress);
            fclose(congress);
        }
    }
    fclose(congress);
    return 0;
}


// LEMBRAR DE SÓ REMOVER UM ALUNO SE ELE NÃO ESTIVER CADASTRADO EM NADA;
// -------------------------------------------------------------------->
int remover_congressista(){

    FILE *congress;
    FILE *congress2;

    congress = fopen("Arquivos\\congressistas.txt", "rb");
    congress2 = fopen("Arquivos\\temp.txt", "ab");

    if (congress == NULL || congress2 == NULL){
        fclose(congress);
        fclose(congress2);
        return -1;
    } else {
        CONGRESSISTA cong;
        if (quantidade_congressistas() == 0){
                printf("\n\n==> NAO EXISTEM CONGRESSISTAS CADASTRADOS\n");
            } else {

                listar_congressistas();
                int ID;
                printf("Digite o ID que Deseja Remover: ");
                scanf("%d", &ID);

                while (fread(&cong, sizeof(CONGRESSISTA), 1, congress) == 1){
                    if (ID != cong.ID){
                        fwrite(&cong, sizeof(CONGRESSISTA), 1, congress2);
                    }
                }

                // O arquivo só será aberto se não houve falha.
                // Logo só será preciso fechar se ele foi aberto.
                fclose(congress2);
                fclose(congress);
                remove("Arquivos\\congressistas.txt");
                rename("Arquivos\\temp.txt", "Arquivos\\congressistas.txt");
                printf("\n==> CONGRESSISTA REMOVIDO COM SUCESSO\n");
                return 0;
        }

    }
    fclose(congress2);
    fclose(congress);
}

int editar_congressista(){

    FILE *congress;
    FILE *congress2;

    congress = fopen("Arquivos\\congressistas.txt", "rb");
    congress2 = fopen("Arquivos\\temp.txt", "ab");

    if (congress == NULL || congress2 == NULL){
        fclose(congress);
        fclose(congress2);
        return -1;
    } else {
        CONGRESSISTA aux;
        int editar_escolha;
        int ID;
        if (quantidade_congressistas() == 0){
            fclose(congress);
            fclose(congress2);
            return -1;
        } else {

        listar_congressistas();
        printf("Digite o ID que Deseja Remover: ");
        scanf("%d", &ID);

        do {
            printf("\n|1| - Alterar Nome\n");
            printf("|2| - Alterar Curso\n");
            printf("|3| - Alterar Tudo\n");
            printf("|4| - Voltar\n");
            printf(">>> ");
            scanf("%d", &editar_escolha);
            setbuf(stdin, NULL);

            switch(editar_escolha){
            case 1:

                while(fread(&aux, sizeof(CONGRESSISTA), 1, congress)){
                    if (aux.ID != ID){
                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    } else {
                        printf("\nNovo Nome: ");
                        fgets(aux.nome, 30, stdin);
                        strcpy(aux.nome, strupr(aux.nome));
                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    }
                }
                break;
            case 2:
                while(fread(&aux, sizeof(CONGRESSISTA), 1, congress)){
                    if (aux.ID != ID){
                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    } else {
                        printf("\nNovo Curso: ");
                        fgets(aux.curso, 30, stdin);
                        strcpy(aux.curso, strupr(aux.curso));
                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    }
                }
            case 3:
                while(fread(&aux, sizeof(CONGRESSISTA), 1, congress)){
                    if (aux.ID != ID){
                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    } else {
                        printf("\nNovo Nome: ");
                        fgets(aux.nome, 30, stdin);
                        strcpy(aux.nome, strupr(aux.nome));
                        setbuf(stdin, NULL);

                        printf("\nNovo Curso: ");
                        fgets(aux.curso, 30, stdin);
                        strcpy(aux.curso, strupr(aux.curso));
                        setbuf(stdin, NULL);

                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    }
                }
            }
        } while(editar_escolha != 4);

        }
    }
    fclose(congress);
    fclose(congress2);
    remove("Arquivos\\congressistas.txt");
    rename("Arquivos\\temp.txt", "Arquivos\\congressistas.txt");
    printf("\n==> CONGRESSISTA ALTERADO COM SUCESSO\n");
}

/*
int editar_congressista(){

    FILE *congress;
    FILE *congress2;

    congress = fopen("Arquivos\\congressistas.txt", "rb");
    congress2 = fopen("Arquivos\\temp.txt", "ab");

    if (congress == NULL || congress2 == NULL){
        fclose(congress);
        fclose(congress2);
        return -1;
    } else {
        CONGRESSISTA aux;
        int editar_escolha;
        int ID;
        if (quantidade_congressistas() == 0){
            fclose(congress);
            fclose(congress2);
            return -1;
        } else {

        listar_congressistas();
        printf("Digite o ID que Deseja Remover: ");
        scanf("%d", &ID);

        do {
            printf("\n|1| - Alterar Nome\n");
            printf("|2| - Alterar Curso\n");
            printf("|3| - Alterar Tudo\n");
            printf("|4| - Voltar\n");
            printf(">>> ");
            scanf("%d", &editar_escolha);
            setbuf(stdin, NULL);

            switch(editar_escolha){
            case 1:

                while(fread(&aux, sizeof(CONGRESSISTA), 1, congress)){
                    if (aux.ID != ID){
                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    } else {
                        printf("\nNovo Nome: ");
                        fgets(aux.nome, 30, stdin);
                        strcpy(aux.nome, strupr(aux.nome));
                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    }
                }
                break;
            case 2:
                while(fread(&aux, sizeof(CONGRESSISTA), 1, congress)){
                    if (aux.ID != ID){
                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    } else {
                        printf("\nNovo Curso: ");
                        fgets(aux.curso, 30, stdin);
                        strcpy(aux.curso, strupr(aux.curso));
                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    }
                }
            case 3:
                while(fread(&aux, sizeof(CONGRESSISTA), 1, congress)){
                    if (aux.ID != ID){
                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    } else {
                        printf("\nNovo Nome: ");
                        fgets(aux.nome, 30, stdin);
                        strcpy(aux.nome, strupr(aux.nome));
                        setbuf(stdin, NULL);

                        printf("\nNovo Curso: ");
                        fgets(aux.curso, 30, stdin);
                        strcpy(aux.curso, strupr(aux.curso));
                        setbuf(stdin, NULL);

                        fwrite(&aux, sizeof(CONGRESSISTA), 1, congress2);
                    }
                }
            }
        } while(editar_escolha != 4);

        }
    }
    fclose(congress);
    fclose(congress2);
    remove("Arquivos\\congressistas.txt");
    rename("Arquivos\\temp.txt", "Arquivos\\congressistas.txt");
    printf("\n==> CONGRESSISTA ALTERADO COM SUCESSO\n");
}
*/
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
        fclose(org);
        return -1;
    } else {
        ORGANIZADOR orga;
        while (fread(&orga, sizeof(ORGANIZADOR), 1, org) == 1){
            quantidade++;
        }
    }
    fclose(org);
    return quantidade;
}

int listar_organizadores(){

    FILE *org;
    org = fopen("Arquivos\\organizadores.txt", "rb");

    if (org == NULL){
        fclose(org);
        return -1;
    } else {
        ORGANIZADOR orga;
        if (quantidade_organizadores() == 0){
            fclose(org);
            return -1;
        } else {
            printf("\n\nListando: \n");
            while(fread(&orga, sizeof(ORGANIZADOR),1, org) == 1){
                printf("ID: %d\n", orga.ID);
                printf("Login: %s", orga.login);
                printf("Senha: %s", orga.senha);
                putchar('\n');
            }
            fclose(org);
        }
    }
    fclose(org);
    return 0;
}

int cadastrar_organizador(){

    FILE *org;
    org = fopen("Arquivos\\organizadores.txt", "ab");

    if (org == NULL){
        fclose(org);
        return -1;
    } else {
        ORGANIZADOR orga;
        // NUMERO 6 RECEBE UM ID DE ORGANIZADOR
        orga.ID = gerar_id_valido(6);

        setbuf(stdin, NULL);

        printf("\n\n");

        printf("Login: ");
        fgets(orga.login, 30, stdin);
        setbuf(stdin, NULL);

        printf("Senha: ");
        fgets(orga.senha, 30, stdin);
        setbuf(stdin, NULL);

        fwrite(&orga, sizeof(ORGANIZADOR), 1, org);
        fclose(org);
    }
    return 0;
    fclose(org);
}

int remover_organizador(){

    FILE *org;
    FILE *org_aux;
    org = fopen("Arquivos\\organizadores.txt", "rb");
    org_aux = fopen("Arquivos\\temp.txt", "ab");

    if (org == NULL || org_aux == NULL){
        fclose(org);
        fclose(org_aux);
        return -1;
    } else {
            ORGANIZADOR pessoa;

            if (quantidade_organizadores() == 0){
                printf("\n\n==> NAO EXISTEM ORGANIZADORES CADASTRADOS\n");
            } else {
                listar_organizadores();
                int ID;
                printf("Digite o ID que Deseja Remover: ");
                scanf("%d", &ID);

                while (fread(&pessoa, sizeof(ORGANIZADOR), 1, org) == 1){
                    if (ID != pessoa.ID){
                        fwrite(&pessoa, sizeof(ORGANIZADOR), 1, org_aux);
                    }
                }

                fclose(org);
                fclose(org_aux);
                remove("Arquivos\\organizadores.txt");
                rename("Arquivos\\temp.txt", "Arquivos\\organizadores.txt");
        }
    }
    fclose(org);
    fclose(org_aux);
}

int editar_organizador(){

    FILE *org;
    FILE *org_aux;

    org = fopen("Arquivos\\organizadores.txt", "rb");
    org_aux = fopen("Arquivos\\temp.txt", "ab");

    if (org == NULL || org_aux == NULL){
        fclose(org);
        fclose(org_aux);
        return -1;
    } else {
        ORGANIZADOR aux;
        int editar_escolha;
        int ID;
        if (quantidade_organizadores() == 0){
            fclose(org);
            fclose(org_aux);
            return -1;
        } else {

        listar_organizadores();
        printf("Digite o ID que Deseja Remover: ");
        scanf("%d", &ID);

        do {
            printf("\n|1| - Alterar Login\n");
            printf("|2| - Alterar Senha\n");
            printf("|3| - Alterar Tudo\n");
            printf("|4| - Voltar\n");
            printf(">>> ");
            scanf("%d", &editar_escolha);
            setbuf(stdin, NULL);

            switch(editar_escolha){
            case 1:

                while(fread(&aux, sizeof(ORGANIZADOR), 1, org)){
                    if (aux.ID != ID){
                        fwrite(&aux, sizeof(ORGANIZADOR), 1, org_aux);
                    } else {
                        printf("\nNovo Login: ");
                        fgets(aux.login, 30, stdin);
                        fwrite(&aux, sizeof(ORGANIZADOR), 1, org_aux);
                    }
                }
                break;
            case 2:
                while(fread(&aux, sizeof(ORGANIZADOR), 1, org)){
                    if (aux.ID != ID){
                        fwrite(&aux, sizeof(ORGANIZADOR), 1, org_aux);
                    } else {
                        printf("\nNova Senha: ");
                        fgets(aux.senha, 30, stdin);
                        fwrite(&aux, sizeof(ORGANIZADOR), 1, org_aux);
                    }
                }
            case 3:
                while(fread(&aux, sizeof(ORGANIZADOR), 1, org)){
                    if (aux.ID != ID){
                        fwrite(&aux, sizeof(ORGANIZADOR), 1, org_aux);
                    } else {
                        printf("\nNovo Login: ");
                        fgets(aux.login, 30, stdin);
                        setbuf(stdin, NULL);

                        printf("\nNova Senha: ");
                        fgets(aux.senha, 30, stdin);
                        setbuf(stdin, NULL);

                        fwrite(&aux, sizeof(ORGANIZADOR), 1, org_aux);
                    }
                }
            }
        } while(editar_escolha != 4);

        }
    }
    fclose(org);
    fclose(org_aux);
    remove("Arquivos\\organizadores.txt");
    rename("Arquivos\\temp.txt", "Arquivos\\organizadores.txt");
}

/*
*       -----------------------
*           PALESTRANTES
*       -----------------------
*/

int quantidade_palestrantes(){

    FILE *pales;
    int quantidade=0;
    pales = fopen("Arquivos\\palestrantes.txt", "rb");

    if (pales == NULL){
        printf("Falha ao carregar o arquivo.\n");
    } else {
        PALESTRANTE pa;
        while (fread(&pa, sizeof(PALESTRANTE), 1, pales) == 1){
            quantidade++;
        }
    }
    fclose(pales);
    return quantidade;
}

void listar_palestrantes(){

    FILE *pale;
    pale = fopen("Arquivos\\palestrantes.txt", "rb");

    if (pale == NULL){
        fclose(pale);
        printf("Falha ao carregar o arquivo.\n");
    } else {
        PALESTRANTE palest;
        if (quantidade_palestrantes() == 0){
            printf("Nao existem palestrantes cadastrados.");
        } else {
            printf("Listando: \n");
            while(fread(&palest, sizeof(PALESTRANTE),1, pale) == 1){
                printf("ID: %d\n", palest.ID);
                printf("Nome: %s", palest.nome);
                printf("Especialidade: %s", palest.especialidade);
                putchar('\n');
            }
        }
        fclose(pale);
    }
}

void cadastrar_palestrante(){

    FILE *pale;
    pale = fopen("Arquivos\\palestrantes.txt", "ab");

    if (pale == NULL){
        printf("Falha ao carregar o arquivo.\n");
    } else {
        PALESTRANTE palest;

        // 7 GERA UM ID DO TIPO PALESTRANTE
        palest.ID = gerar_id_valido(7);

        printf("Nome: ");
        fgets(palest.nome, 30, stdin);
        strcpy(palest.nome, strupr(palest.nome));
        setbuf(stdin, NULL);

        printf("Especialidade: ");
        fgets(palest.especialidade, 30, stdin);
        strcpy(palest.especialidade, strupr(palest.especialidade));
        setbuf(stdin, NULL);

        fwrite(&palest, sizeof(CONGRESSISTA), 1, pale);

    }
    fclose(pale);
}

void remover_palestrante(){

    FILE *pale;
    FILE *pale_aux;

    pale = fopen("Arquivos\\palestrantes.txt", "rb");
    pale_aux = fopen("Arquivos\\temp.txt", "wb");

    if (pale == NULL){
        fclose(pale);
        printf("Falha ao carregar o arquivo.\n");
    } else {
        if (pale_aux == NULL){
            fclose(pale_aux);
            printf("Falha ao carregar o arquivo.\n");
        } else {
            PALESTRANTE palest;

            int ID;
            scanf("%d", &ID);

            while (fread(&palest, sizeof(PALESTRANTE), 1, pale) == 1){
                if (ID != palest.ID){
                    fwrite(&palest, sizeof(PALESTRANTE), 1, pale_aux);
                }
            }
            fclose(pale);
            fclose(pale_aux);
            remove("Arquivos\\palestrantes.txt");
            rename("Arquivos\\temp.txt", "Arquivos\\palestrantes.txt");
        }
    }
}

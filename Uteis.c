#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Participantes.h"
#include "Eventos.h"
#include "Uteis.h"

int gerar_id(int tipo){
    switch(tipo){
    // Gera um ID para Palestra
    case 1:
        return (0 + (rand()%100));
    // Gera um ID para Grupo de Discussoes
    case 2:
        return (100 + (rand()%100));
    // Gera um ID para Curso
    case 3:
        return (200 + (rand()%100));
    // Gera um ID para Oficina
    case 4:
        return (300 + (rand()%100));
    // Gera um ID Para Congressista
    case 5:
        return (1000 + (rand()%1000));
    // Gera um ID Para Organizador
    case 6:
        return (2000 + (rand()%1000));
    // Gera um ID Para Palestrante
    case 7:
        return(3000 + (rand()%1000));
    //Gera um ID para Local
    case 8:
        return (4000 + (rand()%1000));
    }
}

int verificar_ID(int tipo, int ID){
    FILE *palestras;
    FILE *gp;
    FILE *cursos;
    FILE *oficinas;
    FILE *congress;
    FILE *organizadores;
    FILE *pale;
    FILE *locais;

    switch (tipo){
    // Verifica um ID para Palestra
    case 1:
        palestras = fopen("Arquivos\\palestras.txt", "rb");

        if (palestras == NULL){
            printf("Falha ao carregar o arquivo.");
        } else {
            PALESTRA pa;

            while (fread(&pa, sizeof(PALESTRA), 1, palestras) == 1){
                if (ID == pa.ID){
                    fclose(palestras);
                    return 0; // RETORNA 0 SE O ID JÁ EXISTE
                }
            }
            fclose(palestras);
            return 1; // RETORNA 1 SE O ID NÃO EXISTIA
        }
        break;
    // Verifica um ID para Grupo de Discussoes
    case 2:
        gp = fopen("Arquivos\\gp_discussoes.txt", "rb");

        if (gp == NULL){
            printf("Falha ao carregar o arquivo.");
        } else {
            GP_DISCUSSOES gd;

            while (fread(&gd, sizeof(GP_DISCUSSOES), 1, gp) == 1){
                if (ID == gd.ID){
                    fclose(gp);
                    return 0; // RETORNA 0 SE O ID JÁ EXISTE
                }
            }
            fclose(gp);
            return 1; // RETORNA 1 SE O ID NÃO EXISTIA
        }
        break;
    // Verifica um ID para Curso
    case 3:
        cursos = fopen("Arquivos\\cursos.txt", "rb");

        if (cursos == NULL){
            printf("Falha ao carregar o arquivo.");
        } else {
            CURSO cur;

            while (fread(&cur, sizeof(CURSO), 1, cursos) == 1){
                if (ID == cur.ID){
                    fclose(cursos);
                    return 0; // RETORNA 0 SE O ID JÁ EXISTE
                }
            }
            fclose(cursos);
            return 1; // RETORNA 1 SE O ID NÃO EXISTIA
        }
        break;
    // Verifica um ID para Oficina
    case 4:
        oficinas = fopen("Arquivos\\oficinas.txt", "rb");

        if (oficinas == NULL){
            printf("Falha ao carregar o arquivo.");
        } else {
            OFICINA ofic;

            while (fread(&ofic, sizeof(OFICINA), 1, oficinas) == 1){
                if (ID == ofic.ID){
                    fclose(oficinas);
                    return 0; // RETORNA 0 SE O ID JÁ EXISTE
                }
            }
            fclose(oficinas);
            return 1; // RETORNA 1 SE O ID NÃO EXISTIA
        }
        break;
    // Gera um ID Para Congressista
    case 5:
        congress = fopen("Arquivos\\congressistas.txt", "rb");

        if (congress == NULL){
            printf("Falha ao carregar o arquivo.");
        } else {
            CONGRESSISTA cong;

            while (fread(&cong, sizeof(CONGRESSISTA), 1, congress) == 1){
                if (ID == cong.ID){
                    fclose(congress);
                    return 0; // RETORNA 0 SE O ID JÁ EXISTE
                }
            }
            fclose(congress);
            return 1; // RETORNA 1 SE O ID NÃO EXISTIA
        }
        break;
    // Gera um ID para Organizador
    case 6:
        organizadores = fopen("Arquivos\\organizadores.txt", "rb");

        if (organizadores == NULL){
            printf("Falha ao carregar o arquivo.");
        } else {
            ORGANIZADOR org;

            while (fread(&org, sizeof(ORGANIZADOR), 1, organizadores) == 1){
                if (ID == org.ID){
                    fclose(organizadores);
                    return 0; // RETORNA 0 SE O ID JÁ EXISTE
                }
            }
            fclose(organizadores);
            return 1; // RETORNA 1 SE O ID NÃO EXISTIA
        }
        break;
    // Gera um ID para Palestrante
    case 7:
        pale = fopen("Arquivos\\palestrantes.txt", "rb");

        if (pale == NULL){
            printf("Falha ao carregar o arquivo.");
        } else {
            PALESTRANTE palest;

            while (fread(&palest, sizeof(PALESTRANTE), 1, pale) == 1){
                if (ID == palest.ID){
                    fclose(pale);
                    return 0; // RETORNA 0 SE O ID JÁ EXISTE
                }
            }
            fclose(pale);
            return 1; // RETORNA 1 SE O ID NÃO EXISTIA
        }
        break;
    // Gera um ID para Local
    case 8:
        locais = fopen("Arquivos\\locais.txt", "rb");

        if (locais == NULL){
            printf("Falha ao carregar o arquivo.");
        } else {
            LOCAL loc;

            while (fread(&loc, sizeof(LOCAL), 1, locais) == 1){
                if (ID == loc.ID){
                    fclose(locais);
                    return 0; // RETORNA 0 SE O ID JÁ EXISTE
                }
            }
            fclose(locais);
            return 1; // RETORNA 1 SE O ID NÃO EXISTIA
        }
        break;
    }
}

int gerar_id_valido(int tipo){

    int id;
    do {
        id = gerar_id(tipo);
    } while(verificar_ID(tipo, id) != 1);
    return id;
}

void zerarArray(int *array, int n){

    int i;
    for (i=0; i < n; i++){
        array[i] = 0;
    }
}

void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int calcular_meio(int colunas, char *string){

    int meio = (colunas - strlen(string)) / 2;
    return meio;
}

char *retornar_nome_palestrante(int ID){

    FILE *palestrantes;
    palestrantes = fopen("Arquivos\\palestrantes.txt", "rb");

    char *nome;

    PALESTRANTE pale;
    while (fread(&pale, sizeof(PALESTRANTE), 1, palestrantes)){
        if (pale.ID == ID){
            strcpy(nome, pale.nome);
            fclose(palestrantes);
            return nome;
        }
    }

}

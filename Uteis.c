#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        return (100 + (rand()%200));
    // Gera um ID para Curso
    case 3:
        return (200 + (rand()%200));
    // Gera um ID para Oficina
    case 4:
        return (300 + (rand()%300));
    // Gera um ID Para Congressista
    case 5:
        return (1000 + (rand()%1000));
    case 6:
        return (2000 + (rand()%2000));
    }
}

int verificar_ID(int tipo, int ID){
    FILE *palestras;
    FILE *gp;
    FILE *cursos;
    FILE *oficinas;
    FILE *congress;
    FILE *organizadores;

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
    // Verifica um ID para Curso
    case 3:
        cursos = fopen("Arquivos\\cursos.txt", "rb");

        if (gp == NULL){
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
    // Verifica um ID para Oficina
    case 4:
        oficinas = fopen("Arquivos\\oficinas.txt", "rb");

        if (gp == NULL){
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
    // Gera um ID Para Congressista
    case 5:
        congress = fopen("Arquivos\\congressistas.txt", "rb");

        if (gp == NULL){
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
    }
}

int gerar_id_valido(int tipo){

    int id;
    do {
        id = gerar_id(tipo);
    } while(verificar_ID(tipo, id) != 1);
    return id;
}

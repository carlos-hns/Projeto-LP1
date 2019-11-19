#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include "Participantes.h"
#include "Uteis.h"
#include "Eventos.h"

/*
*       -----------------------
*           LOCAIS
*       -----------------------
*/

void cadastrar_local(){
    FILE *locais;
    locais = fopen("Arquivos\\locais.txt", "ab");

    if (locais == NULL){
        fclose(locais);
        printf("Falha ao carregar o arquivo.");
    } else {

        LOCAL loc;
        loc.ID = gerar_id_valido(8);

        printf("\nTipo do Evento: \n");
        printf("|1| - Para Palestra\n");
        printf("|2| - Para GP de Discussao\n");
        printf("|3| - Para Curso\n");
        printf("|4| - Para Oficina\n");
        printf(">>> ");

        do {
            scanf("%d", &loc.tipo_evento);
        } while(loc.tipo_evento < 1 || loc.tipo_evento > 4);


        printf("\nDia do Evento:\n");
        printf("|1| - Dia 14\n");
        printf("|2| - Dia 15\n");
        printf(">>> ");

        do {
            scanf("%d", &loc.dia);
        } while (loc.dia != 1 && loc.dia != 2);

        if (loc.dia == 1){
            loc.dia = 14;
        } else {
            loc.dia = 15;
        }

        printf("\nHorario do Evento: \n");
        printf("|1| - 07:00 as 09:00\n");
        printf("|2| - 09:00 as 11:00\n");
        printf("|3| - 13:00 as 15:00\n");
        printf("|4| - 15:00 as 17:00\n");
        printf(">>> ");

        int horario_escolha;

        do {
            scanf("%d", &horario_escolha);
        } while(horario_escolha < 1 || horario_escolha > 4);


        switch (horario_escolha){
        case 1:
            strcpy(loc.horario, "07:00-09:00");
            break;
        case 2:
            strcpy(loc.horario, "09:00-11:00");
            break;
        case 3:
            strcpy(loc.horario, "13:00-15:00");
            break;
        case 4:
            strcpy(loc.horario, "15:00-17:00");
            break;
        }

        printf("\nCarga Horaria: \n");
        printf("|1| - 1H\n");
        printf("|2| - 2H\n");
        printf(">>> ");

        do {
            scanf("%d", &loc.carga_horaria);
        } while (loc.carga_horaria != 1 && loc.carga_horaria != 2);


        printf("\nLocais: \n");
        printf("|1| - AUDITORIO 1 - [150 PESSOAS]\n");
        printf("|2| - AUDITORIO 2 - [100 PESSOAS]\n");
        printf("|3| - AUDITORIO 3 - [50 PESSOAS]\n");
        printf("|4| - SALA 1 - [50 PESSOAS]\n");
        printf("|5| - SALA 2 - [50 PESSOAS]\n");
        printf("|6| - SALA 3 - [30 PESSOAS]\n");
        printf("|7| - LABORATORIO 1 - [20 PESSOAS]\n");
        printf("|8| - LABORATORIO 2 - [20 PESSOAS]\n");
        printf(">>> ");

        int sala_escolha;

        do {
            scanf("%d", &sala_escolha);
        } while (sala_escolha < 1 || sala_escolha > 8);


        switch(sala_escolha){
        case 1:
            strcpy(loc.local, "AUDITORIO 1");
            break;
        case 2:
            strcpy(loc.local, "AUDITORIO 2");
            break;
        case 3:
            strcpy(loc.local, "AUDITORIO 3");
            break;
        case 4:
            strcpy(loc.local, "SALA 1");
            break;
        case 5:
            strcpy(loc.local, "SALA 2");
            break;
        case 6:
            strcpy(loc.local, "SALA 3");
            break;
        case 7:
            strcpy(loc.local, "LABORATORIO 1");
            break;
        case 8:
            strcpy(loc.local, "LABORATORIO 2");
            break;

        }

        // 1 == DISPONIVEL
        // -1 == NAO DISPONIVEL

        loc.disponibilidade = 1;

        fwrite(&loc, sizeof(LOCAL), 1, locais);
        fclose(locais);
    }
}

void listar_reservas_locais(){

    FILE *locais;
    locais = fopen("Arquivos\\locais.txt", "rb");

    if (locais == NULL){
            fclose(locais);
        printf("Falha ao carregar o arquivo.");
    } else {
        LOCAL loc;

        printf("Listando: \n\n");
        while(fread(&loc, sizeof(LOCAL), 1, locais) == 1){
            printf("ID: %d\n", loc.ID);
            printf("DIA: %d\n", loc.dia);
            printf("HORARIO: %s\n", loc.horario);
            printf("CARGA HORARIA: %dH\n", loc.carga_horaria);
            printf("LOCAL: %s\n", loc.local);
            printf("DISPONIBILIDADE: %d\n", loc.disponibilidade);
            putchar('\n');

        }

        fclose(locais);
    }
}

void listar_por_tipo_evento(int ID){

    FILE *locais;
    locais = fopen("Arquivos\\locais.txt", "rb");


    if (locais == NULL){
        fclose(locais);
        printf("Falha ao carregar o arquivo.\n");
    } else {
        LOCAL loc;

        // TIPO PALESTRA
        if (ID >= 0 && ID <= 100){
            while(fread(&loc, sizeof(LOCAL), 1, locais) == 1){
                if (loc.ID >= 0 && loc.ID <= 100){
                    printf("ID: %d\n", loc.ID);
                    printf("Dia: %d\n", loc.dia);
                    printf("Horario: %s", loc.horario);
                    printf("Carga Horaria: %dH\n", loc.carga_horaria);
                    printf("%s", loc.local);
                    printf("%d\n", loc.disponibilidade);
                    putchar('\n');
                }
            }
        // TIPO GP DE DISCUSSOES
        } else if (ID > 100 && ID <= 200){
            while(fread(&loc, sizeof(LOCAL), 1, locais) == 1){
                if (loc.ID > 100 && loc.ID <= 200){
                    printf("ID: %d\n", loc.ID);
                    printf("Dia: %d\n", loc.dia);
                    printf("Horario: %s", loc.horario);
                    printf("Carga Horaria: %dH\n", loc.carga_horaria);
                    printf("%s", loc.local);
                    printf("%d\n", loc.disponibilidade);
                    putchar('\n');
                }
            }
        // TIPO CURSO
        } else if(ID > 200  && ID <= 300){
            while(fread(&loc, sizeof(LOCAL), 1, locais) == 1){
                if (loc.ID > 200  && loc.ID <= 300){
                    printf("ID: %d\n", loc.ID);
                    printf("Dia: %d\n", loc.dia);
                    printf("Horario: %s", loc.horario);
                    printf("Carga Horaria: %dH\n", loc.carga_horaria);
                    printf("%s", loc.local);
                    printf("%d\n", loc.disponibilidade);
                    putchar('\n');
                }
            }
        // TIPO OFICINA
        } else if (ID > 300 && ID <= 400){
            while(fread(&loc, sizeof(LOCAL), 1, locais) == 1){
                if (loc.ID > 300 && loc.ID <= 400){
                    printf("ID: %d\n", loc.ID);
                    printf("Dia: %d\n", loc.dia);
                    printf("Horario: %s", loc.horario);
                    printf("Carga Horaria: %dH\n", loc.carga_horaria);
                    printf("%s", loc.local);
                    printf("%d\n", loc.disponibilidade);
                    putchar('\n');
                }
            }
        }
        fclose(locais);
    }
}

void alterar_disponibilidade(int ID, int estado){

    // 1 DISPONIVEL
    // -1 INDISPONIVEL

    FILE *locais;
    FILE *locais_aux;
    locais = fopen("Arquivos\\locais.txt", "rb");
    locais_aux = fopen("Arquivos\\temp.txt", "wb");
    if (locais == NULL){
            fclose(locais);
        printf("Falha ao carregar o arquivo.\n");
    } else {
        if (locais_aux == NULL){
            locais_aux;
            printf("Falha ao carregar o arquivo.\n");
        } else {

            LOCAL loc;

            while(fread(&loc, sizeof(LOCAL), 1, locais)){
                if (loc.ID == ID){
                    loc.disponibilidade = estado;
                }

                fwrite(&loc, sizeof(LOCAL), 1, locais_aux);
            }
            fclose(locais);
            fclose(locais_aux);
            remove("Arquivos\\locais.txt");
            rename("Arquivos\\temp.txt", "Arquivos\\locais.txt");
        }
    }
}

/*
*       -----------------------
*           PALESTRA
*       -----------------------
*/

void listar_palestras(){

    FILE *palestras;
    palestras = fopen("Arquivos\\palestras.txt", "rb");

    if (palestras == NULL){
        fclose(palestras);
        printf("Falha ao carregar o arquivo.\n");
    } else {
        PALESTRA pale;

        while(fread(&pale, sizeof(PALESTRA), 1, palestras)){
            printf("\nID: %d\n", pale.ID);
            printf("CAPACIDADE: %d\n", pale.capacidade);
            printf("TEMA: %s", pale.tema);
            printf("PROFESSOR: %d\n", pale.professor_palestrante);

        }
        fclose(palestras);
    }
}

// --> Vamos incrementar essa fun��o a cada local adcionando;
int disponibilidade_palestrante_PCO(int ID){

    // VERIFICA A DISPONIBILIDADE EM PALESTRA/CURSO/OFICINA

    FILE *palestras;
    palestras = fopen("Arquivos\\palestras.txt", "rb");

    if (palestras == NULL){
        printf("Falha ao carregar o arquivo.\n");
    } else {
        PALESTRA pale;
        while(fread(&pale, sizeof(PALESTRA), 1, palestras) == 1){
            printf("ID PROFESSORES: %d\n", pale.professor_palestrante);
            if (ID == pale.professor_palestrante){
                return 0; // PROFESSOR J� PARTICIPA DE ALGO
            }
        }


        return -1;
    }
}

int cadastrar_palestra(){

    FILE *palestras;
    FILE *locais;
    FILE *locais2;

    palestras = fopen("Arquivos\\palestras.txt", "ab");

    if (palestras == NULL){
        printf("Falha ao carregar o arquivo.\n");
    } else {
        if (quantidade_palestrantes() == 0){
            printf("Nao existem palestrantes cadastrados.\n");
            printf("Por favor, cadastre e tente novamente.");
        } else {
            PALESTRA pale;

            // GERA ID DE PALESTRA
            pale.ID = gerar_id_valido(1);
            zerarArray(pale.matriculas, 150);

            //CAPACIDADE
            printf("CAPACIDADE >>> ");
            do {
                scanf("%d", &pale.capacidade);
            } while(pale.capacidade < 50 || pale.capacidade > 150);

            setbuf(stdin, NULL);

            // TEMA
            printf("TEMA: ");
            fgets(pale.tema, 50, stdin);
            strcpy(pale.tema, strupr(pale.tema));
            setbuf(stdin, NULL);

            //ESCOLHER PALESTRANTE
            listar_palestrantes();
            int matricula_palestrante;
            printf("ID DO PALESTRANTE: >>> ");

            do {
                scanf("%d", &matricula_palestrante);
            } while (verificar_ID(7, matricula_palestrante) != 0);

            if (disponibilidade_palestrante_PCO(matricula_palestrante) == 0){
                printf("Professor ja ministra um evento.\n");
                return -1;
            }

            pale.professor_palestrante = matricula_palestrante;

            locais = fopen("Arquivos\\locais.txt", "rb");

            if (locais == NULL){
                printf("Falha ao carregar o arquivo.\n");
            } else {
                LOCAL loc;
                while(fread(&loc, sizeof(LOCAL), 1, locais)){
                    if (loc.tipo_evento == 1 && loc.disponibilidade == 1){
                        printf("ID: %d\n", loc.ID);
                        printf("DIA: %d\n", loc.dia);
                        printf("HORARIO: %s\n", loc.horario);
                        printf("CARGA HORARIA: %dH\n", loc.carga_horaria);
                        printf("LOCAL: %s\n", loc.local);
                        printf("DISPONIBILIDADE: %d\n", loc.disponibilidade);
                        putchar('\n');
                    }
                }

                fclose(locais);
                int id_escolha;

                printf("ID LOCAL: >>> ");
                scanf("%d", &id_escolha);

                locais2 = fopen("Arquivos\\locais.txt", "rb");

                while(fread(&loc, sizeof(LOCAL), 1, locais2)){
                    if (loc.ID == id_escolha){
                        pale.loc = loc;
                    }
                }

                fclose(locais2);

                fwrite(&pale, sizeof(PALESTRA), 1, palestras);
                alterar_disponibilidade(id_escolha, -1);
                fclose(palestras);
            }
        }
    }
}

int remover_palestra(){

    FILE *palestras;
    FILE *palestras_aux;

    palestras = fopen("Arquivos\\palestras.txt", "rb");
    palestras_aux = fopen("Arquivos\\tempo.txt", "wb");

    if (palestras == NULL || palestras_aux == NULL){
        printf("Falha ao carregar o arquivo.\n");
    } else {

        PALESTRA pale;
        int ID;
        listar_palestras();
        printf("ID P/ REMOVER >>> ");
        scanf("%d", &ID);

        while(fread(&pale, sizeof(PALESTRA), 1, palestras) == 1){
            if (ID != pale.ID){
                fwrite(&pale, sizeof(PALESTRA), 1, palestras_aux);
            } else{

                alterar_disponibilidade(pale.loc.ID, 1);
            }
        }

        fclose(palestras);
        fclose(palestras_aux);
        remove("Arquivos\\palestras.txt");
        rename("Arquivos\\tempo.txt", "Arquivos\\palestras.txt");
    }
}





/*
*       -----------------------
*           GP DE DISCUSS�O
*       -----------------------
*/


/*
*       -----------------------
*           CURSO
*       -----------------------
*/

/*
*       -----------------------
*           OFICINA
*       -----------------------
*/

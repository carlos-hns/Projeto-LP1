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

int gerar_locais_zerados(){

    FILE *locais;
    locais = fopen("Arquivos\\locais.txt", "wb");

    if (locais == NULL){
        fclose(locais);
        return -1;
    } else {

        LOCAL loc;

        // AUDITORIO 1
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 14;
        strcpy(loc.horario, "07:00-09:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // AUDITORIO 1
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 14;
        strcpy(loc.horario, "09:00-11:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // AUDITORIO 1
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 15;
        strcpy(loc.horario, "07:00-09:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);


        // AUDITORIO 1
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 15;
        strcpy(loc.horario, "09:00-11:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // <---------------------------------------------->

        // AUDITORIO 2
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 14;
        strcpy(loc.horario, "07:00-09:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);


        // AUDITORIO 2
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 14;
        strcpy(loc.horario, "09:00-11:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);


        // AUDITORIO 2
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 15;
        strcpy(loc.horario, "07:00-09:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // AUDITORIO 2
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 15;
        strcpy(loc.horario, "09:00-11:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // <---------------------------------------------->

        // AUDITORIO 3
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 14;
        strcpy(loc.horario, "07:00-09:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 3");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // AUDITORIO 3
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 14;
        strcpy(loc.horario, "09:00-11:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 3");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 15;
        strcpy(loc.horario, "07:00-09:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 3");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // AUDITORIO 3
        loc.tipo_evento = 1; // PALESTRA
        loc.dia = 15;
        strcpy(loc.horario, "09:00-11:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "AUDITORIO 3");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // <---------------------------------------------->

        // SALA 1 - CURSOS
        loc.tipo_evento = 3; // CURSO
        loc.dia = 14;
        strcpy(loc.horario, "13:00-15:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // SALA 1
        loc.tipo_evento = 3; // CURSO
        loc.dia = 15;
        strcpy(loc.horario, "13:00-15:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // <---------------------------------------------->


        // SALA 2
        loc.tipo_evento = 3; // CURSO
        loc.dia = 14;
        strcpy(loc.horario, "13:00-15:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // SALA 2
        loc.tipo_evento = 3; // CURSO
        loc.dia = 15;
        strcpy(loc.horario, "13:00-15:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // <---------------------------------------------->

        // SALA 1 - GP DE DISCUSSAO
        loc.tipo_evento = 2; // GP DISCUSSAO
        loc.dia = 14;
        strcpy(loc.horario, "15:00-16:00");
        loc.carga_horaria = 1;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // SALA 1
        loc.tipo_evento = 2; // GP DISCUSSAO
        loc.dia = 15;
        strcpy(loc.horario, "15:00-16:00");
        loc.carga_horaria = 1;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // <---------------------------------------------->


        // SALA 2 - GP DE DISCUSSAO
        loc.tipo_evento = 2; // GP DISCUSSAO
        loc.dia = 14;
        strcpy(loc.horario, "15:00-16:00");
        loc.carga_horaria = 1;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // SALA 2
        loc.tipo_evento = 2; // GP DISCUSSAO
        loc.dia = 15;
        strcpy(loc.horario, "15:00-16:00");
        loc.carga_horaria = 1;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // <---------------------------------------------->

        // SALA 3 - GP DE DISCUSSAO
        loc.tipo_evento = 2; // GP DISCUSSAO
        loc.dia = 14;
        strcpy(loc.horario, "13:00-14:00");
        loc.carga_horaria = 1;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 3");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // SALA 3
        loc.tipo_evento = 2; // GP DISCUSSAO
        loc.dia = 14;
        strcpy(loc.horario, "14:00-15:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 3");

        fwrite(&loc, sizeof(LOCAL), 1, locais);


        // SALA 3 - GP DE DISCUSSAO
        loc.tipo_evento = 2; // GP DISCUSSAO
        loc.dia = 15;
        strcpy(loc.horario, "13:00-14:00");
        loc.carga_horaria = 1;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 3");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // SALA 3
        loc.tipo_evento = 2; // GP DISCUSSAO
        loc.dia = 15;
        strcpy(loc.horario, "14:00-15:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "SALA 3");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // <---------------------------------------------->


        // LABORATORIO 1 - OFICINA
        loc.tipo_evento = 4; // OFICINA
        loc.dia = 14;
        strcpy(loc.horario, "13:00-15:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "LABORATORIO 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // LABORATORIO 1
        loc.tipo_evento = 4; // OFICINA
        loc.dia = 14;
        strcpy(loc.horario, "15:00-17:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "LABORATORIO 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);


        // LABORATORIO 1 - OFICINA
        loc.tipo_evento = 4; // OFICINA
        loc.dia = 15;
        strcpy(loc.horario, "13:00-15:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "LABORATORIO 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // LABORATORIO 1
        loc.tipo_evento = 4; // OFICINA
        loc.dia = 15;
        strcpy(loc.horario, "15:00-17:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "LABORATORIO 1");

        fwrite(&loc, sizeof(LOCAL), 1, locais);


        // <---------------------------------------------->

        // LABORATORIO 2 - OFICINA
        loc.tipo_evento = 4; // OFICINA
        loc.dia = 14;
        strcpy(loc.horario, "13:00-15:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "LABORATORIO 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // LABORATORIO 1
        loc.tipo_evento = 4; // OFICINA
        loc.dia = 14;
        strcpy(loc.horario, "15:00-17:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "LABORATORIO 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);


        // LABORATORIO 2 - OFICINA
        loc.tipo_evento = 4; // OFICINA
        loc.dia = 15;
        strcpy(loc.horario, "13:00-15:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "LABORATORIO 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);

        // LABORATORIO 2
        loc.tipo_evento = 4; // OFICINA
        loc.dia = 15;
        strcpy(loc.horario, "15:00-17:00");
        loc.carga_horaria = 2;
        loc.disponibilidade = 1; // DISPONIVEL
        loc.ID = gerar_id_valido(8); // ID LOCAL
        strcpy(loc.local, "LABORATORIO 2");

        fwrite(&loc, sizeof(LOCAL), 1, locais);
        fclose(locais);
    }
    fclose(locais);
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
            //Sleep(500);

        }

        fclose(locais);
    }
    fclose(locais);
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

int alterar_disponibilidade(int ID, int estado){

    FILE *locais;
    FILE *locais_aux;

    locais = fopen("Arquivos\\locais.txt", "rb");
    locais_aux = fopen("Arquivos\\alterar_disponibilidade.txt", "ab");

    if (locais == NULL || locais_aux == NULL){
        return -1;
    } else {

        LOCAL loc;
        while(fread(&loc, sizeof(LOCAL), 1, locais)){
            if(loc.ID == ID){
                loc.disponibilidade = estado;
            }
            fwrite(&loc, sizeof(LOCAL), 1, locais_aux);
        }

        fclose(locais);
        fclose(locais_aux);

        remove("Arquivos\\locais.txt");
        rename("Arquivos\\alterar_disponibilidade.txt", "Arquivos\\locais.txt");
    }
    return 0;
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

// --> Vamos incrementar essa função a cada local adcionando;
int disponibilidade_palestrante_PCO(int ID){

    // VERIFICA A DISPONIBILIDADE EM PALESTRA/CURSO/OFICINA

    FILE *palestras;
    palestras = fopen("Arquivos\\palestras.txt", "rb");

    if (palestras == NULL){
        fclose(palestras);
        return -1;
    } else {
        PALESTRA pale;
        while(fread(&pale, sizeof(PALESTRA), 1, palestras) == 1){
            printf("ID PROFESSORES: %d\n", pale.professor_palestrante);
            if (ID == pale.professor_palestrante){
                fclose(palestras);
                return -1; // PROFESSOR JÁ PARTICIPA DE ALGO
            }
        }

        fclose(palestras);
        return 0;
    }
}

int cadastrar_palestra(){

    FILE *palestras;
    FILE *locais;

    palestras = fopen("Arquivos\\palestras.txt", "ab");
    if (palestras == NULL){
        fclose(palestras);
        return -1;
    } else {
        if (quantidade_palestrantes() == -1){
            fclose(palestras);
            return -1;
        } else {
            if (quantidade_palestrantes() == 0){
                fclose(palestras);
                return -2;
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

                if (disponibilidade_palestrante_PCO(matricula_palestrante) == -1){
                    printf("Professor ja ministra um evento.\n");
                    return -3;
                }

                pale.professor_palestrante = matricula_palestrante;

                locais = fopen("Arquivos\\locais.txt", "rb");

                if (locais == NULL){
                    fclose(palestras);
                    return -1;
                } else {
                    LOCAL loc;
                    while(fread(&loc, sizeof(LOCAL), 1, locais)){
                        if (loc.tipo_evento == 1 && loc.disponibilidade == 1){
                            if (pale.capacidade == 50 && (strcmp(loc.local, "AUDITORIO 3") == 0)){
                                printf("ID: %d\n", loc.ID);
                                printf("DIA: %d\n", loc.dia);
                                printf("HORARIO: %s\n", loc.horario);
                                printf("CARGA HORARIA: %dH\n", loc.carga_horaria);
                                printf("LOCAL: %s\n", loc.local);
                                printf("DISPONIBILIDADE: %d\n", loc.disponibilidade);
                                putchar('\n');
                                Sleep(1500);
                            } else {
                                if ((pale.capacidade > 50 && pale.capacidade <= 100) &&(strcmp(loc.local, "AUDITORIO 2") == 0)){
                                    printf("ID: %d\n", loc.ID);
                                    printf("DIA: %d\n", loc.dia);
                                    printf("HORARIO: %s\n", loc.horario);
                                    printf("CARGA HORARIA: %dH\n", loc.carga_horaria);
                                    printf("LOCAL: %s\n", loc.local);
                                    printf("DISPONIBILIDADE: %d\n", loc.disponibilidade);
                                    putchar('\n');
                                    Sleep(1500);
                                } else {
                                    if ((pale.capacidade > 100 && pale.capacidade <= 150) &&(strcmp(loc.local, "AUDITORIO 1") == 0)){
                                            printf("ID: %d\n", loc.ID);
                                            printf("DIA: %d\n", loc.dia);
                                            printf("HORARIO: %s\n", loc.horario);
                                            printf("CARGA HORARIA: %dH\n", loc.carga_horaria);
                                            printf("LOCAL: %s\n", loc.local);
                                            printf("DISPONIBILIDADE: %d\n", loc.disponibilidade);
                                            putchar('\n');
                                            Sleep(1500);
                                    }
                                }
                            }
                        }
                    }
                    fclose(locais);

                    int id_escolha;
                    printf("ID LOCAL: >>> ");
                    scanf("%d", &id_escolha);

                    locais = fopen("Arquivos\\locais.txt", "rb");
                    if (locais == NULL){
                        fclose(palestras);
                        return -1;
                    } else {

                        while(fread(&loc, sizeof(LOCAL), 1, locais)){
                            if (loc.ID == id_escolha){
                                pale.loc = loc;
                                break;
                            }
                        }
                    }
                    fclose(locais);

                    fwrite(&pale, sizeof(PALESTRA), 1, palestras);
                    fclose(palestras);

                    alterar_disponibilidade(id_escolha, -1);
                }
            }
        }
    }
}

int remover_palestra(){

    FILE *palestras;
    FILE *palestras_aux;

    palestras = fopen("Arquivos\\palestras.txt", "rb");
    palestras_aux = fopen("Arquivos\\tempo.txt", "ab");

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
*           GP DE DISCUSSÃO
*       -----------------------
*/


/*
*       -----------------------
*           CURSO
*       -----------------------
*/

int listar_cursos(){

    FILE *cursos;
    cursos = fopen("Arquivos\\cursos.txt", "rb");

    if (cursos == NULL){
        return -1;
    } else {

        CURSO cur;

        while(fread(&cur, sizeof(CURSO), 1, cursos)){
            printf("\nID: %d\n", cur.ID);
            printf("CAPACIDADE: %d\n", cur.capacidade);
            printf("TEMA: %s", cur.tema);
            printf("PROFESSOR: %d\n", cur.professor_palestrante);

        }
        fclose(cursos);
    }
}

int cadastrar_curso(){

    FILE *cursos;
    cursos = fopen("Arquivos\\cursos.txt", "ab");

    if (cursos == NULL){
        return -1;
    } else {
        if (quantidade_palestrantes() == -1){
            fclose(cursos);
            return -1; // ERRO NA INICIALIZAÇÃO
        } else {
            if (quantidade_palestrantes() == 0){
                fclose(cursos); // PALESTRANTES VAZIOS
                return -2;
            } else {

                CURSO cur;

                // GERA ID DE PALESTRA
                cur.ID = gerar_id_valido(3);
                zerarArray(cur.matriculas, 40);

                //CAPACIDADE
                printf("CAPACIDADE >>> ");
                do {
                    scanf("%d", &cur.capacidade);
                } while(cur.capacidade < 1 || cur.capacidade > 40);

                setbuf(stdin, NULL);

                // TEMA
                printf("TEMA: ");
                fgets(cur.tema, 50, stdin);
                strcpy(cur.tema, strupr(cur.tema));
                setbuf(stdin, NULL);

                //ESCOLHER PALESTRANTE
                listar_palestrantes();
                int matricula_palestrante;
                printf("ID DO PALESTRANTE: >>> ");

                do {
                    scanf("%d", &matricula_palestrante);
                } while (verificar_ID(7, matricula_palestrante) != 0);

                if (disponibilidade_palestrante_PCO(matricula_palestrante) == -1){
                    printf("Professor ja ministra um evento.\n");
                    return -3;
                }

                cur.professor_palestrante = matricula_palestrante;

                FILE *locais;
                locais = fopen("Arquivos\\locais.txt", "rb");

                if (locais == NULL){
                    fclose(cursos);
                    return -1;
                } else {
                    LOCAL loc;
                    int contador =0;

                    while(fread(&loc, sizeof(LOCAL), 1, locais)){
                        if (loc.tipo_evento == 3 &&
                             loc.disponibilidade == 1 &&
                             strcmp(loc.horario, "13:00-15:00") == 1){
                            contador++;
                        }
                    }

                    if (contador == 0){
                        return -4; // SALAS INDISPONIVEIS...
                    }
                    fseek(locais, 0, 0);

                    while(fread(&loc, sizeof(LOCAL), 1, locais)){
                        if (loc.tipo_evento == 3 &&
                             loc.disponibilidade == 1 &&
                             strcmp(loc.horario, "13:00-15:00") == 1){

                            printf("ID: %d\n", loc.ID);
                            printf("DIA: %d\n", loc.dia);
                            printf("HORARIO: %s\n", loc.horario);
                            printf("CARGA HORARIA: %dH\n", loc.carga_horaria);
                            printf("LOCAL: %s\n", loc.local);
                            printf("DISPONIBILIDADE: %d\n", loc.disponibilidade);
                            putchar('\n');
                            Sleep(1500);
                        }
                    }
                    fclose(locais);

                    int id_escolha;
                    printf("ID LOCAL: >>> ");
                    scanf("%d", &id_escolha);

                    locais = fopen("Arquivos\\locais.txt", "rb");
                    if (locais == NULL){
                        fclose(cursos);
                        return -1;
                    } else {

                        while(fread(&loc, sizeof(LOCAL), 1, locais)){
                            if (loc.ID == id_escolha){
                                cur.loc = loc;
                                break;
                            }
                        }
                    }
                    fclose(locais);

                    fwrite(&cur, sizeof(CURSO), 1, cursos);
                    fclose(cursos);

                    alterar_disponibilidade(id_escolha, -1);
                }

            // VERIFICAR SE A FUNÇÃO ESTA PEGANDO!
            // SÓ TROQUEI AS VARIAVEIS E OS NOMES...
            }
        }
    }
}



/*
*       -----------------------
*           OFICINA
*       -----------------------
*/

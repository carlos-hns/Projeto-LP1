#ifndef REGISTRO_PESSOA
#define REGISTRO_PESSOA

typedef struct {

    int ID;
    char nome[30];
    char curso[30];

} CONGRESSISTA;

typedef struct {

    int ID;
    char login[30];
    char senha[30];

} ORGANIZADOR;

typedef struct {

    int ID;
    char nome[30];
    char endereco[30];

} PALESTRANTE;

#endif

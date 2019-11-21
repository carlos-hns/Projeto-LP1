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
    // Area em que se especializou.
    char formacao[30];

} PALESTRANTE;

// CONGRESSSISTAS
int quantidade_congressistas();
int listar_congressistas();
int cadastrar_congressista();
int remover_congressista();

// ORGANIZADORES
int quantidade_organizadores();
int listar_organizadores();
int cadastrar_organizador();
int remover_organizador();

// PALESTRANTES
int quantidade_palestrantes();
int listar_palestrantes();
int cadastrar_palestrante();
int remover_palestrante();

#endif

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
    char especialidade[30];

} PALESTRANTE;

// CONGRESSSISTAS
int quantidade_congressistas();
int listar_congressistas();
int cadastrar_congressista();
int remover_congressista();

// ORGANIZADORES
int quantidade_organizadores();
void listar_organizadores();
void cadastrar_organizador();
void remover_organizador();

// PALESTRANTES
int quantidade_palestrantes();
void listar_palestrantes();
void cadastrar_palestrante();
void remover_palestrante();

#endif

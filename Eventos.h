#ifndef LOCAL_EVENTO
#define LOCAL_EVENTO

typedef struct {

    int ID; // ID DO LOCAL
    char horario[15];
    int tipo_evento;
    int dia;
    int carga_horaria;
    char local[15];
    int disponibilidade;

} LOCAL;

typedef struct {

    int ID; // ID DA PALESTRA
    int capacidade;
    int matriculas[150];
    char tema[50];
    int professor_palestrante; // ID DO PALESTRANTE
    LOCAL loc;

} PALESTRA;

typedef struct {

    int ID; // ID DO GP DE DISCUSSAO
    int capacidade;
    int matriculas[50];
    char tema[50];
    int mesa[5]; // ID's DOS PARTICIPANTES DA MESA
    LOCAL loc;

} GP_DISCUSSOES;

typedef struct {

    int ID; // ID DO CURSO
    int capacidade;
    int matriculas[40];
    char tema[50];
    int professor_palestrante; // ID DO PALESTRANTE
    LOCAL loc;

} CURSO;

typedef struct {

    int ID; // ID DA PALESTRA
    int capacidade;
    int matriculas[20];
    char tema[50];
    int professor_palestrante; // ID DO PALESTRANTE
    LOCAL loc;

} OFICINA;

// LOCAL

int alterar_disponibilidade(int ID, int estado);
void cadastrar_local();



#endif // LOCAL_EVENTO

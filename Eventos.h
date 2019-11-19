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
    int matriculas[50];
    char local[15];
    int horario;
    int carga_horaria;
    char tema[50];
    int mesa[5]; // ID's DOS PARTICIPANTES DA MESA


} GP_DISCUSSOES;

typedef struct {

    int ID; // ID DO CURSO
    int matriculas[40];
    char local[15];
    int horario;
    int carga_horaria;
    char tema[50];
    int professor_palestrante; // ID DO PROFESSOR


} CURSO;

typedef struct {

    int ID; // ID DA OFICINA
    int matriculas[20];
    char local[15];
    int horario;
    int carga_horaria;
    char tema[50];
    int professor_palestrante; // ID DO PROFESSOR


} OFICINA;

// LOCAL

void cadastrar_local();



#endif // LOCAL_EVENTO

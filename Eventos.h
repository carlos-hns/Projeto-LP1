#ifndef LOCAL_EVENTO
#define LOCAL_EVENTO

typedef struct {

    int ID;
    char horario[15];
    int dia;
    char tema[50];
    char carga_horaria[4];
    int disponibilidade;

} LOCAL;

typedef struct {

    int ID; // ID DA PALESTRA
    int matriculas[150];
    char local[15];
    int horario;
    int carga_horaria;
    char tema[50];
    int professor_palestrante; // ID DO PALESTRANTE


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

#endif // LOCAL_EVENTO

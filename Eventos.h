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
void cadastrar_local();
int gerar_locais_zerados();
void listar_reservas_locais();
void listar_por_tipo_evento(int ID);
int alterar_disponibilidade(int ID, int estado);

// PALESTRA
int quantidade_palestras();
int listar_palestras();
int disponibilidade_palestrante_PCO(int ID);
int cadastrar_palestra();
int remover_palestra();
int editar_palestra();

// GP DISCUSSAO
int quantidade_gp_discussao();
int listar_gp_discussao();
int criar_gp_discussoes();
int remover_gp_discussoes();
int editar_gp_discussoes();

// CURSO
int quantidade_cursos();
int listar_cursos();
int cadastrar_curso();
int remover_cursos();
int editar_curos();

// OFICINA
int quantidade_oficinas();
int listar_oficinas();
int remover_oficinas();
int cadastrar_oficina();
int editar_oficinas();

#endif // LOCAL_EVENTO

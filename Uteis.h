#ifndef UTEIS
#define UTEIS

int gerar_id(int tipo);
int verificar_ID(int tipo, int ID);
int gerar_id_valido(int tipo);
void zerarArray(int *array, int n);
void gotoxy(int x, int y);
int calcular_meio(int colunas, char *string);
char *retornar_nome_palestrante(int ID);

#endif // UTEIS

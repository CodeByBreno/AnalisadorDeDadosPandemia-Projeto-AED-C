/*funções de apoio*/
int size (char *);
int alfabetico (char *, char *);
int checkNome(char *);
int checkIdade(int);
int * CombSort (int *, int );
float Mediana (int *, int );
float DesvioPadrao (int * , int , float );

/*funções de busca*/
int getSearchSize(NODO **);
int checkNome(char *);
int manipulate(NODO **, LISTA);
int manipulateNode(NODO *, LISTA);
    void mostrarDados(NODO *);
        char *getGenero(char);
        char *getRenda(int);
        char *getFatRisco(char *);
        char *getFatRiscoByPosition(int);
        char *getSituation(int);
    int editarDados(NODO *, LISTA);
        void setNome(NODO *);
        void setIdade(NODO *, LISTA);
        void setGenero(NODO *, LISTA);
        void setRenda(NODO *, LISTA);
        void setFatRisco(NODO *, LISTA);
        void setSituation(NODO *, LISTA);
int searchMenu(LISTA);
int searchByNomeMenu(LISTA);
int searchByIdadeMenu(LISTA);
int searchByGeneroMenu(LISTA);
int searchByRendaMenu(LISTA);
int searchByFatRiscoMenu(LISTA);
int searchBySituationMenu(LISTA);

int getMatchingNumbersByName(LISTA, char *);
int getMatchingNumbersByIdade(LISTA, int);
int getMatchingNumbersByGenero(LISTA, char);
int getMatchingNumbersByRenda(LISTA, int);
int getMatchingNumbersByFatRisco(LISTA, char *);
int getMatchingNumbersBySituation(LISTA, int);
NODO **searchByName(LISTA, char *);
NODO **searchByIdade(LISTA, int);
NODO **searchByGenero(LISTA, char);
NODO **searchByRenda(LISTA, int);
NODO **searchByFatRisco(LISTA, char *);
NODO **searchBySituation(LISTA, int);

/*funções fundamentais*/
void create_list (LISTA *);
void inserir(FICHA *, LISTA);
void removeNode(NODO *, LISTA);
void update (int, LISTA, FICHA *);
void finalizar (LISTA, char *);

/*funções de analise dos dados*/
char monitor (int);
void analise_numerica (int *, int, float, char *);
void numeros_idade (LISTA);
void numeros_genero (LISTA);
void numeros_renda (LISTA);
void numeros_fatores_risco (LISTA);
void numeros_situation (LISTA);

/*funções de manipulação de arquivos*/
void inserir_arquivo (FILE *, LISTA);
void salvar_arquivo (FILE *, LISTA);


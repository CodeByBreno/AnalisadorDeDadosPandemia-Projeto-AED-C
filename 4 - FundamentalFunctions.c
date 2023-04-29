
/*funções fundamentais ---------------------------------------*/
void create_list (LISTA * lista){
	int i, j;
	*lista = (NC *) malloc(sizeof(NC));
	if (!lista){
		printf ("Ocorreu um erro ao alocar a memoria necessária\n");
		exit (50);
	}
	(*lista)->tamanho = 0;
	(*lista)->start = NULL;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 16 + F; j++) (*lista)->numeros[i][j] = 0;
}

void inserir (FICHA * dados_de_entrada, LISTA lista){
	NODO * i, * novo;
	int cont = 0;

	i = lista->start;
	novo = (NODO *) malloc (sizeof(NODO));
	if (!novo){
		printf ("Erro ao alocar memoria\n");
		return;
	}
	novo->dados = (FICHA *) malloc (sizeof(FICHA));
	if (!novo->dados){
		printf ("Erro ao alocar memoria\n");
		return;
	}

	novo->dados = dados_de_entrada;

	if (lista->start == NULL){
		novo->next = novo;
		novo->prev = novo;
		lista->start = novo;
		update (1, lista, novo->dados);
		return;
	}
	else{

		while (alfabetico(dados_de_entrada->nome, i->dados->nome) != 1 && cont < lista->tamanho){
			i = i->next;
			cont++;
		}

		novo->next = i;
		novo->prev = i->prev;
		i->prev = novo;
		(novo->prev)->next = novo;
		if (i == lista->start && alfabetico(novo->dados->nome, i->dados->nome) == 1)
			lista->start = novo;
		update (1, lista, novo->dados);
		return;
	}
}
/* Essa função supõe que o nodo existe e já está na lista*/
void removeNode(NODO *n, LISTA l){ // remover os nodos cabeçalho
    update(-1, l, n->dados);
    if(l->tamanho==1)
        l->start = NULL;
    else{
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    free(n);

}

void update (int method, LISTA lista, FICHA * dados){
    int faixa, k;
	lista->tamanho += method;
	if (dados->idade <= 6) faixa = 0;
	else if (dados->idade <= 12) faixa = 1;
	else if (dados->idade <= 18) faixa = 2;
	else if (dados->idade <= 24) faixa = 3;
	else if (dados->idade <= 31) faixa = 4;
	else if (dados->idade <= 40) faixa = 5;
	else if (dados->idade <= 60) faixa = 6;
	else faixa = 7;

	lista->numeros[dados->situation][faixa] += method;

	if (dados->genero == 'M') faixa = 8;
	else if (dados->genero == 'F') faixa = 9;
	else faixa = 10;
	lista->numeros[dados->situation][faixa] += method;

	lista->numeros[dados->situation][dados->renda + 11] += method;

	for (faixa = 16, k = 0; faixa < 16 + F; faixa++, k++){
		if (dados->fatrisco[k] == '1') lista->numeros[dados->situation][faixa] += method;
	}

	lista->numeros[dados->situation][16 + F] += method;
}

void finalizar (LISTA lista, char * vet){
	FILE * file;
	file = fopen(vet, "w");
	if (!file){
		printf ("Erro ao salvar dados\n");
		exit (52);
	}

	salvar_arquivo (file, lista);
	exit (1);
}

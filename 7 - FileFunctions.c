/*funções de manipulação de arquivos*/
void inserir_arquivo (FILE * arq, LISTA list){
	char c, vet[58 + F];
	int i, flag;

	/* inserindo o nome da doença */
	fgets (sickness, 31, arq);
	c = (char)getc(arq);
	while (c != EOF){
		FICHA * entradas = (FICHA *) malloc (sizeof(FICHA));

		for (i = 0, flag = 0; c != '%'; i++){
			if (i) c = (char)getc(arq);

			vet[i] = c;

			if (flag != 1 && vet[i] >= '0' && vet[i] <= '9' ){
				vet[i - 1] = '\n';
				flag = 1;
			}
		}

		c = (char)getc(arq);
		if (c == '\n') c = (char)getc(arq);
		vet[i] = '\0';
		sscanf (vet, "%[^\n] %d %c %d %s %d", entradas->nome, &entradas->idade, &entradas->genero, &entradas->renda, entradas->fatrisco, &entradas->situation);
		inserir (entradas, list);
	}
	fclose (arq);
}

void salvar_arquivo (FILE * arq, LISTA lista){
	NODO * i, * aux;
	char vet[58 + F];
	int cont = 0;
	fputs (sickness, arq);
    /*fputs("\n", arq);*/
	for (i = lista->start; cont < lista->tamanho; i = i->next, cont++){
        putc('\n', arq);
		sprintf (vet, "%s %d %c %d %s %d%%", i->dados->nome, i->dados->idade, i->dados->genero, i->dados->renda, i->dados->fatrisco, i->dados->situation);
		fputs(vet, arq);
	}
	printf("Dados salvos com sucesso.\n");
	waitForInput();
}


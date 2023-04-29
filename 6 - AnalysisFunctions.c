/*funções de analise -----------------------------------------*/
char monitor (int k){
	char choose, vet[5][17] = {"idade", "genero", "renda", "fatores de risco"};
	printf ("\nVocê deseja ver a distribuição por %s de qual grupo de pacientes?\n"
			"(1) - Pacientes que vieram a óbito\n"
			"(2) - Pacientes que possuem sintomas leves\n"
			"(3) - Pacientes que possuem sintomas médios\n"
			"(4) - Pacientes que possuem sintomas graves\n"
			"(5) - Pacientes que foram curados\n\n"
			"Se deseja voltar, aperte qualquer outra tecla\n", vet[k]);
	scanf ("%c", &choose);
	setbuf (stdin, NULL);

	if (choose != '1' && choose != '2' && choose != '3' && choose != '4' && choose != '5')
		return('a');
	return (choose);
}

void analise_numerica (int * vet, int tamanho, float media, char * grupo){
	float desvio, mediana;

	printf ("\nPara o grupo de pessoas que %s,\n", grupo);
	printf ("\nA media de pacientes afetados por faixa vale %.3f\n", media);
	printf ("A Mediana de pacientes afetados nas faixas vale %.3f\n", mediana = Mediana(vet, tamanho));
	desvio = DesvioPadrao (vet, tamanho, media);
	printf ("O Desvio padrão de pacientes afetados nas faixas vale %.3f\n\n", desvio);

	printf ("\n(Se a mediana vale zero, a maioria das faixas não tem ninguem)\n");

	if (mediana != 0){
		if (desvio < 0.3) printf ("A doença parece afetar diferentes faixas de maneira uniforme\n");
		else if (desvio < 0.6) printf ("A doença parece ter preferencia por algumas faixas\n");
		else printf ("A doença notavelmente afeta mais algumas faixas do que outras\n");
	}

}

void numeros_idade (LISTA lista){
	float media = 0, desvio;
	int i, *num;
	char choose, vet[5][24] = {"vieram a óbito", "tiveram sintomas leves", "tiveram sintomas medios", "tiveram sintomas graves"};
	char faixas[8][16] = {"0 a 6 anos     ", "7 a 12 anos    ", "13 a 18 anos   ", "19 a 24 anos   ", "25 a 30 anos   ", "31 a 40 anos   ", "41 a 60 anos   ", "mais de 60 anos"};

	choose = monitor(0);
	if (choose == 'a') return;

	printf ("\nAnalise por faixa de pacientes que %s por %s\n", vet[choose-'1'], sickness);
	for (i = 0; i < 8; i++){
		printf ("%s: %d %s\n", faixas[i], lista->numeros[choose-'1'][i], vet[choose - '1']);
		media += lista->numeros[choose - '1'][i];
	}
	media /= 8;
	analise_numerica (lista->numeros[choose-'1'], 8, media, vet[choose-'1']);
	waitForInput();
}


void numeros_genero (LISTA lista){
	int M = 0, Fe = 0, O = 0, aux;
	float media;
	char choose, vet[5][24] = {"vieram a óbito", "tiveram sintomas leves", "tiveram sintomas medios", "tiveram sintomas graves", "foram curados"};

	for (aux = 0; aux < 5; aux++){
		M += lista->numeros[aux][8];
		Fe += lista->numeros[aux][9];
		O += lista->numeros[aux][10]; }

	printf ("Total de pacientes registrados para cada genero:\n"
		"Masculino: %d\n"
		"Feminino: %d\n"
		"Outro: %d\n", M, Fe, O);

	choose = monitor (1);
	if (choose == 'a') return;

	analise_numerica (lista->numeros[choose-'1']+8, 3, (M+F+O)/3, "foram infectados/curados,\ntemos para cada genero: ");

	printf ("\nCerto! Cerca de %d pacientes homens %s\n", lista->numeros[choose-'1'][8], vet[choose-'1']);
	printf ("%d mulheres apresentaram situação igual\n", lista->numeros[choose-'1'][9], vet[choose-'1']);
	printf ("E outros %d dentro desse grupo se classificaram como outro genero\n\n", lista->numeros[choose-'1'][10], vet[choose-'1']);

	analise_numerica (lista->numeros[choose-'1']+8, 3, (lista->numeros[choose-'1'][8] + lista->numeros[choose-'1'][9] + lista->numeros[choose-'1'][10])/3, vet[choose - '1']);

	printf ("\n\nPressione alguma tecla para continuar\n");
	getchar ();
	system("cls");
}

void numeros_renda (LISTA lista){
	int i, j, renda_por_sit[5];
	char choose, vet[5][24] = {"vieram a óbito", "tiveram sintomas leves", "tiveram sintomas medios", "tiveram sintomas graves", "foram curados"};
	char faixas[5][20] = {"com menos de um", "entre um e tres", "entre tres e cinco", "entre cinco e dez", "com mais que dez"};
	float media = 0;

	for (j = 0; j < 5; j++)
		for (i = 0; i < 5; i++)
			renda_por_sit[j] += lista->numeros[i][11 + j];

	printf ("Total de pacientes registrados para cada grupo de renda: \n");
	for (i = 0; i < 5; i++)
		printf ("Renda %s salario(s) minimo(s) per capita: %d\n", faixas[i], renda_por_sit[i]);

	choose = monitor(2);
	if (choose == 'a');

	printf ("No grupo de pessoas que %s temos:", vet[choose - '1']);
	for (i = 0; i < 5; i++, media += lista->numeros[choose - '1'][11 + i])
		printf ("%s salario(s) minimo(s) per capita: %d\n", faixas[i], lista->numeros[choose - '1'][11 + i]);

	analise_numerica (lista->numeros[choose-'1']+11, 5, media/5, vet[choose - '1']);

    waitForInput();
}

void numeros_fatores_risco (LISTA lista){
	char choose, vet[5][24] = {"vieram a óbito", "tiveram sintomas leves", "tiveram sintomas medios", "tiveram sintomas graves", "foram curados"};
	float media;
	int i, aux, num = 0, *pos;
	printf ("Você deseja saber os numeros de pacientes para cada fator de risco,\n"
			"Em geral (Aperte 0)\n"
			"Dentro de um grupo de situação (Aperte outro digito)\n");
	scanf ("%c", &choose);

	if (choose == '0'){
		for (i = 0; i < F; i++){
			for (aux = 0; aux < 5; aux++) num += lista->numeros[aux][16 + i];
			printf ("%s: %d pacientes\n", fatores_de_risco[i], num);
		}

		waitForInput();
		return;
	}

	else{
		choose = monitor (3);
		for (i = 0; i < F; i++){
			printf ("%s: %d pacientes\n", fatores_de_risco[i], lista->numeros[choose-'1'][16 + i]);
			media += lista->numeros[choose-'1'][16 + i];
			}
		media /= F;

		analise_numerica (lista->numeros[choose-'1'] + 16, F, media, vet[choose - '1']);

		waitForInput();
	}
}

void numeros_situation (LISTA lista){
	int i;
	printf ("Foram resgistrados %d óbitos até o presente\n", lista->numeros[0][16 + F]);
	printf ("Além disso, %d pacientes apresentaram sintomas leves\n", lista->numeros[1][16 + F]);
	printf ("Outros %d apresentaram sintomas médios\n", lista->numeros[2][16 + F]);
	printf ("E %d apresentaram sintomas graves\n", lista->numeros[3][16 + F]);
	printf ("Por fim, foram curados %d pacientes\n", lista->numeros[4][16 + F]);
	printf ("\nAo todo %d pacientes foram registrados\n\n", lista->tamanho);
}


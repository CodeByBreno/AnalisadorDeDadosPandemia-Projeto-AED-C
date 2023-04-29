#include <stdio.h>
#include <Stdlib.h>
#define F 5
#define NAME_SIZE 50

char fatores_de_risco[6][20] = {"Hipertensao",
							"Diabetes",
							"Doencas Cardiacas",
							"Doencas Pulmonares",
							"Fumante"};

char sickness[32];

typedef struct{
	char nome[NAME_SIZE + 1];
	int idade;
	char genero;
	int renda;
	char fatrisco[F + 1];
	int situation;
} FICHA;

typedef struct node{
	FICHA * dados;
	struct node * next;
	struct node * prev;
} NODO;

typedef struct NC{
	int tamanho;
    NODO * start;
	int numeros[5][17 + F];
} NC;

typedef NC * LISTA;

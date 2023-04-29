#include <stdlib.h>

/*funções de apoio -----------------------------------*/
int size (char * vet){
	int i;
	for (i = 0; vet[i] != '\0'; i++);
	return (i);
}

int alfabetico (char * vet1, char * vet2){
	int i, flag = 0, aux;
	for (i = 0; vet1[i] !='\0' && vet2[i] != '\0'; i++){
		if (vet1[i] < vet2[i]){
			flag = 1;
			return (1);
		}
		if (vet1[i] > vet2[i]){
			flag = 2;
			return (2);
		}
	}
	aux = size(vet1) - size(vet2);
	if (aux > 0) return (2);
	if (aux < 0) return (1);
	if (aux == 0) return (1);
}

int checkNome(char *nome){
    int i;
    char c;
    for(i = 0; nome[i] != '\0'; i++){
        if((nome[i] < 'A' || (nome[i] > 'Z' && nome[i] < 'a') || nome[i] > 'z') && nome[i] != ' ' && nome[i] != '\0')
			return 0;
    }
    return 1;
}

int checkIdade (int k){
	return (k <= 150 && k >= 0);
}

int checkFileName (char * vet){
	int i = 0, cont = 0;
	if (size(vet) < 5) return 0;
	while(++i && vet[i] != '\0')
		if (vet[i] == '.'){
			if (vet[i + 1] != 't') return 0;
			if (vet[i + 2] != 'x') return 0;
			if (vet[i + 3] != 't') return 0;
			if (vet[i + 4] != '\0') return 0;
			return 1;
		}
}

int * CombSort (int * vet, int tamanho){
	int i, j, gap, flag, aux;
	gap = tamanho;
	do {
				if (gap != 1) gap /= 1.3;
				for (i = 0, j = gap, flag = 0; j < tamanho; i++, j++)
					if (vet[i] > vet[j]){
						aux = vet[i];
						vet[i] = vet[j];
						vet[j] = aux;
						flag = 1;
					}
			} while (!(flag == 0 && gap == 1));
	return (vet);
}

float Mediana (int * vet, int tamanho){
	int vet2;
	float aux;
	CombSort (vet, tamanho);
	if (tamanho%2 == 0){
		aux = tamanho/2;
		return ((vet[(int)aux-1] + vet[(int)aux])/2);
	}
	else return ((float)vet[(tamanho-1)/2]);
}

float DesvioPadrao (int * vet, int tamanho, float media){
	int i;
	float var = 0;
	for (i = 0; i < tamanho; i++)
		var += pow (vet[i] - media, 2);
	var /= tamanho;
	return (sqrt(var));
}

void waitForInput(){
    printf("\nPressione uma tecla para continuar.\n");
    setbuf(stdin, NULL);
    char a = getchar();
    setbuf(stdin, NULL);
    system("cls");
}

#include <locale.h>
#include <windows.h>
#include <math.h>

#include "1 - TypesDefinition.c"
#include "2 - MainHeader.h"
#include "3 - SupportFunctions.c"
#include "4 - FundamentalFunctions.c"
#include "5 - SearchFunctions.c"
#include "6 - AnalysisFunctions.c"
#include "7 - FileFunctions.c"
#include "8 - SearchLibrary.c"

int main (){
	int i, aux = 0, ret = 1;
	char choose, *support, vet2[108];
	FILE * arq;
	FICHA * entradas;
	LISTA lista_de_fichas;
	setlocale(LC_ALL, "Portuguese");

	create_list(&lista_de_fichas);

	/*Menu inicial*/
	do {
		if (aux++ > 0){
            system("cls");
            printf ("Op��o Inv�lida, re-insira um valor adequado\n\n");
		}

		if(aux == 1)
            printf ("Ol�!\n");
        printf("Voc� deseja:\n"
				"1. Ler os dados de um arquivo j� existente\n"
				"2. Criar um novo arquivo\n"
				"3. Finalizar Aplica��o\n");
		scanf ("%c", &choose);
		if (choose == '3') exit (1);
		setbuf (stdin, NULL);

	} while (choose != '1' && choose != '2');


	/*Inserir o nome do arquivo*/
	aux = 0;
	do {
		if (aux++ > 0){
            system("cls");
            printf ("O nome inserido era inv�lido. \n");
		}
		printf ("\n(O nome deve ter a forma arquivo.txt)\n"
				"Insira o nome do arquivo: ");
		support = (char *) malloc (sizeof(char)*101);
		scanf ("%100[^\n]", support);
		setbuf (stdin, NULL);
	} while (!checkFileName(support));

	/* Inser��o do endere�o da pasta Lista no nome do arquivo*/
	sprintf (vet2, "Listas/%s", support);
	free(support);

	/* Abertura/Cria��o do arquivo */
	switch (choose){
		case '1':
			arq = fopen(vet2, "r");
			if (!arq){
				printf ("Arquivo Inv�lido\n");
				exit (51);
			}
			inserir_arquivo (arq, lista_de_fichas);
			printf("Leitura completa.\n");
			waitForInput();
			break;
		case '2':
			arq = fopen(vet2, "a+");
			if (!arq){
				printf ("Ocorreu um erro ao criar o arquivo\n");
				exit (52);
			}
			printf ("(M�XIMO 30 LETRAS)\n"
					"Esses dados ser�o referentes a qual doen�a?: ");
			scanf ("%30[^\n]", sickness);
			break;
		default:
			printf ("Entrada inv�lida\n");
			exit (53);
	}

	while(1){
        ret = 1;

		system("cls");
		setbuf (stdin, NULL);
		aux = 0;

		printf ("\nO que voc� deseja fazer?\n"
				"1. Inserir uma nova ficha de paciente\n"
				"2. Buscar por uma ficha de paciente\n"
				"3. Apresentar uma analise de dados baseado em algum campo\n"
				"Outro d�gito. Finalizar Aplica��o\n");
		scanf ("%c", &choose);
		setbuf(stdin, NULL);

		switch(choose){
			case '1':
				entradas = (FICHA *) malloc (sizeof(FICHA));
				/*inser��o do nome*/
				printf ("\nCerto! Vamos agora inserir uma nova ficha de dados\n"
						"Comecemos com o nome do paciente: ");
				scanf ("%50[^\n]", entradas->nome);
				setbuf (stdin, NULL);

				while (!checkNome(entradas->nome)){
					system("cls");
					setbuf (stdin, NULL);
					printf("O nome inserido � inv�lido\n"
							"Nomes devem possuir somente letras maiusculas, minusculas ou espa�os\n"
							"A primeira letra do nome deve ser maiuscula\n"
							"Insira o nome novamente: ");
					scanf ("%30[^\n]", entradas->nome);
				}
				setbuf (stdin, NULL);

				/*inser��o da idade*/
				printf ("\nAgora insira sua idade: ");
				scanf ("%d", &(entradas->idade));

				while (!checkIdade(entradas->idade)){
					system("cls");
					printf ("Por favor, informe uma idade entre 0 e 150 anos\n");
					scanf ("%d", &(entradas->idade));
				}
				setbuf (stdin, NULL);

				/*inser��o do genero*/
				printf ("\nInsira agora o genero do paciente\n"
						"(M) - Masculino  (F) - Feminino (O) - Outro. Insira: ");
				scanf ("%c", &(entradas->genero));

				while (entradas->genero != 'M' && entradas->genero != 'F' && entradas->genero != 'O'){
					system("cls");
					printf ("Entrada inv�lida, por favor, insira somente 'M', 'F' ou 'O'\n"
							"(M) - Masculino  (F) - Feminino (O) - Outro. Insira:");
					scanf ("%c", &(entradas->genero));
					setbuf (stdin, NULL);
				}
				setbuf (stdin, NULL);


				/*inser��o do grupo de renda*/
				aux = 0;
				while (!aux || entradas->renda > 4 || entradas->renda < 0){
					if (aux++ > 0){
						system("cls");
						printf ("Op��o inv�lida, por favor insira um n�mero entre 1 e 5\n");
					}
					printf ("\nEm qual dos seguintes grupos de renda familiar o paciente se enquadra?\n"
						"1. menos de 1 salario minimo per capita\n"
						"2. entre 1 e 3 salarios minimos per capita\n"
						"3. entre 3 e 5 salarios minimos per capita\n"
						"4. entre 5 e 10 salarios minimos per capita\n"
						"5. mais de 10 salarios minimos per capita\n");
					scanf ("%d", &(entradas->renda));

					entradas->renda--;
				}
				setbuf (stdin, NULL);

				/*inser��o de fatores de risco*/
				setbuf (stdin, NULL);
				printf ("\nA seguir ser�o apresentadas uma s�rie de fatores de risco para %s\n"
						"Aperte 1 para os que o paciente tiver e 0 para os que ele n�o tiver\n\n", sickness);
				for (i = 0; i < F; i++){
					printf ("O paciente possui %s ?  ", fatores_de_risco[i]);
					scanf ("%c", &(entradas->fatrisco[i]));
					setbuf (stdin, NULL);

					if (entradas->fatrisco[i] != '0' && entradas->fatrisco[i] != '1'){
						printf ("\nEntrada inv�lida, por favor insira o valor corretamente\n");
						i--;
					}
				}
				entradas->fatrisco[F] = '\0';
				setbuf(stdin, NULL);

				/*inser��o da situa��o*/
				aux = 0;
				while (!aux || entradas->situation > 4 || entradas->situation < 0){
					if (aux++ > 0){
						system("cls");
						printf ("Op��o inv�lida, por favor insira um n�mero entre 1 e 5\n");
					}
					printf ("\nEm qual das seguintes condi��es o paciente se encontra?\n"
						"1. �bito\n"
						"2. Sintomas Leves\n"
						"3. Sintomas M�dios\n"
						"4. Sintomas Graves\n"
						"5. Curado\n");
					scanf ("%d", &(entradas->situation));
					entradas->situation--;
					setbuf (stdin, NULL);
				}

				inserir (entradas, lista_de_fichas);
				break;

			case '2':
				ret = searchMenu (lista_de_fichas);
				break;

			case '3':
				system("cls");
				printf ("Voc� deseja ver a analise dos dados em rela��o a qual campo?\n"
						"1. Idade\n"
						"2. Genero\n"
						"3. Grupo de Renda\n"
						"4. Fatores de Risco\n"
						"5. Situa��o\n");
				scanf ("%d", &i);
				setbuf (stdin, NULL);
				system("cls");

				switch (i){
					case 1:
						numeros_idade (lista_de_fichas);
						break;
					case 2:
						numeros_genero (lista_de_fichas);
						break;
					case 3:
						numeros_renda (lista_de_fichas);
						break;
					case 4:
						numeros_fatores_risco (lista_de_fichas);
						break;
					case 5:
						numeros_situation (lista_de_fichas);
						break;
					default:
						printf ("Valor inv�lido\n");
						break;
				}
                break;
			default:
			    system("cls");
				printf ("Tem certeza?\n"
						"1. Sim\n"
						"Outro D�gito. N�o\n");
				scanf ("%c", &choose);
				setbuf (stdin, NULL);
				aux = 5;
				if (choose == '1') finalizar(lista_de_fichas, vet2);
		}

	}
}


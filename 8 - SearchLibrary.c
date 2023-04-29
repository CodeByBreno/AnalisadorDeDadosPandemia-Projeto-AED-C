/*biblioteca de busca*/

#define MAIN_MENU 1
#define SEARCH_MENU 2
#define SEARCH_SUBMENU 3
#define MANIPULATE_NODO_MENU 4

int searchMenu(LISTA l){
    int e = -1, ret = SEARCH_MENU;
    while(1){
        system("cls");
        printf("Escolha dado a pesquisar:\n");
        printf("1. Nome\n");
        printf("2. Idade\n");
        printf("3. Genero\n");
        printf("4. Renda\n");
        printf("5. Fatores de Risco\n");
        printf("6. Situacao\n");
        printf("7. Voltar para o menu principal\n");
        setbuf(stdin, NULL);
        scanf("%d", &e);

        switch(e){
	        case 1:
	            ret = searchByNomeMenu(l);
	            break;
	        case 2:
	            ret = searchByIdadeMenu(l);
	            break;
	        case 3:
	            ret = searchByGeneroMenu(l);
	            break;
	        case 4:
	            ret = searchByRendaMenu(l);
	            break;
	        case 5:
	            ret = searchByFatRiscoMenu(l);
	            break;
	        case 6:
	            ret = searchBySituationMenu(l);
	            break;
	        case 7:
	            return 0;
	        default:
	            printf("Opcao invalida. Tente novamente.\n");
	            break;
        }
        if(ret<SEARCH_MENU){
            return 0;
        }
    }
    return 0;
}

int searchByNomeMenu(LISTA l){
    char nome[NAME_SIZE + 1];
    int ret = 1;
    NODO **n;
    while(1){
        int a = 0;
        do{
            if(!a){
                system("cls");
            }
            printf("Digite o nome a consultar:\n");
            setbuf(stdin, NULL);
            scanf("%30[^\n]", nome);
            if(a = !checkNome(nome)){
                system("cls");
                printf("Nome invalido. Tente novamente\n");
            }
        } while(a);
        n = searchByName(l, nome);
        ret = manipulate(n, l);
        if(n){
            free(n);
            n = NULL;
        }
        if(ret<SEARCH_SUBMENU){
            return ret;
        }
    }
    return ret;
}

int searchByIdadeMenu(LISTA l){
    int idade = -1, ret;
    NODO **n;
    while(idade<0){
        if(idade == -1){
            system("cls");
        }
        printf("Digite uma opcao ou a idade alvo:\n");
        printf("-1. Voltar para o menu de busca\n");
        printf("-2. Voltar para o menu principal\n");
        scanf("%d", &idade);
        if(idade < 0){
			if(idade == -1){
	   			return SEARCH_MENU;
			} else if(idade == -2){
	  			return MAIN_MENU;
			} else{
			    system("cls");
	  		 	printf("Opcao invalida. Tente novamente.\n");
	  		 	idade = -2;
	  			continue;
			}
        }
        n = searchByIdade(l, idade);
        ret = manipulate(n ,l);
        if(n){
			free(n);
			n = NULL;
        }
        if(ret<SEARCH_SUBMENU)
			return ret;
        else
			idade = -1;
    }
}

int searchByGeneroMenu(LISTA l){
    int ret, e;
    char g = '0';
    NODO **n;
    while(1){
        if(g == '0'){
            system("cls");
        }
        printf("Digite uma opcao para pesquisa:\n");
        printf("1. Masculino\n");
        printf("2. Feminino\n");
        printf("3. Outro\n");
        printf("4. Voltar para o menu de busca\n");
        printf("5. Voltar para o menu principal\n");
        scanf("%d", &e);
        switch(e){
	        case 1:
				g = 'M';
				break;
	        case 2:
				g = 'F';
				break;
	        case 3:
				g = 'O';
				break;
	        case 4:
				return SEARCH_MENU;
	        case 5:
				return MAIN_MENU;
	        default:
	            system("cls");
				printf("Opcao invalida. Tente novamente.\n");
				g = '1';
				continue;
        }
        n = searchByGenero(l, g);
        ret = manipulate(n ,l);
        if(n){
			free(n);
			n = NULL;
        	}
        if(ret<SEARCH_SUBMENU)
			return ret;
    }
}

int searchByRendaMenu(LISTA l){
    int ret, e = 0, i;
    char *c;
    NODO **n;
    while(1){
        if(!e){
            system("cls");
        }
        printf("Digite uma opcao para pesquisa:\n");
        printf("1. %s\n", c = getRenda(0));
        free(c);
        printf("2. %s\n", c = getRenda(1));
        free(c);
        printf("3. %s\n", c = getRenda(2));
        free(c);
        printf("4. %s\n", c = getRenda(3));
        free(c);
        printf("5. %s\n", c = getRenda(4));
        free(c);
        printf("6. Voltar para o menu de busca\n");
        printf("7. Voltar para o menu principal\n");
        scanf("%d", &e);
        switch(e){
	        case 1:
				i = 0;
				break;
	        case 2:
				i = 1;
				break;
	        case 3:
				i = 2;
				break;
	        case 4:
				i = 3;
				break;
	        case 5:
				i = 4;
				break;
	        case 6:
				return SEARCH_MENU;
	      	case 7:
				return MAIN_MENU;
	        default:
	            system("cls");
				printf("Opcao invalida. Tente novamente.\n");
				e = -1;
				continue;
        }
        n = searchByRenda(l, i);
        ret = manipulate(n ,l);
        if(n){
			free(n);
			n = NULL;
        }
        if(ret<SEARCH_SUBMENU)
			return ret;
    }
}

int searchByFatRiscoMenu(LISTA l){
    int ret, e = 0, i, j;
    char *c;
    NODO **n;
    while(1){
        if(!e){
            system("cls");
        }
        printf("Digite uma opcao para pesquisa:\n");
        printf("1. %s\n", fatores_de_risco[0]);
        printf("2. %s\n", fatores_de_risco[1]);
        printf("3. %s\n", fatores_de_risco[2]);
        printf("4. %s\n", fatores_de_risco[3]);
        printf("5. %s\n", fatores_de_risco[4]);
        printf("6. Voltar para o menu de busca\n");
        printf("7. Voltar para o menu principal\n");
        scanf("%d", &e);
        switch(e){
	        case 1:
				i = 0;
				break;
	        case 2:
				i = 1;
				break;
	        case 3:
				i = 2;
				break;
	        case 4:
				i = 3;
				break;
	        case 5:
				i = 4;
				break;
	        case 6:
				return SEARCH_MENU;
	      	case 7:
				return MAIN_MENU;
	        default:
	            system("cls");
				printf("Opcao invalida. Tente novamente.\n");
				e = -1;
				continue;
        }
        c = (char *)malloc(5*sizeof(char));
        for(j = 0; j<5; j++)
	c[j] = '0';
        c[j] = 0;
        c[i] = '1';
        n = searchByFatRisco(l, c);
        free(c);
        ret = manipulate(n ,l);
        if(n){
			free(n);
			n = NULL;
        }
        if(ret<SEARCH_SUBMENU)
			return ret;
    }
}

int searchBySituationMenu(LISTA l){
    int ret, e = 0, i;
    char *c;
    NODO **n;
    while(1){
        if(!e){
            system("cls");
        }
        printf("Digite uma opcao para pesquisa:\n");
        printf("1. %s\n", c = getSituation(0));
        free(c);
        printf("2. %s\n", c = getSituation(1));
        free(c);
        printf("3. %s\n", c = getSituation(2));
        free(c);
        printf("4. %s\n", c = getSituation(3));
        free(c);
        printf("5. %s\n", c = getSituation(4));
        free(c);
        printf("6. Voltar para o menu de busca\n");
        printf("7. Voltar para o menu principal\n");
        scanf("%d", &e);
        switch(e){
	        case 1:
				i = 0;
				break;
	        case 2:
				i = 1;
				break;
	        case 3:
				i = 2;
				break;
	        case 4:
				i = 3;
				break;
	        case 5:
				i = 4;
				break;
	        case 6:
				return SEARCH_MENU;
	      	case 7:
				return MAIN_MENU;
	        default:
	            system("cls");
				printf("Opcao invalida. Tente novamente.\n");
				e = -1;
				continue;
        }
        n = searchBySituation(l, i);
        ret = manipulate(n ,l);
        if(n){
			free(n);
			n = NULL;
        }
        if(ret<SEARCH_SUBMENU)
			return ret;
    }
}


int manipulate(NODO **n, LISTA l){
    int j = 0, e = -1, i = getSearchSize(n);
    system("cls");
    if(!n){
        printf("Nao foi possivel alocar memoria para realizar a busca.\n");
    }
    else{
        if(!i){
			printf("Nao foram encontrados registros com as caracteristicas especificadas.\n");
			waitForInput();
        }
        else{
			if(i == 1){
	    		printf("Foi encontrado um resultado correspondente.\n");
                waitForInput();
	   	 		return manipulateNode(n[0], l);
			} else
	   			printf("Foram encontrados %d resultados correspondentes.\n", i);
	   			waitForInput();
      	}
    }

    while(e<1 || e>i+3){
        if(e == -1){
            system("cls");
        }
        if(i>1){
            printf("Selecione o registro ou opcao desejada:\n");
            for(j = 0; j < i; j++)
                printf("%d. %s\n", j+1, n[j]->dados->nome);
        } else{
            printf("Selecione a opcao desejada:\n");
        }
        j++;
        printf("%d. Voltar para o submenu de busca\n", j++);
        printf("%d. Voltar para o menu de busca\n", j++);
        printf("%d. Voltar para o menu principal\n", j);
        scanf("%d", &e);
        if(e<1 || e>i+3){
            system("cls");
			printf("Opcao invalida. Tente novamente.\n");
			e = -2;
        }
    }

    for(j = 0; j<i; j++)
        if(e == j+1)
			return manipulateNode(n[j], l);

    j++;
    if(e == j++){
        return SEARCH_SUBMENU;
    }
    if(e == j++){
        return SEARCH_MENU;
    }
    return MAIN_MENU;
}


int manipulateNode(NODO *n, LISTA l){
    int e = -1, j, k = 1, ret;
    while(1){
        j = 1;
        while(e<1 || e>j){
            if(e == -1){
                system("cls");
            }
            if(n){
                printf("Registro selecionado: %s\n", n->dados->nome);
                printf("O que deseja fazer?\n");
                printf("%d. Exibir dados\n", j++);
                printf("%d. Editar registro\n", j++);
                printf("%d. Remover registro\n", j++);
            } else{
                printf("Nenhum registro selecionado.\n");
                printf("O que deseja fazer?\n");
            }
			printf("%d. Voltar para o submenu de busca\n", j++);
            printf("%d. Voltar para o menu de busca\n", j++);
            printf("%d. Voltar para o menu principal\n", j);
            setbuf(stdin, NULL);
            scanf("%d", &e);
            if(e<1 || e>j){
                system("cls");
    	    	printf("Opcao invalida. Tente novamente.\n");
                e = -2;
            }
        }
        j = 1;
        if(n){
            if(e == j++){
                mostrarDados(n);
                ret = MANIPULATE_NODO_MENU;
            } else if(e == j++){
	    		ret = editarDados(n, l);
            } else if(e == j++){
	    		removeNode(n, l);
	    		printf("Removido com sucesso.\n");
	    		n = NULL;
	    		waitForInput();
	   			return manipulateNode(n, l);
            }
        }
        if(e == j++){
			return SEARCH_SUBMENU;
        } else if(e == j++){
			return SEARCH_MENU;
        } else if(e == j++){
			return MAIN_MENU;
        }
        if(ret<MANIPULATE_NODO_MENU)
			return ret;
        e = -1;
    }
}

void mostrarDados(NODO *n){
    char *c;
    system("cls");
    printf("Informações do registro:\n");
    printf("Nome: %s\n", n->dados->nome);
    printf("Idade: %d\n", n->dados->idade);
    printf("Genero: %s\n", c = getGenero(n->dados->genero));
    free(c);
    printf("Renda: %s\n", c = getRenda(n->dados->renda));
    free(c);
    printf("Fatores de risco: %s", c = getFatRisco(n->dados->fatrisco));
    free(c);
    printf("Situacao: %s\n", c = getSituation(n->dados->situation));
    free(c);
    waitForInput();
}

char *getGenero(char g){
    char *ret;
    ret = (char *)malloc(11*sizeof(char));
    switch(g){
    case 'M':
        sprintf(ret, "%s", "masculino");
        break;
    case 'F':
        sprintf(ret, "%s", "feminino");
        break;
    case 'O':
        sprintf(ret, "%s", "outro");
        break;
    default:
        sprintf(ret, "%s", "indefinido");
    }
    return ret;
}



char *getRenda(int r){
    char *ret;
    ret = (char *) malloc(41*sizeof(char));
    switch(r){
    case 0:
        sprintf(ret, "%s", "ate 1 salario minimo per capita");
        break;
    case 1:
        sprintf(ret, "%s", "entre 1 e 3 salarios minimos per capita");
        break;
    case 2:
        sprintf(ret, "%s", "entre 3 e 5 salarios minimos per capita");
        break;
    case 3:
        sprintf(ret, "%s", "entre 5 e 10 salarios minimos per capita");
        break;
    case 4:
        sprintf(ret, "%s", "mais de 10 salarios minimos per capita");
        break;
    default:
        ret = "indefinido";
    }
    return ret;
}

char *getFatRisco(char *fat){
    char *ret;
    int i;
    ret = (char *)malloc(99*sizeof(char));
    sprintf(ret, "%s", "\n{\n");
    for(i = 0; i<5; i++){
        sprintf(ret, "%s%s: %s\n", ret, fatores_de_risco[i], (fat[i]=='1')?"sim":"nao");
    }
    sprintf(ret, "%s}\n\0", ret);
    return ret;
}


char *getSituation(int s){
    char *ret;
    ret = (char *) malloc(16*sizeof(char));
    switch(s){
    case 0:
        sprintf(ret, "%s", "Obito");
        break;
    case 1:
        sprintf(ret, "%s", "sintomas leves");
        break;
    case 2:
        sprintf(ret, "%s", "sintomas medios");
        break;
    case 3:
        sprintf(ret, "%s", "sintomas graves");
        break;
    case 4:
        sprintf(ret, "%s", "curado");
        break;
    default:
        sprintf(ret, "%s", "indefinido");
    }
    return ret;
}

int editarDados(NODO *n, LISTA l){
    int j, e = -1;
    while(1){
        if(e == -1){
            system("cls");
        }
        j = 1;
        printf("Selecione o dado a editar:\n");
        printf("%d. Nome\n", j++);
        printf("%d. Idade\n", j++);
        printf("%d. Genero\n", j++);
        printf("%d. Renda\n", j++);
        printf("%d. Fatores de Risco\n", j++);
        printf("%d. Situacao\n", j++);
        printf("%d. Voltar para o submenu de busca\n", j++);
        printf("%d. Voltar para o menu de busca\n", j++);
        printf("%d. Voltar para o menu principal\n", j);
        scanf("%d", &e);
        j = 1;
        if(e == j++){
            setNome(n);
        } else if(e == j++){
            setIdade(n, l);
        } else if(e == j++){
            setGenero(n, l);
        } else if(e == j++){
            setRenda(n, l);
        } else if(e == j++){
            setFatRisco(n, l);
        } else if(e == j++){
            setSituation(n, l);
        } else if(e == j++){
            return SEARCH_SUBMENU;
        } else if(e == j++){
            return SEARCH_MENU;
        } else if(e == j){
            return MAIN_MENU;
        } else{
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            e = -2;
        }
    }
}

void setNome(NODO *n){
    int e = -1;
    while(1){
        if(e == -1){
            system("cls");
        }
        printf("Nome atual: %s\n", n->dados->nome);
        printf("Alterar?\n");
        printf("1. Sim\n");
        printf("2. Nao\n");
        scanf("%d", &e);
        if(e == 1){
            char c[NAME_SIZE + 1];
            printf("Digite o novo nome:\n");
            setbuf(stdin, NULL);
            scanf("%30[^\n]", c);
            setbuf(stdin, NULL);
            if(checkNome(c)){
                sprintf(n->dados->nome, "%s", c);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else {
                system("cls");
                printf("Nome invalido. Tente novamente.\n");
                e = -2;
            }
        } else if(e == 2){
            return;
        } else{
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            e = -2;
        }
    }
}

void setIdade(NODO *n, LISTA l){
    int e = -1;
    while(1){
        if(e == -1){
            system("cls");
        }
        printf("Idade atual: %d\n", n->dados->idade);
        printf("Alterar?\n");
        printf("1. Sim\n");
        printf("2. Nao\n");
        scanf("%d", &e);
        if(e == 1){
            int id;
            printf("Digite a nova idade:\n");
            scanf("%d", &id);
            if(id>=0 && id<=150){
                update(-1, l, n->dados);
                n->dados->idade = id;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else {
                system("cls");
                printf("Idade invalida. Tente novamente.\n");
                e = -2;
            }
        } else if(e == 2){
            return;
        } else{
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            e = -2;
        }
    }
}

void setGenero(NODO *n, LISTA l){
    int e = -1;
    while(1){
        char *c;
        if(e == -1){
            system("cls");
        }
        printf("Genero atual: %s\n", c = getGenero(n->dados->genero));
        free(c);
        c = NULL;
        printf("Alterar?\n");
        printf("1. Sim\n");
        printf("2. Nao\n");
        scanf("%d", &e);
        if(e == 1){
            int e1;
            printf("Qual o genero a ser atribuido?\n");
            printf("1. Masculino\n");
            printf("2. Feminino\n");
            printf("3. Outro\n");
            printf("4. Cancelar\n");
            scanf("%d", &e1);
            if(e1 == 1){
                update(-1, l, n->dados);
                n->dados->genero = 'M';
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 2){
                update(-1, l, n->dados);
                n->dados->genero = 'F';
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 3){
                update(-1, l, n->dados);
                n->dados->genero = 'O';
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 4){
                return;
            } else{
                system("cls");
                printf("Opcao invalida.\n");
                e = -2;
            }
        } else if(e == 2){
            return;
        } else{
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            e = -2;
        }
    }
}

void setRenda(NODO *n, LISTA l){
    int e = -1;
    while(1){
        char *c;
        if(e == -1){
            system("cls");
        }
        printf("Renda atual: %s\n", c = getRenda(n->dados->renda));
        free(c);
        c = NULL;
        printf("Alterar?\n");
        printf("1. Sim\n");
        printf("2. Nao\n");
        scanf("%d", &e);
        if(e == 1){
            int e1;
            printf("Qual a faixa a ser atribuida?\n");
            printf("1. %s\n", c = getRenda(0));
            free(c);
            printf("2. %s\n", c = getRenda(1));
            free(c);
            printf("3. %s\n", c = getRenda(2));
            free(c);
            printf("4. %s\n", c = getRenda(3));
            free(c);
            printf("5. %s\n", c = getRenda(4));
            free(c);
            printf("6. Cancelar\n");
            scanf("%d", &e1);
            if(e1 == 1){
                update(-1, l, n->dados);
                n->dados->renda = 0;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 2){
                update(-1, l, n->dados);
                n->dados->renda = 1;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 3){
                update(-1, l, n->dados);
                n->dados->renda = 2;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 4){
                update(-1, l, n->dados);
                n->dados->renda = 3;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 5){
                update(-1, l, n->dados);
                n->dados->renda = 4;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 6){
                return;
            } else{
                system("cls");
                printf("Opcao invalida.\n");
                e = -2;
            }
        } else if(e == 2){
            return;
        } else{
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            e = -2;
        }
    }
}



void setSituation(NODO *n, LISTA l){
    int e = -1;
    while(1){
        char *c;
        if(e == -1){
            system("cls");
        }
        printf("Situacao atual: %s\n", c = getSituation(n->dados->situation));
        free(c);
        c = NULL;
        printf("Alterar?\n");
        printf("1. Sim\n");
        printf("2. Nao\n");
        scanf("%d", &e);
        if(e == 1){
            int e1;
            printf("Qual a situacao a ser atribuida?\n");
            printf("1. %s\n", c = getSituation(0));
            free(c);
            printf("2. %s\n", c = getSituation(1));
            free(c);
            printf("3. %s\n", c = getSituation(2));
            free(c);
            printf("4. %s\n", c = getSituation(3));
            free(c);
            printf("5. %s\n", c = getSituation(4));
            free(c);
            printf("6. Cancelar\n");
            scanf("%d", &e1);
            if(e1 == 1){
                update(-1, l, n->dados);
                n->dados->situation = 0;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 2){
                update(-1, l, n->dados);
                n->dados->situation = 1;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 3){
                update(-1, l, n->dados);
                n->dados->situation = 2;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 4){
                update(-1, l, n->dados);
                n->dados->situation = 3;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 5){
                update(-1, l, n->dados);
                n->dados->situation = 4;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
                break;
            } else if(e1 == 6){
                return;
            } else{
                system("cls");
                printf("Opcao invalida.\n");
                e = -2;
            }
        } else if(e == 2){
            return;
        } else{
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            e = -2;
        }
    }
}

void setFatRisco(NODO* n, LISTA l){
    int e = -1, j = 1;
    char *c;
    while(1){
        if(e == -1){
            system("cls");
        }
        printf("Situacao atual: %s", c = getFatRisco(n->dados->fatrisco));
        free(c);
        printf("Qual dos fatores de risco deve ser alterado?\n");
        printf("%d. %s\n", j++, fatores_de_risco[0]);
        printf("%d. %s\n", j++, fatores_de_risco[1]);
        printf("%d. %s\n", j++, fatores_de_risco[2]);
        printf("%d. %s\n", j++, fatores_de_risco[3]);
        printf("%d. %s\n", j++, fatores_de_risco[4]);
        printf("%d. Voltar\n", j);
        scanf("%d", &e);
        if(e>0 && e<j){
            int e2;
            printf("Qual e o valor a ser inserido?\n");
            printf("1. Sim\n");
            printf("2. Nao\n");
            scanf("%d", &e2);
            if(e==1 || e ==2){
                update(-1, l, n->dados);
                n->dados->fatrisco[e-1] = e2-1;
                update(1, l, n->dados);
                printf("Alterado com sucesso.\n");
                waitForInput();
            } else{
                system("cls");
                printf("Opcao invalida. Tente novamente.\n");
                e = -2;
            }
        } else if(e == j){
            return;
        } else{
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            e = -2;
        }
    }
}

int getSearchSize(NODO **n){
    if(!n)
        return 0;
    else{
        int i;
        for(i = 0; n[i]!=NULL; i++);
        return i;
    }
}

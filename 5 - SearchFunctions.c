/*funções de busca*/

NODO **searchByName(LISTA l, char *nome){
    NODO **n, *p;
    int i, j, k = 0;
    p = l->start;
    i = getMatchingNumbersByName(l, nome);
    n = (NODO **) malloc((i+1)*sizeof(NODO *));
    if(!n)
        return NULL;
    while(k<i){
        int t1, t2, j, z, x = 1;
        t1 = size(nome);
        t2 = size(p->dados->nome);
        for(j = 0; j<t2-t1; j++, x = 1){
            if(nome[0] == p->dados->nome[j]){
                for(z = 1; z<t1; z++){
                    if(nome[z] == p->dados->nome[j+z]){
                        x++;
                    }
                }
                if(x == t1){
                    n[k++] = p;
                    break;
                }
            }
        }
        p = p->next;
    }
    n[k] = NULL;
    return n;
}

int getMatchingNumbersByName(LISTA l, char *nome){
    NODO *n;
    int t = l->tamanho, a = 0;
    n = l->start;
    while(t--){
        int t1, t2, i, j, k = 1;
        t1 = size(nome);
        t2 = size(n->dados->nome);
        for(i = 0; i<t2-t1+1; i++, k = 1){
	if(nome[i] == n->dados->nome[i]){
	    for(j = 1; j<t1; j++)
	        if(nome[j+i] == n->dados->nome[j+i])
		k++;
	    if(k == t1){
	        a++;
	        break;
	    }
	}
        }
        n = n->next;
    }
    return a;
}


NODO **searchByIdade(LISTA l, int idade){
    NODO **n, *p;
    int i, j=0;
    p = l->start;
    i = getMatchingNumbersByIdade(l, idade);
    n = (NODO **) malloc((i+1)*sizeof(NODO *));
    if(!n)
        return NULL;
    while(j<i){
        if(p->dados->idade == idade)
	n[j++] = p;
        p=p->next;
    }
    n[j] = NULL;
    return n;
}

int getMatchingNumbersByIdade(LISTA l, int idade){
    NODO *n;
    int t = l->tamanho, j = 0;
    n = l->start;
    while(t--){
        if(n->dados->idade == idade)
            j++;
        n = n->next;
    }
    return j;
}


NODO **searchByGenero(LISTA l, char genero){
    NODO **n, *p;
    int i, j=0;
    p = l->start;
    i = getMatchingNumbersByGenero(l, genero);
    n = (NODO **) malloc((i+1)*sizeof(NODO *));
    if(!n)
        return NULL;
    while(j<i){
        if(p->dados->genero == genero)
	n[j++] = p;
        p=p->next;
    }
    n[j] = NULL;
    return n;
}

int getMatchingNumbersByGenero(LISTA l, char genero){
    NODO *n;
    int t = l->tamanho, j = 0;
    n = l->start;
    while(t--){
        if(n->dados->genero == genero)
            j++;
        n = n->next;
    }
    return j;
}

NODO **searchByRenda(LISTA l, int renda){
    NODO **n, *p;
    int i, j=0;
    p = l->start;
    i = getMatchingNumbersByRenda(l, renda);
    n = (NODO **) malloc((i+1)*sizeof(NODO *));
    if(!n)
        return NULL;
    while(j<i){
        if(p->dados->renda == renda)
	n[j++] = p;
        p=p->next;
    }
    n[j] = NULL;
    return n;
}

int getMatchingNumbersByRenda(LISTA l, int renda){
    NODO *n;
    int t = l->tamanho, j = 0;
    n = l->start;
    while(t--){
        if(n->dados->renda == renda)
            j++;
        n = n->next;
    }
    return j;
}

NODO **searchByFatRisco(LISTA l, char* fat){
    NODO **n, *p;
    int j = 0, i, k, pos = 0;
    p = l->start;
    i = getMatchingNumbersByFatRisco(l, fat);
    n = (NODO **) malloc((i+1)*sizeof(NODO *));
    if(!n)
        return NULL;
    for(k = 0; k < size(fat); k++){
        if(fat[k]=='1'){
            break;
        }
    }
    while(j<i){
        if(p->dados->fatrisco[k] == '1')
            n[j++] = p;
        p = p->next;
    }
    n[j] = NULL;
    return n;
}

/*NODO **searchByFatRisco(LISTA l, char *fat){
    NODO **n, *p;
    int j = 0, s = size(fat), i, k;
    p = l->start;
    i = getMatchingNumbersByFatRisco(l, fat);
    n = (NODO **) malloc((i+1)*sizeof(NODO *));
    if(!n)
        return NULL;
    while(j<i){
        for(k = 0; k<s; k++)
            if(p->dados->fatrisco[k] != fat[k])
                break;
        if(k == s-1)
            n[j++] = p;
        p = p->next;
    }
    n[j] == NULL;
    return n;
}*/

int getMatchingNumbersByFatRisco(LISTA l, char* fat){
    NODO *n;
    int i, j, k = 0;
    n = l->start;
    for(i = 0; i < size(fat); i++){
        if(fat[i]=='1'){
            break;
        }
    }

    for(j = 0; j < l->tamanho; j++){
        if(n->dados->fatrisco[i] == '1'){
            k++;
        }
        n = n->next;
    }
    return k;
}

/*int getMatchingNumbersByFatRisco(LISTA l, char *fat){
    NODO *n;
    int t = l->tamanho, j = 0, s = size(fat), i;
    n = l->start;
    while(t--){
        for(i = 0; i<s; i++)
	if(n->dados->fatrisco[i] != fat[i])
	    break;
        if(i == s-1)
	j++;
        n = n->next;
    }
    return j;
}*/

NODO **searchBySituation(LISTA l, int situation){
    NODO **n, *p;
    int i, j=0;
    p = l->start;
    i = getMatchingNumbersBySituation(l, situation);
    n = (NODO **) malloc((i+1)*sizeof(NODO *));
    if(!n)
        return NULL;
    while(j<i){
        if(p->dados->situation == situation)
	n[j++] = p;
        p=p->next;
    }
    n[j] = NULL;
    return n;
}

int getMatchingNumbersBySituation(LISTA l, int situation){
    NODO *n;
    int t = l->tamanho, j = 0;
    n = l->start;
    while(t--){
        if(n->dados->situation == situation)
            j++;
        n = n->next;
    }
    return j;
}

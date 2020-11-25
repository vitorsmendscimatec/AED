typedef struct no{ //Struct da pilha(deck)
    POKEMON *pokemon;    
	struct no *prox;
} NO;

typedef NO* PILHA;

PILHA* cria_pilha(){  
    PILHA *pi = (PILHA*) malloc(sizeof(PILHA));
    if(pi != NULL)
        *pi = NULL;
    return pi; 
}

int pilha_vazia(PILHA *p){ 
    if(p==NULL) return 1; 
	return 0; 
}

int empilha(PILHA *p, POKEMON *c){
    if(p==NULL) return 0;
    NO *novo_no = (NO*)malloc(sizeof(NO));
    if(novo_no==NULL) return 0;

    novo_no->pokemon = c;
    novo_no->prox=NULL;
    if((*p)==NULL)
        *p = novo_no;
    else{
        novo_no->prox = *p;
        *p = novo_no;
    }
    return 1;
}

void imprime_pilha(PILHA *p){ //Imprime deck
    NO *aux = *p;

    while(aux!=NULL){
        imprimirPokemon(aux->pokemon);
        aux=aux->prox;
    }
}

POKEMON *desempilha(PILHA *p){// cava o deck
    NO *topo = *p;
    int i;
    POKEMON *c = (POKEMON*) malloc(sizeof(POKEMON));

    if(topo != NULL){
        printf("======================\n");
        printf("Cavando: %s\n", topo->pokemon->nome);
		printf("======================\n\n");


        strcpy(c->nome, topo->pokemon->nome);
        strcpy(c->tipo, topo->pokemon->tipo);
        c->hp = topo->pokemon->hp;
        for(i=0;i<2;i++){
            c->atk[i] = topo->pokemon->atk[i];
        }
        
        printf("GO %s!\n", c->nome);

        *p = topo->prox;

        free(topo);

        return c;
    }else{
        printf("PILHA VAZIA!");
        return 0;
    }
}

//ESTA COM ALGUM ERRO
//Enche o deck com os pokemon da pokedex
/*PILHA* enche_deck(){
	PILHA* p = cria_pilha();
	LISTAE* l = cria_lista();
	FILE *pArq;
	pArq = fopen("pokedex.bin", "rb");
	if(pArq == NULL){
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}
	
	int cont = 0;
	while(getc(pArq) != EOF){				//Loop enquanto não chegar ao fim do arquivo
		POKEMON temp;
		fseek(pArq, cont*sizeof(POKEMON), SEEK_SET);
		fread(&temp, sizeof(POKEMON), 1, pArq);
		insere_fim(l, temp);
		cont++;
	}
	fclose(pArq);
	
	retira_random(l);
	while(!listase_vazia(l)){
		POKEMON *temp = retira_random(l);
		empilha(p, temp);
	}
	destroi_listase(l);
	return p;
}*/




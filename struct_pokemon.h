typedef struct pokemon{ //Struct do pokemongo
	char nome[30];
	char tipo[20];
	int hp;
	int atk;
} POKEMON;

POKEMON* cria_pokemon(char *nome, char *tipo, int hp, int atk){ 
	//cria o pokemongo, foi complicado por conta desse malloc ai, tinha esquecido dele. Retorna o ponteiro pokemongo para ser usado na pilha(deck).
    POKEMON *p = (POKEMON*) malloc(sizeof(POKEMON));
    strcpy(p->nome, nome);
    strcpy(p->tipo, tipo);
    p->hp = hp;
 	p->atk = atk;

    return p;
}

int compara_vantagens(char *tipopk1, char *tipopk2){ // compara atks, retorna 0 se � igual ou normal, retorna 1 se tem desvantagem, retorna 2 se tem vantagem
	if(strcmp(tipopk1, "Normal") == 0){
		return 0;
	}
	else if(strcmp(tipopk1, "Water") == 0){
		if(strcmp(tipopk2, "Grass") == 0) return 1;
		else if(strcmp(tipopk2, "Fire") == 0) return 2;
	}
	else if(strcmp(tipopk1, "Fire") == 0){
		if(strcmp(tipopk2, "Water") == 0) return 1;
		else if(strcmp(tipopk2, "Grass") == 0) return 2;
	}
	else if(strcmp(tipopk1, "Grass") == 0){
		if(strcmp(tipopk2, "Fire") == 0) return 1;
		else if(strcmp(tipopk2, "Water") == 0) return 2;
	}
	return 0;
}

void imprimirPokemon(POKEMON *v){
	printf("======================\n");
	printf("Pokemon: \n");     
    printf("Nome: %s\n", v->nome);
    printf("Tipo: %s\n", v->tipo);
    printf("HP: %d\n", v->hp);
    printf("Ataque: %d\n", v->atk);
	printf("======================\n");
}

//num representa o numero que sera exibido na frente do pokemon
void imprimirPokemonResumo(POKEMON *v, int num){
	printf("%d -> ", num);
    printf("Nome: %s    ", v->nome);
    printf("Tipo: %s    ", v->tipo);
    printf("HP: %d    ", v->hp);
    printf("Ataque: %d", v->atk);
    printf("\n");
}

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
        c->atk = topo->pokemon->atk;
        
        printf("GO %s!\n", c->nome);

        *p = topo->prox;

        free(topo);

        return c;
    }else{
        printf("PILHA VAZIA!");
        return 0;
    }
}

void atacar(POKEMON *atacante, POKEMON *atacado){
    int multiplicador;
    float efeito;

    multiplicador = compara_vantagens(atacante->tipo, atacado->tipo);   
    if(multiplicador == 0){
        efeito = 1.0;
        printf("%s atacou %s!\n", atacante->nome, atacado->nome);
    }else if(multiplicador == 1){
        efeito = 0.5;
        printf("%s atacou %s!\n Nao parece ter sido efetivo...\n", atacante->nome, atacado->nome);
    }else if(multiplicador == 2){
		efeito = 2.0;
		printf("%s atacou %s!\n O ataque foi superefetivo!!!\n", atacante->nome, atacado->nome);
    }
    sleep(2);
    atacado->hp = int(atacado->hp - (atacante->atk)*efeito);
    
}

int sem_vida(POKEMON* p){
	if(p->hp <= 0){
		return 1;
	} else {
		return 0;
	}
}

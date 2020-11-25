#define TAM 6

typedef struct{ // struct do cemiterio e suas funcoes
	int cont;
	POKEMON *pokemon[TAM];
} CEMITERIO;

CEMITERIO* criarCemiterio(){
	CEMITERIO *l;
	l = (CEMITERIO*)malloc(sizeof(CEMITERIO));
	if(l != NULL){
		l->cont = 0;
	}
	return l;
}

void destruirCemiterio(CEMITERIO* l){
	free(l);
}

int tamanhoCemiterio(CEMITERIO* l){
	if(l == NULL) return -1;
	else return l->cont;		
}

int estahVaziaCemiterio(CEMITERIO* l){
	if(l == NULL) return -1;
	else return l->cont == 0;
}

int estaCheiaCemiterio(CEMITERIO* l){
	if(l == NULL) return -1;
	else return l->cont == TAM;
}

void imprime_cemiterio(CEMITERIO* l){
	int i;
	if(l != NULL){
		if(!estahVaziaCemiterio(l)){
			for(i=0; i<l->cont; i++){
				imprimirPokemon(l->pokemon[i]);
			}
		}else{
			printf("Lista esta vazia!\n");
		}
	}else{
		printf("Lista nao foi criada!\n");
	}
}

int insere_cemiterio(CEMITERIO* l, POKEMON *v){
	int i, posicao;
	if(l==NULL) return 0;
	if(estaCheiaCemiterio(l)) return 0;
	if(estahVaziaCemiterio(l)) 
		posicao = 0;
	else{
		for(i=l->cont-1; i>=0 && (strcmp(l->pokemon[i]->nome, v->nome) > 0); i--){
			l->pokemon[i+1] = l->pokemon[i];
		}
		posicao = i+1;
	}
	l->pokemon[posicao] = v;
	l->cont++;
	return 1;
}

int buscaBinariaC(CEMITERIO *l, char *nome){ 
	int inf, sup, meio;
	inf=0;
	sup=(l->cont - 1);
	while (inf<=sup)
	{
		meio=(inf+sup)/2;
		if (strcmp(l->pokemon[meio]->nome, nome) == 0)
			return meio;
		else if (strcmp(l->pokemon[meio]->nome, nome) > 0)
			sup = meio-1;
		else
			inf=meio+1;
	}
    return -1; 
}

POKEMON* reviver_pokemon(CEMITERIO *l, char *nome){
	int i;
	int posRem;
	POKEMON *p;
	
	if(l == NULL) return 0;
	if(estahVaziaCemiterio(l)) return 0;
	
	posRem = buscaBinariaC(l, nome);
	p = l->pokemon[posRem];

	if(posRem >= 0){
		for(i=posRem; i<l->cont; i++){
			l->pokemon[i] = l->pokemon[i+1];
		}
		l->cont--;	
	}
    return p;
}
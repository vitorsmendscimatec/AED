
typedef struct{ //Mão, coloquei 5 pokemons mas foi só pra teste
	int cont;
	POKEMON *pokemon[5];   
} Mao;

Mao* criarMao(){
	Mao *l;
	l = (Mao*)malloc(sizeof(Mao));
	if(l != NULL){
		l->cont = 0;
	}
	return l;
}

void destruirMao(Mao* l){
	free(l);
}

int tamanhoMao(Mao* l){
	if(l == NULL) return -1;
	else return l->cont;		
}

int estahVaziaMao(Mao* l){
	if(l == NULL) return -1;
	else return l->cont == 0;
}

int estaCheiaMao(Mao* l){
	if(l == NULL) return -1;
	else return l->cont == 5;
}

int inserirOrdenadoMao(Mao* l, POKEMON *v){
	int i, posicao;
	if(l==NULL) return 0;
	if(estaCheiaMao(l)) return 0;
	if(estahVaziaMao(l)) 
		posicao = 0;
	else{ // Acha a posicao para inserir
		for(i=l->cont-1; i>=0 && (strcmp(l->pokemon[i]->nome, v->nome) > 0); i--){
			l->pokemon[i+1] = l->pokemon[i];
		}
		posicao = i+1;
	}
	l->pokemon[posicao] = v;
	l->cont++;
	return 1;
}



void imprimirMao(Mao* l){
	int i;
	if(l != NULL){
		if(!estahVaziaMao(l)){
			for(i=0; i<l->cont; i++){
				imprimirPokemon(l->pokemon[i]);
			}
		}else{
			printf("Mao esta vazia!\n");
		}
	}else{
		printf("Mao nao foi criada!\n");
	}
}

int buscaBinaria(Mao *l, char *nome){ 
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

int remover(Mao *l, char *nome){
	int i;
	int posRem; 
	
	if(l == NULL) return -1;
	if(estahVaziaMao(l)) return -1;
	
	posRem = buscaBinaria(l, nome);
	
	// Se encontrou o nome para remover
	if(posRem >= 0){
		// Desloca os pokemons que estiverem � direita da posicao encontrada, 1 casa para esquerda
		for(i=posRem; i<l->cont; i++){
			l->pokemon[i] = l->pokemon[i+1];
		}
		l->cont--; // N�o � preciso remover o �ltimo item do vetor, pois o cont controla essa informacao	
	}
    return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 6

typedef struct pokemon{ //Struct do pokemongo
	int num;
	char nome[30];
	char tipo[20];
	int hp;
	int atk;
} POKEMON;

POKEMON* cria_pokemon(int num, char *nome, char *tipo, int hp, int atk){ 
	//cria o pokemongo, foi complicado por conta desse malloc ai, tinha esquecido dele. Retorna o ponteiro pokemongo para ser usado na pilha(deck).
    POKEMON *p = (POKEMON*) malloc(sizeof(POKEMON));
    p->num = num;
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
	printf("Num: %d \n", v->num);  
    printf("Nome: %s\n", v->nome);
    printf("Tipo: %s\n", v->tipo);
    printf("HP: %d\n", v->hp);
    printf("Ataque: %d\n", v->atk);
	printf("======================\n");
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

typedef struct{ //Mão, coloquei 5 pokemons mas foi só pra teste
	int cont;
	char nome[30];
	POKEMON *pokemon[TAM];   
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

POKEMON* remover_damao(Mao *l, char *nome){
	int i;
	int posRem;
	POKEMON *p;
	
	if(l == NULL) return 0;
	if(estahVaziaMao(l)) return 0;
	
	posRem = buscaBinaria(l, nome);
	p = l->pokemon[posRem];

	if(posRem >= 0){
		for(i=posRem; i<l->cont; i++){
			l->pokemon[i] = l->pokemon[i+1];
		}
		l->cont--;	
	}
    return p;
}

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
/////////////////////////////////////////////////////////////////////////////LISTA POKEDEX
#define pmax 15



typedef struct pokemon{ //Struct do pokemongo
	char nome[30];
	char tipo[20];
	int hp;
	ataque atk[2];
} POKEMON;

POKEMON* cria_pokemon(char *nome, char *tipo, int hp, ataque atk1, ataque atk2){ 
	//cria o pokemongo, foi complicado por conta desse malloc ai, tinha esquecido dele. Retorna o ponteiro pokemongo para ser usado na pilha(deck).
    POKEMON *p = (POKEMON*) malloc(sizeof(POKEMON));
    
    strcpy(p->nome, nome);
    strcpy(p->tipo, tipo);
    p->hp = hp;
    strcpy(p->atk[0].nome, atk1.nome);
    strcpy(p->atk[0].tipo, atk1.tipo);
    p->atk[0].dano = atk1.dano;
    strcpy(p->atk[1].nome, atk2.nome);
    strcpy(p->atk[1].tipo, atk2.tipo);
    p->atk[1].dano = atk2.dano;

    return p;
}

void imprimirPokemon(POKEMON *v){
	printf("======================\n");
	printf("Pokemon: \n");
    printf("Nome: %s\n", v->nome);
    printf("Tipo: %s\n", v->tipo);
    printf("HP: %d\n", v->hp);
    printf("Ataques: %s // %s\n", v->atk[0].nome, v->atk[1].nome);
	printf("======================\n");
}

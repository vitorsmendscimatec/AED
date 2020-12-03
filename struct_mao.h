#define TAM 6

typedef struct{ //Mao, coloquei 5 pokemons mas foi so pra teste
	int cont;
	char nome[30];
	POKEMON pokemon[TAM];   
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
	else return l->cont == TAM;
}

int inserirOrdenadoMao(Mao* l, POKEMON *v){
	int i, posicao;
	if(l==NULL) return 0;
	if(estaCheiaMao(l)) return 0;
	if(estahVaziaMao(l)) 
		posicao = 0;
	else{ // Acha a posicao para inserir
		for(i=l->cont-1; i>=0 && (strcmp(l->pokemon[i].nome, v->nome) > 0); i--){
			//printf("l[i+1]: %s    l[i]: %s", l->pokemon[i+1]);
			l->pokemon[i+1] = l->pokemon[i];
			
		}
		posicao = i+1;
	}
	l->pokemon[posicao] = *v;
	l->cont++;
	return 1;
}

void imprimirMao(Mao* l){
	int i;
	if(l != NULL){
		if(!estahVaziaMao(l)){
			for(i=0; i<l->cont; i++){
				imprimirPokemon(&l->pokemon[i]);
			}
		}else{
			printf("Mao esta vazia!\n");
		}
	}else{
		printf("Mao nao foi criada!\n");
	}
}

void imprimerMaoLinhas(Mao* l){
	int i;
	if(l != NULL){
		if(!estahVaziaMao(l)){
			for(i=0; i<l->cont; i++){
				imprimirPokemonResumo(&l->pokemon[i], i+1);
			}
		}else{
			printf("Mao esta vazia!\n");
		}
	}else{
		printf("Mao nao foi criada!\n");
	}
}

const char *centerAlignText(char *field, unsigned int fieldWidth, const char *text){
    if (fieldWidth == 0 || field == NULL) return "";

    fieldWidth--;
    unsigned int len = strlen(text);
    unsigned int padding = fieldWidth > len ? (fieldWidth+1 - len)/2 : 0;
    sprintf(field, "%*s%.*s%*s", padding, "", fieldWidth-1, text, padding>0 && len%2!=fieldWidth%2 ? padding-1 : padding, "");

    return (const char *)field;
}

void imprimirMaoHorizontal(Mao* l){
	int i;
	int numChars = 140;		//numero de caracteres por linha do terminal
	char campo[numChars/6];		//Divide por 6 já que esse é o tamanho maximo da mao
	char total[numChars];
	
	if(l != NULL){
		if(!estahVaziaMao(l)){
			centerAlignText(campo, (sizeof campo)-1, l->nome);
    		printf("%s\n", campo);
    		
    		memset(campo, 0, numChars/6);
			for(i=0; i<l->cont; i++){
				printf("|%s|", centerAlignText(campo, sizeof campo, "======================"));
			}
			printf("\n");
			
			memset(campo, 0, numChars/6);
			for(i=0; i<l->cont; i++){
				char pos_c[10], temp[10];
				strcpy(pos_c, "Num: ");
				itoa(i+1, temp, 10);
				strcat(pos_c, temp);
				centerAlignText(campo, (sizeof campo)-1, pos_c);
    			printf("|%s|", campo);
			}
			printf("\n");
			
			memset(campo, 0, numChars/6);
			for(i=0; i<l->cont; i++){
				centerAlignText(campo, (sizeof campo)-1, l->pokemon[i].nome);
    			printf("|%s|", campo);
			}
			printf("\n");
			
			memset(campo, 0, numChars/6);
			for(i=0; i<l->cont; i++){
				centerAlignText(campo, (sizeof campo)-1, l->pokemon[i].tipo);
    			printf("|%s|", campo);
			}
			printf("\n");
			
			memset(campo, 0, numChars/6);
			for(i=0; i<l->cont; i++){
				char hp[10], temp_hp[5];
				strcpy(hp, "HP: ");
				itoa(l->pokemon[i].hp, temp_hp, 10);
				strcat(hp, temp_hp);
				centerAlignText(campo, (sizeof campo)-1, hp);
    			printf("|%s|", campo);
			}
			printf("\n");
			
			memset(campo, 0, numChars/6);
			for(i=0; i<l->cont; i++){
				char atk[10], temp_atk[5];
				strcpy(atk, "DANO: ");
				itoa(l->pokemon[i].atk, temp_atk, 10);
				strcat(atk, temp_atk);
				centerAlignText(campo, (sizeof campo)-1, atk);
    			printf("|%s|", campo);
			}
			printf("\n");
			
			for(i=0; i<l->cont; i++){
				printf("|%s|", centerAlignText(campo, sizeof campo, "======================"));
			}
			printf("\n");
			
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
		if (strcmp(l->pokemon[meio].nome, nome) == 0)
			return meio;
		else if (strcmp(l->pokemon[meio].nome, nome) > 0)
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
	p = &l->pokemon[posRem];

	if(posRem >= 0){
		for(i=posRem; i<l->cont; i++){
			l->pokemon[i] = l->pokemon[i+1];
		}
		l->cont--;	
	}
    return p;
}

//Versao que remove pela posicao
// pode haver 2 pokemons com o msm nome
POKEMON remover_pokemon(Mao *l, int posRem){
	int i;
	POKEMON p;
	strcpy(p.nome, "Mao nula ou inexistente!");
	
	if(l == NULL) return p;
	if(estahVaziaMao(l)) return p;
	
	p = l->pokemon[posRem];

	if(posRem >= 0){
		for(i=posRem; i<l->cont; i++){
			l->pokemon[i] = l->pokemon[i+1];
		}
		l->cont--;	
	}
	printf("%s, seu %s esta fora de combate!\n", l->nome, p.nome);
	sleep(2);
    return p;
}

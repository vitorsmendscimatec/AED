#include "includes.h"

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
	int numChars = 132;		//numero de caracteres por linha do terminal
	char campo[numChars/7];		//Divide por 6 já que esse é o tamanho maximo da mao
	
	if(l != NULL){
		if(!estahVaziaMao(l)){
			for(i=0; i<l->cont; i++){
				printf("|%s|", centerAlignText(campo, sizeof campo, "======================"));
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
				char hp[5];
				itoa(l->pokemon[i].hp, hp, 10);
				centerAlignText(campo, (sizeof campo)-1, hp);
    			printf("|%s|", campo);
			}
			printf("\n");
			
			memset(campo, 0, numChars/6);
			for(i=0; i<l->cont; i++){
				char atk[5];
				itoa(l->pokemon[i].atk, atk, 10);
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

int main(){
	//char campo[21];
	//printf("|_%s_|\n\n", centerAlignText(campo, sizeof campo, "Ola Mundo!"));
	int var;
    POKEMON* pko;
    Mao* m = criarMao();
    print_arquivo();
    
    
    for (int i = 0; i<6; i++){
    	scanf(" %d", &var);
		pko = busca_pokemon_pos(var);
		inserirOrdenadoMao(m, pko);
		imprimirMao(m);
	}
    
	
	imprimirMaoHorizontal(m);
	return 0;
}

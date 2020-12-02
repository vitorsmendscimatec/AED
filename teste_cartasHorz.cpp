#include "includes.h"

int main(){
	int var;
    POKEMON* pko;
    Mao* m = criarMao();
    print_arquivo();
    
    printf("tamanho: %d\n", tam_arquivo());
    
    for (int i = 0; i<6; i++){
    	scanf(" %d", &var);
		pko = busca_pokemon_pos(var);
		inserirOrdenadoMao(m, pko);
		//imprimirMao(m);
	}
    
	
	imprimirMaoHorizontal(m);
	return 0;
}

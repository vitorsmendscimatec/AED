#include "includes.h"



int main(){  
	int var;
    POKEMON* pko;
    Mao* m = criarMao();
    print_arquivo();
    /*for(int i = 0; i<3; i++){
    	scanf(" %d", &var);
	    pko = busca_pokemon_pos(var);
	    
	    //imprimirPokemon(pko);
	    inserirOrdenadoMao(m, pko);
	}*/
    scanf(" %d", &var);
	pko = busca_pokemon_pos(var);
	inserirOrdenadoMao(m, pko);
//    imprimirMaoHorizontal(m);
    //imprimirMao(m);
	
}

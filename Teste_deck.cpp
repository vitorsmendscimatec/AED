#include "includes.h"

int main(){
    Mao *m;
   
    POKEMON *squirtle, *bulbasaur;
    PILHA *p;

    p = cria_pilha();
	m = criarMao();

    squirtle = cria_pokemon("Squirtle", "Water", 30, 8 );
    bulbasaur = cria_pokemon("Bulbasaur", "Grass", 30, 8 );

    inserirOrdenadoMao(m, squirtle);
    inserirOrdenadoMao(m, bulbasaur);
    imprimirMao(m);

    printf("========================\n");
    atacar(squirtle, squirtle);

    
    return 0;
}

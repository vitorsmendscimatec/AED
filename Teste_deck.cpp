#include "includes.h"

int main(){
    Mao *m;
    ataque TACKLE, BUBBLES, VINE;
    POKEMON *squirtle, *bulbasaur;
    PILHA *p;

    p = cria_pilha();
	m = criarMao();

	TACKLE = cria_ataque("Tackle", "Normal", 10);
    BUBBLES = cria_ataque("Bubbles", "Water", 10);
    VINE = cria_ataque("Vine Whip", "Grass", 10);
    
	squirtle = cria_pokemon("Squirtle", "Water", 35, TACKLE, BUBBLES);
    
    bulbasaur = cria_pokemon("Bulbasaur", "Grass", 35, TACKLE, VINE);

    empilha(p, squirtle);
    empilha(p, bulbasaur);

    inserirOrdenadoMao(m, desempilha(p));

    inserirOrdenadoMao(m, desempilha(p));

    imprimirMao(m);

    return 0;
}

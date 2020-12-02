#include "includes.h"

int main(){
    Mao *mA, *mB;
   
    POKEMON *squirtle, *bulbasaur;
    PILHA *p;

    p = cria_pilha();
	mA = criarMao();
	mB = criarMao();
	
    squirtle = cria_pokemon("Squirtle", "Water", 30, 8 );
    bulbasaur = cria_pokemon("Bulbasaur", "Grass", 30, 8 );

    inserirOrdenadoMao(mA, squirtle);
    inserirOrdenadoMao(mB, bulbasaur);
    imprimirMao(mA);
	imprimirMao(mB);
	
    printf("========================\n");
    atacar(&mA->pokemon[0], &mB->pokemon[0]);
    
    printf("Mao A\n");
    imprimirMaoHorizontal(mA);
    printf("Mao B\n");
    imprimirMaoHorizontal(mB);

    
    return 0;
}

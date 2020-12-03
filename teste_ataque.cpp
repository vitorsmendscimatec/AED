#include "includes.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
    Mao *mA, *mB;
   
    POKEMON *squirtle, *bulbasaur;
    PILHA *p;

	mA = criarMao();
	mB = criarMao();
	strcpy(mA->nome, "Fulano");
	strcpy(mB->nome, "Beltrano");
	
    squirtle = cria_pokemon("Squirtle", "Water", 30, 60 );
    bulbasaur = cria_pokemon("Bulbasaur", "Grass", 30, 30 );

    inserirOrdenadoMao(mA, squirtle);
    inserirOrdenadoMao(mB, bulbasaur);
    
	/*printf("========================\n");
    printf("Mao A\n");
    imprimirMaoHorizontal(mA);
    printf("Mao B\n");
    imprimirMaoHorizontal(mB);*/
    
	/*int pk1, pk2;
	do {
		scanf("%d", &pk1);
	} while (pk1 <=0 || pk1 > tamanhoMao(mA));
	
	do {
		scanf("%d", &pk2);	
	} while (pk2 <=0 || pk2 > tamanhoMao(mB));*/
	
	jogo(mA, mB);		
    //printf("%s\n", mA->pokemon[pk1-1].nome);
    //printf("%s\n", mB->pokemon[pk2-1].nome);
    //atacar(&mA->pokemon[pk1-1], &mB->pokemon[pk2-1]);
    
    printf("Mao A\n");
    imprimirMaoHorizontal(mA);
    printf("Mao B\n");
    imprimirMaoHorizontal(mB);

    
    return 0;
}

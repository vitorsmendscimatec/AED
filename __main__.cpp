#include "includes.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"

int main(){
	setlocale(LC_ALL, "Portuguese");
	int a, b;
	Mao *m1;
	Mao *m2;
	m1 = criarMao();
	m2 = criarMao();



	
	while(a!=3){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         "); printf("                   POKEMON");
	printf("\n                                                                         "); printf("                   LAPA EDITION © 2020.");
	printf("\n\n                                                                                            "); system("PAUSE");
	a = iniciar();
	printpokemon(11);
	sleep(2);
	
	
	system("cls");
	switch(a){
		case 1: {
			int c=0;
			while(c == 0){
				m1 = digitenome1();
				m2 = digitenome2();	
				c = strcmp(m1->nome, m2->nome);
				if(c==0) {printf("Você digitou o mesmo nome para os dois players!\n"); sleep(1);}; //deletar dela e aparecer dps de 1seg
				system("cls");
			}
			
			int v;
			escolha(m1, 1, m1->nome);
			escolha(m2, 2, m2->nome);
			v = jogo(m1, m2);
			if(v == 1) endgame(m1->nome);
			else endgame(m2->nome);
		}
		// Falta implementar os casos 2 e 3 (regras e sair)
		case 2: {
			
			//instruções.
			
			break;
		}
		
	}  		}
	
	return 0;
}

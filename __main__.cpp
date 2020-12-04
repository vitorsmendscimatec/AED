#include "includes.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int a, b;
	Mao *m1;
	Mao *m2;
	m1 = criarMao();
	m2 = criarMao();

	a = iniciar();
	printpokemon(11);
	sleep(2);
	printf("                                                       POKEMON LAPA EDITION");
	system("cls");
	
	switch(a){
		case 1: {
			int c=0;
			while(c == 0){
				m1 = digitenome1();
				m2 = digitenome2();	
				c = strcmp(m1->nome, m2->nome);
				if(c==0) printf("Voce digitou o mesmo nome para os dois players!\n"); //deletar dela e aparecer dps de 1seg
				system("cls");
			}
			
			int v;
			escolha(m1, 1);
			escolha(m2, 2);
			v = jogo(m1, m2);
			if(v == 1) endgame(m1->nome);
			else endgame(m2->nome);
		}
		// Falta implementar os casos 2 e 3 (regras e sair)
		case 2: {
			//Mostrar regras
			break;
		}
		
		case 3: {
			//Sair do jogo
			break;
		}
	}
	
	return 0;
}

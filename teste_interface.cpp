#include "includes.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"
// função ataque nao funciona!
// o 3 ta errado
int main(){
	int a, b;
	Mao *m1;
	Mao *m2;
		m1 = criarMao();
		m2 = criarMao();
	
	
	
		a = iniciar();
		printpokemon(11); sleep(2);
		printf("                                                       POKEMON LAPA EDITION");
		system("cls");
	switch(a){
	case 1: {
		int c=0;
		while(c == 0){
		m1 = digitenome1();
		m2 = digitenome2();	
		c = strcmp(m1->nome, m2->nome);
		if(c==0) printf("Vocï¿½ digitou o mesmo nome para os dois players!\n"); //deletar dela e aparecer dps de 1seg
		system("cls");
		}
int v;
	escolha(m1, 1, m1->nome);
	escolha(m2, 2, m2->nome);
	v = jogo(m1, m2);
	if(v == 1) endgame(m1->nome);
	else endgame(m2->nome);
	}
	
	}
	
	return 0;
}

#include "includes.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"

void gerencia_jogo(Mao* m1, Mao* m2, int a){
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
			system("cls");
			if(v == 1) endgame(m1->nome);
			else endgame(m2->nome);
			system("cls");
			printf("Deseja iniciar um novo jogo? [S/N]\n");
			char resp[10];
			scanf("%s", &resp);
			for(int k = 0; k<strlen(resp); k++){
			  resp[k] = tolower(resp[k]);
			}
			
			if(strcmp(resp, "s") == 0){
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
				
				gerencia_jogo(m1, m2, a);
			} else {
				printf("Ate a proxima!!!\n");
			}
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
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int a, b;
	Mao *m1;
	Mao *m2;
	m1 = criarMao();
	m2 = criarMao();
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         "); printf("                   POKEMON");
	printf("\n                                                                         "); printf("                   LAPA EDITION **2020**");
	printf("\n\n                                                                                            \n\n"); system("PAUSE");
	
	a = iniciar();
	printpokemon(11);
	sleep(2);
	printf("                                                       POKEMON LAPA EDITION");
	system("cls");
	
	gerencia_jogo(m1, m2, a);
	
	return 0;
}

#include "includes.h"


int main(){
int a, b;
Mao *m1;
Mao *m2;
	m1 = criarMao();
	m2 = criarMao();



	a = iniciar();
	pikachu();
	system("cls");
switch(a){
case 1: {
	int c=0;
	while(c == 0){
	m1 = digitenome1();
	m2 = digitenome2();	
	c = strcmp(m1->nome, m2->nome);
	if(c==0) printf("Voc� digitou o mesmo nome para os dois players!\n"); //deletar dela e aparecer dps de 1seg
	
	}

Mao *p;
escolha(m1, m2, p);
//rodada(m1, m2); //batalha pokemon
endgame();
}

}

return 0;
}

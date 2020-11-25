#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>//necessário p/ função time()
#include <conio.h>
#include "interface.h"

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
	c = strcmp(m1->player, m2->player);
	if(c==0) printf("Você digitou o mesmo nome para os dois players!\n");
	}
escolha(m1, m2);
endgame();
}

}

return 0;
}

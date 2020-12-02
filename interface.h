//adicionar na entrada do jogo duas variaveis para o nome dos jogadores.


int iniciar(){
int a;

char center[100];
system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
printf("SEJA BEM VINDO AO POKEMON LAPA EDITION\n\n                                                                         DIGITE:\n                                                                         1- Iniciar jogo\n                                                                         2- Instru??es\n                                                                         3- Sair do jogo\n\n          ");
scanf("%d", &a);
system("cls");
if(a==1 || a==2 || a==3)return a;
else printf("%sComando inv?lido!", center); sleep(1); iniciar();
}

void endgame(char* nome){
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         VENCEDOR: ", nome);
printf("\n                                                                                                         88                                                       ");
printf("\n                                                                                                         88                                                       ");
printf("\n                                                                                                         88                                                       ");
printf("\n                                                                          ,adPPYba, 8b,dPPYba,   ,adPPYb,88  ,adPPYb,d8 ,adPPYYba, 88,dPYba,,adPYba,   ,adPPYba,  ");
printf("\n                                                                         a8P_____88 88P'   ``8a a8ï¿½    `Y88 a8`    `Y88 ``     `Y8 88P'   '88`    `8a a8P_____88  ");
printf("\n                                                                         8PP`````` 88        88 8b       88 8b       88 ,adPPPPP88 88      88      88 8PP````````  ");
printf("\n                                                                         `8b,   ,aa 88      88 `8a,   ,d88` `8a,   ,d88 88,    ,88 88      88      88 `8b,   ,aa  ");
printf("\n                                                                          ``Ybbd8`' 88       88  ``8bbdP`Y8  ``YbbdP`Y8 ``8bbdP`Y8 88      88      88  ``Ybbd8`'   ");
printf("\n                                                                                                             aa,    ,88                                          ");
printf("\n                                                                                                              `Y8bbdP`");
}

Mao* digitenome1(void){
Mao *m1;
m1 = criarMao();
printf("Digite o nome do Player 1: ");
scanf(" %[^\n]", &m1->nome);
fflush(stdin);
return m1;
}

Mao* digitenome2(void){
Mao *m2;
m2 = criarMao();
printf("Digite o nome do Player 2: ");
scanf(" %[^\n]", &m2->nome);
fflush(stdin);
return m2;
}


void escolha(Mao *m, int num, char *nome){
int i;
POKEMON *p[5];
for(i=5; i>0; i--){
system("cls");
printf("\n%s escolha 5 dentre os pokemons abaixo atraves de seus respectivos numero.\n", nome);
print_arquivo();
printf("\nDigite o numero do pokemon e em seguida pressione a teclar enter, eh permitido apenas 5 pokemons.\n");	
	

int pos;
scanf("%d", &pos);

int vagas;
	if(pos<16 && pos>0){
  
	vagas = i-1;
	p[i] = busca_pokemon_pos(pos);
	inserirOrdenadoMao(m, p[i]);
	system("cls");
	imprimirPokemon(p[i]); printf("\n");
	printpokemon(pos); sleep(2);system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
	printf("RESGISTRANDO\n                                                                         %s entrou para o seu time!", p[i]->nome);  
	printf("\n                                                                         ");
	printf("Restam %d vagas em sua mao.", vagas);  sleep(2); system("cls");				
						}


	else{
	vagas = i;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
	printf("COMANDO INVALIDO!"); 
	i++;
	sleep(2); system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
	printf("Restam %d vagas em sua mao.", vagas);  sleep(2); system("cls");
		}
	
}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
	printf("Sua mao esta completa!");  sleep(2); system("cls");
	imprimirMaoHorizontal(m); sleep(5);
system("cls");
}



int jogo(Mao* m1, Mao* m2){
int cont=1, v=0;
int esc;
system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
printf("O jogo inicie em: 3"); sleep(1);
system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
printf("O jogo inicie em: 2"); sleep(1);
system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
printf("O jogo inicie em: 1"); sleep(1);
while(cont != 0){
system("cls");
printf("                                                                         Rodada %d\n", cont);
printf("\nPlayer: %s\n", m1->nome);
imprimirMaoHorizontal(m1);
printf("\nPlayer: %s\n", m2->nome);
imprimirMaoHorizontal(m2);
printf("\n%s escolha:\n1) Atacar um pokemon adversario\n2) Passar a vez  ", m1->nome);
scanf("%d", &esc);
switch(esc){

case 1: {
system("cls");
imprimirMaoHorizontal(m1);
imprimirMaoHorizontal(m2);
int pk1, pk2;
POKEMON *patk1, *patk2;
printf("\n%s Digite com qual pokemon você deseja atacar e aperte ENTER.\nDepois, digite o pokemon que você deseja atacar e aparte enter. ", m1->nome);
scanf("%d", &pk1);
patk1 = busca_pokemon_pos(pk1);
scanf("%d", &pk2);
patk2 = busca_pokemon_pos(pk2);
atacar(patk1,patk2);
	break;
}
case 2: {
system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
printf("O jogador passou a vez."); sleep(1); system("cls");
	break;
}
}
int cont2;
cont2 = tamanhoMao(m2);
if(cont2 == -1) v=1; cont=0;
system("cls");

printf("                                                                         Rodada %d", cont);
imprimirMaoHorizontal(m1);
imprimirMaoHorizontal(m2);
printf("\n%s escolha:\n1) Atacar um pokemon adversario\n2) Passar a vez", m2->nome);
scanf("%d", &esc);
switch(esc){

case 1: {
system("cls");
imprimirMaoHorizontal(m1);
imprimirMaoHorizontal(m2);
int pk1, pk2;
POKEMON *patk1, *patk2;
printf("\n%s Digite com qual pokemon você deseja atacar e aperte ENTER.\nDepois, digite o pokemon que você deseja atacar e aparte enter. ", m2->nome);
scanf("%d", &pk1);
patk1 = busca_pokemon_pos(pk1);
scanf("%d", &pk2);
patk2 = busca_pokemon_pos(pk2);
atacar(patk1,patk2);
	break;
}
case 2: {
system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
printf("O jogador passou a vez.");
	break;
}
}

int cont1;
cont1 = tamanhoMao(m1);
if(cont1 == -1) v=2; cont=0;


cont++;	
}	

return v;
}

//adicionar na entrada do jogo duas variaveis para o nome dos jogadores.

void pikachu(){
printf("                                                                                                                      ,-.\n");
    printf("                                                                                                                   _.|  '\n");
    printf("                                                                                                                 .'  | /\n");
    printf("                                                                                                               ,'    |'\n");
    printf("                                                                                                              /      /\n");
    printf("                                                                                                _..----\"\"---.'      /\n");
    printf("                                                                          _.....---------...,-\"\"                  ,'\n");
    printf("                                                                          `-._  \\                                /\n");
    printf("                                                                              `-.+_            __           ,--. .\n");
    printf("                                                                                   `-.._     .:  ).        (`--\"| \\\n");
    printf("                                                                                        7    | `\" |         `...'  \\\n");
    printf("                                                                                        |     `--'     '+\"        ,\". ,\"\"-\n");
    printf("                                                                                        |   _...        .____     | |/    '\n");
    printf("                                                                                   _.   |  .    `.  '--\"   /      `./     j\n");
    printf("                                                                                  \\' `-.|  '     |   `.   /        /     /\n");
    printf("                                                                                  '     `-. `---\"      `-\"        /     /\n");
    printf("                                                                                   \\       `.                  _,'     /\n");
    printf("                                                                                    \\        `                        .\n");
    printf("                                                                                     \\                                j\n");
    printf("                                                                                      \\                              /\n");
    printf("                                                                                       `.                           .\n");
    printf("                                                                                         +                          \\\n");
    printf("                                                                                         |                           L\n");
    printf("                                                                                         |                           |\n");
    printf("                                                                                         |  _ /,                     |\n");
    printf("                                                                                         | | L)'..                   |\n");
    printf("                                                                                         | .    | `                  |\n");
    printf("                                                                                         '  \\'   L                   '\n");
    printf("                                                                                          \\  \\   |                  j\n");
    printf("                                                                                           `. `__'                 /\n");
    printf("                                                                                         _,.--.---........__      /\n");
    printf("                                                                                        ---.,'---`         |   -j\"\n");
    printf("                                                                                         .-'  '....__      L    |\n");
    printf("                                                                                       \"\"--..    _,-'       \\ l||\n");
    printf("                                                                                           ,-'  .....------. `||'\n");
    printf("                                                                                        _,'                /\n");
    printf("                                                                                      ,'                  /\n");
    printf("                                                                                     '---------+-        /\n");
    printf("                                                                                              /         /\n");
    printf("                                                                                            .'         /\n");
    printf("                                                                                          .'          /\n");
    printf("                                                                                        ,'           /\n");
    printf("                                                                                      _'....----\"\"\"\"\" mh\n");sleep(1);
}
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

void endgame(){
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
printf("\n                                88                                                       ");
printf("\n                                88                                                       ");
printf("\n                                88                                                       ");
printf("\n ,adPPYba, 8b,dPPYba,   ,adPPYb,88  ,adPPYb,d8 ,adPPYYba, 88,dPYba,,adPYba,   ,adPPYba,  ");
printf("\na8P_____88 88P'   ``8a a8�    `Y88 a8`    `Y88 ``     `Y8 88P'   '88`    `8a a8P_____88  ");
printf("\n8PP`````` 88        88 8b       88 8b       88 ,adPPPPP88 88      88      88 8PP````````  ");
printf("\n`8b,   ,aa 88      88 `8a,   ,d88` `8a,   ,d88 88,    ,88 88      88      88 `8b,   ,aa  ");
printf("\n ``Ybbd8`' 88       88  ``8bbdP`Y8  ``YbbdP`Y8 ``8bbdP`Y8 88      88      88  ``Ybbd8`'   ");
printf("\n                                    aa,    ,88                                          ");
printf("\n                                     `Y8bbdP`");
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

Mao* iniciepokedex(void){
	Mao *m;
	
	m = criarMao();
	POKEMON *p1, *p2, *p3;
	p1 = cria_pokemon(1,(char*)"Biancossauro", (char*)"Fogo", 120, 30);
	inserirOrdenadoMao(m, p1);
	p2 = cria_pokemon(2,(char*)"Lapossauro", (char*)"Grama", 100, 50);
	inserirOrdenadoMao(m, p2);
	p3 = cria_pokemon(3,(char*)"Charmander", (char*)"Fogo", 80, 60);
	inserirOrdenadoMao(m, p3);
	return m;
}

void escolha(Mao* m1, Mao* m2, Mao* p){
printf("Escolha 5 dentre os pokemons abaixo atraves de seus respectivos numero.\n");
p = iniciepokedex();
imprimirMao(p);
printf("\nDigite o numero do pokemon e em seguida pressione a teclar enter");

int i;

for(i=0;i<6;i++){
int n;
scanf("%d", &n);
//buscaBinaria()//necessidade de alteracao, para buscar por numero.
//inserirOrdenadoMao(m1, )



if(i == 5) printf("\n\nsua mao esta cheia!\n\n");

				}
}

void iniciajogo(Mao m1, Mao m2){
//recolhe do deck
int i;
for(i=1;i<6;i++){
printf("Round %d", i);
}
	
}

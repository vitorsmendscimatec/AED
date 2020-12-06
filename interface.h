//adicionar na entrada do jogo duas variaveis para o nome dos jogadores.


int iniciar(){
	int a;
	
	char center[100];
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
	printf("SEJA BEM VINDO AO POKEMON LAPA EDITION\n\n                                                                         DIGITE:\n                                                                         1- Iniciar jogo\n                                                                         2- Instrucoes\n                                                                         3- Sair do jogo\n\n          ");
	scanf("%d", &a);
	system("cls");
	if(a==1 || a==2 || a==3) return a;
	else{
		//printf("%sComando invalido!", center);
		fflush(stdin);
		printf("Comando invalido!\n");
		sleep(1);
		iniciar();	
	} 
}

void endgame(char* nome){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         VENCEDOR: %s", nome);
	printf("\n                                                                                                         88                                                       ");
	printf("\n                                                                                                         88                                                       ");
	printf("\n                                                                                                         88                                                       ");
	printf("\n                                                                          ,adPPYba, 8b,dPPYba,   ,adPPYb,88  ,adPPYb,d8 ,adPPYYba, 88,dPYba,,adPYba,   ,adPPYba,  ");
	printf("\n                                                                         a8P_____88 88P'   ``8a a8�    `Y88 a8`    `Y88 ``     `Y8 88P'   '88`    `8a a8P_____88  ");
	printf("\n                                                                         8PP`````` 88        88 8b       88 8b       88 ,adPPPPP88 88      88      88 8PP````````  ");
	printf("\n                                                                         `8b,   ,aa 88      88 `8a,   ,d88` `8a,   ,d88 88,    ,88 88      88      88 `8b,   ,aa  ");
	printf("\n                                                                          ``Ybbd8`' 88       88  ``8bbdP`Y8  ``YbbdP`Y8 ``8bbdP`Y8 88      88      88  ``Ybbd8`'   ");
	printf("\n                                                                                                             aa,    ,88                                          ");
	printf("\n                                                                                                              `Y8bbdP`\n");
	
	system("pause");
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


void escolha(Mao *m, int num){
	int i;
	POKEMON* temp;
	for(i=5; i>0; i--){
		system("cls");
		printf("\n%s escolha 5 dentre os pokemons abaixo atraves de seus respectivos numero.\n", m->nome);
		print_arquivo();
		printf("\nDigite o numero do pokemon e em seguida pressione a tecla ENTER, eh permitido apenas 5 pokemons.\n");	
			
		
		int pos;
		scanf(" %d", &pos);
		
		int vagas;
			if(pos > 0 && pos < 12){
				vagas = i-1;
				temp = busca_pokemon_pos(pos);
				inserirOrdenadoMao(m, temp);
				system("cls");
				imprimirPokemon(temp); printf("\n");
				printpokemon(pos); sleep(2);system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
				printf("RESGISTRANDO\n                                                                         %s entrou para o seu time!", temp->nome);  
				printf("\n                                                                         ");
				printf("Restam %d vagas em sua mao.", vagas);  sleep(2); system("cls");				
			}
		
		
			else{
			vagas = i;
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                                            ");
			printf("COMANDO INVALIDO!"); 
			i++;
			sleep(2); system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                                            ");
			printf("Restam %d vagas em sua mao.", vagas);  sleep(2); system("cls");
			}
		
	}
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                         ");
		printf("Sua mao esta completa!");  sleep(2); system("cls");
		imprimirMaoHorizontal(m); 
		printf("%s, estes sao os seus pokemons\n", m->nome);
		system("pause");

	system("cls");
}

int verifica_vitoria(Mao* m1, Mao* m2){
	if(estahVaziaMao(m1)) return 1;
	if(estahVaziaMao(m2)) return 1;
	if(estahVaziaMao(m1) && estahVaziaMao(m2)) return 1;	// Indica que algo deu errado e ambos estao de maos vazias
	return 0;
}

int jogo(Mao* m1, Mao* m2){
	int cont=1, v=0, estado;
	int esc;
	system("cls");
	for(int i = 3; i > 0; i--){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                                            ");
		printf("O jogo inicia em: %d", i);
		sleep(1);
		system("cls");	
	}

	while(cont != 0){
		system("cls");
		printf("                                                                         Rodada %d\n", cont);
		imprimirMaoHorizontal(m1);
		imprimirMaoHorizontal(m2);
		printf("\n%s escolha:\n1) Atacar um pokemon adversario\n2) Passar a vez  \n", m1->nome);
		scanf(" %d", &esc);
		// vez da mao 1
		switch(esc){
		
			case 1: {
				system("cls");
				printf("                                                                         Rodada %d\n", cont);
				imprimirMaoHorizontal(m1);
				imprimirMaoHorizontal(m2);
				int pk1, pk2;
				printf("\n%s Digite com qual pokemon voce deseja atacar e aperte ENTER.\nDepois, digite o pokemon que voce deseja atacar e aperte enter.\n", m1->nome);
				//VERIFICAR VALIDADE
				do {
					scanf(" %d", &pk1);	
				} while (pk1 <=0 || pk1 > tamanhoMao(m1));
				
				
				do {
					scanf(" %d", &pk2);
				} while (pk2 <=0 || pk2 > tamanhoMao(m2));
	
				atacar(&m1->pokemon[pk1-1],&m2->pokemon[pk2-1]);
				if(sem_vida(&m2->pokemon[pk2-1])){		//Se o atacado estiver sem vida
					remover_pokemon(m2, pk2-1);
				}
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
		if(cont2 == -1){
			v=1;
			cont=0;	
		} 
		system("cls");
		
		estado = verifica_vitoria(m1, m2);
		if(estado != 0){
			return estado;
		}
		
		printf("                                                                         Rodada %d\n", cont);
		imprimirMaoHorizontal(m1);
		imprimirMaoHorizontal(m2);
		printf("\n%s escolha:\n1) Atacar um pokemon adversario\n2) Passar a vez\n", m2->nome);
		int esc2;
		scanf(" %d", &esc2);
		// VEZ do jogador 2
		switch(esc2){
		
			case 1: {
				system("cls");
				printf("                                                                         Rodada %d\n", cont);
				imprimirMaoHorizontal(m1);
				imprimirMaoHorizontal(m2);
				int pk1, pk2;
				printf("\n%s Digite com qual pokemon voce deseja atacar e aperte ENTER.\nDepois, digite o pokemon que voce deseja atacar e aparte enter.\n", m2->nome);
				
				do {
					scanf(" %d", &pk2);
				} while (pk2 <=0 || pk2 > tamanhoMao(m2));
				
				do {
					scanf(" %d", &pk1);	
				} while (pk1 <=0 || pk1 > tamanhoMao(m1));
	
				atacar(&m2->pokemon[pk2-1], &m1->pokemon[pk1-1]);
				if(sem_vida(&m1->pokemon[pk1-1])){		//Se o atacado estiver sem vida
					remover_pokemon(m1, pk1-1);
				}
	
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
		if(cont1 == -1){
			v=2; 
			cont=0;	
		} 

		estado = verifica_vitoria(m1, m2);
		if(estado != 0){
			return estado;	
		}
		cont++;	
	}	
	
	return v;
}

typedef struct ataque{ //Bem basic�o struct do atk
    char nome[20];
    char tipo[20];
    int dano;
}ataque;

ataque cria_ataque(char *nome, char *tipo, int dano){ //Cria a struct do atk, bem obvio.
	ataque atk;
	
	strcpy(atk.nome, nome);
	strcpy(atk.tipo, tipo);
	atk.dano = dano;
	
	return atk;
}

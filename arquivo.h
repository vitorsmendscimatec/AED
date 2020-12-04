void registra(POKEMON* p){
	
	FILE *pArq = fopen("pokedex.bin", "ab");
	
	if(pArq == NULL){
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}
	fwrite(p, sizeof(POKEMON), 1, pArq);
	fclose(pArq);
}

void print_arquivo(){
	FILE *pArq;
	POKEMON p;
	pArq = fopen("pokedex.bin", "rb");
	if(pArq == NULL){
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}

	int cont = 0;
	while(getc(pArq) != EOF){				//Loop enquanto n?o chegar ao fim do arquivo
		fseek(pArq, cont*sizeof(POKEMON), SEEK_SET);
		fread(&p, sizeof(POKEMON), 1, pArq);
		//OBS: deve ser alterado conforme mudan?as na struct POKEMON
		printf("%d - %s tipo: %s HP = %d\n", cont+1, p.nome, p.tipo, p.hp);	//Print formatado dos dados do tipo POKEMON
		cont++;
	}
	
	fclose (pArq);
}

//CUIDADO => como o nome indica essa fun??o apaga toda a pokedex
void del_all(){
	//remove ("pokedex.bin");
	FILE *pArq;
	pArq = fopen("pokedex.bin", "wb");		//Esse comando ger? um novo arquivo com o mesmo nome do anterior e apagar? o antigo
	fclose(pArq);
}

int tam_arquivo(){
	FILE *pArq;
	POKEMON p;
	int cont = 0;
	pArq = fopen("pokedex.bin", "rb");
	if(pArq == NULL){
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}

	
	while(getc(pArq) != EOF){				//Loop enquanto n?o chegar ao fim do arquivo
		fseek(pArq, cont*sizeof(POKEMON), SEEK_SET);
		fread(&p, sizeof(POKEMON), 1, pArq);
		//OBS: deve ser alterado conforme mudan?as na struct POKEMON
		//printf("%d - %s tipo: %s HP = %d\n", cont+1, p.nome, p.tipo, p.hp);	//Print formatado dos dados do tipo POKEMON
		cont++;
	}
	fclose (pArq);
	return cont;
}
//busca um pokemon pela posicao informada, do 1? ao n?
POKEMON* busca_pokemon_pos(int pos){
	if(pos <= 0 || pos > tam_arquivo()){
		printf("Essa posicao posicao nao existe no arquivo\n\nERRO!");
		exit(10);
	}
	pos--;
	FILE *pArq;
	POKEMON* p;
	pArq = fopen("pokedex.bin", "rb");
	if(pArq == NULL){
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}

	fseek(pArq, pos*sizeof(POKEMON), SEEK_SET);
	fread(p, sizeof(POKEMON), 1, pArq);
	fclose (pArq);
	return p;
}


void lista_to_arq(LISTAE* l, int apaga_ant=0){
	//apaga_ant = 0 => os dados ser�o acrescentados ao arquivo ja existente
	//apaga_ant = 1 => apaga todos os dados anteriores
	if(apaga_ant){
		FILE *pArq;
		pArq = fopen("pokedex.bin", "wb");
	}

	NOL* aux = *l;
	while(aux != NULL){
		registra(&aux->dados);
		aux = aux->prox;
	}
}

//Apaga o antigo pokemon na posicao pos e substitui pelo novo pokemon informado
void sobrescreve(POKEMON p, int pos){

	LISTAE* l = cria_lista();
	FILE *pArq;
	pArq = fopen("pokedex.bin", "rb");
	if(pArq == NULL){
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}
	
	int cont = 0;
	while(getc(pArq) != EOF){				//Loop enquanto n?o chegar ao fim do arquivo
		POKEMON temp;
		fseek(pArq, cont*sizeof(POKEMON), SEEK_SET);
		fread(&temp, sizeof(POKEMON), 1, pArq);
		//printf("POS = %d   CONT = %d\n", pos, cont+1);
		if(cont+1 == pos){
			insere_fim(l, p);	//O valor de p e inserido na lista ao inves do valor original do arquivo
			//printf("%d  p\n", cont+1);
		} else {
			insere_fim(l, temp);
			//printf("%d  temp\n", cont+1);
		}
	//	printf("%d  temp\n", cont+1);
		cont++;
	}
	fclose(pArq);
	
	if(pos<=0 || pos > tamanho_listase(l)){
		printf("Parametro 'pos' invalido!\n");
		exit(10);
	}
	
	printf("Lista Atualizada!\n");	
	print_lista(l);
	lista_to_arq(l, 1);
	destroi_listase(l);
}

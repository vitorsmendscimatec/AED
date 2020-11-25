#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>//necessário p/ função time()
#include <conio.h>

#include "ataque_struct.h"
#include "pokemon_struct.h"
#include "lista_enc.h"
#include "deck.h"
#include "registro_arquivo.h"


//Isso serve para ele parar de dar 'warning' por converter string constante para 'char*'
#pragma GCC diagnostic ignored "-Wwrite-strings"

int main(){
	ataque TACKLE, BUBBLES, VINE;
    POKEMON* squirtle, *bulbasaur, *SSsquirtleSS;
    LISTAE* l = cria_lista();
    
	TACKLE = cria_ataque("Tackle", "Normal", 10);
    BUBBLES = cria_ataque("Bubbles", "Water", 10);
    VINE = cria_ataque("Vine Whip", "Grass", 10);
    //Criar tantos ataques quanto se queira
    
    //Modelo sobre como criar um pokemon
	squirtle = cria_pokemon("Squirtle", "Water", 35, TACKLE, BUBBLES);
    bulbasaur = cria_pokemon("Bulbasaur", "Grass", 35, TACKLE, VINE);
    SSsquirtleSS = cria_pokemon("SSSquirtleSS", "Water", 35, TACKLE, BUBBLES);
    

    //del_all();
    //sobrescreve(*SSsquirtleSS, 1);
    //registra(SSsquirtleSS);
    //registra(bulbasaur);
    //lista_to_arq(l);
    //print_arquivo();
	return 0;
}

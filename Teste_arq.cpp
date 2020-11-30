#include "includes.h"

//Isso serve para ele parar de dar 'warning' por converter string constante para 'char*'
#pragma GCC diagnostic ignored "-Wwrite-strings"

int main(){
    POKEMON* squirtle, *bulbasaur, *lapossauro;
    //Modelo sobre como criar um pokemon
	squirtle = cria_pokemon(1 ,"Squirtle", "Water", 35, 10);
    bulbasaur = cria_pokemon(2 ,"Bulbasaur", "Grass", 35, 10);
    lapossauro = cria_pokemon(3, "Lapossauro", "Fire", 35, 10);

    del_all();

    //sobrescreve(*lapossauro, 1);
    registra(lapossauro);
    registra(bulbasaur);
    registra(squirtle);
    //lista_to_arq(l);
    
    print_arquivo();

	return 0;
}

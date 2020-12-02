#include "includes.h"

//Isso serve para ele parar de dar 'warning' por converter string constante para 'char*'
#pragma GCC diagnostic ignored "-Wwrite-strings"

int main(){
    POKEMON *Biancossauro, *Meowth, *lapossauro,* squirtle, *bulbasaur, *Charmander, *Pidgey, *Rattata, *Vulpix, *Poliwag, *Pikachu;
	Biancossauro = cria_pokemon((char*)"Biancossauro", (char*)"Fire", 40, 5);
	Meowth = cria_pokemon((char*)"Meowth", (char*)"Grass", 100, 50);
	
    //Modelo sobre como criar um pokemon
    lapossauro = cria_pokemon("Lapossauro", "Fire", 35, 10);
    squirtle = cria_pokemon("Squirtle", "Water", 30, 7 );
    bulbasaur = cria_pokemon("Bulbasaur", "Grass", 30, 7 );
    Charmander = cria_pokemon("Charmander", "Fire", 30, 7 );
    Pidgey = cria_pokemon("Pidgey", "Normal", 35, 5 );
    Rattata = cria_pokemon("Rattata", "Normal", 35, 5);
    //Pikachu =  cria_pokemon("Pikachu", "Electric", 30, 7 );
    Vulpix = cria_pokemon("Vulpix", "Fire", 30, 7 );
    Poliwag = cria_pokemon("Poliwag", "Water", 35, 5 );
	Pikachu = cria_pokemon("Pikachu", "Normal", 35, 5);
	//Abra = cria_pokemon("Abra", "Physhic", 30, 7);

    del_all();

    //sobrescreve(*lapossauro, 1);
    registra(Biancossauro);
    registra(Meowth);

    registra(lapossauro);
    registra(squirtle);
    registra(bulbasaur);
    registra(Charmander);
    registra(Pidgey);
    registra(Rattata);
    
    registra(Vulpix);
    registra(Poliwag);
    registra(Pikachu);
    print_arquivo();
    
	return 0;
}

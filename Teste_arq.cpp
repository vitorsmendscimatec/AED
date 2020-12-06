#include "includes.h"

//Isso serve para ele parar de dar 'warning' por converter string constante para 'char*'
#pragma GCC diagnostic ignored "-Wwrite-strings"

int main(){
    POKEMON *Biancossauro, *Meowth, *lapossauro,* squirtle, *bulbasaur, *Charmander, *Pidgey, *Rattata, *Vulpix, *Poliwag, *Pikachu;

	
    //Modelo sobre como criar um pokemon
    lapossauro = cria_pokemon("Lapossauro", "Normal", 100, 50);
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
	
	Biancossauro = cria_pokemon("Biancossauro", "Fire", 50, 15);
	Meowth = cria_pokemon("Meowth", "Grass", 50, 15);
	lapossauro = cria_pokemon("Lapossauro", "Normal", 200, 100);
    squirtle = cria_pokemon("Squirtle", "Water", 40, 20);
    bulbasaur = cria_pokemon("Bulbasaur", "Grass", 70, 10);
    Charmander = cria_pokemon("Charmander", "Fire", 40, 20);
    Pidgey = cria_pokemon("Pidgey", "Normal", 50, 15);
    Rattata = cria_pokemon("Rattata", "Water", 50, 15);
    Vulpix = cria_pokemon("Vulpix", "Fire", 70, 10);
    Poliwag = cria_pokemon("Poliwag", "Water", 70, 10);
	Pikachu = cria_pokemon("Pikachu", "Grass", 40, 20);

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

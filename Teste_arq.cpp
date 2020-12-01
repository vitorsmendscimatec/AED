#include "includes.h"

//Isso serve para ele parar de dar 'warning' por converter string constante para 'char*'
#pragma GCC diagnostic ignored "-Wwrite-strings"

int main(){
    POKEMON *lapossauro,* squirtle, *bulbasaur, *Charmander, *Pidgey, *Rattata, *Vulpix, *Poliwag, *Meganium;
    POKEMON *p1, *p2, *p3;
	p1 = cria_pokemon((char*)"Biancossauro", (char*)"Fogo", 40, 5);
	p2 = cria_pokemon((char*)"Lapossauro", (char*)"Grama", 100, 50);
	
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
	Meganium = cria_pokemon("Meganium", "Grass", 35, 5 );
	//Abra = cria_pokemon("Abra", "Physhic", 30, 7);

    del_all();

    //sobrescreve(*lapossauro, 1);
    registra(p1);
    registra(p2);

    registra(lapossauro);
    registra(squirtle);
    registra(bulbasaur);
    registra(Charmander);
    registra(Pidgey);
    registra(Rattata);
    
    registra(Vulpix);
    registra(Poliwag);
    registra(Meganium);
    print_arquivo();
    
	return 0;
}

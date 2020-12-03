// inclui todos os includes necessarios

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>//necess�rio p/ fun��o time()
#include <conio.h>
#include <locale.h>
#include <unistd.h>
#include <windows.h>

#include "prints.h"
#include "struct_pokemon.h"
#include "lista_enc.h"
#include "arquivo.h"
#include "struct_mao.h"
#include "struct_cemiterio.h"
#include "interface.h"

//Isso serve para ele parar de dar 'warning' por converter string constante para 'char*'
#pragma GCC diagnostic ignored "-Wwrite-strings"

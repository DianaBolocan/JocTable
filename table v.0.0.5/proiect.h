#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
struct player
{
	char nume[10];
	short linii;
	short partide;
	short zar1;
	short zar2;
	char piesa;
	short eliminate;
};
struct clasamentJoc
{
    char numeJucator;
    int partide;
    int linii;
}players[10];



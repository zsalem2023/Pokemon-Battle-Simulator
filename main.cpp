//clear warnings
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//define constants
#define MUSIC false
#define PROTEUS false
#define TIME 2000
#define NUM_POKEMON 32

//include platform-dependent libraries
#if PROTEUS
	#include <FEHLCD.h>
	#include <FEHIO.h>
	#include <FEHUtility.h>
#else
	#include <iostream>
	#include "windows.h"
	using namespace std;
	#include <sstream>
	#include <vector>
	#include <iomanip>
	#include <iterator>
	#include <sstream>
#endif

//include platform-independent libraries
#include <cstring>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//global variables
int wins1 = 0, wins2 = 0, pick = 2;
bool loopGame = true;

//include source code
#include "utility.h"
#include "pokemonstd.h"
#include "movefactory.h"
#include "pokemonfactory.h"
#include "game.h"

//main function that runs the game
int main()
{
	//loop the game
	while (loopGame)
	{
		welcome();
	}

	//print that the game has ended
	#if PROTEUS
		LCD.WriteLine("Game has ended.");
	#else
		std::cout << "The game has ended." << std::endl;
	#endif
}
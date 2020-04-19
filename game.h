#ifndef GAME_H
#define GAME_H

//prompts the player to switch their current pokemon to another on their team, returns 8 + [the index of the pokemon selected], called by selectAction (and by useMove upon faint)
int selectSwitch(Player* player)
{
	int input;
	if (!player->isAI)
	{
		//list alive pokemon
		for (int i = 0; i < 6; i++)
		{
			if (player->pokemon[i].alive)
			{
				#if PROTEUS
					char s[256];
					sprintf(s, "%d: %s (%f%)", i + 1, player->pokemon[i].info.name, std::ceil(((player->pokemon[i].currentHp + 0.0) / player->pokemon[i].stats.hp) * 100));
					LCD.WriteLine(s);
				#else
					std::cout << i + 1 << ": " << player->pokemon[i].info.name << " (" << std::setprecision(0) << std::fixed << ((player->pokemon[i].currentHp + 0.0) / player->pokemon[i].stats.hp) * 100 << "%)" << std::endl;
				#endif
			}
		}
		bool validInput = false;
		//get a valid pokemon to switch to
		while (!validInput)
		{
			#if PROTEUS
				LCD.WriteLine("Switch Pokemon!");
				input = getInput(6);
			#else
				std::cout << "Pick the pokemon to switch to -->";
				std::cin >> input;
			#endif

			if (input > 6 || !player->pokemon[input - 1].alive)
			{
				#if PROTEUS
					LCD.WriteLine("Not a valid choice!");
				#else
					std::cout << "Not a valid choice!" << std::endl;
				#endif	
			}
			else
			{
				validInput = true;
			}
			input += 7;
		}
	}
	else
	{
		input = pick + 7;
		pick++;
	}
	player->willUseMove = false;

	#if PROTEUS
		LCD.Clear();
	#else
		system("CLS");
	#endif

	return input;
}

//switches the player's active pokemon to its index-th pokemon, called by selectAction (and by useMove upon faint)
void performSwitchAction(Player* player, int index)
{
	player->activePokemon = &(player->pokemon[index]);

	#if PROTEUS
		char s[256];
		sprintf(s, "P%d sw/ to %s!", player->name, player->activePokemon->info.name);
		LCD.WriteLine(s);
	#else
		std::cout << "Player " << player->name << " switched to " << player->activePokemon->info.name << "!" << std::endl;
	#endif

	Sleep(TIME);
};

//performs move of attacker on defender, called by performMoveAction
void useMove(Player* attacker, Player* defender, Move* move)
{
	#if PROTEUS
		char s[256];
		sprintf(s, "%s uses %s!", attacker->activePokemon->info.name, move->info.name);
		LCD.WriteLine(s);
	#else
		std::cout << attacker->activePokemon->info.name << " uses " << move->info.name << "!" << std::endl;
	#endif
	Sleep(TIME);

	performMove(attacker->activePokemon, defender->activePokemon, move);
	#if PROTEUS
		LCD.WriteLine(move->moveResults);
	#else
		sprintf(move->moveResults + std::strlen(move->moveResults)-1, "\0");
		std::cout << move->moveResults << std::endl;
	#endif

	Sleep(TIME);
	for (int i = 0; i < 256; i++)
	{
		move->moveResults[i] = 0;
	}

	if (!defender->activePokemon->alive)
	{
		defender->numAlive--;
		defender->willUseMove = false;
		if (defender->numAlive > 0)
		{
			#if PROTEUS
				char s[256];
				sprintf(s, "\nP%d, switch your Pokemon!", defender->name);
				LCD.WriteLine(s);
			#else
				std::cout << std::endl << "Player " << defender->name << ", change your Pokemon! (vs. " << attacker->activePokemon->info.name << " (" << std::ceil(((attacker->activePokemon->currentHp + 0.0) / attacker->activePokemon->stats.hp) * 100) << "%))" << std::endl;
			#endif

			int input = selectSwitch(defender);
			performSwitchAction(defender, input - 8);
		}
		else
		{
			attacker->won = true;
		}
	}
}

//performs move action of attacker, prints attempted move action and results (damage, status, move failure, etc), called by performActions
void performMoveAction(Player* attacker, Player* defender, Move* move)
{
	if (attacker->willUseMove)
	{
		performBeforeMoveStatus(attacker->activePokemon);
		if (std::strlen(attacker->activePokemon->beforeStatusResults) != 0)
		{
			#if PROTEUS
				LCD.WriteLine(attacker->activePokemon->beforeStatusResults);
			#else
				std::cout << attacker->activePokemon->beforeStatusResults << std::endl;
			#endif
			Sleep(TIME);
		}
		if (!attacker->activePokemon->disabled)
		{
			useMove(attacker, defender, move);
			#if PROTEUS
				LCD.WriteLine("");
			#else
				std::cout << std::endl;
			#endif
		}
	}
}

//performs both players' selected actions, called by battle
void performActions(Player* player1, Player* player2, int input1, int input2)
{
	//performs switches in order and prints the actions, if either or both pokemon are switched out
	if (input1 > 7)
	{
		performSwitchAction(player1, input1 - 8);
	}
	if (input2 > 7)
	{
		performSwitchAction(player2, input2 - 8);
	}
	
	//perform moves in order and prints the actions, if either or both pokemon attempt to use a move
	if (player1->activePokemon->stats.speed*Calculator::statMult1(player1->activePokemon->speedMult) >= player2->activePokemon->stats.speed*Calculator::statMult1(player2->activePokemon->speedMult))
	{
		//player 1 goes first
		if (input1 < 5)
		{
			performMoveAction(player1, player2, &(player1->activePokemon->moves[input1 - 1]));
		}
		if (input2 < 5)
		{
			performMoveAction(player2, player1, &(player2->activePokemon->moves[input2 - 1]));
		}
	}
	else
	{
		//player 2 goes first
		if (input2 < 5)
		{
			performMoveAction(player2, player1, &(player2->activePokemon->moves[input2 - 1]));
		}
		if (input1 < 5)
		{
			performMoveAction(player1, player2, &(player1->activePokemon->moves[input1 - 1]));
		}
	}

	performAfterRoundStatus(player1->activePokemon);
	if (std::strlen(player1->activePokemon->afterStatusResults) != 0)
	{
		#if PROTEUS
			LCD.WriteLine(player1->activePokemon->afterStatusResults);
		#else
			std::cout << player1->activePokemon->afterStatusResults << std::endl;
		#endif

		Sleep(TIME);
	}

	player2->activePokemon->afterStatusResults[0] = '\0';
	performAfterRoundStatus(player2->activePokemon);
	if (std::strlen(player2->activePokemon->afterStatusResults) != 0)
	{
		#if PROTEUS
			LCD.WriteLine(player2->activePokemon->afterStatusResults);
		#else
			std::cout << player2->activePokemon->afterStatusResults << std::endl;
		#endif

		Sleep(TIME);
	}

	player2->activePokemon->afterStatusResults[0] = '\0';
}

//prompts the user to choose a move or switch pokemon, returns the move chosen or the selection action, called by battle
int selectAction(Player* attacker, Player* defender)
{
	int input = 0;
	if (!attacker->isAI)
	{
		bool viewInput = true;
		#if PROTEUS
			char s[256];
			sprintf(s, "P%d, select!\n%s (%d%%)\nvs. %s (%d%%)", attacker->name, attacker->activePokemon->info.name, std::ceil(((attacker->activePokemon->currentHp + 0.0) / attacker->activePokemon->stats.hp) * 100), defender->activePokemon->info.name, std::ceil(((defender->activePokemon->currentHp + 0.0) / defender->activePokemon->stats.hp) * 100));
			LCD.WriteLine(s);
		#else
			std::cout << "Player " << attacker->name << ", select an action!" << std::endl;
			std::cout << std::endl << attacker->activePokemon->info.name << " (" << std::setprecision(0) << std::fixed << std::ceil(((attacker->activePokemon->currentHp + 0.0) / attacker->activePokemon->stats.hp) * 100) << "%)" << " vs. " << defender->activePokemon->info.name << " (" << std::setprecision(0) << std::fixed << std::ceil(((defender->activePokemon->currentHp + 0.0) / defender->activePokemon->stats.hp) * 100) << "%)" << std::endl;
		#endif

		for (int i = 0; i < 4; i++)
		{
			#if PROTEUS
				char s2[256];
				sprintf(s2, "%d: %s   ", i + 1, attacker->activePokemon->moves[i].info.name);
				LCD.WriteLine(s2);
			#else
				std::cout << i + 1 << ": " << attacker->activePokemon->moves[i].info.name << "   ";
			#endif
			if (attacker->activePokemon->moves[i].attack.power != 0)
			{
				#if PROTEUS
					LCD.WriteLine(attacker->activePokemon->moves[i].attack.power);
				#else
					std::cout << attacker->activePokemon->moves[i].attack.power;
				#endif
			}
			#if PROTEUS
				//char s3[256];
				//sprintf(s3, "   %s   %d   %d%%", stringifyType(attacker->activePokemon->moves[i].info.type), attacker->activePokemon->moves[i].info.pp, attacker->activePokemon->moves[i].info.accuracy * 100);
				//LCD.WriteLine(s3);
			#else
				std::cout << "   " << stringifyType(attacker->activePokemon->moves[i].info.type);
				std::cout << "   " << attacker->activePokemon->moves[i].info.pp;
				std::cout << "   " << attacker->activePokemon->moves[i].info.accuracy * 100 << "%";
				std::cout << std::endl;
			#endif
		}
		#if PROTEUS
			LCD.WriteLine("\n5: Change Pokemon");
		#else
			std::cout << std::endl << "5: Change Pokemon" << std::endl;
		#endif
		while (viewInput)
		{
			#if PROTEUS
				input = getInput(7);
			#else
				std::cout << "-->";
				std::cin >> input;
			#endif

			switch (input)
			{
				case 1: case 2: case 3: case 4:
					viewInput = false;
					break;
				case 5:
					#if PROTEUS
						LCD.Clear();
						char s[256];
						sprintf(s, "P%d, switch Pokemon!", attacker->name);
						LCD.WriteLine(s);
					#else
						system("CLS");
						std::cout << "Player " << attacker->name << ", change your Pokemon! (vs. " << defender->activePokemon->info.name << " (" << std::ceil(((defender->activePokemon->currentHp + 0.0) / defender->activePokemon->stats.hp) * 100) << "%))" << std::endl;
					#endif
					input = selectSwitch(attacker);
					viewInput = false;
					break;
				default:
					#if PROTEUS
						LCD.WriteLine("Not valid choice!");
					#else
						std::cout << "Not a valid choice!" << std::endl;
					#endif

					break;
			}
			#if PROTEUS
				LCD.WriteLine("");
			#else
				std::cout << std::endl;
			#endif
		}
	}
	else
	{
		#if PROTEUS
			srand(TimeNow());
		#else
			srand(time(NULL));
		#endif
		input = (rand() % (4)) + 1; //random int between 1 and 4 inclusive
	}
	return input;
}

//runs selection and action for both players until one wins, called by welcome
void battle(Player* player1, Player* player2)
{
	#if MUSIC
		PlaySound(TEXT("fight.wav"), NULL, SND_LOOP | SND_ASYNC);
	#endif

	int input1, input2;

	while (player1->numAlive > 0 && player2->numAlive > 0)
	{
		Sleep(TIME);

		#if PROTEUS
			LCD.Clear();
		#else
			system("CLS");
		#endif

		//assume both players will use move unless told otherwise
		player1->willUseMove = true;
		player2->willUseMove = true;

		input1 = selectAction(player1, player2);

		#if PROTEUS
			LCD.Clear();
		#else
			system("CLS");
		#endif

		input2 = selectAction(player2, player1);

		#if PROTEUS
			LCD.Clear();
		#else
			system("CLS");
		#endif

		performActions(player1, player2, input1, input2);
	}

	if (player1->won)
	{
	#if PROTEUS
		LCD.WriteLine("P1 has won!");
	#else
			std::cout << "Player 1 has won the game!" << std::endl;
	#endif
		wins1++;

		#if MUSIC
				PlaySound(TEXT("victory.wav"), NULL, SND_LOOP | SND_ASYNC);
		#endif
		
		int input;
		bool loop = true;
		loopGame = false;

		while (loop)
		{
			#if PROTEUS
				LCD.WriteLine("1:Play,2:Stats,3:Quit");
				input = getInput(3);
				LCD.Clear();
			#else
				std::cout << "Press 1 to replay, 2 to view stats, 3 to quit-->";
				std::cin >> input;
				system("CLS");
			#endif
			switch (input)
			{
				case 1:
				{
					loop = false;
					pick = 2;
					loopGame = true;
					break;
				}
				case 2:
				{
					#if PROTEUS
						char s[256];
						sprintf(s, "P1: %d wins./nP2: %d wins.", wins1, wins2);
						LCD.WriteLine(s);
					#else
						std::cout << "Player 1: " << wins1 << " wins" << std::endl;
						std::cout << "Player 2: " << wins2 << " wins" << std::endl;
					#endif
					break;
				}
				case 3:
				{
					loop = false;
					loopGame = false;
					break;
				}
			}
		}
	}
	else if (player2->won)
	{
		#if PROTEUS
			LCD.WriteLine("P2 has won!");
		#else
			std::cout << "Player 2 has won the game!" << std::endl;
		#endif
		wins2++;
		#if MUSIC
			PlaySound(TEXT("victory.wav"), NULL, SND_LOOP | SND_ASYNC);
		#endif

		int input;
		bool loop = true;
		loopGame = false;

		while (loop)
		{
			#if PROTEUS
				LCD.WriteLine("1:Play,2:Stats,3:Quit");
				input = getInput(3);
				LCD.Clear();
			#else
				std::cout << "Press 1 to replay, 2 to view stats, 3 to quit-->";
				std::cin >> input;
				system("CLS");
			#endif
			switch (input)
			{
				case 1:
				{
					loop = false;
					pick = 2;
					loopGame = true;
					break;
				}
				case 2:
				{
					#if PROTEUS
						char s[256];
						sprintf(s, "P1: %d wins./nP2: %d wins.", wins1, wins2);
						LCD.WriteLine(s);
					#else
						std::cout << "Player 1: " << wins1 << " wins" << std::endl;
						std::cout << "Player 2: " << wins2 << " wins" << std::endl;
					#endif
					break;
				}
				case 3:
				{
					loop = false;
					loopGame = false;
					break;
				}
			}
		}
	}
}

//prints stats of pokemon, called by selectTeam
void showStats(Pokemon pok)
{
	char space[100];
	sprintf(space, "                                                                                       \r");
	char temp[100];
	sprintf(temp, "                        \r%s ", pok.info.name);
	#if PROTEUS
		char s[256];
		sprintf(s, "%sType(s): %s %s\n%sMoves:   %s, %s\n%s, %s\n\033[A\033[A", space, stringifyType(pok.info.type1), stringifyType(pok.info.type2), space, pok.moves[0].info.name, pok.moves[1].info.name, pok.moves[2].info.name, pok.moves[3].info.name);
		LCD.WriteLine(s);
		LCD.WriteLine(temp);
	#else
		std::cout << std::endl << space << "Type(s): " << stringifyType(pok.info.type1);
		std::cout << " " << stringifyType(pok.info.type2) << std::endl;
		std::cout << space << "Moves:   " << pok.moves[0].info.name << ", " << pok.moves[1].info.name << ", " << pok.moves[2].info.name << ", " << pok.moves[3].info.name << std::endl;
		std::cout << space << "Stats: " << pok.stats.hp << " " << pok.stats.attack << " " << pok.stats.defense << " " << pok.stats.specialAttack << " " << pok.stats.specialDefense << " " << pok.stats.speed;
		std::cout << "\033[A\033[A\033[A\r";
		std::cout << temp;
	#endif
}

//prompts the player to select a team of six pokemon, updates arr to be the selected team, called by welcome
void selectTeam(Pokemon* arr, int player, bool isAI)
{
	if (!isAI)
	{
		int place = 0;
		int totalSelected = 0;
		int input;
	    char team[256];
		for (int i = 0; i < 256; i++)
		{
			team[i] = '\0';
		}
		Pokemon all[NUM_POKEMON] = { Aggron(), Alakazam(), Alex(), Arcanine(), Blissey(), Casey(), Charizard(), Dragonite(), Drapion(), Electivire(), Feraligatr(), Flygon(), Gallade(), Garchomp(), Gengar(), Gyarados(), Kingdra(), Luxray(), Mamoswine(), Metagross(), Milotic(), PorygonZ(), Rhyperior(), Salamence(), Scizor(), Steelix(), Swampert(), Togekiss(), Torterra(), Tyranitar(), Umbreon(), Weavile() };
		
		while (totalSelected < 6)
		{
			#if PROTEUS
				LCD.WriteLine("1:UP,2:DOWN,3:SELECT");
			#else
				std::cout << "1: UP, 2: DOWN, 3: SELECT, 4: UNDO" << std::endl;
			#endif

			#if PROTEUS
				char s[256];
				sprintf(s, "P%d, choose your team!\n%s\n%s ", player, team, all[0].info.name);
				LCD.WriteLine(s);
			#else
				std::cout << "Player " << player << ", choose your six Pokemon!" << std::endl << std::endl;
				std::cout << team << std::endl << std::endl;
				std::cout << all[0].info.name << " ";
			#endif
			showStats(all[place]);

			#if PROTEUS
				input = getInput(5);
				LCD.Clear();
			#else
				std::cin >> input;
				system("CLS");
			#endif

			switch (input)
			{
				case 1:
					if (place > 0)
					{
						place--;
					}
					else
					{
						place = NUM_POKEMON - 1;
					}
					break;
				case 2:
					if (place < NUM_POKEMON - 1)
					{
						place++;
					}
					else
					{
						place = 0;
					}
					break;
				case 3:
					arr[totalSelected] = all[place];
					totalSelected++;

					team[0] = '\0';
					for (int i = 0; i < totalSelected - 1; i++)
					{
						sprintf(team + std::strlen(team), "%s, ", arr[i].info.name);
					}
					sprintf(team + std::strlen(team), "%s", arr[totalSelected - 1].info.name);
					break;
				case 4:
					if (totalSelected > 0)
					{
						totalSelected--;
						team[0] = '\0';
						if (totalSelected > 0)
						{
							for (int i = 0; i < totalSelected - 1; i++)
							{
								sprintf(team + std::strlen(team), "%s, ", arr[i].info.name);
							}
							sprintf(team + std::strlen(team), "%s", arr[totalSelected - 1].info.name);
						}
					}
			}
		}
	}
	else
	{
		arr[0] = Charizard();
		arr[1] = Metagross();
		arr[2] = Torterra();
		arr[3] = Garchomp();
		arr[4] = Gengar();
		arr[5] = Electivire();
	}
}

//prints welcome banner and intiates game, called by main function
void welcome()
{
	#if MUSIC
		PlaySound(TEXT("opening.wav"), NULL, SND_LOOP | SND_ASYNC);
	#endif

	#if PROTEUS
		LCD.WriteLine("Pokemon Battle Simulator!");
		LCD.WriteLine("Each player chooses a move\nor switchs their Pokemon");
		LCD.WriteLine("Faster Pokemon goes first");
		LCD.WriteLine("Moves damage opponents");
		LCD.WriteLine("When a Pokemon loses all\nits HP, it faints");
		LCD.WriteLine("Play until one Player\nhas 0 Pokemon left");
		LCD.WriteLine("1: One Player, 2: Two Player");
	#else			  
		std::cout << "Welcome to Nick & Zach's Pokemon Battle Simulator!" << std::endl;
		std::cout << "(Only for educational use)" << std::endl << std::endl;

		std::cout << "Both players can either choose a move or switch their current Pokemon" << std::endl;
		std::cout << "When both players pick a move, the faster Pokemon goes first" << std::endl;
		std::cout << "Moves damage opponents, and when a Pokemon loses all its health, it faints" << std::endl;
		std::cout << "Certain moves are more effective against different pokemon, like a water move against a fire type" << std::endl;
		std::cout << "A match goes until all six Pokemon on one team faints" << std::endl << std::endl;
		std::cout << "Pokemon Battles are between two teams of 6 Pokemon" << std::endl;
	
		std::cout << "Press 1 for Single Player, 2 for Two Player-->";
	#endif

	int input;
	#if PROTEUS
		input = getInput(2);
		LCD.Clear();
	#else
		std::cin >> input;
		system("CLS");
	#endif
	#if MUSIC
		PlaySound(TEXT("selecting.wav"), NULL, SND_LOOP | SND_ASYNC);
	#endif

	//make player 1
	Pokemon team1[6];
	selectTeam(team1, 1, false);
	Player player1(1, team1, false);
	player1.activePokemon = player1.pokemon;

	//make player 2
	Pokemon team2[6];
	selectTeam(team2, 2, !(input - 1));
	Player player2(2, team2, !(input - 1));
	player2.activePokemon = player2.pokemon;

	#if PROTEUS
		LCD.Clear();
	#else
		system("CLS");
	#endif

	//print teams to the screen
	#if PROTEUS
		//LCD.WriteLine("Team 1: ");
	#else
		std::cout << "Team 1: ";
	#endif
		for (int i = 0; i < 5; i++)
		{
			#if PROTEUS
				//char s[256];
				//sprintf(s, "%s, ", player1.pokemon[i].info.name);
				//LCD.WriteLine(s);
			#else
				std::cout << player1.pokemon[i].info.name << ", ";
			#endif
		}
		#if PROTEUS
			//char s2[256];
			//sprintf(s2, "and %s", player1.pokemon[5].info.name);
			//LCD.WriteLine(s2);
			//LCD.WriteLine("Team 2: ");
		#else
			std::cout << "and " << player1.pokemon[5].info.name << std::endl;
			std::cout << "Team 2: ";
	#endif
	for (int i = 0; i < 5; i++)
	{
		#if PROTEUS
			//char s3[256];
			//sprintf(s3, "%s, ", player2.pokemon[i].info.name);
			//LCD.WriteLine(s3);
		#else
			std::cout << player2.pokemon[i].info.name << ", ";
		#endif
	}
	#if PROTEUS
		//char s4[256];
		//sprintf(s4, "and %s\n", player2.pokemon[5].info.name);
		//LCD.WriteLine(s4);
	#else
		std::cout << "and " << player2.pokemon[5].info.name << std::endl << std::endl;
	#endif

	//start the game
	battle(&player1, &player2);
}

#endif //GAME_H
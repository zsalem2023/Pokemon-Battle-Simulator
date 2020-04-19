#ifndef UTILITY_H
#define UTILITY_H

#if PROTEUS
//prints n buttons on the bottom of the screen, returns the number pressed by the user
int getInput(int n)
{
	// declare icon array called buttons of size n
	FEHIcon::Icon buttons[n];

	// declare strings for icon label
	char labels[6][20] = { "1", "2", "3", "4", "5", "6" };

	// draw icon in a 1 by n array, with top margin of n pixels and bottom, left, and right margins of 5 pixels
	// use labels, and make icon border white and icon text white
	FEHIcon::DrawIconArray(buttons, 1, n, 190, 5, 5, 5, labels, WHITE, WHITE);

	float x, y;
	int input = 0;

	while (input == 0)
	{
		LCD.ClearBuffer();
		while (!LCD.Touch(&x, &y))
		{
		}

		for (int i = 0; i < n; i++)
		{
			if (buttons[i].Pressed(x, y, 0))
			{
				input = i + 1;
			}
		}
	}

	return input;
}
#endif

//returns the lowest of two floats
float lowest(float a, float b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//returns effectiveness (not very, super, etc) of the effectiveness multiplier
char* stringifyEffectiveness(float effectiveness)
{
	static char ans[256];
	effectiveness *= 100;
	int effective = effectiveness;
	switch (effective)
	{
	case 0:
		sprintf(ans, "It has no effect!");
		break;
	case 25: case 50:
		sprintf(ans, "It wasn't very effective...");
		break;
	case 200: case 400:
		sprintf(ans, "It was super effective!");
		break;
	}
	return ans;
}

//returns strength (rose sharply, fell drasitically, etc) of buff/nerf
char* stringifyStrength(int strength)
{
	static char ans[256];
	if (strength > 0)
	{
		sprintf(ans + std::strlen(ans), "rose");
	}
	else
	{
		sprintf(ans + std::strlen(ans), "fell");
	}
	switch (abs(strength))
	{
	case 1:
		sprintf(ans + std::strlen(ans), ".");
		break;
	case 2:
		sprintf(ans + std::strlen(ans), "sharply.");
		break;
	case 3: case 4: case 5: case 6:
		sprintf(ans + std::strlen(ans), "drastically.");
		break;
	}
	return ans;
}

//returns the stat (attack, special defense, etc) of the type
char* stringifyStat(int type)
{
	static char ans[256];
	switch (type)
	{
	case 1:
		sprintf(ans, "attack");
		break;
	case 2:
		sprintf(ans, "defense");
		break;
	case 3:
		sprintf(ans, "special attack");
		break;
	case 4:
		sprintf(ans, "special defense");
		break;
	case 5:
		sprintf(ans, "speed");
		break;
	case 6:
		sprintf(ans, "accuracy");
		break;
	case 7:
		sprintf(ans, "evasiveness");
		break;
	}
	return ans;
}

//returns the name of the type (flying, fighting, etc)
char* stringifyType(int type)
{
	static char ans[256];

	switch (type)
	{
	case 0:
		sprintf(ans, "");
		break;
	case 1:
		sprintf(ans, "NORMAL");
		break;
	case 2:
		sprintf(ans, "FIGHT");
		break;
	case 3:
		sprintf(ans, "FLYING");
		break;
	case 4:
		sprintf(ans, "POISON");
		break;
	case 5:
		sprintf(ans, "GROUND");
		break;
	case 6:
		sprintf(ans, "ROCK");
		break;
	case 7:
		sprintf(ans, "BUG");
		break;
	case 8:
		sprintf(ans, "GHOST");
		break;
	case 9:
		sprintf(ans, "STEEL");
		break;
	case 10:
		sprintf(ans, "FIRE");
		break;
	case 11:
		sprintf(ans, "WATER");
		break;
	case 12:
		sprintf(ans, "GRASS");
		break;
	case 13:
		sprintf(ans, "ELECTR");
		break;
	case 14:
		sprintf(ans, "PSYCHIC");
		break;
	case 15:
		sprintf(ans, "ICE");
		break;
	case 16:
		sprintf(ans, "DRAGON");
		break;
	case 17:
		sprintf(ans, "DARK");
		break;
	}
	return ans;
}

#endif //UTILITY_H
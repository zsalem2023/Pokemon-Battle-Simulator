#ifndef POKEMONSTD_H
#define POKEMONSTD_H

//basic info for each move
class mInfo
{
public:
	char name[256];
	int type;
	int pp;
	float accuracy;

	mInfo() {}
	mInfo(char* name, int type = NULL, int pp = NULL, float accuracy = NULL)
	{
		sprintf(this->name, "%s", name);
		this->type = type;
		this->pp = pp;
		this->accuracy = accuracy;
	}
};

//attack information for certain moves
class mAttack
{
public:
	int power;
	bool physical;

	mAttack(int power = NULL, int physical = NULL)
	{
		this->power = power;
		this->physical = physical;
	}
};

//status information for certain moves
class mStatus
{
public:
	int type;
	float chance;
	bool self;

	mStatus(int type = NULL, float chance = NULL, bool self = NULL)
	{
		this->type = type;
		this->chance = chance;
		this->self = self;
	}
};

//buff information for certain moves
class mBuff
{
public:
	int type[7];
	int strength;
	bool self;
	float chance;

	mBuff() {}
	mBuff(int* type, int strength = NULL, bool self = NULL, float chance = NULL)
	{
		this->strength = strength;
		this->self = self;
		this->chance = chance;

		for (int i = 0; i < 7; i++)
		{
			this->type[i] = type[i];
		}
	}
};

//nerf information for certain moves
class mNerf
{
public:
	int type[7];
	int strength;
	bool self;
	float chance;

	mNerf() {}
	mNerf(int* type, int strength = NULL, bool self = NULL, float chance = NULL)
	{
		for (int i = 0; i < 7; i++)
		{
			this->type[i] = type[i];
		}
		this->strength = strength;
		this->self = self;
		this->chance = chance;
	}
};

//healing information for certain moves
class mHeal
{
public:
	float percentage;

	mHeal(int percentage = NULL)
	{
		this->percentage = percentage;
	}
};

//move that allows pokemon to damage, apply status effects, buff/nerf, etc
class Move
{
public:
	mInfo info;
	mAttack attack;
	mStatus status;
	mBuff buff;
	mNerf nerf;
	mHeal heal;
	char moveResults[256];

	Move(mInfo info = mInfo(), mAttack attack = mAttack(), mStatus status = mStatus(), mBuff buff = mBuff(), mNerf nerf = mNerf(), mHeal heal = mHeal())
	{
		sprintf(this->info.name, "%s", info.name);
		this->info.type = info.type;
		this->info.pp = info.pp;
		this->info.accuracy = info.accuracy;

		this->attack.power = attack.power;
		this->attack.physical = attack.physical;

		this->status.type = status.type;
		this->status.chance = status.chance;
		this->status.self = status.self;

		for (int i = 0; i < 7; i++)
		{
			this->buff.type[i] = buff.type[i];
		}
		this->buff.strength = buff.strength;
		this->buff.self = buff.self;
		this->buff.chance = buff.chance;

		for (int i = 0; i < 7; i++)
		{
			this->nerf.type[i] = nerf.type[i];
		}
		this->nerf.strength = nerf.strength;
		this->nerf.self = nerf.self;
		this->nerf.chance = nerf.chance;

		this->heal.percentage = heal.percentage;

		for (int i = 0; i < 256; i++)
		{
			this->moveResults[i] = 0;
		}
	}
};

//basic info for each pokemon
class Info
{
public:
	char name[256];
	char ability[256];
	int type1;
	int type2;
	int id;

	Info() {}
	Info(char name[256], char ability[256], int type1, int type2, int id = NULL)
	{
		sprintf(this->name, "%s", name);
		sprintf(this->ability, "%s", ability);
		this->type1 = type1;
		this->type2 = type2;
		this->id = id;
	}
};

//stat points for each pokemon
class Stats
{
public:
	int level;
	int hp;
	int attack;
	int defense;
	int specialAttack;
	int specialDefense;
	int speed;

	Stats(int hp = 0, int attack = 0, int defense = 0, int specialAttack = 0, int specialDefense = 0, int speed = 0)
	{
		this->level = 100;

		this->hp = hp;
		this->attack = attack;
		this->defense = defense;
		this->specialAttack = specialAttack;
		this->specialDefense = specialDefense;
		this->speed = speed;
	}
};

//pokemon with info, stats, moves, etc
class Pokemon
{
public:
	bool alive;
	int status;
	int turnsSinceStatus;
	int turnsDisabled;
	bool disabled;
	int currentHp;
	int level;

	char beforeStatusResults[256];
	char afterStatusResults[256];

	int attackMult;
	int defenseMult;
	int specialAttackMult;
	int specialDefenseMult;
	int speedMult;
	int accuracyMult;
	int evasivenessMult;

	Info info;
	Stats stats;
	Move moves[4];

	Pokemon() {}
	Pokemon(Info info, Stats stats, Move* moves)
	{
		for (int i = 0; i < 256; i++)
		{
			this->beforeStatusResults[i] = 0;
			this->afterStatusResults[i] = 0;

		}

		//initializes basic stuff
		sprintf(this->info.name, "%s", info.name);
		sprintf(this->info.ability, "%s", info.ability);
		this->info.type1 = info.type1;
		this->info.type2 = info.type2;
		this->info.id = info.id;

		//initializing stats
		this->stats.hp = stats.hp;
		this->stats.speed = stats.speed;
		this->stats.attack = stats.attack;
		this->stats.defense = stats.defense;
		this->stats.specialAttack = stats.specialAttack;
		this->stats.specialDefense = stats.specialDefense;

		this->attackMult = 0;
		this->defenseMult = 0;
		this->specialAttackMult = 0;
		this->specialDefenseMult = 0;
		this->speedMult = 0;
		this->accuracyMult = 0;
		this->evasivenessMult = 0;

		//initializing moves
		for (int i = 0; i < 4; i++)
		{
			this->moves[i] = moves[i];
		}

		//initializes normal start values
		this->alive = true;
		this->currentHp = this->stats.hp;
		this->status = 0;
		this->turnsSinceStatus = -1;
		this->turnsDisabled = 0;
		this->disabled = false;
		this->level = 100;
	}
};

//contains methods to perform routine game-logic calculations
class Calculator
{
public:
	static int damage(Pokemon attacker, Pokemon defender, Move* move)
	{
		float effectiveAttack, effectiveDefense, STAB, effectiveness, rng, damage, critical;

		if (move->attack.physical)
		{
			effectiveAttack = attacker.stats.attack * Calculator::statMult1(attacker.attackMult);
			effectiveDefense = defender.stats.defense * Calculator::statMult1(defender.defenseMult);
		}
		else
		{
			effectiveAttack = attacker.stats.specialAttack * Calculator::statMult1(attacker.specialAttackMult);
			effectiveDefense = defender.stats.specialDefense * Calculator::statMult1(defender.specialDefenseMult);
		}

		if (move->info.type == attacker.info.type1 || move->info.type == attacker.info.type2)
		{
			STAB = 1.5;
		}
		else
		{
			STAB = 1;
		}

		effectiveness = typeMultiplier(move->info.type, defender.info.type1, defender.info.type2);
		char* effective = stringifyEffectiveness(effectiveness);
		if (std::strcmp(effective, "") != 0)
		{
			//make sure effectiveness hasn't already been added to vector; getting odd error where it adds twice for no reason
			//if (!(find(move->moveResults.begin(), move->moveResults.end(), effective) != move->moveResults.end()))
			//{
			sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", effective);
			//}
		}

		if (Calculator::landed(1.0 / 16.0))
		{
			critical = 2;
			sprintf(move->moveResults + std::strlen(move->moveResults), "A critical hit!\n");
		}
		else
		{
			critical = 1;
		}

		#if PROTEUS
			srand(TimeNow());
		#else
			srand(time(NULL));
		#endif
		rng = (rand() % (100 - 85 + 1)) + 85; // between 85 and 100 inclusive

		damage = critical * ((((2.0 * attacker.level / 5.0 + 2) * effectiveAttack * move->attack.power / effectiveDefense) / 50.0) + 2) * STAB * effectiveness * rng / 100.0;

		return damage;
	};
	static float accuracy(Pokemon attacker, Pokemon defender, Move move)
	{
		return move.info.accuracy * Calculator::statMult2(attacker.accuracyMult) / Calculator::statMult2(defender.evasivenessMult);
	};
	static bool landed(float chance)
	{
		#if PROTEUS
			srand(TimeNow());
		#else
			srand(time(NULL));
		#endif
		float rng = (rand() % (101)) / 100.0;
		return chance >= rng;
	}
	static float statMult1(int multLevel)
	{
		float mult;
		switch (multLevel) {
		case -6:
			mult = 0.25;
			break;
		case -5:
			mult = 0.29;
			break;
		case -4:
			mult = 0.33;
			break;
		case -3:
			mult = 0.40;
			break;
		case -2:
			mult = 0.50;
			break;
		case -1:
			mult = 0.66;
			break;
		case 0:
			mult = 1.00;
			break;
		case 1:
			mult = 1.50;
			break;
		case 2:
			mult = 2.00;
			break;
		case 3:
			mult = 2.50;
			break;
		case 4:
			mult = 3.00;
			break;
		case 5:
			mult = 3.50;
			break;
		case 6:
			mult = 4.00;
			break;
		}
		return mult;
	}
private:
	static float typeMultiplier(int attackType, int defenderType1, int defenderType2)
	{
		return partialTypeMultiplier(attackType, defenderType1) * partialTypeMultiplier(attackType, defenderType2);
	};
	static float partialTypeMultiplier(int attackType, int defenderType)
	{
		float mult = 1;
		switch (attackType)
		{
		case 0:
			mult = 1;
			break;
		case 1: // normal
			switch (defenderType)
			{
			case 6: case 9:
				mult = 0.5;
				break;
			case 8:
				mult = 0;
				break;
			}
			break;
		case 2: // fighting
			switch (defenderType)
			{
			case 1: case 6: case 9: case 15: case 17:
				mult = 2;
				break;
			case 3: case 4: case 7: case 14:
				mult = 0.5;
				break;
			case 8:
				mult = 0;
				break;
			}
			break;
		case 3: // flying
			switch (defenderType)
			{
			case 2: case 7: case 12:
				mult = 2;
				break;
			case 6: case 9: case 13:
				mult = 0.5;
				break;
			}
			break;
		case 4: // poison
			switch (defenderType)
			{
			case 12:
				mult = 2;
				break;
			case 4: case 5: case 6: case 8:
				mult = 0.5;
				break;
			case 9:
				mult = 0;
				break;
			}
			break;
		case 5: // ground
			switch (defenderType)
			{
			case 4: case 6: case 9: case 10: case 13:
				mult = 2;
				break;
			case 7: case 12:
				mult = 0.5;
				break;
			case 3:
				mult = 0;
				break;
			}
			break;
		case 6: // rock
			switch (defenderType)
			{
			case 3: case 7: case 10: case 15:
				mult = 2;
				break;
			case 2: case 5: case 9:
				mult = 0.5;
				break;
			}
			break;
		case 7: // bug
			switch (defenderType)
			{
			case 12: case 14: case 17:
				mult = 2;
				break;
			case 2: case 3: case 4: case 7: case 8: case 9:
				mult = 0.5;
				break;
			}
			break;
		case 8: // ghost
			switch (defenderType)
			{
			case 8: case 14:
				mult = 2;
				break;
			case 9: case 17:
				mult = 0.5;
				break;
			case 1:
				mult = 0;
				break;
			}
			break;
		case 9: // steel
			switch (defenderType)
			{
			case 6: case 15:
				mult = 2;
				break;
			case 9: case 10: case 11: case 13:
				mult = 0.5;
				break;
			}
			break;
		case 10: // fire
			switch (defenderType)
			{
			case 7: case 9: case 12: case 15:
				mult = 2;
				break;
			case 6: case 10: case 11:
				mult = 0.5;
				break;
			}
			break;
		case 11: // water
			switch (defenderType)
			{
			case 5: case 6: case 10:
				mult = 2;
				break;
			case 11: case 12: case 16:
				mult = 0.5;
				break;
			}
			break;
		case 12: // grass
			switch (defenderType)
			{
			case 5: case 6: case 11:
				mult = 2;
				break;
			case 3: case 4: case 7: case 9: case 10: case 12: case 16:
				mult = 0.5;
				break;
			}
			break;
		case 13: // electric
			switch (defenderType)
			{
			case 3: case 11:
				mult = 2;
				break;
			case 12: case 13: case 16:
				mult = 0.5;
				break;
			case 5:
				mult = 0;
				break;
			}
			break;
		case 14: // psychic
			switch (defenderType)
			{
			case 2: case 4:
				mult = 2;
				break;
			case 9: case 14:
				mult = 0.5;
				break;
			case 17:
				mult = 0;
				break;
			}
			break;
		case 15: // ice
			switch (defenderType)
			{
			case 3: case 5: case 6: case 12: case 16:
				mult = 2;
				break;
			case 9: case 10: case 11: case 15:
				mult = 0.5;
				break;
			}
			break;
		case 16: // dragon
			switch (defenderType)
			{
			case 16:
				mult = 2;
				break;
			case 9:
				mult = 0.5;
				break;
			}
			break;
		case 17: // dark
			switch (defenderType)
			{
			case 8: case 14:
				mult = 2;
				break;
			case 2: case 9: case 17:
				mult = 0.5;
				break;
			}
			break;
		}
		return mult;
	};
	static float statMult2(int multLevel)
	{
		float mult;
		switch (multLevel) {
		case -6:
			mult = 0.333;
			break;
		case -5:
			mult = 0.375;
			break;
		case -4:
			mult = 0.43;
			break;
		case -3:
			mult = 0.50;
			break;
		case -2:
			mult = 0.60;
			break;
		case -1:
			mult = 0.75;
			break;
		case 0:
			mult = 1.00;
			break;
		case 1:
			mult = 1.333;
			break;
		case 2:
			mult = 1.667;
			break;
		case 3:
			mult = 2.00;
			break;
		case 4:
			mult = 2.333;
			break;
		case 5:
			mult = 2.667;
			break;
		case 6:
			mult = 3.00;
			break;
		}
		return mult;
	}
};

//workaround: prototype required here
void applyStatus(Pokemon*, Move*);

//contains methods for performing moves
class MoveSteps
{
public:
	static void damage(Pokemon* attacker, Pokemon* defender, Move* move)
	{
		float effectiveAccuracy = Calculator::accuracy(*attacker, *defender, *move);

		if (Calculator::landed(effectiveAccuracy))
		{
			int damage = lowest(Calculator::damage(*attacker, *defender, move), defender->currentHp);
			defender->currentHp -= damage;

			if (defender->currentHp != 0 && damage != 0)
			{
				int d = std::floor((damage * 1.0 / defender->stats.hp) * 100.0);
				char temp[256];
				sprintf(temp, "%s took %d%% damage", defender->info.name, d);
				sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
			}

			if (defender->currentHp == 0 && damage != 0)
			{
				defender->alive = false;
				char temp[256];
				sprintf(temp, "%s fainted!", defender->info.name);
				sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
			}
			else
			{
				int h = std::ceil((defender->currentHp * 1.0 / defender->stats.hp) * 100.0);
				char temp[256];
				sprintf(temp, "%s now has %d%% HP left.", defender->info.name, h);
				sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
			}
		}
		else
		{
			sprintf(move->moveResults + std::strlen(move->moveResults), "But it missed!\n");
		}
	};
	static void heal(Pokemon* target, Move* move)
	{
		if (target->currentHp > 0)
		{
			int heal = lowest((target->stats.hp * move->heal.percentage), (target->stats.hp - target->currentHp));
			target->currentHp += heal;

			char temp[256];
			sprintf(temp, "%s recovered %d health.", target->info.name, heal);
			sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
		}
	};
	static void status(Pokemon* target, Move* move)
	{
		if (target->currentHp > 0)
		{
			if (Calculator::landed(move->status.chance))
			{
				applyStatus(target, move);
			}
		}
	};
	static void buff(Pokemon* target, Move* move)
	{
		if (target->currentHp > 0)
		{
			if (Calculator::landed(move->buff.chance))
			{
				for (int i = 0; i < 7; i++)
				{
					switch (move->buff.type[i])
					{
					case 1:
						target->attackMult += move->buff.strength;
						if (target->attackMult > 6) target->attackMult = 6;
						break;
					case 2:
						target->defenseMult += move->buff.strength;
						if (target->defenseMult > 6) target->defenseMult = 6;
						break;
					case 3:
						target->specialAttackMult += move->buff.strength;
						if (target->specialAttackMult > 6) target->specialAttackMult = 6;
						break;
					case 4:
						target->specialDefenseMult += move->buff.strength;
						if (target->specialDefenseMult > 6) target->specialDefenseMult = 6;
						break;
					case 5:
						target->speedMult += move->buff.strength;
						if (target->speedMult > 6) target->speedMult = 6;
						break;
					case 6:
						target->accuracyMult += move->buff.strength;
						if (target->accuracyMult > 6) target->accuracyMult = 6;
						break;
					case 7:
						target->evasivenessMult += move->buff.strength;
						if (target->evasivenessMult > 6) target->evasivenessMult = 6;
						break;
					}
					if (move->buff.type[i] != 0)
					{
						char temp[256];
						sprintf(temp, "%s's %s %s", target->info.name, stringifyStat(move->buff.type[i]), stringifyStrength(move->buff.strength));
						sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
					}
				}
			}
		}
	};
	static void nerf(Pokemon* target, Move* move)
	{
		if (target->currentHp > 0)
		{
			if (Calculator::landed(move->nerf.chance))
			{
				for (int i = 0; i < 7; i++)
				{
					switch (move->nerf.type[i])
					{
					case 1:
						target->attackMult -= move->nerf.strength;
						if (target->attackMult < -6) target->attackMult = -6;
						break;
					case 2:
						target->defenseMult -= move->nerf.strength;
						if (target->defenseMult < -6) target->defenseMult = -6;
						break;
					case 3:
						target->specialAttackMult -= move->nerf.strength;
						if (target->specialAttackMult < -6) target->specialAttackMult = -6;
						break;
					case 4:
						target->specialDefenseMult -= move->nerf.strength;
						if (target->specialDefenseMult < -6) target->specialDefenseMult = -6;
						break;
					case 5:
						target->speedMult -= move->nerf.strength;
						if (target->speedMult < -6) target->speedMult = -6;
						break;
					case 6:
						target->accuracyMult -= move->nerf.strength;
						if (target->accuracyMult < -6) target->accuracyMult = -6;
						break;
					case 7:
						target->evasivenessMult -= move->nerf.strength;
						if (target->evasivenessMult < -6) target->evasivenessMult = -6;
						break;
					}
					if (move->nerf.type[i] != 0)
					{
						char temp[256];
						sprintf(temp, "%s's %s %s", target->info.name, stringifyStat(move->nerf.type[i]), stringifyStrength(move->nerf.strength));
						sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
					}
				}
			}
		}
	};
};

//workaround: temp move required here
Move tempMove = Move(mInfo((char*)"Confused", 0, 1, 1.0), mAttack(40, 1));

//contains methods for applying and evaluating status effects
class StatusSteps
{
public:
	static void damage(Pokemon* target, int eighths)
	{
		target->currentHp -= eighths / 8.0 * target->stats.hp;
		if (target->currentHp <= 0) {
			target->currentHp = 0;
			target->alive = false;
		}

	};
	static void disable(Pokemon* target, float chance)
	{
		if (Calculator::landed(chance))
		{
			target->disabled = true;
		}
	};
	static void nerf(Pokemon* target, int type, int strength)
	{
		switch (type)
		{
		case 1:
			target->attackMult -= strength;
			if (target->attackMult < -6) target->attackMult = -6;
			break;
		case 12:
			target->defenseMult -= strength;
			if (target->defenseMult < -6) target->defenseMult = -6;
			break;
		case 3:
			target->specialAttackMult -= strength;
			if (target->specialAttackMult < -6) target->specialAttackMult = -6;
			break;
		case 4:
			target->specialDefenseMult -= strength;
			if (target->specialDefenseMult < -6) target->specialDefenseMult = -6;
			break;
		case 5:
			target->speedMult -= strength;
			if (target->speedMult < -6) target->speedMult = -6;
			break;
		case 6:
			target->accuracyMult -= strength;
			if (target->accuracyMult < -6) target->accuracyMult = -6;
			break;
		case 7:
			target->evasivenessMult -= strength;
			if (target->evasivenessMult < -6) target->evasivenessMult = -6;
			break;
		}
	};
	static void escapeStatus(Pokemon* target, float chance)
	{
		if (Calculator::landed(chance))
		{
			target->status = 0;
		}
	};
	static void setDisabledTurns(Pokemon* target, int max)
	{
		#if PROTEUS
			srand(TimeNow());
		#else
			srand(time(NULL));
		#endif
		target->turnsDisabled = rand() % max + 1;
	};
	static void updateStatus(Pokemon* target)
	{
		switch (target->status)
		{
		case 0:
			target->disabled = 0;
			target->turnsDisabled = 0;
			target->turnsSinceStatus = -1;
			break;
		case 5:
			target->disabled = true;
			break;
		case 8:
			if (target->disabled)
			{
				MoveSteps::damage(target, target, &tempMove);
			}
			break;
		}
	};
	static void passTurn(Pokemon* target)
	{
		if (target->status != 0)
		{
			target->turnsSinceStatus++;
			if (target->turnsDisabled <= target->turnsSinceStatus)
			{
				target->disabled = false;
				target->status = 0;
			}
		}
	};
};

//applies the status to the target, if they don't already have one, called by MoveSteps::status
void applyStatus(Pokemon* target, Move* move)
{
	if (!((target->info.type1 == 9 || target->info.type2 == 9) && (move->status.type == 2 || move->status.type == 3)) && target->status == 0)
	{
		target->status = move->status.type;
		target->turnsSinceStatus = 0;
	}
	char temp[256];
	switch (move->status.type)
	{
	case 1:
		StatusSteps::nerf(target, 5, 1);
		sprintf(temp, "%s was paralyzed!", target->info.name);
		sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
		break;
	case 2:
		sprintf(temp, "%s was poisoned!", target->info.name);
		sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
		break;
	case 3:
		sprintf(temp, "%s was badly poisoned!", target->info.name);
		sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
		break;
	case 4:
		StatusSteps::nerf(target, 1, 2);
		sprintf(temp, "%s was burned!", target->info.name);
		sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
		break;
	case 5:
		sprintf(temp, "%s was frozen!", target->info.name);
		sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
		break;
	case 6:
		StatusSteps::setDisabledTurns(target, 5);
		sprintf(temp, "%s fell asleep!", target->info.name);
		sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
		break;
	case 7:
		StatusSteps::disable(target, 1.0);
		break;
	case 8:
		StatusSteps::setDisabledTurns(target, 4);
		sprintf(temp, "%s became confused!", target->info.name);
		sprintf(move->moveResults + std::strlen(move->moveResults), "%s\n", temp);
		break;
	}
}

//performs pre-move status effect on target, updates target.beforeStatusResults with results of the status, called at the start of performMoveAction during each turn
void performBeforeMoveStatus(Pokemon* target)
{
	char temp[256];
	switch (target->status)
	{
	case 1:
		StatusSteps::disable(target, 0.25);
		StatusSteps::updateStatus(target);
		sprintf(temp, "%s is paralyzed and couldn't move!", target->info.name);
		if (target->disabled) sprintf(target->beforeStatusResults + std::strlen(target->beforeStatusResults), "%s\n", temp);
		break;
	case 5:
		StatusSteps::escapeStatus(target, 0.20);
		StatusSteps::updateStatus(target);
		if (target->disabled) sprintf(temp, "%s is frozen!", target->info.name);
		if (target->status == 0) sprintf(temp, "%s thawed out!", target->info.name);
		if (target->disabled || target->status == 0) sprintf(target->beforeStatusResults + std::strlen(target->beforeStatusResults), "%s\n", temp);
		break;
	case 6:
		StatusSteps::updateStatus(target);
		if (target->disabled) sprintf(temp, "%s is alseep!", target->info.name);
		if (target->status == 0) sprintf(temp, "%s woke up!", target->info.name);
		if (target->disabled || target->status == 0) sprintf(target->beforeStatusResults + std::strlen(target->beforeStatusResults), "%s\n", temp);
		break;
	case 7:
		StatusSteps::disable(target, 1);
		StatusSteps::updateStatus(target);
		sprintf(temp, "%s flinched!", target->info.name);
		if (target->disabled) sprintf(target->beforeStatusResults + std::strlen(target->beforeStatusResults), "%s\n", temp);
		break;
	case 8:
		StatusSteps::disable(target, 0.50);
		StatusSteps::updateStatus(target);
		sprintf(temp, "%s hurt itself in confusion!", target->info.name);
		if (target->disabled) sprintf(target->beforeStatusResults + std::strlen(target->beforeStatusResults), "%s\n", temp);
		break;
	}
}

//performs post-round status effect on target, updates target.afterStatusResults with results of the status, called by performActions at end of each round
void performAfterRoundStatus(Pokemon* target)
{
	char temp3[256];
	StatusSteps::passTurn(target);
	switch (target->status)
	{
	case 2:
		sprintf(temp3, "%s took 12% damage from poison!", target->info.name);
		sprintf(target->afterStatusResults + std::strlen(target->afterStatusResults), "%s\n", temp3);
		StatusSteps::damage(target, 1);
		break;
	case 3:
		sprintf(temp3, "%s took %d%% damage from poison!", target->info.name, (std::floor(target->turnsSinceStatus / 8.0 * 100.0)));
		sprintf(target->afterStatusResults + std::strlen(target->afterStatusResults), "%s\n", temp3);
		StatusSteps::damage(target, target->turnsSinceStatus);
		break;
	case 4:
		sprintf(temp3, "%s took 12% damage from burn!", target->info.name);
		sprintf(target->afterStatusResults + std::strlen(target->afterStatusResults), "%s\n", temp3);
		StatusSteps::damage(target, 1);
		break;
	}
}

//executes the attacker's move on the defender, updates move.moveResults with results of move, called at the end of performMoveAction during each turn
void performMove(Pokemon* attacker, Pokemon* defender, Move* move)
{
	move->info.pp--;
	if (move->attack.power != NULL)
	{
		MoveSteps::damage(attacker, defender, move);
	}
	if (move->status.chance != NULL)
	{
		if (move->status.self)
		{
			MoveSteps::status(attacker, move);
		}
		else
		{
			MoveSteps::status(defender, move);
		}
	}
	if (move->buff.self != NULL)
	{
		if (move->buff.self)
		{
			MoveSteps::buff(attacker, move);
		}
		else
		{
			MoveSteps::buff(defender, move);
		}
	}
	if (move->nerf.self != NULL)
	{
		if (move->nerf.self)
		{
			MoveSteps::nerf(attacker, move);
		}
		else
		{
			MoveSteps::nerf(defender, move);
		}
	}
	if (move->heal.percentage != NULL)
	{
		MoveSteps::heal(attacker, move);
	}
}

//player of the game with six pokemon
class Player
{
public:
	Pokemon pokemon[6];
	Pokemon* activePokemon;
	int name;
	bool isAI;
	int numAlive;
	bool willUseMove;
	bool won;

	//player constructor
	Player(int name, Pokemon _pokemon[], bool isAI = false)
	{
		this->name = name;
		for (int i = 0; i < 6; i++)
		{
			pokemon[i] = _pokemon[i];
		}

		activePokemon = _pokemon;

			this->isAI = isAI;
			this->numAlive = 6;
			this->willUseMove = true;
			this->won = false;
		}
};

#endif //POKEMONSTD_H
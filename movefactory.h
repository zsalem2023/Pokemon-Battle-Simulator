#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H

//Alphabetically ordered Pokemon moves

//a
Move AerialAce()
{
	return Move(mInfo((char*)"Aerial Ace", 3, 32, 100.0), mAttack(60, true));
}
Move Agility()
{
	int buffTypes[7] = { 0,0,0,0,5,0,0 };
	return Move(mInfo((char*)"Agility", 14, 48, 1), mAttack(), mStatus(), mBuff(buffTypes, 2, true, 1.0));
}
Move AirSlash()
{
	return Move(mInfo((char*)"Air Slash", 3, 24, 0.95), mAttack(75, false), mStatus(7, 0.3, false));
}
Move AquaTail()
{
	return Move(mInfo((char*)"Aqua Tail", 11, 16, 0.9), mAttack(90, true));
}
Move Avalanche()
{
	return Move(mInfo((char*)"Avalanche", 17, 16, 1.0), mAttack(60, true));
}
//b
Move BodySlam()
{
	return Move(mInfo((char*)"Body Slam", 1, 24, 1.0), mAttack(85, true), mStatus(1, 0.3, false));
}
Move BrickBreak()
{
	return Move(mInfo((char*)"Brick Break", 2, 24, 1.0), mAttack(75, true));
}
Move Bite()
{
	return Move(mInfo((char*)"Bite", 17, 40, 1.0), mAttack(60, true), mStatus(7, 0.3, false));
}
//c
Move CloseCombat()
{
	int nerfTypes[7] = { 0,2,0,4,0,0,0 };
	return Move(mInfo((char*)"Close Combat", 2, 8, 1.0), mAttack(120, true), mStatus(), mBuff(), mNerf(nerfTypes, 1, true, 1.0));
}
Move CrossPoison()
{
	return Move(mInfo((char*)"Cross Poison", 4, 32, 1.0), mAttack(70, true), mStatus(2, 0.1, false));
}
Move Crunch()
{
	int nerfTypes[7] = { 0,0,0,4,0,0,0 };
	return Move(mInfo((char*)"Crunch", 15, 24, 1.0), mAttack(80, true), mStatus(), mBuff(), mNerf(nerfTypes, 1, false, 0.2));
}
Move ConfuseRay()
{
	return Move(mInfo((char*)"Confuse Ray", 8, 16, 1.0), mAttack(), mStatus(8,1.0,false));
}
//d
Move DarkPulse()
{
	return Move(mInfo((char*)"Dark Pulse", 17, 24, 1.0), mAttack(80, false), mStatus(2, 0.2, false));
}
Move DoubleEdge()
{
	return Move(mInfo((char*)"Double Edge", 1, 16, 1.0), mAttack(120, true));
}
Move DragonClaw()
{
	return Move(mInfo((char*)"Dragon Claw", 16, 24, 1.0), mAttack(80, true));
}
Move DragonDance()
{
	int buffTypes[7] = { 1,0,0,0,5,0,0 };
	return Move(mInfo((char*)"Dragon Dance", 16, 32, 1.0), mAttack(), mStatus(), mBuff(buffTypes, 1, true, 1.0));
}
Move DragonPulse()
{
	return Move(mInfo((char*)"Dragon Pulse", 16, 16, 1.0), mAttack(85, false));
}
Move DragonRush()
{
	return Move(mInfo((char*)"Dragon Rush", 16, 16, 0.8), mAttack(100, true), mStatus(7, 0.2, false));
}
//e
Move Earthquake()
{
	return Move(mInfo((char*)"Earthquake", 5, 10, 1.0), mAttack(100, true));
}
Move EnergyBall()
{
	int nerfTypes[7] = { 0,0,0,4,0,0,0 };
	return Move(mInfo((char*)"Energy Ball", 12, 16, 1.0), mAttack(90, false), mStatus(), mBuff(), mNerf(nerfTypes, 1, false, 0.2));
}
//f
Move FireBlast()
{
	return Move(mInfo((char*)"Fire Blast", 10, 8, 0.85), mAttack(110, false), mStatus(4, 0.2, false));
}
Move FireFang()
{
	return Move(mInfo((char*)"Fire Fang", 10, 24, 0.95), mAttack(65, true), mStatus(4, 0.1, false));
}
Move FirePunch()
{
	return Move(mInfo((char*)"Fire Punch", 10, 24, 1.0), mAttack(75, true), mStatus(4, 0.1, false));
}
Move FixCode()
{
	return Move(mInfo((char*)"Fix Code", 1, 16, 1.0), mAttack(), mStatus(8, 1.0, false));
}
Move Flamethrower()
{
	return Move(mInfo((char*)"Flamethrower", 10, 24, 1.0), mAttack(90, false), mStatus(4, 0.1, 0));
}
//g
//h
//b
Move HarshGrading()
{
	return Move(mInfo((char*)"Harsh Grading", 1, 24, 1.0), mAttack(100, true));
}
Move HydroPump()
{
	return Move(mInfo((char*)"Hydro Pump", 11, 8, 0.8), mAttack(110, false));
}
//i
Move IceBeam()
{
	return Move(mInfo((char*)"Ice Beam", 15, 16, 1.0), mAttack(90, false), mStatus(5, 0.1, false));
}
Move IcePunch()
{
	return Move(mInfo((char*)"Ice Punch", 15, 24, 1.0), mAttack(75, true), mStatus(5, 0.1, false));
}
Move IronHead()
{
	return Move(mInfo((char*)"Iron Head", 9, 24, 1.0), mAttack(80, true), mStatus(7, 0.3, false));
}
//j
Move JournalPresentation()
{
	return Move(mInfo((char*)"Journal Presentation", 1, 16, 1.0), mAttack(), mStatus(6, 1.0, false));
}
//j
//l
//m
Move Megahorn()
{
	return Move(mInfo((char*)"Megahorn", 7, 16, 0.85), mAttack(120, true));
}
Move MeteorMash()
{
	int buffTypes[7] = { 1,0,0,0,0,0,0 };
	return Move(mInfo((char*)"Meteor Mash", 9, 24, 0.9), mAttack(80, true), mStatus(), mBuff(buffTypes, 1, true, 0.2));
}
//n
Move NightSlash()
{
	return Move(mInfo((char*)"Night Slash", 17, 24, 1.0), mAttack(70, true));
}
//o
//p
Move Psychic()
{
	int nerfTypes[7] = { 0,0,0,4,0,0,0 };
	return Move(mInfo((char*)"Psychic", 14, 16, 1.0), mAttack(90, false), mStatus(), mBuff(), mNerf(nerfTypes, 1, false, 0.1));
}
Move PsychoCut()
{
	return Move(mInfo((char*)"Psycho Cut", 14, 32, 1.0), mAttack(70, true));
}
//q
//r
//s
Move ShadowBall()
{
	int nerfTypes[7] = { 0,0,0,4,0,0,0 };
	return Move(mInfo((char*)"Shadow Ball", 8, 24, 1.0), mAttack(80, false), mStatus(), mBuff(), mNerf(nerfTypes, 1, false, 0.2));
}
Move SignalBeam()
{
	return Move(mInfo((char*)"Signal Beam", 7, 16, 1.0), mAttack(85, false), mStatus(8, 0.1, false));
}
Move SludgeBomb()
{
	return Move(mInfo((char*)"Sludge Bomb", 4, 16, 1.0), mAttack(90, false), mStatus(2, 0.3, false));
}
Move StoneEdge()
{
	return Move(mInfo((char*)"Stone Edge", 6, 8, 0.8), mAttack(100, true));
}
Move Superpower()
{
	int nerfTypes[7] = { 1,2,0,0,0,0,0 };
	return Move(mInfo((char*)"Superpower", 2, 8, 1.0), mAttack(120, true), mStatus(), mBuff(), mNerf(nerfTypes, 1, true, 1.0));
}
Move SwordsDance()
{
	int buffTypes[7] = { 1,0,0,0,0,0,0 };
	return Move(mInfo((char*)"Swords Dance", 1, 8, 1), mAttack(), mStatus(), mBuff(buffTypes, 2, true, 1.0));
}
//t
Move Thunderbolt()
{
	return Move(mInfo((char*)"Thunderbolt", 13, 24, 1.0), mAttack(90, false), mStatus(1, 0.1, 0));
}
Move ThunderPunch()
{
	return Move(mInfo((char*)"Thunder Punch", 13, 24, 1.0), mAttack(75, true), mStatus(1, 0.1, false));
}
Move Toxic()
{
	return Move(mInfo((char*)"Toxic", 4, 16, 0.9), mAttack(), mStatus(3, 1.0, false));
}
//u
//v
//w
Move WoodHammer()
{
	return Move(mInfo((char*)"Wood Hammer", 12, 24, 1.0), mAttack(120, true), mStatus(), mBuff(), mNerf(), mHeal(-0.33));
}
//x
Move XScissor()
{
	return Move(mInfo((char*)"X-Scissor", 7, 24, 1.0), mAttack(80, true));
}
//y
//z
Move ZenHeadbutt()
{
	return Move(mInfo((char*)"Zen Headbutt", 14, 24, 0.9), mAttack(80, true), mStatus(7, 0.2, false));
}

#endif //MOVEFACTORY_H
#ifndef POKEMONFACTORY_H
#define POKEMONFACTORY_H

//Alphabetically ordered Pokemon, with Pokedex number for reference

//306
Pokemon Aggron()
{
	Move Moves[4] = { Earthquake(), IronHead(), BrickBreak(), StoneEdge() };
	return Pokemon(Info((char*)"Aggron", (char*)"", 9, 6), Stats(281, 256, 396, 156, 156, 136), Moves);
}

//065
Pokemon Alakazam()
{
	Move Moves[4] = { Psychic(), ShadowBall(), EnergyBall(), SignalBeam() };
	return Pokemon(Info((char*)"Alakazam", (char*)"Synchronize", 14, 0, 65), Stats(251, 136, 126, 306, 226, 276), Moves);
}

//???
Pokemon Alex()
{
	Move Moves[4] = { HarshGrading(), JournalPresentation(), FixCode(), BodySlam() };
	return Pokemon(Info((char*)"Alex", (char*)"", 1, 0), Stats(999, 999, 999, 999, 999, 999), Moves);
}

//059
Pokemon Arcanine()
{
	Move Moves[4] = { FireFang(), BodySlam(), CloseCombat(), DoubleEdge() };
	return Pokemon(Info((char*)"Arcanine", (char*)"", 10, 0), Stats(321, 256, 196, 236, 196, 226), Moves);
}

//242
Pokemon Blissey()
{
	Move Moves[4] = { BrickBreak(), DoubleEdge(), Earthquake(), FirePunch() };
	return Pokemon(Info((char*)"Blissey", (char*)"", 1, 0), Stats(651, 56, 56, 186, 306, 146), Moves);
}

//???
Pokemon Casey()
{
	Move Moves[4] = { HarshGrading(), JournalPresentation(), FixCode(), Earthquake() };
	return Pokemon(Info((char*)"Casey", (char*)"", 1, 0), Stats(999, 999, 999, 999, 999, 999), Moves);
}

//006
Pokemon Charizard()
{
	Move Moves[4] = { Flamethrower(), AirSlash(), DragonPulse(), FireBlast() };
	return Pokemon(Info((char*)"Charizard", (char*)"Blaze", 10, 3, 6), Stats(297, 204, 192, 254, 206, 236), Moves);
}

//149
Pokemon Dragonite()
{
	Move Moves[4] = { DragonClaw(), DragonDance(), Earthquake(), FirePunch() };
	return Pokemon(Info((char*)"Dragonite", (char*)"Inner Focus", 16, 3, 149), Stats(323, 304, 226, 236, 236, 196), Moves);
}

//452
Pokemon Drapion()
{
	Move Moves[4] = { Crunch(), XScissor(), CrossPoison(), BrickBreak() };
	return Pokemon(Info((char*)"Drapion", (char*)"", 4, 17), Stats(281, 216, 256, 156, 186, 226), Moves);
}

//466
Pokemon Electivire()
{
	Move Moves[4] = { ThunderPunch(), IcePunch(), FirePunch(), BrickBreak() };
	return Pokemon(Info((char*)"Electivire", (char*)"Motor Drive", 13, 0, 466), Stats(291, 282, 170, 226, 206, 226), Moves);
}

//160
Pokemon Feraligatr()
{
	Move Moves[4] = { AquaTail(), BrickBreak(), Crunch(), DragonDance() };
	return Pokemon(Info((char*)"Feraligatr", (char*)"", 11, 0), Stats(311, 246, 236, 194, 202, 192), Moves);
}

//330
Pokemon Flygon()
{
	Move Moves[4] = { Earthquake(), DragonClaw(), FirePunch(), StoneEdge() };
	return Pokemon(Info((char*)"Flygon", (char*)"", 5, 16), Stats(301, 236, 196, 196, 196, 236), Moves);
}

//475
Pokemon Gallade()
{
	Move Moves[4] = { CloseCombat(), Earthquake(), FirePunch(), PsychoCut() };
	return Pokemon(Info((char*)"Gallade", (char*)"Steadfast", 14, 2), Stats(277, 286, 166, 166, 266, 196), Moves);
}

//445
Pokemon Garchomp()
{
	Move Moves[4] = { Earthquake(), DragonRush(), StoneEdge(), SwordsDance() };
	return Pokemon(Info((char*)"Garchomp", (char*)"Sand Veil", 16, 5, 445), Stats(357, 296, 226, 196, 206, 240), Moves);
}

//094
Pokemon Gengar()
{
	Move Moves[4] = { ShadowBall(), Toxic(), DarkPulse(), SludgeBomb() };
	return Pokemon(Info((char*)"Gengar", (char*)"Cursed Body", 8, 4, 94), Stats(261, 166, 156, 296, 186, 256), Moves);
}

//130
Pokemon Gyarados()
{
	Move Moves[4] = { AquaTail(), Avalanche(), Crunch(), DragonDance() };
	return Pokemon(Info((char*)"Gyarados", (char*)"", 11, 3), Stats(331, 286, 194, 156, 236, 198), Moves);
}

//230
Pokemon Kingdra()
{
	Move Moves[4] = { HydroPump(), IceBeam(), SignalBeam(), Agility() };
	return Pokemon(Info((char*)"Kingdra", (char*)"Swift Swim", 11, 16, 230), Stats(291, 226, 226, 226, 226, 206), Moves);
}

//405
Pokemon Luxray()
{
	Move Moves[4] = { Thunderbolt(), FireFang(), Crunch(), SignalBeam() };
	return Pokemon(Info((char*)"Luxray", (char*)"", 13, 0), Stats(301, 276, 194, 226, 194, 176), Moves);
}

//473
Pokemon Mamoswine()
{
	Move Moves[4] = { Avalanche(), Earthquake(), StoneEdge(), DoubleEdge() };
	return Pokemon(Info((char*)"Mamoswine", (char*)"", 15, 5), Stats(361, 296, 196, 176, 156, 196), Moves);
}

//376
Pokemon Metagross()
{
	Move Moves[4] = { Earthquake(), ZenHeadbutt(), MeteorMash(), IcePunch() };
	return Pokemon(Info((char*)"Metagross", (char*)"Clear Body", 9, 14, 376), Stats(301, 306, 296, 226, 216, 176), Moves);
}

//350
Pokemon Milotic()
{
	Move Moves[4] = { HydroPump(), IceBeam(), DragonPulse(), Toxic() };
	return Pokemon(Info((char*)"Milotic", (char*)"Marvel Scale", 11, 0), Stats(331, 156, 194, 236, 286, 198), Moves);
}

//474
Pokemon PorygonZ()
{
	Move Moves[4] = { Thunderbolt(), IceBeam(), Psychic(), SignalBeam() };
	return Pokemon(Info((char*)"Porygon-Z", (char*)"", 1, 0), Stats(311, 196, 176, 306, 186, 216), Moves);
}

//464
Pokemon Rhyperior()
{
	Move Moves[4] = { Earthquake(), StoneEdge(), BrickBreak(), Megahorn() };
	return Pokemon(Info((char*)"Rhyperior", (char*)"Lightning Rod", 5, 6), Stats(371, 316, 296, 146, 146, 116), Moves);
}

//373
Pokemon Salamence()
{
	Move Moves[4] = { Crunch(), Earthquake(), DragonClaw(), BrickBreak() };
	return Pokemon(Info((char*)"Salamence", (char*)"Intimidate", 16, 3), Stats(331, 306, 196, 256, 196, 236), Moves);
}

//212
Pokemon Scizor()
{
	Move Moves[4] = { IronHead(), NightSlash(), XScissor(), AerialAce() };
	return Pokemon(Info((char*)"Scizor", (char*)"Swarm", 9, 7, 212), Stats(281, 296, 236, 146, 196, 166), Moves);
}

//208
Pokemon Steelix()
{
	Move Moves[4] = { Earthquake(), AquaTail(), FireFang(), DoubleEdge() };
	return Pokemon(Info((char*)"Steelix", (char*)"", 9, 5), Stats(291, 206, 436, 146, 166, 96), Moves);
}

//260
Pokemon Swampert()
{
	Move Moves[4] = { AquaTail(), IcePunch(), Earthquake(), StoneEdge() };
	return Pokemon(Info((char*)"Swampert", (char*)"Torrent", 11, 5), Stats(341, 256, 216, 206, 216, 156), Moves);
}

//468
Pokemon Togekiss()
{
	Move Moves[4] = { AirSlash(), DoubleEdge(), Flamethrower(), SignalBeam() };
	return Pokemon(Info((char*)"Togekiss", (char*)"", 3, 0), Stats(311, 136, 226, 276, 266, 196), Moves);
}

//389
Pokemon Torterra()
{
	Move Moves[4] = { Earthquake(), StoneEdge(), WoodHammer(), Superpower() };
	return Pokemon(Info((char*)"Torterra", (char*)"", 12, 5, 389), Stats(331, 254, 246, 186, 206, 148), Moves);
}

//248
Pokemon Tyranitar()
{
	Move Moves[4] = { IcePunch(), Crunch(), StoneEdge(), ThunderPunch() };
	return Pokemon(Info((char*)"Tyranitar", (char*)"Sand Stream", 6, 17, 248), Stats(341, 304, 256, 226, 236, 158), Moves);
}

//197
Pokemon Umbreon()
{
	Move Moves[4] = { Bite(), ConfuseRay(), DoubleEdge(), Toxic() };
	return Pokemon(Info((char*)"Umbreon", (char*)"", 17, 0), Stats(331, 166, 256, 156, 296, 166), Moves);
}

//461
Pokemon Weavile()
{
	Move Moves[4] = { IcePunch(), NightSlash(), BrickBreak(), XScissor() };
	return Pokemon(Info((char*)"Weavile", (char*)"Pressure", 17, 15, 461), Stats(281, 276, 166, 126, 206, 286), Moves);
}

#endif //POKEMONFACTORY_H
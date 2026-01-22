#pragma once
#include "Npc.h"
using namespace std;
class Evils : virtual public Npc
{
protected:
	string boss_spells[3] = { "ядовитая лужа","смертоносная лужа", "каскад боли" };
public:
	Evils();
	Evils(string n, int h, float d);
};
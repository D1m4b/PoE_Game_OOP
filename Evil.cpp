#pragma once
#include "Evil.h"
Evils::Evils() : Evils("Мевина", 850, 520)
{
	cout << "Заспавнился ГЛАВНЫЙ БОСС! - МЕЙВЕН! - " << endl;
}
Evils::Evils(string n, int h, float d)
{
	name = n;
	health = h;
	damage = d;
}

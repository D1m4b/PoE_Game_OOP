#pragma once
#include "Npc.h"
#include "Champion.h"
#include "Occultist.h"
class Guardian : public Champion, public Occultist {
protected:
	string auras[3]{ "решимость","дисциплина","злорадство" };
public:
	Guardian();
	Guardian(string name, unsigned int health, float damage);
	void GetInfo() override;
	void GetWeapons() override;
	void Create() override;
	void LevelUp() override;
	void UseAbility() override;
	~Guardian();
};
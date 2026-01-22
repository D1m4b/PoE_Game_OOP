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
	void CastAuras();
	void Create() override;
	~Guardian();
};
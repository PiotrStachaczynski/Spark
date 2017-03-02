#pragma once
#include "engine.h"
class NextLvl :
	public Engine
{
	
public:
	NextLvl(void);
	~NextLvl(void);
	void playGameLvL(int score,int ammo,sf::Text Lives,sf::Vector3i mana ,int force,sf::Clock Animuj);
};


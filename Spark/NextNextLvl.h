#pragma once
#include "engine.h"
#include "Score.h"
class NextNextLvl :
	public Engine
{
private:
Score p;
public:


	NextNextLvl(void);
	~NextNextLvl(void);
	void playGameLvLNext(int score,int ammo,sf::Text Lives,sf::Vector3i mana,int force,sf::Clock Animuj);
};


#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h";
#include "Item.h"
#include "Enemy.h"
#include "MainMenu.h"
class Engine
{
protected:
	Player player;
private:
	Item item;
	Enemy enemy;

public:
	MainMenu Ex;
	sf::Clock Animuj;
	Engine();
	~Engine(void);
	void playGame();
	
};


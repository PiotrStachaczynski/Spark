#pragma once
#include "mainmenu.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
 #include <sstream>
#include <SFML/Audio.hpp>
 


class Score :
	public MainMenu
{
private:
	
public:
	Score(void);
	~Score(void);
	void Save(int score,float time, int ammo);
	void zapisz(sf::Text k, float p);
	void Odczyt();
	
};



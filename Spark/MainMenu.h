#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"

using namespace std;

class MainMenu
{
private:
Game restart;	
public:
	MainMenu(void);
	~MainMenu(void);
	void RunMenu();
	void RunStettigs();
	void Esc(sf::RenderWindow & Okno);
};
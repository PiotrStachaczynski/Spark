#include "Game.h"
#include "Animation.h"
#include "MainMenu.h"
#include "Engine.h";
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "NextNextLvl.h"
using namespace sf;

using namespace std;
Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::runGame()
{  
	sf::Text k;
	k.setString("trala");
	MainMenu menu;
	Engine engine;
	menu.RunMenu();
	//engine.playGame();



}

void Game::RunLvl()
{
	Engine engine;
	//menu.RunMenu();
	engine.playGame();
}
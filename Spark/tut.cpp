#include "tut.h"
#include "Engine.h"


tut::tut(void)
{
}


tut::~tut(void)
{
}

void tut::start(void)
{
	sf::RenderWindow Quit(sf::VideoMode(800, 600), "Tutorial");
	Quit.setFramerateLimit(60);
	sf::Texture BG;
	BG.loadFromFile("Data/Images/tut.png");
	sf::Sprite bg;
	bg.setTexture(BG);
	sf::Event game;
	while(Quit.isOpen())
	{
		Quit.clear(sf::Color(0,0,255,255));
		while(Quit.pollEvent(game))
		{		
			
			if(game.type == sf::Event::Closed)
			{
				Quit.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			Quit.close();
			gameing();	
		}
		Quit.clear(sf::Color::Black);
		Quit.draw(bg);
		Quit.display();
	}
}

void tut::gameing(void)
{
	sf::RenderWindow Quit(sf::VideoMode(800, 600), "Tutorial");
	Quit.setFramerateLimit(40);
	sf::Texture BG;
	BG.loadFromFile("Data/Images/tut2.png");
	sf::Sprite bg;
	bg.setTexture(BG);
	sf::Event game;
	while(Quit.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			Quit.close();
			Engine gra;
			gra.playGame();
			
		}
		Quit.clear(sf::Color::Black);
		Quit.draw(bg);
		Quit.display();
	}
}


#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Animation 
{
private:
	
public:
	Animation(void);
	~Animation(void);
	sf::Sprite Animate(sf::Sprite);
};

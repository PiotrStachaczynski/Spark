include "Animation.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int mActuallFrame = 0;


int mActuallLine = 0;


sf::Clock mAnimFrameTime;  

Animation::Animation(void)
{
}


Animation::~Animation(void)
{
}

sf::Sprite Animation::Animate(sf::Sprite animation)
{
	sf::Sprite anim;
	animation.setTextureRect(sf::IntRect(mActuallFrame*50,mActuallLine*50,50,50));
	anim=animation;
	return anim;
}




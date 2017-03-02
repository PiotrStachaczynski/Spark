#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
 
#pragma once
 
class Bullet :public sf::Drawable,sf::Transformable
{
public:
	Bullet(void);
	~Bullet(void);

        Bullet(int x, int y, int s, float a);
       
        void Move();
 
private:
		float angle;
        int speed;
        bool canDestroy;
        sf::CircleShape shape;

	
	//virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};


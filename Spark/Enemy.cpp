#include "Enemy.h"


Enemy::Enemy()
{
	alive=true;
	stay.loadFromFile("Data/Anim/enemy.png");
	dead.loadFromFile("Data/Anim/deco2.png");
	hp=50;
	EnemyBG.setTexture(stay);
}


Enemy::~Enemy(void)
{
}

void Enemy::hurt(sf::Text &p)
{
	hp=hp-3;
}

void Enemy::Animate(int a, int b)
{
	EnemyBG.setTextureRect(sf::IntRect(a*50,b*50,50,50));
}

#pragma once
#include "player.h"
class Enemy :
	public Player
{
private:
	bool alive;
	sf::Sprite EnemyBG;
	sf::Texture stay,dead;
public:
	Enemy();
	~Enemy(void);
	int GetHp()
	{
		return hp;
	}
	void SetHp(int num)
	{
		hp=num;
	}
	void setAlive(bool k)
	{
		alive = k;
	}
	void hurt(sf::Text &p); //funkcja zwraca aktualna ilosc hp
	bool getAlive()
	{
		return alive;
	}
	void kill()
	{
		EnemyBG.setTexture(dead);
	}
	void Die()
	{
		setAlive(false);
		EnemyBG.setColor(Color::Transparent);
	}
	void setPosition(float x, float y)
	{
		EnemyBG.setPosition(x,y);
	}
		void move(Vector2f vector)
	{
		EnemyBG.move(vector.x,vector.y);
	}
	void Animate(int a,int b);
	sf::FloatRect getGlobalBounds()
	{
		return EnemyBG.getGlobalBounds();
	}
	void draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		target.draw(EnemyBG);
	}
};


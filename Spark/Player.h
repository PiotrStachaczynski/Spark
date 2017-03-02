#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Player:public sf::Drawable
{
protected: 
	int hp;
private:
	int dmg;
	float speed;
	sf::Sprite PlayerBg;
	sf::Texture bg,bk,bh,bz,bx,bp,bi,sk,sh,sz,sx,sp,si,pk,ph,pz,px,pp,pi,mk,mh,mz,mx,mp,mi,trans;
	
public:
	Player(void);
	~Player(void){}
	void Rotate(int angle)
	{
		PlayerBg.rotate(angle);
	}
	void setPosition(float x, float y)
	{
		PlayerBg.setPosition(x,y);
	}
	Vector2f getPosition()
	{
		return PlayerBg.getPosition();
	}
	void move(Vector2f vector)
	{
		PlayerBg.move(vector.x,vector.y);
	}
	sf::FloatRect getGlobalBounds()
	{
		return PlayerBg.getGlobalBounds();
	}
	void Hurt(sf::Text &p)
{
	hp=hp-1;
}
	void Walk(int a,int b,float c,int id);
	void Stop();
	int GetHp()
	{
		return hp;
	}
	void ChangeStyle(int id);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		target.draw(PlayerBg);
	}

};


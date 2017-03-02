#pragma once
#include <SFML/Graphics.hpp>
class Item :public sf::Drawable
{
private:
	sf::Sprite item;
	sf::Texture style,style2,style3;
public: 
	Item(void);
	~Item(void);
	int SetItem(int id); // id 1 speed ; id 2 strong ; id 3 gravity oraz ustawia tekstuer
	int ActiveItem(int n); // funkcja ustawia wartoœc force zgodnie dla danego itemu
	void setPosition(float x, float y)
	{
		item.setPosition(x,y);
	}
	sf::FloatRect getGlobalBounds()
	{
		return item.getGlobalBounds();
	}
	sf::Vector2f getPosition()
	{
		return item.getPosition();
	}
	sf::Color getColor()
	{
		return item.getColor();
	}
	void setColor(sf::Color a)
	{
		item.setColor(a);
	}
	void Animate(int a, int b); // Animacja itemu
	void draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		target.draw(item);
	}
};


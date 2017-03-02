#include "Item.h"


Item::Item(void)
{
	style.loadFromFile("Data/Anim/speed.png");
	style2.loadFromFile("Data/Anim/strong.png");
	style3.loadFromFile("Data/Anim/gravity.png");
}


Item::~Item(void)
{
	
}

int Item::SetItem(int id)
{
	if (id==1)
	{
	item.setTexture(style);
	return 5;     // iloc many potrzebnej do transformacji
	}
	if (id==2)
	{
	item.setTexture(style2);
	return 10;		// ilosc many potrzebnej do transformacji
	}
	if (id==3)
	{
	item.setTexture(style3);
	return 15;		// ilosc many potrzebnej do transformacji
	}
}

int Item::ActiveItem(int n)
{
	if (n==5)
	{
		return 1;
	}
	if (n==10)
	{
		return 2;
	}
	if (n==15)
	{
		return 3;
	}
}

void Item::Animate(int a, int b)
{
	item.setTextureRect(sf::IntRect(a*50,b*50,50,50));
}



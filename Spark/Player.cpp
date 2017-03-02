#include "Player.h"


Player::Player(void)
{
	hp=100;
	//Trans
	trans.loadFromFile("Data/Anim/trans.png");
	//Podstawowe;
	bg.loadFromFile("Data/Anim/PlayerStop.png");
	bk.loadFromFile("Data/Anim/PlayerRun.png");
	bh.loadFromFile("Data/Anim/PlayerRun2.png");
	bx.loadFromFile("Data/Anim/PlayerFly.png");
	bz.loadFromFile("Data/Anim/PlayerFly2.png");
	bp.loadFromFile("Data/Anim/Stop2.png");
	bi.loadFromFile("Data/Anim/PlayerPly.png");
	// Speedy Spark
	sk.loadFromFile("Data/Anim/SPlayerRun.png");
	sh.loadFromFile("Data/Anim/SPlayerRun2.png");
	sx.loadFromFile("Data/Anim/SPlayerFly.png");
	sz.loadFromFile("Data/Anim/SPlayerFly2.png");
	sp.loadFromFile("Data/Anim/Sstop.png");
	si.loadFromFile("Data/Anim/SPlayerPly.png");
	// Strong Spark
	pk.loadFromFile("Data/Anim/FPlayerRun.png");
	ph.loadFromFile("Data/Anim/FPlayerRun2.png");
	px.loadFromFile("Data/Anim/FPlayerFly.png");
	pz.loadFromFile("Data/Anim/FPlayerFly2.png");
	pp.loadFromFile("Data/Anim/Fstop.png");
	pi.loadFromFile("Data/Anim/FPlayerPly.png");
	// Gravity Spark
	mk.loadFromFile("Data/Anim/GPlayerRun.png");
	mh.loadFromFile("Data/Anim/GPlayerRun2.png");
	mx.loadFromFile("Data/Anim/GPlayerFly.png");
	mz.loadFromFile("Data/Anim/GPlayerFly2.png");
	mp.loadFromFile("Data/Anim/Gstop2.png");
	mi.loadFromFile("Data/Anim/GPlayerPly.png");
}
void Player::Walk(int a, int b,float c,int id)
{
	sf:: Event event;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (id==0)
		{
		PlayerBg.setTexture(bk);
		}
		if (id==1)
		{
		PlayerBg.setTexture(sk);
		}
		if (id==2)
		{
		PlayerBg.setTexture(pk);
		}
		if (id==3)
		{
		PlayerBg.setTexture(mk);
		}
		ChangeStyle(id);
		
		PlayerBg.setTextureRect(sf::IntRect(a*100,b*100,100,100));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (id==0)
		{
		PlayerBg.setTexture(bh);
		}
		if (id==1)
		{
		PlayerBg.setTexture(sh);
		}
		if (id==2)
		{
		PlayerBg.setTexture(ph);
		}
		if (id==3)
		{
		PlayerBg.setTexture(mh);
		}
		ChangeStyle(id);
		PlayerBg.setTextureRect(sf::IntRect(a*100,b*100,100,100));
	}
	
	else{
		if (id==0)
		{
			PlayerBg.setTexture(bp);
		}
		if (id==1)
		{
			PlayerBg.setTexture(sp);
		}
		if (id==2)
		{
		PlayerBg.setTexture(pp);
		}
		if (id==3)
		{
		PlayerBg.setTexture(mp);
		}
		ChangeStyle(id);
			PlayerBg.setTextureRect(sf::IntRect(a*100,b*100,100,100));
		}
	
	  if (c!=0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (id==0)
				{
				PlayerBg.setTexture(bx);
				}
				if (id==1)
				{
				PlayerBg.setTexture(sx);
				}
				if (id==2)
				{
				PlayerBg.setTexture(px);
				}
				if (id==3)
				{
				PlayerBg.setTexture(mx);
				}
				ChangeStyle(id);
				PlayerBg.setTextureRect(sf::IntRect(a*100,b*100,100,100));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (id==0)
				{
				PlayerBg.setTexture(bz);
				}
				if (id==1)
				{
				PlayerBg.setTexture(sz);
				}
				if (id==2)
				{
				PlayerBg.setTexture(pz);
				}
				if (id==3)
				{
				PlayerBg.setTexture(mz);
				}
				ChangeStyle(id);
				PlayerBg.setTextureRect(sf::IntRect(a*100,b*100,100,100));
			}
			else 
			{
				if (id==0)
				{
				PlayerBg.setTexture(bi);
				}
				if (id==1)
				{
				PlayerBg.setTexture(si);
				}
				if (id==2)
				{
				PlayerBg.setTexture(pi);
				}
				if (id==3)
				{
				PlayerBg.setTexture(mi);
				}
				ChangeStyle(id);
				PlayerBg.setTextureRect(sf::IntRect(a*100,b*100,100,100));
			}
		}
		
		
	//if (event.KeyReleased == Keyboard::A)
	//	PlayerBg.setTexture(bg);
	
}

void Player::Stop()
{
	PlayerBg.setTexture(bg);
}

void Player::ChangeStyle(int id)
{
	if((id==1 || 0 || 2) && sf::Keyboard::isKeyPressed(sf::Keyboard::L) )
		{
		PlayerBg.setTexture(trans);
		}
}




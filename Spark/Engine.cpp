#include "Engine.h"
#include <iostream>
 #include <sstream>
#include "NextLvl.h"
using namespace sf;
Engine::Engine(void)
{
	sf::Clock Animuj;
}

Engine::~Engine(void)
{
}



void Engine::playGame()
{
	Animuj.restart();
	int score=0;
	int HP=0;
	int HP2=0;
	int HP3=0;
	int HPP=0;
	int w=0;
	int s=0;
	int b=0;
	int ammo=25;
	bool shot=false;
	bool fire=false;
	sf::Music soundtrack;
	soundtrack.openFromFile("Data/Music/Dutty.wav");
	

	sf::Texture bull,bull1,bull2,bull3;
	bull.loadFromFile("Data/Anim/bullet.png");
	bull1.loadFromFile("Data/Anim/Sbullet.png");
	bull2.loadFromFile("Data/Anim/Fbullet.png");
	bull3.loadFromFile("Data/Anim/deco2.png");

	sf::Font font;
	sf::Clock intro;
	bool atk=false;
	bool atk2=false;
	font.loadFromFile("Data/digital-7.ttf");
	sf::Text introd,ending;
	sf::Text wrog_live,wrog_live2,wrog_live3;
	wrog_live.setString("");
	wrog_live.setFont(font);
	wrog_live.setCharacterSize(30);
	wrog_live.setColor(Color::Cyan);
	wrog_live.setPosition(695,170);
	wrog_live2.setString("");
	wrog_live2.setFont(font);
	wrog_live2.setCharacterSize(30);
	wrog_live2.setColor(Color::Cyan);
	wrog_live2.setPosition(1345,480);
	wrog_live3.setString("");
	wrog_live3.setFont(font);
	wrog_live3.setCharacterSize(30);
	wrog_live3.setColor(Color::Cyan);
	wrog_live3.setPosition(1805,270);
	ending.setString("GO TO LVL 2");
	ending.setColor(Color::Yellow);
	ending.setFont(font);
	ending.setPosition(3680,430);
	ending.setCharacterSize(30);
	introd.setString("Welcone to LEVEL 1");
	introd.setCharacterSize(40);
	introd.setPosition(200,555);
	introd.setFont(font);
	sf::Text Score,Ammo,Live,Speedy,Time,czas;
	Speedy.setString("Speedy!");
	Speedy.setFont(font);
	Speedy.setCharacterSize(40);
	Speedy.setColor(Color::Red);
	Score.setString("00");
	Score.setFont(font);
	Score.setCharacterSize(40);
	Score.setColor(Color::Red);
	Live.setString("300");
	Live.setFont(font);
	Live.setCharacterSize(40);
	Live.setColor(Color::Cyan);
	Live.setPosition(20,70);
	Time.setPosition(600,10);
	Time.setString("Time:");
	Time.setCharacterSize(40);
	Time.setFont(font);
	Time.setColor(sf::Color::Magenta);
	czas.setPosition(680,10);
	czas.setString("");
	czas.setCharacterSize(40);
	czas.setFont(font);
	czas.setColor(sf::Color::Cyan);
	Ammo.setString("25");
	Ammo.setFont(font);
	Ammo.setCharacterSize(40);
	Ammo.setColor(Color::Red);
	Ammo.setPosition(120,40);
	sf::Text Score2,Ammo2,Speed,Gravity,Strong;
	Score.setPosition(130,10);
	Score2.setString("Score:");
	Score2.setPosition(20,10);
	Score2.setCharacterSize(40);
	Score2.setColor(Color::Yellow);
	Score2.setFont(font);
	Speed.setString("[STRONG]");
	Speed.setPosition(800,490);
	Speed.setCharacterSize(15);
	Speed.setColor(Color::Yellow);
	Speed.setFont(font);
	Gravity.setString("[GRAVITY]");
	Gravity.setPosition(700,490);
	Gravity.setCharacterSize(15);
	Gravity.setColor(Color::Yellow);
	Gravity.setFont(font);
	Strong.setString("[SPEED]");
	Strong.setPosition(900,490);
	Strong.setCharacterSize(15);
	Strong.setColor(Color::Yellow);
	Strong.setFont(font);
	Ammo2.setString("Ammo:");
	Ammo2.setPosition(20,40);
	Ammo2.setCharacterSize(40);
	Ammo2.setColor(Color::Yellow);
	Ammo2.setFont(font);
	int a=255;
	int q=255;
	int e=255;
	int r=255;
	int t=255;
	sf::Vector2i screen(800,600);
	sf::RenderWindow Okno(sf::VideoMode(screen.x, screen.y), "Spark Game"); 
	Okno.setFramerateLimit(60);
	Okno.setKeyRepeatEnabled(true);
	int klatka = 0;
	int linia = 0;
	sf::Clock zegar_klatki; 
	sf::Clock zegar_petli;
	float silnik = 0;
	float TIME_STEP = 0.03f;
	sf::Event windowEvent;
	sf::Texture poin,apoin,amm;
	poin.loadFromFile("Data/Anim/point.png");
	apoin.loadFromFile("Data/Anim/apoint.png");
	amm.loadFromFile("Data/Anim/ammo.png");
	sf::Sprite Amm[5];
	for (int i=0;i<5;i++)
	{
		Amm[i].setTexture(amm);
	}
	sf::Sprite point[30];
	for (int i=0; i<30; i++)
	{
		point[i].setTexture(poin);
	}
	// Ammunicja Pozycje
	Amm[0].setPosition(400,300);
	Amm[1].setPosition(2930,140);
	Amm[2].setPosition(700,510);
	Amm[3].setPosition(2520,510);
	Amm[4].setPosition(2240,200);
	// Punkty Pozycje
	point[0].setPosition(450,300);
	point[1].setPosition(510,300);
	point[2].setPosition(570,300);
	point[3].setPosition(790,200);
	point[4].setPosition(850,200);
	point[5].setPosition(1060,270);
	point[6].setPosition(1200,270);
	point[7].setPosition(1390,140);
	point[8].setPosition(1460,140);
	point[9].setPosition(1510,140);
	point[10].setPosition(2120,200);
	point[11].setPosition(2180,200);
	point[12].setPosition(2450,170);
	point[13].setPosition(3230,350);
	point[14].setPosition(3290,350);
	point[15].setPosition(3350,350);
	point[16].setPosition(3530,150);
	point[17].setPosition(3590,150);
	point[18].setPosition(500,510);
	point[19].setPosition(560,510);
	point[20].setPosition(1200,510);
	point[21].setPosition(1260,510);
	point[22].setPosition(1700,510);
	point[23].setPosition(1760,510);
	point[24].setPosition(2400,510);
	point[25].setPosition(2460,510);
	sf::Texture bg;
	bg.loadFromFile("Data/Images/BGgame.png");
	sf:: Sprite Bg;
	Bg.setTexture(bg);
	sf::Texture plat;
	plat.loadFromFile("Data/Images/platform.png");
	// Platformy
	sf::Sprite platform;
	platform.setTexture(plat);
	platform.setPosition(400,350);
	sf::Sprite platform2;
	platform2.setTexture(plat);
	platform2.setPosition(700,250);
	sf::Sprite platform3;
	platform3.setTexture(plat);
	platform3.setPosition(1050,320);
	sf::Sprite platform4;
	platform4.setTexture(plat);
	platform4.setPosition(1380,190);
	sf::Sprite platform5;
	platform5.setTexture(plat);
	platform5.setPosition(1700,350);
	sf::Sprite platform6;
	platform6.setTexture(plat);
	platform6.setPosition(2100,250);
	sf::Sprite platform7;
	platform7.setTexture(plat);
	platform7.setPosition(2400,220);
	sf::Sprite platform8;
	platform8.setTexture(plat);
	platform8.setPosition(2900,190);
	sf::Sprite platform9;
	platform9.setTexture(plat);
	platform9.setPosition(3200,400);
	sf::Sprite platform10;
	platform10.setTexture(plat);
	platform10.setPosition(3500,200);
	// KONIEC
	sf::Texture end;
	end.loadFromFile("Data/Anim/portal.png");
	sf::Sprite End;
	End.setTexture(end);
	End.setPosition(3700,460);
	// CAM CAM CAM
	sf::RectangleShape cam(sf::Vector2f(20,20));
	cam.setFillColor(Color::Transparent);
	cam.setOutlineColor(Color::Transparent);
	cam.setOutlineThickness(5);
	cam.setPosition(400,300);
	sf::Clock clock;
	sf::View view;
	float Camspeed=8000.0f;
	view.reset(sf::FloatRect(0,0,screen.x,screen.y));
	view.setViewport(sf::FloatRect(0,0,1.0f,1.0f));
	sf::Vector2f positions(0,0);

	std::vector<sf::Sprite> bulletVec;
	std::vector<sf::Sprite> bulletVec2;
	std::vector<sf::Sprite> bulletVec3;
	std::vector<sf::Sprite> bulletVec4;
	std::vector<sf::Sprite> bulletVec5;

	//Podstawowe Skladowe
	sf::Vector3i mana(sf::Vector3i(0,0,0));
	float gravity=0.5;
	float Movespeed=1.5f;
	float Jumpspeed=3.0f;
	float temp;
	int ground = 580;
	int force = 0;
	float collide= -1.5f;
	sf::Vector2f velocity(sf::Vector2f(0,0));

	Enemy wrog,wrog2,wrog3;
	wrog.setPosition(700,200);
	wrog2.setPosition(1350,510);
	wrog3.setPosition(1800,300);
	
	Player player;
	player.setPosition(300,50);
	Item item,item2,item3;
	item.setPosition(900,510);
	item.SetItem(1); // speed
	item2.setPosition(800,510);
	item2.SetItem(2); // strong
	item3.setPosition(700,510);
	item3.SetItem(3); // gravity
	//Podstawowe skladowe
		
	// Pobranie stanu hp;
	HP=wrog.GetHp();
	HP2=wrog2.GetHp();
	HP3=wrog3.GetHp();

	// MUZYKA MUZYKA MUZYKA
	sf::Music run,fly,poi,shoot,Ammu,in,trans,Bum;
	run.openFromFile("Data/Music/run.wav");
	fly.openFromFile("Data/Music/jet.wav");
	poi.openFromFile("Data/Music/point.wav");
	shoot.openFromFile("Data/Music/shoot.wav");
	Ammu.openFromFile("Data/Music/ammo.wav");
	in.openFromFile("Data/Music/item.wav");
	trans.openFromFile("Data/Music/trans.wav");
	Bum.openFromFile("Data/Music/bum.wav");
	// MUZYKA MUZYKA MUZYKA

	// Warunki Czekania
	sf::Clock clocker;
	sf::Clock zegar;
	sf::Clock zegar2;
	sf::Clock zegar3;

	while(Okno.isOpen())
	{
		clock.restart();
		Okno.clear(sf::Color(0,0,255,255));
		if (soundtrack.getStatus()!=sf::Music::Playing) soundtrack.play();
		soundtrack.setVolume(10);

		silnik += zegar_petli.restart().asSeconds();

		while(Okno.pollEvent(windowEvent))
		{
			if(windowEvent.type == sf::Event::Closed)
			{
				Okno.close();
			}
		}
	
		if (sf::Keyboard::isKeyPressed(Keyboard::Escape))
		{
			soundtrack.pause();
			Ex.Esc(Okno);
		}



	
		if(silnik > TIME_STEP)
		{

			if(zegar_klatki.getElapsedTime().asSeconds() > 0.1)
			{

				zegar_klatki.restart();


				klatka++;
			}


			if(klatka >= 2)
			{

				klatka = 0;


				linia++;
			}


			if(linia >= 3)
			{

				linia = 0;
			}
		
			/// Itemy ITEM ITEM ITEM
			
			if (force==0)
			{
				Movespeed=1.5f;
				collide=-1.5f;
				Jumpspeed=3;
			}
			if (force==1)
			{
				Movespeed=6.5f;
				collide=-6.5f;
				Jumpspeed=3;
			}
			if (force==2)
			{
				Movespeed=3.f;
				collide=-3.0f;
				Jumpspeed=3;
			}
			if (force==3)
			{
				Movespeed=4.f;
				collide=-4.0f;
				Jumpspeed=8;
			}
			if (sf::Keyboard::isKeyPressed(Keyboard::L))
			{
				std::stringstream ss ;
				score--;
				ss << score;
				Score.setString(ss.str());
				if (sf::Keyboard::isKeyPressed(Keyboard::P) && mana.x==1)
			{
				trans.play();
				force = 1;
				Movespeed=6.5f;
				collide=-6.5f;
				Jumpspeed=3;
			}
				if (sf::Keyboard::isKeyPressed(Keyboard::U))
			{
				trans.play();
				force = 0;
				Movespeed=1.5f;
				collide=-1.5f;
				Jumpspeed=3;
			}
				if (sf::Keyboard::isKeyPressed(Keyboard::O) && mana.y==1)
			{
				trans.play();
				force = 2;
				Movespeed=3.f;
				collide=-3.0f;
				Jumpspeed=3;
			}
				if (sf::Keyboard::isKeyPressed(Keyboard::I) && mana.z==1)
			{
				trans.play();
				force = 3;
				Movespeed=4.f;
				collide=-4.0f;
				Jumpspeed=8;
			}
			}
			
			
			if (player.getGlobalBounds().intersects(item.getGlobalBounds()))
			{
				mana.x=1;
			
				if(item.getColor()!=Color::Transparent)
				{
					item.setColor(sf::Color(255,255,255,e)); 
					e=e-51;
			
				}
				if (e==0)
				{
					in.play();
					item.setColor(Color::Transparent); e=255;
					Strong.setString("");
				}
			
			}
				if (player.getGlobalBounds().intersects(item2.getGlobalBounds()))
			{
				mana.y=1;
			
				if(item2.getColor()!=Color::Transparent)
				{
					item2.setColor(sf::Color(255,255,255,e)); 
					r=r-51;
			
				}
				if (r==0)
				{
					in.play();
					item2.setColor(Color::Transparent); r=255;
					Speed.setString("");
				}
			
			}
					if (player.getGlobalBounds().intersects(item3.getGlobalBounds()))
			{
				mana.z=1;
			
				if(item3.getColor()!=Color::Transparent)
				{
					item3.setColor(sf::Color(255,255,255,e)); 
					t=t-51;
			
				}
				if (t==0)
				{
					in.play();
					item3.setColor(Color::Transparent); t=255;
					Gravity.setString("");
				}
			
			}
			// Wrogowie
			wrog.Animate(klatka,linia);
			wrog2.Animate(klatka,linia);
			wrog3.Animate(klatka,linia);
			// Itemy ITEM ITEM
			player.Walk(klatka,linia,velocity.y,force);
			item.Animate(klatka,linia);
			item2.Animate(klatka,linia);
			item3.Animate(klatka,linia);
			HPP=player.GetHp();
			HP=wrog.GetHp();
			HP2=wrog2.GetHp();
			HP3=wrog3.GetHp();
			std::stringstream ss,kk,ll,oo,pp,aa;
			oo << HP;
			pp << HP2;
			aa << HP3;
			ss << score;
			ll << HPP;
			wrog_live.setString(oo.str());
			wrog_live2.setString(pp.str());
			wrog_live3.setString(aa.str());
			Live.setString(ll.str());
			Score.setString(ss.str());
			// ss << score+10;
			for (int o=0; o<=4; o++)
			{
			Amm[o].setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			if (Amm[o].getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				if(Amm[o].getColor()!=Color::Transparent)
				{
					Amm[o].setColor(sf::Color(255,255,255,q)); 
					q=q-51;
			
				}
				if (q==0)
				{
					Ammu.play();
			ammo=ammo+10;
			kk << ammo;
			Ammo.setString(kk.str());
					Amm[o].setColor(Color::Transparent); q=255;
				}
			}
			}
			
		

			for (int j=0; j<=25; j++)
			{
			point[j].setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			if (point[j].getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				if (point[j].getColor()!=Color::Transparent)
				{
			point[j].setColor(sf::Color(255,255,255,a));     
			a=a-51;
				}
				if (a==0) 
					{
						 poi.play();
						point[j].setColor(Color::Transparent);  a=255;
						score=score+5;
						
						
					}
			}
			}
		
			
			// Strzelanie

			//sf::Time timer = clocker.getElapsedTime();
			introd.setColor(Color::Magenta);

			if (sf::Keyboard::isKeyPressed(Keyboard::Space))
		{
			fire = true;
				shot =true;
        }
	
		
			
		if (fire == true) 	
		{
			sf::Time timer = clocker.getElapsedTime();
			if (timer.asSeconds() >= 0.2f )
			{
			if (ammo>0)
			{
			ammo=ammo-1;
			kk << ammo;
			Ammo.setString(kk.str());
			if (shoot.getStatus()!=sf::Music::Playing) shoot.play();
			}
			if (ammo<=0)
			{
				ammo=0;
				Ammo.setString("00");
				bulletVec.resize(0);
				bulletVec2.resize(0);
			}
		        sf::Sprite newBullet,newBullet2;
				if (force==0)
				{
				newBullet.setTexture(bull);
				newBullet2.setTexture(bull);
				}
				if (force==1)
				{
				newBullet.setTexture(bull1);
				newBullet2.setTexture(bull1);
				}
				if (force==2)
				{
				newBullet.setTexture(bull2);
				newBullet2.setTexture(bull2);
				}
				if (force==3)
				{
				newBullet.setTexture(bull2);
				newBullet2.setTexture(bull2);
				}
				newBullet.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));	newBullet2.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
				newBullet.setPosition(player.getPosition().x+76,player.getPosition().y); newBullet2.setPosition(player.getPosition().x+76,player.getPosition().y);
				if (sf::Keyboard::isKeyPressed(Keyboard::A))
				{
				bulletVec.push_back(newBullet);
				}
				else bulletVec2.push_back(newBullet2);
				fire = false;
				clocker.restart();
			}
        }
		

		// czas czas czas czas czas
				std::stringstream tt ;
				float ik;
				sf::Time hhh=Animuj.getElapsedTime();
				ik=hhh.asSeconds();
				tt << ik;
				czas.setString(tt.str());
		//KONIEC KOD
			End.setTextureRect(sf::IntRect(klatka*100,linia*100,100,100));
			if (player.getGlobalBounds().intersects(End.getGlobalBounds()))
			{
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
				{
					Okno.close();
					soundtrack.stop();
					NextLvl p;
					p.playGameLvL(score,ammo,Live,mana,force,Animuj);	
					
				}
			}
		//KONIEC KOD
			//   Dec.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));

			//	animation2.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			//animation3.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			//	animation4.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			/// ATAK PRZECINIK 
			
			if ( 1==1)
			{
			sf::Time timer = zegar2.getElapsedTime();
			 sf::Sprite newBullet;
			 newBullet.setTexture(bull3);
			 newBullet.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			if (timer.asSeconds() >= 3.0f )
			{
				
				newBullet.setPosition(1350,500);
				bulletVec3.push_back(newBullet);
				zegar2.restart();
			}
			}
			//ATAK PRZECIWNIK 2
			
			if (3==3)
			{
			sf::Time tim = zegar3.getElapsedTime();
			 sf::Sprite newBullet;
			 newBullet.setTexture(bull3);
			 newBullet.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			if (tim.asSeconds() >= 3.0f )
			{
				
				newBullet.setPosition(700,200);
				bulletVec4.push_back(newBullet);
				zegar3.restart();
			}
			}
			
				//Przecinik3
				
			if (2==2)
			{
			sf::Time tima = zegar.getElapsedTime();
			 sf::Sprite newBullet;
			 newBullet.setTexture(bull3);
			 newBullet.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			if (tima.asSeconds() >= 3.0f )
			{
				
				newBullet.setPosition(1800,300);
				bulletVec5.push_back(newBullet);
				zegar.restart();
			
			}
			}

			silnik -= TIME_STEP;
		}
		
		
		sf::Time Intro = intro.getElapsedTime();
			if (Intro.asSeconds() >= 0.2f )
			{
				introd.setColor(sf::Color::Cyan);
				intro.restart();
			}

			if (HPP <= 0)
		{
			soundtrack.stop();
			Okno.close();
			playGame();
		}
		Okno.clear(sf::Color::Black);	  
		sf::Vector2i pozycja = sf::Mouse::getPosition(Okno);
		if (windowEvent.type == sf::Event::MouseButtonPressed)
		{
			if (windowEvent.mouseButton.button == sf::Mouse::Left)
			{
				
			}
		}	
		
		sf::Event event;
		while (Okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Okno.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (run.getStatus()!=sf::Music::Playing) run.play();
			velocity.x=Movespeed;
		}
		else  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (run.getStatus()!=sf::Music::Playing) run.play();
			velocity.x=-Movespeed;
		}
		else velocity.x=0;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			velocity.y=-Jumpspeed;
		
		}

	 player.move(velocity);
	 if (player.getPosition().x>=280)
	 {
	 Score.move(velocity.x,0);
	 Score2.move(velocity.x,0);
	 Ammo.move(velocity.x,0);
	 Ammo2.move(velocity.x,0);
	 Live.move(velocity.x,0);
	 Time.move(velocity.x,0);
	 czas.move(velocity.x,0);
	 }
	 //if (Score2.getPosition().x==20)
	// {
	//Score.move(0,0);
	 //Score2.move(0,0);
	 //Ammo.move(0,0);
	 //Ammo2.move(0,0);
	 //Live.move(0,0);
	// }
	 if (velocity.y!=0) if (fly.getStatus()!=sf::Music::Playing) fly.play();
	 if (velocity.y==0) fly.pause();
	 if (velocity.y != 0)  run.pause(); 
	 if (velocity.x== 0)  run.pause();
	 if (windowEvent.type==sf::Event::KeyReleased && windowEvent.key.code == sf::Keyboard::D) run.pause();
	 if (windowEvent.type==sf::Event::KeyReleased && windowEvent.key.code == sf::Keyboard::A) run.pause();
		cam.move(velocity.x,velocity.y-200);
		if(player.getPosition().y+100<ground || velocity.y < 0)
		{
			velocity.y+=gravity;
		}
		else
		{
			player.setPosition(player.getPosition().x,ground-100);
			velocity.y=0;
		
		}
// KOLIZJE!! KOLIZJE !! KOLIZJE!! KOLIZJE !!	
// KOLIZJE!! KOLIZJE !! KOLIZJE!! KOLIZJE !!	
// KOLIZJE!! KOLIZJE !! KOLIZJE!! KOLIZJE !!
	
			if (player.getPosition().y+20<=0)
			{
				player.move(sf::Vector2f(velocity.x,15));

			
			}
			if (player.getPosition().x-60>=3700)
			{
				player.move(sf::Vector2f(-15,velocity.y));

			}
				if (player.getPosition().x-60>=3700)
			{
				Score.move(sf::Vector2f(-15,velocity.y));
			}
			if (player.getPosition().x-60<=60)
			{
				player.move(sf::Vector2f(15,velocity.y));
			}
		//	if (Score2.getPosition().x<=60)
		//		{
//
		//			Score.move(sf::Vector2f(5,velocity.y));
			//		Score2.move(sf::Vector2f(5,velocity.y));
		//			Ammo.move(sf::Vector2f(5,velocity.y));
		//			Ammo2.move(sf::Vector2f(5,velocity.y));
		//			Live.move(sf::Vector2f(5,velocity.y));
			//	}
			
			if (cam.getPosition().x+70>=3640)
			{
			cam.move(sf::Vector2f(collide,velocity.y));
			Score.move(sf::Vector2f(collide,0));
				Score2.move(sf::Vector2f(collide,0));
				Ammo.move(sf::Vector2f(collide,0));
					Ammo2.move(sf::Vector2f(collide,0));
				Live.move(sf::Vector2f(collide,0));
				Time.move(sf::Vector2f(collide,0));
				czas.move(sf::Vector2f(collide,0));
				
			}
			if (cam.getPosition().x<=200)
			{
				
				cam.move(sf::Vector2f(-collide,velocity.y));
			}
			if(platform.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<300)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,265);
				}
			}
				if(platform2.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<=200)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
					
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,165);
				}
			}
					if(platform3.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<270)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,245);
				}
			}
						if(platform4.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<140)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,105);
				}
			}
						if(platform5.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<300)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,265);
				}
			}
				if(platform6.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<=200)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,165);
				}
			}
					if(platform7.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<170)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,145);
				}
			}
						if(platform8.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<140)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,105);
				}
			}
				if(platform9.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<350)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,315);
				}
			}
					if(platform10.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<150)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,115);
				}
			}
// KOLIZJE!! KOLIZJE !! KOLIZJE!! KOLIZJE !!	
// KOLIZJE!! KOLIZJE !! KOLIZJE!! KOLIZJE !!	
// KOLIZJE!! KOLIZJE !! KOLIZJE!! KOLIZJE !!			
	
		positions.x=cam.getPosition().x + 10 -(screen.x*0.5f);
		positions.y=cam.getPosition().y + 10 -(screen.y*0.5f);
		if (positions.x < 0 )
			positions.x = 0;
		if (positions.y < 0 )
			positions.y = 0;
		view.reset(sf::FloatRect(positions.x,positions.y,screen.x,screen.y));


		Okno.setView(view);	
		//Okno.draw...
		Okno.draw(Bg);
		Okno.draw(cam);
		Okno.draw(introd);
		Okno.draw(Live);
		if (HP>0)
		{
		Okno.draw(wrog_live);
		}
		if (HP2>0)
		{
		Okno.draw(wrog_live2);
		}
		if (HP3>0)
		{
		Okno.draw(wrog_live3);
		}
		Okno.draw(Score);
		Okno.draw(Score2);
		Okno.draw(Ammo);
		Okno.draw(Ammo2);
		Okno.draw(item);
		Okno.draw(item2);
		Okno.draw(item3);
		Okno.draw(Speed);
		Okno.draw(Strong);
		Okno.draw(Gravity);
		
		Okno.draw(wrog);
		
		Okno.draw(wrog2);
	
		Okno.draw(wrog3);
		Okno.draw(czas);
		Okno.draw(point[0]);
		Okno.draw(point[1]);
		Okno.draw(point[2]);
		Okno.draw(point[3]);
		Okno.draw(point[4]);
		Okno.draw(point[5]);
		Okno.draw(point[6]);
		Okno.draw(point[7]);
		Okno.draw(point[8]);
		Okno.draw(point[9]);
		Okno.draw(point[10]);
		Okno.draw(point[11]);
		Okno.draw(point[12]);
		Okno.draw(point[13]);
		Okno.draw(point[14]);
		Okno.draw(point[15]);
		Okno.draw(point[16]);
		Okno.draw(point[17]);
		Okno.draw(point[18]);
		Okno.draw(point[19]);
		Okno.draw(point[20]);
		Okno.draw(point[21]);
		Okno.draw(point[22]);
		Okno.draw(point[23]);
		Okno.draw(point[24]);
		Okno.draw(point[25]);
		Okno.draw(Amm[0]);
		Okno.draw(Amm[1]);
		//Okno.draw(Amm[2]);
		Okno.draw(Amm[3]);
		Okno.draw(Amm[4]);
		Okno.draw(ending);
		Okno.draw(Time);
		Okno.draw(platform);
		Okno.draw(platform2);
		Okno.draw(platform3);
		Okno.draw(platform4);
		Okno.draw(platform5);
		Okno.draw(platform6);
		Okno.draw(platform7);
		Okno.draw(platform8);
		Okno.draw(platform9);
		Okno.draw(platform10);
		Okno.draw(End);
		//Okno.draw(Dec17);
		Okno.draw(player);
		
		//Strzaly przecinik

			for (int i = 1; i < bulletVec3.size();i++) 
		{
			 if (HP2<=0)
				 {
					 bulletVec3[i].setColor(Color::Transparent);
					 bulletVec3[i].setPosition(0,900);

				 }
			 else
			 {
				 Okno.draw(bulletVec3[i]);
				 bulletVec3[i].move(-7,0);
				 if(bulletVec3[i].getGlobalBounds().intersects(player.getGlobalBounds()))
				 {
					
					 player.move(sf::Vector2f(-1,0));
					 cam.move(sf::Vector2f(-1,0));
					  Score.move(sf::Vector2f(-1,0));
					   Live.move(sf::Vector2f(-1,0));
					    Score2.move(sf::Vector2f(-1,0));
						Ammo.move(sf::Vector2f(-1,0));
						Ammo2.move(sf::Vector2f(-1,0));
						Time.move(sf::Vector2f(-1,0));
						czas.move(sf::Vector2f(-1,0));
						  player.Hurt(Live);
					 atk=true;
					 
				
					 
					
					
					 if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 
					 bulletVec3[i].setColor(Color::Transparent);
				 }
				  if(!bulletVec3[i].getGlobalBounds().intersects(player.getGlobalBounds()))
				  {
					  if (atk==true)
					  {
						
						  atk=false;
					  }
				  }
				 
			 }
			}
			
			 for (int i = 1; i < bulletVec4.size();i++) 
			 {
			 if (HP<=0)
				 {
					 bulletVec4[i].setColor(Color::Transparent);
					 bulletVec4[i].setPosition(0,900);

				 }
			 else
			 {
				 Okno.draw(bulletVec4[i]);
				 bulletVec4[i].move(-7,7);
				 if(bulletVec4[i].getGlobalBounds().intersects(player.getGlobalBounds()))
				 {
					
					 player.move(sf::Vector2f(-1,0));
					 cam.move(sf::Vector2f(-1,0));
					  Score.move(sf::Vector2f(-1,0));
					   Live.move(sf::Vector2f(-1,0));
					    Score2.move(sf::Vector2f(-1,0));
						Ammo.move(sf::Vector2f(-1,0));
						Ammo2.move(sf::Vector2f(-1,0));
						Time.move(sf::Vector2f(-1,0));
						czas.move(sf::Vector2f(-1,0));
						  player.Hurt(Live);
					 atk=true;
					 
				
					 
					
					
					 if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 
					 bulletVec4[i].setColor(Color::Transparent);
				 }
				  if(!bulletVec4[i].getGlobalBounds().intersects(player.getGlobalBounds()))
				  {
					  if (atk==true)
					  {
						
						  atk=false;
					  }
				  }
				 
			 }
				
		}

			 for (int i = 1; i < bulletVec5.size();i++) 
			 {
			 if (HP3<=0)
				 {
					 bulletVec5[i].setColor(Color::Transparent);
					 bulletVec5[i].setPosition(0,900);
				 }
			 else
			 {
				 Okno.draw(bulletVec5[i]);
				 bulletVec5[i].move(-7,0);
				 if(bulletVec5[i].getGlobalBounds().intersects(player.getGlobalBounds()))
				 {
					
					 player.move(sf::Vector2f(-1,0));
					 cam.move(sf::Vector2f(-1,0));
					  Score.move(sf::Vector2f(-1,0));
					   Live.move(sf::Vector2f(-1,0));
					    Score2.move(sf::Vector2f(-1,0));
						Ammo.move(sf::Vector2f(-1,0));
						Ammo2.move(sf::Vector2f(-1,0));
						Time.move(sf::Vector2f(-1,0));
						czas.move(sf::Vector2f(-1,0));
						  player.Hurt(Live);
					 atk=true;
					 
				
					 
					
					
					 if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 
					 bulletVec5[i].setColor(Color::Transparent);
				 }
				  if(!bulletVec5[i].getGlobalBounds().intersects(player.getGlobalBounds()))
				  {
					  if (atk==true)
					  {
						
						  atk=false;
					  }
				  }
				 
			 }
				
		}
			// Strzelanie
		
		
		
 
			for (int i = 1; i < bulletVec.size();i++) 
		{
			
			
				 Okno.draw(bulletVec[i]);
		if (force == 0)
		{
		 bulletVec[i].move(-15,0);
		}
		if (force == 1)
		{
		 bulletVec[i].move(-22,0);
		}
		if (force == 2)
		{
		 bulletVec[i].move(-12,0);
		}
		if (force == 3)
		{
		 int losowa;
	srand((int)time(NULL));
	losowa=rand()%(25)-10;
		 bulletVec[i].move(-15,-losowa);
		}
		}	
				for (int i = 1; i < bulletVec2.size();i++) 
		{
			
			
				 Okno.draw(bulletVec2[i]);
				
				 
			
		if (force == 0)
		{
		 bulletVec2[i].move(15,0);
		 //Kolicja pocisk  - wrog 
		 if(bulletVec2[i].getGlobalBounds().intersects(wrog.getGlobalBounds()))
				 {
					
					 wrog.hurt(wrog_live);
					 score=score+2;
					 
					 if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 shot = false;
					 HP=wrog.GetHp();
					 if (HP<=0)
					 {
						 wrog.Die();
						 wrog.setPosition(0,0);
					 }
					 wrog_live.move(6,0);
					 wrog.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
		 	 if(bulletVec2[i].getGlobalBounds().intersects(wrog2.getGlobalBounds()))
				 {
					
					 wrog2.hurt(wrog_live2);
					 score=score+2;
					 
					 shot = false;
					 HP2=wrog2.GetHp();
					  if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 if (HP2<=0)
					 {
						 
						 wrog2.Die();
						 wrog2.setPosition(0,0);
					 }
					 wrog_live2.move(6,0);
					 wrog2.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
			 	 if(bulletVec2[i].getGlobalBounds().intersects(wrog3.getGlobalBounds()))
				 {
					 sf::Clock zegar;
					
					 wrog3.hurt(wrog_live3);
					 score=score+2;
					 
					 shot = false;
					 HP3=wrog3.GetHp();
					  if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 if (HP3<=0)
					 {
							wrog3.Die();
							wrog3.setPosition(0,0);
					 }
					 wrog_live3.move(6,0);
					 wrog3.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
		 
				
		}
		if (force == 1)
		{
	//Kolicja pocisk  - wrog 
		 if(bulletVec2[i].getGlobalBounds().intersects(wrog.getGlobalBounds()))
				 {
					 
					 wrog.hurt(wrog_live);
					 score=score+2;
					 
					 if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 shot = false;
					 HP=wrog.GetHp();
					 if (HP<=0)
					 {
						 wrog.Die();
						 wrog.setPosition(0,0);
					 }
					 wrog_live.move(6,0);
					 wrog.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
		 	 if(bulletVec2[i].getGlobalBounds().intersects(wrog2.getGlobalBounds()))
				 {
					
					 wrog2.hurt(wrog_live2);
					 score=score+2;
					 
					 shot = false;
					 HP2=wrog2.GetHp();
					  if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 if (HP2<=0)
					 {
						 
						 wrog2.Die();
						 wrog2.setPosition(0,0);
					 }
					 wrog_live2.move(6,0);
					 wrog2.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
			 	 if(bulletVec2[i].getGlobalBounds().intersects(wrog3.getGlobalBounds()))
				 {
					 sf::Clock zegar;
					
					 wrog3.hurt(wrog_live3);
					 score=score+2;
					 
					 shot = false;
					 HP3=wrog3.GetHp();
					  if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 if (HP3<=0)
					 {
							wrog3.Die();
							wrog3.setPosition(0,0);
					 }
					 wrog_live3.move(6,0);
					 wrog3.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
		 bulletVec2[i].move(22,0);
		}
		if (force == 2)
		{
			//Kolicja pocisk  - wrog 
		 if(bulletVec2[i].getGlobalBounds().intersects(wrog.getGlobalBounds()))
				 {
					 
					 wrog.hurt(wrog_live);
					 score=score+2;
					 
					 if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 shot = false;
					 HP=wrog.GetHp();
					 if (HP<=0)
					 {
						 wrog.Die();
						 wrog.setPosition(0,0);
					 }
					 wrog_live.move(6,0);
					 wrog.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
		 	 if(bulletVec2[i].getGlobalBounds().intersects(wrog2.getGlobalBounds()))
				 {
					 
					 wrog2.hurt(wrog_live2);
					 score=score+2;
					 
					 shot = false;
					 HP2=wrog2.GetHp();
					  if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 if (HP2<=0)
					 {
						 
						 wrog2.Die();
						 wrog2.setPosition(0,0);
					 }
					 wrog_live2.move(6,0);
					 wrog2.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
			 	 if(bulletVec2[i].getGlobalBounds().intersects(wrog3.getGlobalBounds()))
				 {
					 sf::Clock zegar;
					 
					 wrog3.hurt(wrog_live3);
					 score=score+2;
					 
					 shot = false;
					 HP3=wrog3.GetHp();
					  if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 if (HP3<=0)
					 {
							wrog3.Die();
							wrog3.setPosition(0,0);
					 }
					 wrog_live3.move(6,0);
					 wrog3.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
		 bulletVec2[i].move(12,0);
		}
		if (force == 3)
		{
			//Kolicja pocisk  - wrog 
		 if(bulletVec2[i].getGlobalBounds().intersects(wrog.getGlobalBounds()))
				 {
					 
					 wrog.hurt(wrog_live);
					 score=score+2;
					 
					 if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 shot = false;
					 HP=wrog.GetHp();
					 if (HP<=0)
					 {
						 wrog.Die();
						 wrog.setPosition(0,0);
					 }
					 wrog_live.move(6,0);
					 wrog.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
		 	 if(bulletVec2[i].getGlobalBounds().intersects(wrog2.getGlobalBounds()))
				 {
					
					 wrog2.hurt(wrog_live2);
					 score=score+2;
					 
					 shot = false;
					 HP2=wrog2.GetHp();
					  if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 if (HP2<=0)
					 {
						 
						 wrog2.Die();
						 wrog2.setPosition(0,0);
					 }
					 wrog_live2.move(6,0);
					 wrog2.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
			 	 if(bulletVec2[i].getGlobalBounds().intersects(wrog3.getGlobalBounds()))
				 {
					 sf::Clock zegar;
					
					 wrog3.hurt(wrog_live3);
					 score=score+2;
					 
					 shot = false;
					 HP3=wrog3.GetHp();
					  if (Bum.getStatus()!=sf::Music::Playing) Bum.play();
					 if (HP3<=0)
					 {
							wrog3.Die();
							wrog3.setPosition(0,0);
					 }
					 wrog_live3.move(6,0);
					 wrog3.move(sf::Vector2f(6,0));
					 bulletVec2[i].setColor(Color::Transparent);
					 
				 }
		 int losowa;
	srand((int)time(NULL));
	losowa=rand()%(25)-10;
		 bulletVec2[i].move(15,-losowa);
		}
		 
		}
			// Okno.draw(bulletVec[i]);
				
        //Okno.draw(bulletVec[i]);
				
			// Strzelanie
		
		Okno.display();
	}

}


// LEVEL 2 
// LEVEL 2

// LEVEL 2

// LEVEL 2

// LEVEL 2



		
			// Strzelanie
		
		
		




// LEVEL 2
// LEVEL 2
// LEVEL 2
// LEVEL 2
// LEVEL 2

// LEVEL 3
// LEVEL 3
// LEVEL 3



// LEVEL 3
// LEVEL 3
// LEVEL 3
// LEVEL 3
// LEVEL 3

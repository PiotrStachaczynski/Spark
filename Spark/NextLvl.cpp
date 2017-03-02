#include "NextLvl.h"
 #include <sstream>
#include <iostream>
#include "NextNextLvl.h"


NextLvl::NextLvl(void)
{
}


NextLvl::~NextLvl(void)
{
}


void NextLvl::playGameLvL(int score,int ammo,sf::Text Live,sf::Vector3i mana,int force,sf::Clock Animuj)
{
	int w=0;
	int s=0;
	bool fire=false;
	sf::Music Muzyka;
	Muzyka.openFromFile("Data/Music/lvl.wav");
	sf::Sprite End;
	sf::Texture bull,bull1,bull2,end;
	end.loadFromFile("Data/Anim/portal.png");
	End.setTexture(end);
	bull.loadFromFile("Data/Anim/bullet.png");
	bull1.loadFromFile("Data/Anim/Sbullet.png");
	bull2.loadFromFile("Data/Anim/Fbullet.png");
	End.setPosition(3700,460);
	sf::Font font;
	sf::Clock intro;
	font.loadFromFile("Data/digital-7.ttf");
	sf::Text introd,ending;
	ending.setCharacterSize(30);
	ending.setString("GO TO LVL 3");
	ending.setColor(Color::Yellow);
	ending.setFont(font);
	ending.setPosition(3680,430);
	introd.setString("Welcone to LEVEL 2");
	introd.setCharacterSize(40);
	introd.setPosition(200,555);
	introd.setFont(font);
	sf::Text Score,Ammo,Time,czas;
	//Score.setString("00");
	Score.setFont(font);
	Score.setCharacterSize(40);
	Score.setColor(Color::Red);
	//Live.setString("[+] [+] [+]");
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
	czas.setCharacterSize(40);
	czas.setFont(font);
	czas.setColor(sf::Color::Cyan);
	Ammo.setString("25");
	Ammo.setFont(font);
	Ammo.setCharacterSize(40);
	Ammo.setColor(Color::Red);
	Ammo.setPosition(120,40);
	sf::Text Score2,Ammo2;
	Score.setPosition(130,10);
	Score2.setString("Score:");
	Score2.setPosition(20,10);
	Score2.setCharacterSize(40);
	Score2.setColor(Color::Yellow);
	Score2.setFont(font);
	Ammo2.setString("Ammo:");
	Ammo2.setPosition(20,40);
	Ammo2.setCharacterSize(40);
	Ammo2.setColor(Color::Yellow);
	Ammo2.setFont(font);
	int a=255;
	int q=255;
	int e=255;
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
	poin.loadFromFile("Data/Anim/point2.png");
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
	Amm[0].setPosition(350,250);
	Amm[1].setPosition(2830,250);
	Amm[2].setPosition(700,510);
	Amm[3].setPosition(2520,510);
	Amm[4].setPosition(2240,200);
	// Punkty Pozycje
	point[0].setPosition(400,250);
	point[1].setPosition(460,250);
	point[2].setPosition(520,250);
	point[3].setPosition(570,350);
	point[4].setPosition(620,350);
	point[5].setPosition(860,270);
	point[6].setPosition(920,270);
	point[7].setPosition(1290,140);
	point[8].setPosition(1360,140);
	point[9].setPosition(1410,140);
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
	bg.loadFromFile("Data/Images/BGgame2.png");
	sf:: Sprite Bg;
	Bg.setTexture(bg);
	sf::Texture plat;
	plat.loadFromFile("Data/Images/platform2.png");
	// Platformy
	sf::Sprite platform;
	platform.setTexture(plat);  
	platform.setPosition(350,300);                        // Platform 1 X
	sf::Sprite platform2;
	platform2.setTexture(plat);
	platform2.setPosition(550,400);                       // Platform 2 X
	sf::Sprite platform3;
	platform3.setTexture(plat);
	platform3.setPosition(850,320);						  // Platform 3 X
	sf::Sprite platform4;
	platform4.setTexture(plat);
	platform4.setPosition(1280,190);                      // Platform 4 X 
	sf::Sprite platform5;
	platform5.setTexture(plat);
	platform5.setPosition(1600,280);					  // Platform 5 X
	sf::Sprite platform6;
	platform6.setTexture(plat);
	platform6.setPosition(2100,250);					  // Platform 6 X
	sf::Sprite platform7;
	platform7.setTexture(plat);
	platform7.setPosition(2400,350);                      // Platform 7 X
	sf::Sprite platform8;
	platform8.setTexture(plat);
	platform8.setPosition(2800,300);						
	sf::Sprite platform9;
	platform9.setTexture(plat);
	platform9.setPosition(3200,400);
	sf::Sprite platform10;
	platform10.setTexture(plat);
	platform10.setPosition(3500,200);
	
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
	std::stringstream ss,kk;
	ss << score;
	Score.setString(ss.str());
	kk << ammo;
	Ammo.setString(kk.str());
		//Podstawowe Skladowe
	//sf::Vector3i mana(sf::Vector3i(0,0,0));
	float gravity=0.5;
	float Movespeed=1.5f;
	float Jumpspeed=3.0f;
	float temp;
	int ground = 580;
	//int force = 0;
	float collide= -1.5f;
	sf::Vector2f velocity(sf::Vector2f(0,0));
	
	Player player;
	player.setPosition(300,50);
	Item item;
	item.setPosition(1000,510);
	item.SetItem(1);  // speed
	//Podstawowe skladowe

	// MUZYKA MUZYKA MUZYKA
	sf::Music run,fly,poi,shoot,Ammu,trans;
	run.openFromFile("Data/Music/run.wav");
	fly.openFromFile("Data/Music/jet.wav");
	poi.openFromFile("Data/Music/point.wav");
	shoot.openFromFile("Data/Music/shoot.wav");
	Ammu.openFromFile("Data/Music/ammo.wav");
	trans.openFromFile("Data/Music/trans.wav");
	// MUZYKA MUZYKA MUZYKA

	sf::Clock clocker;

	while(Okno.isOpen())
	{
		clock.restart();
		Okno.clear(sf::Color(0,0,255,255));
		if (Muzyka.getStatus()!=sf::Music::Playing) Muzyka.play();
		Muzyka.setVolume(12);

		silnik += zegar_petli.restart().asSeconds();

		while(Okno.pollEvent(windowEvent))
		{
			if(windowEvent.type == sf::Event::Closed)
			{
				Okno.close();
			}
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
	
			// Itemy ITEM ITEM
		
		
			player.Walk(klatka,linia,velocity.y,force);
		
			std::stringstream ss,kk;
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
						score=score+10;
						ss << score;
						Score.setString(ss.str());
						
					}
			}
			}
		
			
			// Strzelanie
			// Strzelanie
			//sf::Time timer = clocker.getElapsedTime();
			std::stringstream tt ;
				float ik;
				sf::Time hhh=Animuj.getElapsedTime();
				ik=hhh.asSeconds();
				tt << ik;
				czas.setString(tt.str());

					End.setTextureRect(sf::IntRect(klatka*100,linia*100,100,100));
			if (player.getGlobalBounds().intersects(End.getGlobalBounds()))
			{
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
				{
					Okno.close();
					Muzyka.stop();
					NextNextLvl p;
					p.playGameLvLNext(score,ammo,Live,mana,force,Animuj);	
				}
			}
			introd.setColor(Color::Black);

			if (sf::Keyboard::isKeyPressed(Keyboard::Space))
		{
			fire = true;
				
        }
	
			if (sf::Keyboard::isKeyPressed(Keyboard::Escape))
		{
			Muzyka.pause();
			Ex.Esc(Okno);
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
		

		// Strzelanie 
		// Strzelanie

			//Dec18.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));

			//   Dec.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));

			//	animation2.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			//animation3.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			//	animation4.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));


			silnik -= TIME_STEP;
		}
		
		
		sf::Time Intro = intro.getElapsedTime();
			if (Intro.asSeconds() >= 0.2f )
			{
				introd.setColor(sf::Color::Cyan);
				intro.restart();
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
			if(platform.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<250)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,215);
				}
			}
				if(platform2.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<=350)
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
						if(platform5.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<230)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,195);
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
					if(platform7.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<300)
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
						if(platform8.getGlobalBounds().intersects(player.getGlobalBounds()) && player.getPosition().y<250)
			{
				
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
		
					velocity.y=-Jumpspeed;
					player.move(velocity);
				}
				else 
				{
					velocity.y=0;
					player.setPosition(player.getPosition().x,215);
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
		Okno.draw(ending);
		Okno.draw(Live);
		Okno.draw(Time);
		Okno.draw(czas);
		Okno.draw(Score);
		Okno.draw(Score2);
		Okno.draw(Ammo);
		Okno.draw(Ammo2);
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
		Okno.draw(Amm[2]);
		Okno.draw(Amm[3]);
		Okno.draw(Amm[4]);
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
		}
		if (force == 1)
		{
		 bulletVec2[i].move(22,0);
		}
		if (force == 2)
		{
		 bulletVec2[i].move(12,0);
		}
		if (force == 3)
		{
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

#include "MainMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Engine.h";
#include "Score.h"
#include "tut.h"
using namespace std;
using namespace sf;
MainMenu::MainMenu(void)
{
}
MainMenu::~MainMenu(void)
{
}

Engine play;

void MainMenu::RunMenu()
{
	sf::RenderWindow Okno(sf::VideoMode(800, 600), "Spark"); 
	MainMenu kill;
	tut Tut;
	Okno.setFramerateLimit(60);
	sf::Texture bg;
	sf::Font font;
	font.loadFromFile("Robo.ttf");
	sf::Text start("START", font, 40);
	start.setPosition(335,270);
	sf::Text top("TOP", font, 40);
	top.setPosition(360,540);
	sf::Text opcje("OPCJE", font, 40);
	opcje.setPosition(335,370);
	sf::Text exit("EXIT", font, 40);
	exit.setPosition(355,470);
	sf::RectangleShape Start( sf::Vector2f( 150,50) );
	sf::RectangleShape Top( sf::Vector2f( 100,50) );
	sf::RectangleShape Opcje( sf::Vector2f( 150, 50 ) );
	sf::RectangleShape Exit( sf::Vector2f( 150, 50 ) );
	Opcje.setPosition(320,370);
	Exit.setPosition(320,470);
	Start.setPosition(320,270);
	Top.setPosition(345,540);
	Opcje.setFillColor( Color::Transparent);
	Top.setFillColor( Color::Transparent);
	Exit.setFillColor( Color::Transparent);
	Start.setFillColor( Color::Transparent);
	Opcje.setOutlineColor( Color::White );
	Top.setOutlineColor( Color::White );
	Exit.setOutlineColor( Color::White );
	Start.setOutlineColor( Color::White );
	Opcje.setOutlineThickness(2);
	Top.setOutlineThickness(2);
	Exit.setOutlineThickness(2);
	Start.setOutlineThickness(2);
	bg.loadFromFile("Data/Images/MenuBg.png");
	bg.setSmooth(true);
	sf::Sprite title(bg);
	title.setPosition(0, 0);

	sf::Texture decoration1;
	decoration1.loadFromFile("Data/Anim/deco.png");


	sf::Sprite animation,animation2,animation3,animation4,animation5;
	animation.setTexture(decoration1);
	animation2.setTexture(decoration1);
	animation3.setTexture(decoration1);
	animation4.setTexture(decoration1);
	animation5.setTexture(decoration1);

	animation2.setPosition(800,0);
	animation2.setRotation(90);
	animation3.setPosition(0,600);
	animation3.setRotation(270);
	animation4.setPosition(800,600);
	animation4.setRotation(180);

	sf::SoundBuffer button;
	button.loadFromFile("Data/Audio/button.wav");
	sf::Sound Button;
	Button.setBuffer(button);
	sf::Music SoundtrackMenu;
	SoundtrackMenu.openFromFile("Data/Audio/SoundtrackMenu.wav");
	SoundtrackMenu.play();

	
	sf::Event windowEvent;
	sf::Event event;
	int klatka = 0;


	int linia = 0;


	sf::Clock zegar_klatki; 



	sf::Clock zegar_petli;

	float silnik = 0;


	float TIME_STEP = 0.03f;

	while(Okno.isOpen())
	{

		Okno.clear(sf::Color(0,0,255,255));


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

			if(zegar_klatki.getElapsedTime().asSeconds() > 0.01)
			{

				zegar_klatki.restart();


				klatka++;
			}


			if(klatka >= 4)
			{

				klatka = 0;


				linia++;
			}


			if(linia >= 3)
			{

				linia = 0;
			}

			animation.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			animation2.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			animation3.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			animation4.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));


			silnik -= TIME_STEP;
		}
		if (SoundtrackMenu.getStatus()!=sf::Music::Playing) SoundtrackMenu.play();
		Button.setPlayingOffset(sf::seconds(2));
		Okno.clear(sf::Color::Black);	  
		sf::Vector2i pozycja = sf::Mouse::getPosition(Okno);
		if (pozycja.x >=320 && pozycja.x <=470)
		{
			if (pozycja.y >=270 && pozycja.y <=320)
			{
				Start.setOutlineColor(Color::Red);
				Start.setOutlineThickness(12);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						start.setFillColor(Color::Green);
						SoundtrackMenu.stop();
						Okno.close();
						Tut.start();
						start.setFillColor(Color::White);
					}
				}
				//Button.play();
			}
			else Start.setOutlineColor(Color::White); Start.setOutlineThickness(2);
			if (pozycja.y >=540 && pozycja.y <=590)
			{
				Top.setOutlineColor(Color::Red);
				Top.setOutlineThickness(2);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						SoundtrackMenu.stop();
						Score p;
						top.setFillColor(Color::Green);
						p.Odczyt();
						top.setFillColor(Color::White);
					}
				}
				//Button.play();
			}
			else Top.setOutlineColor(Color::White); Start.setOutlineThickness(2);
			if (pozycja.y >=370 && pozycja.y <=420)
			{
				Opcje.setOutlineColor(Color::Red);
				Opcje.setOutlineThickness(12);

				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						
						opcje.setFillColor(Color::Green);
						RunStettigs();
						opcje.setFillColor(Color::White);
					}
				}	
			}

			//Button.play();
			else Opcje.setOutlineColor(Color::White); Opcje.setOutlineThickness(2);
			if (pozycja.y >=470 && pozycja.y <=520)
			{
				Exit.setOutlineColor(Color::Red);
				Exit.setOutlineThickness(12);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						Okno.close();
					}
				}
				//Button.play();
			}
			else Exit.setOutlineColor(Color::White); Exit.setOutlineThickness(2);

		}
		else { Start.setOutlineColor(Color::White); Opcje.setOutlineColor(Color::White); Exit.setOutlineColor(Color::White); }
		sf::Event event;
		while (Okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Okno.close();
		}

		Okno.draw(title);
		Okno.draw(Opcje);
		Okno.draw(top);
		Okno.draw(Exit);
		Okno.draw(Start);
		Okno.draw(start);
		Okno.draw(opcje);
		Okno.draw(exit);
		Okno.draw(Top);
		Okno.draw(animation);
		Okno.draw(animation2);
		Okno.draw(animation3);
		Okno.draw(animation4);

		Okno.display();
	}

}

void MainMenu::RunStettigs()
{
	sf::RenderWindow Stettigs(sf::VideoMode(400, 400), "Spark Stettigs");
	int klatka = 0;
	int linia = 0;
	sf::Clock zegar_klatki; 
	sf::Clock zegar_petli;
	float silnik = 0;
	float TIME_STEP = 0.03f;
	sf::Event windowEvent;
	sf::Texture BG;
	BG.loadFromFile("Data/Images/Options.png");
	sf::Sprite bg;
	bg.setTexture(BG);
	sf::Font font;
	font.loadFromFile("Robo.ttf");
	sf::Text title("GRAPHICS",font,50);
	sf::Text sync("VSync: Disabled",font,25);
	sf::Text high("High",font,40);
	sf::Text medium("Medium",font,25);
	sf::Text low("Low",font,40);
	sf::Text apply("APPLY",font,40);
	sf::Text back("BACK",font,40);
	back.setPosition(30,340);
	back.setFillColor(Color::White);
	apply.setPosition(260,340);
	apply.setFillColor(Color::White);
	title.setPosition(82,47);
	title.setColor(Color::Cyan);
	title.setOutlineColor(Color::Transparent);
	title.setOutlineThickness(2);
	title.setStyle(sf::Text::Bold);
	sync.setPosition(110,250);
	sync.setOutlineColor(Color::White);
	sync.setOutlineThickness(1);
	high.setPosition(40,140);
	high.setOutlineColor(Color::White);
	high.setOutlineThickness(0.7);
	medium.setPosition(160,150);
	medium.setOutlineColor(Color::White);
	medium.setOutlineThickness(0.7);
	low.setPosition(280,140);
	low.setOutlineColor(Color::White);
	low.setOutlineThickness(0.7);
	sf::RectangleShape High( sf::Vector2f( 100,50) );
	sf::RectangleShape Medium ( sf::Vector2f( 100,50) );
	sf::RectangleShape Low( sf::Vector2f( 100,50) );
	sf::RectangleShape Sync( sf::Vector2f( 180,60) );
	sf::RectangleShape Apply( sf::Vector2f( 150,50) );
	sf::RectangleShape Back( sf::Vector2f( 150,50) );
	Back.setPosition(10,340);
	Apply.setPosition(240,340);
	Sync.setPosition(107,240);
	High.setPosition(30,140);
	Medium.setPosition(150,140);
	Low.setPosition(270,140);
	Back.setFillColor(Color::Transparent);
	Back.setOutlineColor(Color::White);
	Back.setOutlineThickness(3);
	Apply.setFillColor(Color::Transparent);
	Apply.setOutlineColor(Color::White);
	Apply.setOutlineThickness(3);
	Sync.setFillColor(Color::Transparent);
	Sync.setOutlineColor(Color::White);
	Sync.setOutlineThickness(3);
	High.setFillColor(Color::Transparent);
	Medium.setFillColor(Color::Transparent);
	Low.setFillColor(Color::Transparent);
	High.setOutlineColor(Color::White);
	Medium.setOutlineColor(Color::White);
	Low.setOutlineColor(Color::White);
	High.setOutlineThickness(3);
	Medium.setOutlineThickness(3);
	Low.setOutlineThickness(3);
	sf::Color test;
	sf::Texture stet;
	stet.loadFromFile("Data/Anim/test2.png");
	sf::Sprite Stet,Stet2;
	Stet.setTexture(stet);
	Stet2.setTexture(stet);
	Stet2.setPosition(400,0);
	Stet2.setRotation(90);


	while(Stettigs.isOpen())
	{


		Stettigs.clear(sf::Color(0,0,255,255));

		silnik += zegar_petli.restart().asSeconds();

		while(Stettigs.pollEvent(windowEvent))
		{
			if(windowEvent.type == sf::Event::Closed)
			{
				Stettigs.close();
			}
		}


		if(silnik > TIME_STEP)
		{

			if(zegar_klatki.getElapsedTime().asSeconds() > 0.01)
			{

				zegar_klatki.restart();


				klatka++;
			}


			if(klatka >= 3)
			{

				klatka = 0;


				linia++;
			}


			if(linia >= 3)
			{

				linia = 0;
			}

			Stet.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			Stet2.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			//animation3.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			//animation4.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));


			silnik -= TIME_STEP;
		}
		Stettigs.clear(sf::Color::Black);
		sf::Vector2i pozycja = sf::Mouse::getPosition(Stettigs);

		if (pozycja.y >=240 && pozycja.y <=300)
		{
			if (pozycja.x >=107 && pozycja.x <=287)
			{
				Sync.setOutlineColor(Color::Red);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						Sync.setOutlineColor(Color::Green);
						Sync.setOutlineThickness(6);
						sync.setOutlineColor(Color::Green);
						sync.setString("VSync: Enabled");
					}
				}
			}
		}
		else Sync.setOutlineColor(Color::White);
		if (pozycja.y >=340 && pozycja.y <=390)
		{
			if (pozycja.x >=240 && pozycja.x <=390)
			{
				Apply.setOutlineColor(Color::Red);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						Apply.setOutlineColor(Color::Green);
						apply.setOutlineColor(Color::Green);
						apply.setOutlineThickness(3);
						Apply.setOutlineThickness(6);
						sync.setOutlineColor(Color::White);
						high.setOutlineColor(Color::White);
						medium.setOutlineColor(Color::White);
						low.setOutlineColor(Color::White);
					}
				}
			}
			else Apply.setOutlineColor(Color::White);
			if (pozycja.x >=10 && pozycja.x <=160)
			{
				Back.setOutlineColor(Color::Red);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						Back.setOutlineColor(Color::Green);
						back.setOutlineColor(Color::Green);
						Back.setOutlineThickness(6);
						Stettigs.close();
					}
				}
			}
			else Back.setOutlineColor(Color::White);
		}
		else {Apply.setOutlineColor(Color::White); Back.setOutlineColor(Color::White); }

		if (pozycja.y >=140 && pozycja.y <=190)
		{
			if (pozycja.x >=30 && pozycja.x <=130)
			{
				High.setOutlineColor(Color::Red);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						High.setOutlineColor(Color::Green);
						High.setOutlineThickness(6);
						high.setOutlineColor(Color::Green);
						medium.setOutlineColor(Color::White);
						low.setOutlineColor(Color::White);
					}
				}	
				//Button.play();
			}
			else High.setOutlineColor(Color::White); High.setOutlineThickness(2);
			if (pozycja.x >=150 && pozycja.x <=250)
			{
				Medium.setOutlineColor(Color::Red);

				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						Medium.setOutlineColor(Color::Green);
						Medium.setOutlineThickness(6);
						medium.setOutlineColor(Color::Green);
						low.setOutlineColor(Color::White);
						high.setOutlineColor(Color::White);
					}
				}	
			}

			//Button.play();
			else Medium.setOutlineColor(Color::White); Medium.setOutlineThickness(2);
			if (pozycja.x >=270 && pozycja.x <=370)
			{
				Low.setOutlineColor(Color::Red);			
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						Low.setOutlineColor(Color::Green);
						Low.setOutlineThickness(6);
						low.setOutlineColor(Color::Green);
						medium.setOutlineColor(Color::White);
						high.setOutlineColor(Color::White);
					}
				}	
				//Button.play();
			}
			else Low.setOutlineColor(Color::White); Low.setOutlineThickness(2);

		}
		else { High.setOutlineColor(Color::White); Medium.setOutlineColor(Color::White); Low.setOutlineColor(Color::White); }
		Stettigs.draw(bg);
		Stettigs.draw(title);
		Stettigs.draw(High);
		Stettigs.draw(Medium);
		Stettigs.draw(Low);
		Stettigs.draw(Apply);
		Stettigs.draw(apply);
		Stettigs.draw(sync);
		Stettigs.draw(low);
		Stettigs.draw(medium);
		Stettigs.draw(high);
		Stettigs.draw(Sync);
		Stettigs.draw(Back);
		Stettigs.draw(back);
		Stettigs.draw(Stet);
		Stettigs.draw(Stet2);
		Stettigs.display();
	} 
}



void MainMenu::Esc(sf::RenderWindow& Okno)
{
	sf::RenderWindow Quit(sf::VideoMode(300, 300), "Spark Stettigs");
	int klatka = 0;
	int linia = 0;
	sf::Clock zegar_klatki; 
	sf::Clock zegar_petli;
	float silnik = 0;
	float TIME_STEP = 0.03f;
	sf::Event windowEvent;
	sf::Texture BG;
	BG.loadFromFile("Data/Images/Options.png");
	sf::Sprite bg;
	bg.setTexture(BG);
	sf::Font font;
	font.loadFromFile("Robo.ttf");
	sf::Text res("RESTART",font,40);
	sf::Text escape("EXIT",font,40);
	sf::Text menu("MENU",font,40);
	res.setPosition(74,40);
	res.setOutlineColor(Color::Cyan);
	res.setOutlineThickness(1);
	escape.setPosition(110,240);
	escape.setOutlineColor(Color::Cyan);
	escape.setOutlineThickness(1);
	menu.setPosition(105,140);
	menu.setOutlineColor(Color::Cyan);
	menu.setOutlineThickness(0.7);
	sf::RectangleShape High( sf::Vector2f( 180,60) );
	sf::RectangleShape Sync( sf::Vector2f( 180,60) );
	sf::RectangleShape Res( sf::Vector2f( 180,60) );
	Sync.setPosition(65,230);
	High.setPosition(65,130);
	Res.setPosition(65,30);
	Sync.setFillColor(Color::Transparent);
	Sync.setOutlineColor(Color::White);
	Sync.setOutlineThickness(3);
	High.setFillColor(Color::Transparent);
	High.setOutlineColor(Color::White);
	High.setOutlineThickness(3);
	Res.setFillColor(Color::Transparent);
	Res.setOutlineColor(Color::White);
	Res.setOutlineThickness(3);

	

	sf::Color test;
	sf::Texture stet;
	stet.loadFromFile("Data/Anim/test2.png");
	sf::Sprite Stet,Stet2;
	Stet.setTexture(stet);
	Stet2.setTexture(stet);
	Stet2.setPosition(400,0);
	Stet2.setRotation(90);


	while(Quit.isOpen())
	{


		Quit.clear(sf::Color(0,0,255,255));

		silnik += zegar_petli.restart().asSeconds();

		while(Quit.pollEvent(windowEvent))
		{
			if(windowEvent.type == sf::Event::Closed)
			{
				Quit.close();
			}
		}


		if(silnik > TIME_STEP)
		{

			if(zegar_klatki.getElapsedTime().asSeconds() > 0.01)
			{

				zegar_klatki.restart();


				klatka++;
			}


			if(klatka >= 3)
			{

				klatka = 0;


				linia++;
			}


			if(linia >= 3)
			{

				linia = 0;
			}

			Stet.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			Stet2.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			//animation3.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));
			//animation4.setTextureRect(sf::IntRect(klatka*50,linia*50,50,50));


			silnik -= TIME_STEP;
		}
		Quit.clear(sf::Color::Black);
		sf::Vector2i pozycja = sf::Mouse::getPosition(Quit);

		if (pozycja.y >=230 && pozycja.y <=290)
		{
			if (pozycja.x >=65 && pozycja.x <=(65+180))
			{
				Sync.setOutlineColor(Color::Red);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						
						Sync.setOutlineThickness(6);
						Quit.close();
						Okno.close();
					}
				}
			}
		}
		else Sync.setOutlineColor(Color::White);
	
		if (pozycja.y >=130 && pozycja.y <=190)
		{
			if (pozycja.x >=65 && pozycja.x <=(65+180))
			{
				High.setOutlineColor(Color::Red);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						High.setOutlineThickness(6);
						Okno.close();
						Quit.close();
						RunMenu();
					}	
				//Button.play();
			}
			}
		}
			else High.setOutlineColor(Color::White);

			if (pozycja.y >=30 && pozycja.y <=90)
		{
			if (pozycja.x >=65 && pozycja.x <=(65+180))
			{
				Res.setOutlineColor(Color::Red);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						Res.setOutlineThickness(6);
						//Okno.close();
						Quit.close();
						Okno.close();
						
						restart.RunLvl();


					}	
				//Button.play();
			}
			}
		}
			else Res.setOutlineColor(Color::White);
			
			
	
		Quit.draw(bg);
		Quit.draw(res);
		Quit.draw(Res);
		//Quit.draw(res);
		Quit.draw(High);
		Quit.draw(escape);
		Quit.draw(menu);
		Quit.draw(Sync);
		Quit.draw(Stet);
		Quit.draw(Stet2);
		Quit.display();
	} 
}

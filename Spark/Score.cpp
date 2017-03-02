#include "Score.h"
#include <fstream>
#include <iostream>

using namespace sf;
struct dane 
{
sf::Text Nick;
float punkty;
};
int i=0;
dane Baza[15];
Score::Score(void)
{
	
}


Score::~Score(void)
{
}



void Score::Save(int score,float time, int ammo)
{
	
	sf::RenderWindow Quit(sf::VideoMode(400, 400), "Score");
	int klatka = 0;
	int linia = 0;
	sf::Clock zegar_klatki; 
	sf::Clock zegar_petli;
	float silnik = 0;
	float TIME_STEP = 0.03f;
	sf::Event windowEvent;
	sf::Texture BG;
	BG.loadFromFile("Data/Images/score.png");
	sf::Sprite bg;
	bg.setTexture(BG);
	sf::Font font;
	font.loadFromFile("Robo.ttf");
	sf::Text podpis("Wpisz sie",font,30);
	sf::Text podpis1("Twoj Wynik",font,30);
	sf::Text escape("Zapisz",font,40);
	sf::Text pkt("",font,40);
	sf::Text pod("",font,30);
	podpis.setPosition(140,10);
	podpis.setOutlineColor(Color::Yellow);
	podpis.setOutlineThickness(1);
	podpis1.setPosition(130,140);
	podpis1.setOutlineColor(Color::Yellow);
	podpis1.setOutlineThickness(1);
	escape.setPosition(135,320);
	escape.setOutlineColor(Color::Yellow);
	escape.setOutlineThickness(1);
	pkt.setPosition(130,182);
	pkt.setOutlineColor(Color::Cyan);
	pod.setPosition(130,60);
	pod.setFillColor(Color::Cyan);
	pod.setOutlineColor(Color::Cyan);
	pod.setOutlineThickness(0.7);
	pkt.setOutlineThickness(0.7);
	sf::RectangleShape Pkt( sf::Vector2f( 180,60) );
	sf::RectangleShape Sync( sf::Vector2f( 180,60) );
	sf::RectangleShape Podpis( sf::Vector2f( 180,60) );
	Sync.setPosition(110,310);
	Pkt.setPosition(110,180);
	Podpis.setPosition(110,50);
	Sync.setFillColor(Color::Transparent);
	Sync.setOutlineColor(Color::Green);
	Sync.setOutlineThickness(3);
	Pkt.setFillColor(Color::Transparent);
	Pkt.setOutlineColor(Color::Green);
	Pkt.setOutlineThickness(3);
	Podpis.setFillColor(Color::Transparent);
	Podpis.setOutlineColor(Color::Green);
	Podpis.setOutlineThickness(3);

	

	sf::Color test;
	sf::Texture stet;
	stet.loadFromFile("Data/Anim/deco2.png");
	sf::Sprite Stet,Stet2;
	Stet.setTexture(stet);
	Stet2.setTexture(stet);
	Stet2.setPosition(400,0);
	Stet2.setRotation(90);
	std::string string = "";
	std::size_t maxTextLength = 8;
	sf::Music Muzyka;
	Muzyka.openFromFile("Data/Music/polka.wav");

	while(Quit.isOpen())
	{

			if (Muzyka.getStatus()!=sf::Music::Playing) Muzyka.play();

		Quit.clear(sf::Color(0,0,255,255));

		silnik += zegar_petli.restart().asSeconds();

		while(Quit.pollEvent(windowEvent))
		{		
			if (windowEvent.type == Event::TextEntered)
			{
				if (windowEvent.text.unicode < 128 && string.size() < maxTextLength)
				string += static_cast<char>(windowEvent.text.unicode);
				pod.setString(string);
			}
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

		if (pozycja.y >=310 && pozycja.y <=360)
		{
			if (pozycja.x >=110 && pozycja.x <=(110+180))
			{
				Sync.setOutlineColor(Color::Red);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						Score kupka;
						kupka.zapisz(pod,((score+ammo)/time));
						Sync.setOutlineThickness(6);
						Quit.close();
						Muzyka.stop();
						MainMenu menu;
						menu.RunMenu();
						//Okno.close();
					}
				}
			}
		}
		else Sync.setOutlineColor(Color::Green);
	
		if (pozycja.y >=130 && pozycja.y <=190)
		{
			if (pozycja.x >=110 && pozycja.x <=(110+180))
			{
		
			}
		}
			else Pkt.setOutlineColor(Color::Green);

			if (pozycja.y >=30 && pozycja.y <=90)
		{
			if (pozycja.x >=110 && pozycja.x <=(110+180))
			{
		
			}
		}
			else Podpis.setOutlineColor(Color::Green);
			std::stringstream kk;
			kk << ((score+ammo)/time);
			pkt.setString(kk.str());
	
		Quit.draw(bg);
		Quit.draw(podpis);
		Quit.draw(Podpis);
		Quit.draw(pod);
		Quit.draw(podpis1);
		Quit.draw(Pkt);
		Quit.draw(escape);
		Quit.draw(pkt);
		Quit.draw(Sync);
		Quit.draw(Stet);
		Quit.draw(Stet2);
		Quit.display();
	} 
}

void Score::zapisz(sf::Text k, float p)
{
	if (i==0)
	{
		for (int t=0;t<15;t++)
		{
		Baza[t].punkty=0;
		}
	}
	Baza[i].Nick=k;
	Baza[i].punkty=p;
		i++;
}

void Score::Odczyt()
{
	sf::RenderWindow Quit(sf::VideoMode(500, 500), "HighScore");
	int klatka = 0;
	int linia = 0;
	sf::Clock zegar_klatki; 
	sf::Clock zegar_petli;
	float silnik = 0;
	float TIME_STEP = 0.03f;
	sf::Event windowEvent;
	sf::Texture BG;
	BG.loadFromFile("Data/Images/topscore.png");
	sf::Sprite bg;
	bg.setTexture(BG);
	sf::Font font;

	font.loadFromFile("Robo.ttf");
	sf::Text podpis("Top Score",font,50);
	sf::Text podpis1("Twoj Wynik",font,30);
	sf::Text escape("BACK",font,40);
	sf::Text pkt("",font,40);
	sf::Text pod("",font,30);
	/// Punktowanie
	sf::Text puntk1 ("1|",font,30); 
	sf::Text puntk2 ("2|",font,30); 
	sf::Text puntk3 ("3|",font,30); 
	sf::Text puntk4 ("4|",font,30); 
	sf::Text puntk5 ("5|",font,30); 
	puntk1.setFillColor(Color::Magenta);
	puntk2.setFillColor(Color::Magenta);
	puntk3.setFillColor(Color::Magenta);
	puntk4.setFillColor(Color::Magenta);
	puntk5.setFillColor(Color::Magenta);
	puntk1.setPosition(150,100);
	puntk2.setPosition(150,150);
	puntk3.setPosition(150,200);
	puntk4.setPosition(150,250);
	puntk5.setPosition(150,300);
				// Posort BubbleSort
	 for( int u = 0; u < 14; u++ )
    {
        for( int j = 0; j < 14 - 1; j++ )
        {
			if( Baza[ j ].punkty < Baza[ j + 1 ].punkty )
                 swap( Baza[ j ], Baza[ j + 1 ] );  
        }
    }
	//Posort BubbleSort
	/// Punktowanie
	/// Odczyt najepszych
	sf::Text pierwszy("kupa",font,30);
	pierwszy.setString(Baza[0].Nick.getString());
	pierwszy.setFillColor(Color::Red);
	pierwszy.setPosition(180,100);
	sf::Text drugi("kupa",font,30);
	drugi.setString(Baza[1].Nick.getString());
	drugi.setFillColor(Color::Red);
	drugi.setPosition(180,150);
	sf::Text trzeci("kupa",font,30);
	trzeci.setString(Baza[2].Nick.getString());
	trzeci.setFillColor(Color::Red);
	trzeci.setPosition(180,200);
	sf::Text czwarty("kupa",font,30);
	czwarty.setString(Baza[3].Nick.getString());
	czwarty.setFillColor(Color::Red);
	czwarty.setPosition(180,250);
	sf::Text piaty("kupa",font,30);
	piaty.setString(Baza[4].Nick.getString());
	piaty.setFillColor(Color::Red);
	piaty.setPosition(180,300);
	/// Odczyt najepszych
	/// PuntyNaj
	sf::Text pkt1("kupa",font,30);
	sf::Text pkt2("kupa",font,30);
	sf::Text pkt3("kupa",font,30);
	sf::Text pkt4("kupa",font,30);
	sf::Text pkt5("kupa",font,30);
	pkt1.setFillColor(Color::Magenta);
	pkt2.setFillColor(Color::Magenta);
	pkt3.setFillColor(Color::Magenta);
	pkt4.setFillColor(Color::Magenta);
	pkt5.setFillColor(Color::Magenta);
	pkt1.setPosition(330,100);
	pkt2.setPosition(330,150);
	pkt3.setPosition(330,200);
	pkt4.setPosition(330,250);
	pkt5.setPosition(330,300);
		/// PunktyNaj

	std::stringstream k1,k2,k3,k4,k5;
	k1 << Baza[0].punkty;
	k2 << Baza[1].punkty;
	k3 << Baza[2].punkty;
	k4 << Baza[3].punkty;
	k5 << Baza[4].punkty;
	pkt1.setString(k1.str());
	pkt2.setString(k2.str());
	pkt3.setString(k3.str());
	pkt4.setString(k4.str());
	pkt5.setString(k5.str());

	podpis.setPosition(140,20);
	podpis.setOutlineColor(Color::White);
	podpis.setFillColor(Color::Cyan);
	podpis.setOutlineThickness(1);
	podpis1.setPosition(130,140);
	podpis1.setOutlineColor(Color::Yellow);
	podpis1.setOutlineThickness(1);
	escape.setPosition(210,420);
	escape.setOutlineColor(Color::Yellow);
	escape.setOutlineThickness(1);
	pkt.setPosition(130,182);
	pkt.setOutlineColor(Color::Cyan);
	pod.setPosition(130,60);
	pod.setFillColor(Color::Cyan);
	pod.setOutlineColor(Color::Cyan);
	pod.setOutlineThickness(0.7);
	pkt.setOutlineThickness(0.7);
	sf::RectangleShape Pkt( sf::Vector2f( 180,60) );
	sf::RectangleShape Sync( sf::Vector2f( 180,60) );
	sf::RectangleShape Podpis( sf::Vector2f( 180,60) );
	Sync.setPosition(170,410);
	Pkt.setPosition(110,180);
	Podpis.setPosition(110,50);
	Sync.setFillColor(Color::Transparent);
	Sync.setOutlineColor(Color::Cyan);
	Sync.setOutlineThickness(3);
	Pkt.setFillColor(Color::Transparent);
	Pkt.setOutlineColor(Color::Green);
	Pkt.setOutlineThickness(3);
	Podpis.setFillColor(Color::Transparent);
	Podpis.setOutlineColor(Color::Green);
	Podpis.setOutlineThickness(3);

	

	sf::Color test;
	sf::Texture stet;
	stet.loadFromFile("Data/Anim/deco.png");
	sf::Sprite Stet,Stet2;
	Stet.setTexture(stet);
	Stet2.setTexture(stet);
	Stet2.setPosition(500,0);
	Stet2.setRotation(90);
	std::string string = "";
	std::size_t maxTextLength = 8;
	sf::Music Muzyka;
	Muzyka.openFromFile("Data/Music/sax.wav");

	while(Quit.isOpen())
	{

			if (Muzyka.getStatus()!=sf::Music::Playing) Muzyka.play();

		Quit.clear(sf::Color(0,0,255,255));

		silnik += zegar_petli.restart().asSeconds();

		while(Quit.pollEvent(windowEvent))
		{		
			if (windowEvent.type == Event::TextEntered)
			{
				if (windowEvent.text.unicode < 128 && string.size() < maxTextLength)
				string += static_cast<char>(windowEvent.text.unicode);
				pod.setString(string);
			}
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

		if (pozycja.y >=410 && pozycja.y <=460)
		{
			if (pozycja.x >=170 && pozycja.x <=(170+180))
			{
				Sync.setOutlineColor(Color::Red);
				if (windowEvent.type == sf::Event::MouseButtonPressed)
				{
					if (windowEvent.mouseButton.button == sf::Mouse::Left)
					{
						Quit.close();
						Muzyka.stop();
					
					}
				}
			}
		}
		else Sync.setOutlineColor(Color::Cyan);
	
		if (pozycja.y >=130 && pozycja.y <=190)
		{
			if (pozycja.x >=110 && pozycja.x <=(110+180))
			{
		
			}
		}
			else Pkt.setOutlineColor(Color::Green);

			if (pozycja.y >=30 && pozycja.y <=90)
		{
			if (pozycja.x >=110 && pozycja.x <=(110+180))
			{
		
			}
		}
			else Podpis.setOutlineColor(Color::Green);
			std::stringstream kk;
			pkt.setString(kk.str());
	
		Quit.draw(bg);
		Quit.draw(podpis);
	//	Quit.draw(Podpis);
	//	Quit.draw(pod);
	//	Quit.draw(podpis1);
	//	Quit.draw(Pkt);
		Quit.draw(escape);
	//	Quit.draw(pkt);
		Quit.draw(puntk1);
		Quit.draw(puntk2);
		Quit.draw(puntk3);
		Quit.draw(puntk4);
		Quit.draw(puntk5);
		Quit.draw(pierwszy);
		Quit.draw(drugi);
		Quit.draw(trzeci);
		Quit.draw(czwarty);
		Quit.draw(piaty);
		Quit.draw(pkt1);
		Quit.draw(pkt2);
		Quit.draw(pkt3);
		Quit.draw(pkt4);
		Quit.draw(pkt5);
		Quit.draw(Sync);
		Quit.draw(Stet);
		Quit.draw(Stet2);
		Quit.display();
	} 
}






  
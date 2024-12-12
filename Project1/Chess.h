#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Board.h"
using namespace std;
class Chess
{
private:
	Board Board;
	bool Gamestate;
	string Turn;
public:
	Chess();
	void play();
};
Chess::Chess()
{
	Gamestate = 1;
	Turn = "White";
	this->Board.initializeBoard();
}
void Chess::play()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(640,640),"Chess");
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
			if (evnt.type == sf::Event::MouseButtonPressed)
			{
				if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					float xpos = sf::Mouse::getPosition(window).x;
					float ypos = sf::Mouse::getPosition(window).y;
					cout << "X: " << xpos << " Y: " << ypos << endl;
				}
			}

		}
		window.clear();
		Board.Drawboard(window);
		window.display();
	}
}

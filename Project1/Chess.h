#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Board.h"
using namespace std;
class Chess
{
private:
	Board board;
public:
	Chess();
	void play();
};
Chess::Chess()
{
	this->board.initializeBoard();
}
void Chess::play()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(640,640),"Chess");
	board.play(window);
}

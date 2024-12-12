#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;
class Bishop :public Piece
{
private:
	
public:
	Bishop(char c, cordinates x, sf::Vector2f pos);
};
Bishop::Bishop(char c,cordinates x,sf::Vector2f pos) :Piece(c, x, pos){}
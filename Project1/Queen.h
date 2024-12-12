#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;
class Queen :public Piece
{
private:
	
public:
	Queen(char c, cordinates x, sf::Vector2f pos);
};
Queen::Queen(char c, cordinates x, sf::Vector2f pos) :Piece(c, x, pos)
{

}

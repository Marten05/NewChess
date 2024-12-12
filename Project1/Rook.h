#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;
class Rook :public Piece
{
private:
	
public:
	Rook(char c, cordinates x, sf::Vector2f pos);
};
Rook::Rook(char c, cordinates x, sf::Vector2f pos) :Piece(c, x, pos)
{

}
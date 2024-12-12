#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;
class King :public Piece
{
private:
	
public:
	King(char c, cordinates x, sf::Vector2f pos);
};
King::King(char c, cordinates x, sf::Vector2f pos) :Piece(c, x, pos)
{

}
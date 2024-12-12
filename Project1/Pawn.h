#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;
class Pawn :public Piece
{
private:
	
public:
	Pawn(char c, cordinates x, sf::Vector2f pos);
};
Pawn::Pawn(char c, cordinates x, sf::Vector2f pos):Piece(c,x,pos){}
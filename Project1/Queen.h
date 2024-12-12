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
	Queen(string Type, char c, cordinates x, sf::Vector2f pos, string fileName);
};
Queen::Queen(string TypePiece, char c, cordinates x, sf::Vector2f pos, string fileName) :Piece(TypePiece,c, x, pos, fileName)
{

}

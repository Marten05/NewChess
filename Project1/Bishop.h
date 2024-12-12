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
	Bishop(string Type, char c, cordinates x, sf::Vector2f pos, string fileName);
};
Bishop::Bishop(string TypePiece, char c, cordinates x, sf::Vector2f pos, string fileName) :Piece(TypePiece, c, x, pos, fileName) {}
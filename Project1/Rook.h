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
	Rook(string Type, char c, cordinates x, sf::Vector2f pos, string fileName);
};
Rook::Rook(string Type, char c, cordinates x, sf::Vector2f pos, string fileName) :Piece(Type, c, x, pos, fileName)
{
}
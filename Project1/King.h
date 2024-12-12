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
	King(string Type, char c, cordinates x, sf::Vector2f pos, string fileName);
};
King::King(string Type, char c, cordinates x, sf::Vector2f pos, string fileName) :Piece(Type, c, x, pos, fileName)
{

}
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;
class Horse :public Piece
{
private:
	
public:
	Horse(string Type, char c, cordinates x, sf::Vector2f pos, string fileName);
};
Horse::Horse(string Type, char c, cordinates x, sf::Vector2f pos, string fileName) :Piece(Type, c, x, pos, fileName)
{

}
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
	Horse(char c, cordinates x, sf::Vector2f pos);
};
Horse::Horse(char c, cordinates x, sf::Vector2f pos) :Piece(c, x, pos)
{

}
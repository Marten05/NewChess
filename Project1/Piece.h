#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
struct cordinates
{
	int x, y;
};
class Piece
{
protected:
	char color;
	sf::Vector2f position;
	cordinates index;
public:
	Piece(char c,cordinates x, sf::Vector2f pos);
};
Piece::Piece(char c, cordinates x, sf::Vector2f pos)
{
	color = c;
	index.x = x.x;
	index.y = x.y;
	position.x = pos.x;
	position.y = pos.y;
}
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
	string typePiece;
	char color;
	sf::Vector2f position;
	cordinates index;
	string fileName;
	sf::Texture Piecetexture;
	sf::Sprite piece;
public:
	Piece(string TypePiece,char c,cordinates x, sf::Vector2f pos,string fileName);
	void DrawPiece(sf::RenderWindow &win);
	void move(int x, int y);
};
Piece::Piece(string TypePiece,char c, cordinates x, sf::Vector2f pos,string fileName)
{
	typePiece = TypePiece;
	color = c;
	index.x = x.x;
	index.y = x.y;
	position.x = pos.x;
	position.y = pos.y;
	if (!Piecetexture.loadFromFile(fileName))
	{
		cout << "Image not loaded";
	}
	piece.setTexture(Piecetexture);
	piece.setPosition(pos.x,pos.y);
	piece.setScale(0.28f, 0.28f);
}
void Piece::DrawPiece(sf::RenderWindow &win)
{
	win.draw(piece);
}
void Piece::move(int x, int y)
{
	int r = (y - 23) / 75;
	int c = (x - 23) / 75;
	this->index.x = r;
	this->index.y = c;
	this->position.x = ((c * 75) + 23);
	this->position.y = ((r * 75) + 23);
	this->piece.setPosition(position);
}
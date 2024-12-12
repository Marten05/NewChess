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
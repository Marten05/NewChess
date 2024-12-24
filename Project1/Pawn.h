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
	Pawn(string TypePiece, char c, cordinates x, sf::Vector2f pos, string fileName);
	bool virtual isleagalmove(Piece* RC[8][8], int Er, int Ec)override;
};
Pawn::Pawn(string TypePiece, char c, cordinates x, sf::Vector2f pos, string fileName) : Piece(TypePiece, c, x, pos, fileName)
{
}
bool Pawn::isleagalmove(Piece* RC[8][8], int Er, int Ec)
{
	int D = 0;
	if (this->getColor() == true)
	{
		D = -1;
	}
	else
	{
		D = 1;
	}
	if (this->index.y == Ec && Er == this->index.x + D && RC[Er][Ec] == nullptr)
	{
		return true;
	}
	if (this->index.y == Ec && Er == this->index.x +(D*2) && RC[Er][Ec] == nullptr/*&& RC[Er+D][Ec+D] == nullptr*/)
	{
		if ((this->index.x == 1 && this->getColor() == false) || (this->index.x == 6 && this->getColor() == true))
		{
			if (isverticalclear(RC, Er, Ec) == true)
			{
				return true;
			}
		}
	}
	if (abs(this->index.y - Ec) == 1 && Er == this->index.x + D && RC[Er][Ec] != nullptr && RC[Er][Ec]->getColor() != this->getColor())
	{
		return true;
	}
	
	return false;
}
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
	return true;
}
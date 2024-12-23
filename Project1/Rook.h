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
	bool virtual isleagalmove(Piece* RC[8][8], int Er, int Ec)override;
};
Rook::Rook(string Type, char c, cordinates x, sf::Vector2f pos, string fileName) :Piece(Type, c, x, pos, fileName)
{
}
bool Rook::isleagalmove(Piece* RC[8][8], int Er, int Ec)
{
	if (this->horizentalmove(Er, Ec) && this->ishorizentalclear(RC, Er, Ec)) {
		cout << "Horizontal move is valid." << std::endl;
		return true;
	}
	if (this->verticalmove(Er, Ec) && this->isverticalclear(RC, Er, Ec)) {
		cout << "Vertical move is valid." << std::endl;
		return true;
	}
	std::cout << "Move is invalid." << std::endl;
	return false;
}
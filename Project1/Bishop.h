#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;
class Bishop :public Piece
{
private:
	
public:
	Bishop(string Type, char c, cordinates x, sf::Vector2f pos, string fileName);
	bool virtual isleagalmove(Piece* RC[8][8], int Er, int Ec)override;
};
Bishop::Bishop(string TypePiece, char c, cordinates x, sf::Vector2f pos, string fileName) :Piece(TypePiece, c, x, pos, fileName) {}
bool Bishop::isleagalmove(Piece* RC[8][8], int Er, int Ec)
{
    if (this->diagnolmove(Er, Ec) && this->isdiagnolclear(RC, Er, Ec))
    {
        if (RC[Er][Ec] != nullptr)
        {
            if (RC[Er][Ec]->getColor() != this->getColor())
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
   
    cout << "Bishop legal move False" << endl;
    return false;
}
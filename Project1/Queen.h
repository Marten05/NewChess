#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;
class Queen :public Piece
{
private:
	
public:
	Queen(string Type, char c, cordinates x, sf::Vector2f pos, string fileName);
	bool virtual isleagalmove(Piece* RC[8][8], int Er, int Ec)override;
};
Queen::Queen(string TypePiece, char c, cordinates x, sf::Vector2f pos, string fileName) :Piece(TypePiece,c, x, pos, fileName)
{

}
bool Queen::isleagalmove(Piece* RC[8][8], int Er, int Ec)
{
    // Check horizontal or vertical (rook-like move)
    if (this->index.x== Er || this->index.y == Ec)
    {
        if ((this->horizentalmove(Er, Ec) && this->ishorizentalclear(RC, Er, Ec)) || (this->verticalmove(Er, Ec) && this->isverticalclear(RC, Er, Ec)))
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
    }
    // Check  diagonal (bishop-like move)
    if (abs(Er - this->index.x) == abs(Ec - this->index.y)) 
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
    }
  
 
    return false;
}

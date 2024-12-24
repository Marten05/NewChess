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
	bool virtual isleagalmove(Piece* RC[8][8], int xpos, int ypos)override;
};
Horse::Horse(string Type, char c, cordinates x, sf::Vector2f pos, string fileName) :Piece(Type, c, x, pos, fileName)
{

}
bool Horse::isleagalmove(Piece* RC[8][8], int Er, int Ec)
{
  
    if ((abs(Er - this->index.x) == 2 && abs(Ec - this->index.y) == 1) || (abs(Er - this->index.x) == 1 && abs(Ec - this->index.y) == 2)) 
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
  
    cout << "Knight Invalid move" << endl;
    return false;
}
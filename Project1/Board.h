#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Piece.h"
#include "Pawn.h"
#include "Horse.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
using namespace std;
class board
{
private:
	Piece* RC[8][8];
public:
	board();
    void initializeBoard();
};
board::board() 
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) 
        {
            RC[i][j] = nullptr;
        }
    }
}
void board::initializeBoard()
{
    for (int i = 0; i < 8; i++) {
        RC[1][i] = new Pawn('B', { 1, i }, sf::Vector2f(i * 100.f, 100.f));
        RC[6][i] = new Pawn('W', { 6, i }, sf::Vector2f(i * 100.f, 600.f));
    }
    //rooks
    RC[0][0] = new Rook('B', { 0, 0 }, sf::Vector2f(0.f, 0.f));
    RC[0][7] = new Rook('B', { 0, 7 }, sf::Vector2f(700.f, 0.f));
    RC[7][0] = new Rook('W', { 7, 0 }, sf::Vector2f(0.f, 700.f));
    RC[7][7] = new Rook('W', { 7, 7 }, sf::Vector2f(700.f, 700.f));
    //queens
    RC[0][3] = new Queen('B', { 0, 3 }, sf::Vector2f(300.f, 0.f)); 
    RC[7][3] = new Queen('W', { 7, 3 }, sf::Vector2f(300.f, 700.f)); 
    //kings
    RC[0][4] = new King('B', { 0, 4 }, sf::Vector2f(400.f, 0.f));
    RC[7][4] = new King('W', { 7, 4 }, sf::Vector2f(400.f, 700.f));
    //knights
    RC[0][1] = new Horse('B', { 0, 1 }, sf::Vector2f(100.f, 0.f)); 
    RC[0][6] = new Horse('B', { 0, 6 }, sf::Vector2f(600.f, 0.f)); 
    RC[7][1] = new Horse('W', { 7, 1 }, sf::Vector2f(100.f, 700.f)); 
    RC[7][6] = new Horse('W', { 7, 6 }, sf::Vector2f(600.f, 700.f)); 
    //bishops
    RC[0][2] = new Bishop('B', { 0, 2 }, sf::Vector2f(200.f, 0.f));
    RC[0][5] = new Bishop('B', { 0, 5 }, sf::Vector2f(500.f, 0.f));
    RC[7][2] = new Bishop('W', { 7, 2 }, sf::Vector2f(200.f, 700.f));
    RC[7][5] = new Bishop('W', { 7, 5 }, sf::Vector2f(500.f, 700.f));
    
}

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
class Board
{
private:
	Piece* RC[8][8];
    sf::Texture Boardtexture;
    sf::Sprite board;
public:
	Board();
    void initializeBoard();
    void Drawboard(sf::RenderWindow& win);
};
Board::Board() 
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) 
        {
            RC[i][j] = nullptr;
        }
    }
    Boardtexture.loadFromFile("Board.png");
    board.setTexture(Boardtexture);
}
void Board::initializeBoard()
{
    for (int i = 0; i < 8; i++) 
    {
       RC[1][i] = new Pawn("BPawan", 'B', {1, i}, sf::Vector2f(((i * 75) + 27), ((1 * 75) + 22)),"b_pawn.png");
       RC[6][i] = new Pawn("WPawan", 'W', { 6, i }, sf::Vector2f(((i * 75) + 27) ,((6 * 75) + 22)), "w_pawn.png");
    }
    //rooks
    RC[0][0] = new Rook("BRook",'B', { 0, 0 }, sf::Vector2f(((0 * 75) + 23),((0 * 75) + 22)) ,"b_rook.png");
    RC[0][7] = new Rook("BRook", 'B', { 0, 7 }, sf::Vector2f(((7 * 75) + 23),((0 * 75) + 22)),"b_rook.png");
    RC[7][0] = new Rook("WRook", 'W', { 7, 0 }, sf::Vector2f(((0 * 75) + 23),((7 * 75) + 22)),"w_rook.png");
    RC[7][7] = new Rook("WRook", 'W', { 7, 7 }, sf::Vector2f(((7 * 75) + 23),((7 * 75) + 22)),"w_rook.png");
    //queens
    RC[0][3] = new Queen("BQueen", 'B', { 0, 3 }, sf::Vector2f(((3 * 75) + 23), ((0 * 75) + 22)), "b_queen.png");
    RC[7][3] = new Queen("WQueen", 'W', { 7, 3 }, sf::Vector2f(((3 * 75) + 23), ((7 * 75) + 22)), "w_queen.png");
    //kings
    RC[0][4] = new King("BKing", 'B', { 0, 4 }, sf::Vector2f(((4 * 75) + 23), ((0 * 75) + 22)), "b_king.png");
    RC[7][4] = new King("WKing", 'W', { 7, 4 }, sf::Vector2f(((4 * 75) + 23), ((7 * 75) + 22)), "w_king.png");
    //knights
    RC[0][1] = new Horse("BKnight", 'B', { 0, 1 }, sf::Vector2f(((1 * 75) + 23), ((0 * 75) + 22)), "b_horse.png");
    RC[0][6] = new Horse("BKnight", 'B', { 0, 6 }, sf::Vector2f(((6 * 75) + 23), ((0 * 75) + 22)), "b_horse.png");
    RC[7][1] = new Horse("WKnight", 'W', { 7, 1 }, sf::Vector2f(((1 * 75) + 23), ((7 * 75) + 22)), "w_horse.png");
    RC[7][6] = new Horse("WKnight", 'W', { 7, 6 }, sf::Vector2f(((6 * 75) + 23), ((7 * 75) + 22)), "w_horse.png");
    //bishops
    RC[0][2] = new Bishop("BBishop", 'B', { 0, 2 }, sf::Vector2f(((2 * 75) + 23), ((0 * 75) + 22)), "b_bishop.png");
    RC[0][5] = new Bishop("BBishop", 'B', { 0, 5 }, sf::Vector2f(((5 * 75) + 23), ((0 * 75) + 22)), "b_bishop.png");
    RC[7][2] = new Bishop("WBishop", 'W', { 7, 2 }, sf::Vector2f(((2 * 75) + 23), ((7 * 75) + 22)), "w_bishop.png");
    RC[7][5] = new Bishop("WBishop", 'W', { 7, 5 }, sf::Vector2f(((5 * 75) + 23), ((7 * 75) + 22)), "w_bishop.png");

    //for (int i = 0; i < 8; i++)
    //{
    //    RC[1][i] = new Pawn("BPawan", 'B', { 1, i }, sf::Vector2f(((1 * 75) + 22), ((i * 75) + 22)), "b_pawn.png");
    //    RC[6][i] = new Pawn("WPawan", 'W', { 6, i }, sf::Vector2f(((6 * 75) + 22), ((i * 75) + 22)), "w_pawn.png");
    //}
    ////rooks
    //RC[0][0] = new Rook("BRook", 'B', { 0, 0 }, sf::Vector2f(((0 * 75) + 22), ((0 * 75) + 22)), "b_rook.png");
    //RC[0][7] = new Rook("BRook", 'B', { 0, 7 }, sf::Vector2f(((0 * 75) + 22), ((7 * 75) + 22)), "b_rook.png");
    //RC[7][0] = new Rook("WRook", 'W', { 7, 0 }, sf::Vector2f(((7 * 75) + 22), ((0 * 75) + 22)), "w_rook.png");
    //RC[7][7] = new Rook("WRook", 'W', { 7, 7 }, sf::Vector2f(((7 * 75) + 22), ((7 * 75) + 22)), "w_rook.png");
    ////queens
    //RC[0][3] = new Queen("BQueen", 'B', { 0, 3 }, sf::Vector2f(((0 * 75) + 22), ((3 * 75) + 22)), "b_queen.png");
    //RC[7][3] = new Queen("WQueen", 'W', { 7, 3 }, sf::Vector2f(((7 * 75) + 22), ((3 * 75) + 22)), "w_queen.png");
    ////kings
    //RC[0][4] = new King("BKing", 'B', { 0, 4 }, sf::Vector2f(((0 * 75) + 22), ((4 * 75) + 22)), "b_king.png");
    //RC[7][4] = new King("WKing", 'W', { 7, 4 }, sf::Vector2f(((7 * 75) + 22), ((4 * 75) + 22)), "w_king.png");
    ////knights
    //RC[0][1] = new Horse("BKnight", 'B', { 0, 1 }, sf::Vector2f(((0 * 75) + 22), ((1 * 75) + 22)), "b_horse.png");
    //RC[0][6] = new Horse("BKnight", 'B', { 0, 6 }, sf::Vector2f(((0 * 75) + 22), ((6 * 75) + 22)), "b_horse.png");
    //RC[7][1] = new Horse("WKnight", 'W', { 7, 1 }, sf::Vector2f(((7 * 75) + 22), ((1 * 75) + 22)), "w_horse.png");
    //RC[7][6] = new Horse("WKnight", 'W', { 7, 6 }, sf::Vector2f(((7 * 75) + 22), ((6 * 75) + 22)), "w_horse.png");
    ////bishops
    //RC[0][2] = new Bishop("BBishop", 'B', { 0, 2 }, sf::Vector2f(((0 * 75) + 22), ((2 * 75) + 22)), "b_bishop.png");
    //RC[0][5] = new Bishop("BBishop", 'B', { 0, 5 }, sf::Vector2f(((0 * 75) + 22), ((5 * 75) + 22)), "b_bishop.png");
    //RC[7][2] = new Bishop("WBishop", 'W', { 7, 2 }, sf::Vector2f(((7 * 75) + 22), ((2 * 75) + 22)), "w_bishop.png");
    //RC[7][5] = new Bishop("WBishop", 'W', { 7, 5 }, sf::Vector2f(((7 * 75) + 22), ((5 * 75) + 22)), "w_bishop.png");
    
}
void Board::Drawboard(sf::RenderWindow &win)
{
    win.draw(board);

    for (int i = 0; i<8; i++)
    {
        for (int j = 0; j<8; j++)
        {
           if(RC[i][j]!= nullptr)
            RC[i][j]->DrawPiece(win);

        }
    }
}
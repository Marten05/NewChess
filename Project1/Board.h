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
    bool Gamestate;
    bool Turn;//Ture=White,False=Black
    bool allleagalmove[8][8];
    sf::Texture Boardtexture;
    sf::Sprite board;
public:
	Board();
    void initializeBoard();//set initial positions
    void play(sf::RenderWindow &window);//main playing loop
    void Drawboard(sf::RenderWindow& win);//draws the chess board 
    void DrawPiece(Piece* RC[8][8], sf::RenderWindow& win);//daws pieces
    void DrawHighlights(sf::RenderWindow& window, bool alllegalmove[8][8]);//draws highlights
    void unhighlight(bool alllegalmove[8][8]);//remove highlights
    Piece* getpos(int x,int y);//get starting position
    void changeturn();//trun change
    bool isKinginCheck(Piece* RC[8][8]);
    bool isCheckMate();
};
Board::Board() 
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) 
        {
            RC[i][j] = nullptr;
            allleagalmove[i][j] = false;
        }
    }
    Gamestate = 1;
    Turn = 1;
    Boardtexture.loadFromFile("Board.png");
    board.setTexture(Boardtexture);
    
}
//void Board::play(sf::RenderWindow& window)
//{
//    Piece* cur = nullptr; //current piece ptr
//    int Sr = -1, Sc = -1;
//    while (window.isOpen())
//    {
//        sf::Event evnt;
//        while (window.pollEvent(evnt))
//        {
//            if (evnt.type == evnt.Closed)
//            {
//                window.close();
//            }
//            if (evnt.type == sf::Event::MouseButtonPressed)
//            {
//    
//                if (evnt.mouseButton.button == sf::Mouse::Left) 
//                {
//                    
//                    if (cur == nullptr)
//                    {
//                        int xpos = sf::Mouse::getPosition(window).x;
//                        int ypos = sf::Mouse::getPosition(window).y;
//                       
//                            cur = getpos(xpos, ypos);//to get positon
//                            Sr = (ypos - 23) / 75;
//                            Sc = (xpos - 23) / 75;
//                            if (cur != nullptr)
//                            {
//                                cur->highlight(RC, Sr, Sc, allleagalmove);
//                            }
//                        
//                     
//                    }
//                    else if (cur != nullptr)
//                    {
//                        {
//                            
//                            int xpos = sf::Mouse::getPosition(window).x;
//                            int ypos = sf::Mouse::getPosition(window).y;
//                            int Er = (ypos - 23) / 75;
//                            int Ec = (xpos - 23) / 75;
//                            if (cur->isleagalmove(RC,Er,Ec) == 1&& isKinginCheck(RC) == false)//Move to that Position
//                            {
//                                cur->move(Sr,Sc,Er, Ec);
//                                unhighlight(allleagalmove);
//                                RC[Sr][Sc] = nullptr;
//                                RC[Er][Ec] = cur;
//                                if ((Sr == Er) && (Sc == Ec))
//                                {
//                                    changeturn();
//                                }
//                                changeturn();
//                                cur = nullptr;
//                                if (isKinginCheck(RC) == true)
//                                {
//                                    cout << "Check";
//                                }
//                            }
//                            else 
//                            {
//                                cout << "Still checked";
//                                cur = nullptr;
//                            }
//                        }
//                    }
//                }
//            }
//            window.clear();
//            Drawboard(window);
//            DrawPiece(RC, window);
//            DrawHighlights(window,allleagalmove);
//            window.display();
//
//        }
//        
//    }
//}
void Board::initializeBoard()
{
    for (int i = 0; i < 8; i++)
    {
       RC[1][i] = new Pawn("BPawan", 'B', { 1, i }, sf::Vector2f(((i * 75) + 23), ((1 * 75) + 23)), "b_pawn.png");
       RC[6][i] = new Pawn("WPawan", 'W', { 6, i }, sf::Vector2f(((i * 75) + 23) ,((6 * 75) + 23)), "w_pawn.png");
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
}
void Board::Drawboard(sf::RenderWindow &win)
{
    win.draw(board);

   
}
Piece* Board::getpos(int x, int y)
{
        Piece* temp = nullptr;
        int r = (y - 23) / 75;
        int c = (x - 23) / 75;
        if (RC[r][c] == nullptr)
        {
            return temp;
        }
        if (RC[r][c]->getColor() == Turn)
        {
            if (RC[r][c] != nullptr)
            {
                temp = RC[r][c];
                cout << "Selected" << endl;
                return temp;
            }
        }
        return temp;
        
}
void Board::changeturn()
{
    Turn = !Turn;
}
void Board::DrawPiece(Piece* RC[8][8], sf::RenderWindow& win)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (RC[i][j] != nullptr)
            {
                win.draw(RC[i][j]->SpritePiece());
            }

        }
    }
}
void Board::DrawHighlights(sf::RenderWindow& window, bool alllegalmove[8][8])
{
    sf::RectangleShape highlight(sf::Vector2f(75, 75)); // 75x75 is the size of each square
    /*highlight.setFillColor(sf::Color(0, 255, 0, 100)); */ // Semi-transparent green
    /*highlight.setFillColor(sf::Color(169, 169, 169, 100));*/ // Soft Gray
    /*highlight.setFillColor(sf::Color(0, 128, 128, 100));*/ // Teal
    highlight.setFillColor(sf::Color(255, 223, 0, 100)); // Golden Yellow


    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            if (alllegalmove[i][j]) 
            {
                highlight.setPosition((j * 75 )+21, (i * 75)+21); // Position based on board grid
                window.draw(highlight);
            }
        }
    }
}
void Board::unhighlight(bool alllegalmove[8][8]) 
{
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            alllegalmove[i][j] = false; // Reset all cells to false
        }
    }
}
bool Board::isKinginCheck(Piece* RC[8][8])
{
    int OpKR=-1, OpKC=-1;
    for (int i = 0;i < 8;i++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (RC[i][y] != nullptr)
            {
                if (Turn == false)
                {
                    if (RC[i][y]->gettype() == "BKing")
                    {
                        OpKR = i;
                        OpKC = y;
                        break;
                    }
                }
                else
                {
                    if (RC[i][y]->gettype() == "WKing")
                    {
                        OpKR = i;
                        OpKC = y;
                        break;

                    }
                }
            }
        }
    }
    if (OpKC == -1 || OpKR == -1)
    {
        return false;
    }
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (RC[i][j] != nullptr && RC[i][j]->getColor() != RC[OpKR][OpKC]->getColor())
            {
                if (RC[i][j]->isleagalmove(RC, OpKR, OpKC) == true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool Board::isCheckMate()
{
    int OpKR = -1, OpKC = -1;
    for (int i = 0;i < 8;i++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (RC[i][y] != nullptr)
            {
                if (Turn == false)
                {
                    if (RC[i][y]->gettype() == "BKing")
                    {
                        OpKR = i;
                        OpKC = y;
                        break;
                    }
                }
                else
                {
                    if (RC[i][y]->gettype() == "WKing")
                    {
                        OpKR = i;
                        OpKC = y;
                        break;

                    }
                }
            }
        }
    }
    if (OpKC == -1 || OpKR == -1)
    {
        return false;
    }
    bool check[8][8] = { false };
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (RC[OpKR][OpKC]->isleagalmove(RC, i, j)==true)
            {
                check[i][j] == true;
            }

        }

    }


}
void Board::play(sf::RenderWindow& window)
{
    Piece* cur = nullptr; // Current piece pointer
    int Sr = -1, Sc = -1; // Starting row and column

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window.close();
            }
            if (evnt.type == sf::Event::MouseButtonPressed)
            {
                if (evnt.mouseButton.button == sf::Mouse::Left)
                {
                    int xpos = sf::Mouse::getPosition(window).x;
                    int ypos = sf::Mouse::getPosition(window).y;
                    int clickedRow = (ypos - 23) / 75;
                    int clickedCol = (xpos - 23) / 75;

                    if (cur == nullptr)
                    {
                        // No piece is currently selected
                        cur = getpos(xpos, ypos); // Get the piece at the clicked position
                        Sr = clickedRow;
                        Sc = clickedCol;

                        if (cur != nullptr)
                        {
                            cur->highlight(RC, Sr, Sc, allleagalmove); // Highlight legal moves
                        }
                    }
                    else
                    {
                        // A piece is already selected
                        if (Sr == clickedRow && Sc == clickedCol)
                        {
                            // Clicked on the same piece: unselect it
                            cur = nullptr;
                            unhighlight(allleagalmove);
                        }
                        else
                        {
                            // Attempt to move the piece
                            int Er = clickedRow;
                            int Ec = clickedCol;

                            if (cur->isleagalmove(RC, Er, Ec))
                            {
                                Piece* temp = RC[Er][Ec];
                                RC[Er][Ec] = cur;
                                RC[Sr][Sc] = nullptr;
                                if (isKinginCheck(RC))
                                {
                                    RC[Sr][Sc] = cur;
                                    RC[Er][Ec] = temp;
                                    cout << "Move leaves king in check!" <<endl;
                                }
                                else
                                {
                                    cur->move(Er, Ec); // Perform the move
                                    unhighlight(allleagalmove); // Remove highlights
                                    RC[Sr][Sc] = nullptr;
                                    RC[Er][Ec] = cur;

                                    changeturn(); // Change the turn
                                    cur = nullptr;
                                }
                                if (isKinginCheck(RC))
                                {
                                    cout << "Check!" << endl;
                                }
                            }
                            else
                            {
                                cout << "Invalid move or king in check!" << endl;
                                cur = nullptr;
                                unhighlight(allleagalmove); // Remove highlights
                            }
                        }
                    }
                }
            }
        }

        // Redraw the board and pieces
        window.clear();
        Drawboard(window);
        DrawPiece(RC, window);
        DrawHighlights(window, allleagalmove); // Draw highlights if any
        window.display();
    }
}


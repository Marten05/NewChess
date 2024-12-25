#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
    bool Turn;                                                                  //Ture=White,False=Black
    bool allleagalmove[8][8];
    sf::Texture Boardtexture;
    sf::Sprite board;
public:
	Board();
    void initializeBoard();                                                     //set initial positions
    void play(sf::RenderWindow &window);                                        //main playing loop
    void Drawboard(sf::RenderWindow& win);                                      //draws the chess board 
    void DrawPiece(Piece* RC[8][8], sf::RenderWindow& win);                     //daws pieces
    void DrawHighlights(sf::RenderWindow& window, bool alllegalmove[8][8]);     //draws highlights
    void unhighlight(bool alllegalmove[8][8]);                                  //remove highlights
    Piece* getpos(int x,int y);                                                 //get starting position
    void changeturn();                                                          //trun change
    bool isKinginCheck(bool turn);
    bool isSelfCheck(bool turn);
    bool isCheckMate();
    bool isStalemate();

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
bool Board::isKinginCheck(bool turn)
{
    int OpKR=-1, OpKC=-1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (RC[i][j] != nullptr)
            {
                if ((turn && RC[i][j]->gettype() == "WKing") || (!turn && RC[i][j]->gettype() == "BKing"))
                {
                    OpKR = i;
                    OpKC = j;
                    break;
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
bool Board::isSelfCheck(bool turn)
{
    return isKinginCheck(!turn);
}
bool Board::isCheckMate()
{
//{
//    int OpKR = -1, OpKC = -1;
//    for (int i = 0; i < 8; i++) 
//    {
//        for (int j = 0; j < 8; j++) 
//        {
//            if (RC[i][j] != nullptr) 
//            {
//                if ((Turn && RC[i][j]->gettype() == "BKing") || (!Turn && RC[i][j]->gettype() == "WKing"))
//                {
//                    OpKR = i;
//                    OpKC = j;
//                    break;
//                }
//            }
//        }
//    }
//    
//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            if (RC[i][j] != nullptr && RC[i][j]->getColor() == RC[OpKR][OpKC]->getColor())//for checking on checked king pieces
//            {
//               Piece* piece = RC[i][j];
//               for (int x = 0; x < 8; x++)
//               {
//                   for (int y = 0; y < 8; y++)//for checking everymove of that piece
//                   {
//                       if (piece->isleagalmove(RC, x, y))
//                       {
//                             Piece* temp = RC[x][y]; //a dummy move to check that any piece can reverse the check!
//                             RC[x][y] = RC[i][j];
//                             RC[i][j] = nullptr;
//                             bool CM = isKinginCheck(Turn);
//                             RC[i][j] = RC[x][y];//reversing the check move
//                             RC[x][y] = temp;
//                             if (CM==false)//if king is not in check after that move then its not checkmate
//                             {
//                                  return false;
//                             }
//                       }
//                   }
//               }  
//            }
//        }
//    }
    
    if (isKinginCheck(Turn) == false)
    {
        return false;
    }
    int OpKR = -1, OpKC = -1;

    // findingking of current player
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (RC[i][j] != nullptr)
            {
                if ((Turn && RC[i][j]->gettype() == "WKing") || (!Turn && RC[i][j]->gettype() == "BKing"))
                {
                    OpKR = i;
                    OpKC = j;
                    break;
                }
            }
        }
    }
    if (OpKR == -1 || OpKC == -1)
        return false;

    // Check all possible moves for the king
    for (int x = OpKR - 1; x <= OpKR + 1; x++)
    {
        for (int y = OpKC - 1; y <= OpKC + 1; y++)
        {
            if (x >= 0 && x < 8 && y >= 0 && y < 8 && (x != OpKR || y != OpKC))
            {
                if (RC[OpKR][OpKC]->isleagalmove(RC, x, y))
                {
                    // dummy move
                    Piece* temp = RC[x][y];
                    RC[x][y] = RC[OpKR][OpKC];
                    RC[OpKR][OpKC] = nullptr;

                    bool kingInCheck = isKinginCheck(Turn);

                    RC[OpKR][OpKC] = RC[x][y];
                    RC[x][y] = temp;

                    if (!kingInCheck)
                        return false; // 
                }
            }
        }
    }

    // Check all pieces of the current player
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (RC[i][j] != nullptr && RC[i][j]->getColor() == RC[OpKR][OpKC]->getColor())
            {
                // Check all possible moves for the piece
                for (int x = 0; x < 8; x++)
                {
                    for (int y = 0; y < 8; y++)
                    {
                        if (RC[i][j]->isleagalmove(RC, x, y))
                        {
                           
                            Piece* temp = RC[x][y];
                            RC[x][y] = RC[i][j];
                            RC[i][j] = nullptr;

                            bool kingInCheck = isKinginCheck(Turn);

                            
                            RC[i][j] = RC[x][y];
                            RC[x][y] = temp;

                            // If the king is not in check after this move, it's not checkmate
                            if (!kingInCheck)
                                return false;
                        }
                    }
                }
            }
        }
    }
 
    return true;
}
bool Board::isStalemate()
{
//{
//    if (isKinginCheck(Turn) == true)
//    {
//        cout << "1 stale mate";
//        return false;
//    }
//    int OpKR = -1, OpKC = -1;
//
//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            if (RC[i][j] != nullptr)
//            {
//                if ((Turn && RC[i][j]->gettype() == "WKing") || (!Turn && RC[i][j]->gettype() == "BKing"))
//                {
//                    OpKR = i;
//                    OpKC = j;
//                    break;
//                }
//            }
//        }
//    }
//
//    if (OpKR == -1 || OpKC == -1)
//    {
//        cout << "2 stale mate";
//        return false;
//    }
//
//    for (int x = OpKR - 1; x <= OpKR + 1; x++)
//    {
//        for (int y = OpKC - 1; y <= OpKC + 1; y++)
//        {
//            if (x >= 0 && x < 8 && y >= 0 && y < 8 && (x != OpKR || y != OpKC))
//            {
//                if (RC[OpKR][OpKC]->isleagalmove(RC, x, y))
//                {
//                    // dummy move
//                    Piece* temp = RC[x][y];
//                    RC[x][y] = RC[OpKR][OpKC];
//                    RC[OpKR][OpKC] = nullptr;
//
//                    bool kingInCheck = isKinginCheck(Turn);
//
//                    RC[OpKR][OpKC] = RC[x][y];
//                    RC[x][y] = temp;
//
//                    if (!kingInCheck)
//                    {
//                        cout << "3 stale mate";
//                        return false;
//                    }
//                }
//            }
//        }
//    }
//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            if (RC[i][j] != nullptr && RC[i][j]->getColor() == RC[OpKR][OpKC]->getColor())
//            {
//                for (int x = 0; x < 8; x++)
//                {
//                    for (int y = 0; y < 8; y++)
//                    {
//                        if (RC[i][j]->isleagalmove(RC, x, y)==true)
//                        {
//                            cout << "4 stale mate";
//                            return false;
//                        }
//                    }
//                }
//            }
//        }
//    }
//    cout << "TrueTrueTrueTrueTrueTrueTrueTrueTrueTrueTrue";
//    return true;
    if (isKinginCheck(Turn)) {
        return false; // Not stalemate if the king is in check
    }

    // Check current player has a legal move
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) 
        {
            if (RC[i][j] != nullptr && RC[i][j]->getColor() ==Turn)
            {
                for (int x = 0; x < 8; x++) {
                    for (int y = 0; y < 8; y++) {
                        if (RC[i][j]->isleagalmove(RC, x, y)) {
                            
                            Piece* temp = RC[x][y];
                            RC[x][y] = RC[i][j];
                            RC[i][j] = nullptr;

                            bool kingInCheck = isKinginCheck(Turn);

         
                            RC[i][j] = RC[x][y];
                            RC[x][y] = temp;

                            // If any legal move exists, it's not stalemate
                            if (!kingInCheck) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }

    // No legal moves and king not in check =stalemate
    return true;
}
void Board::play(sf::RenderWindow& window)
{
    Piece* cur = nullptr; // piece pointer
    int Sr = -1, Sc = -1; // Starting row and column

    sf::SoundBuffer move;
    move.loadFromFile("move.mp3");
    sf::Sound Move;
    Move.setBuffer(move);

    sf::SoundBuffer cap;
    cap.loadFromFile("capture.mp3");
    sf::Sound capture;
    capture.setBuffer(cap);

    sf::SoundBuffer check;
    check.loadFromFile("move-check.mp3");
    sf::Sound Check;
    Check.setBuffer(check);

    sf::SoundBuffer illegal;
    illegal.loadFromFile("illegal.mp3");
    sf::Sound Illegal;
    Illegal.setBuffer(illegal);

    sf::SoundBuffer mate;
    mate.loadFromFile("checkmate.mp3");
    sf::Sound checkmate;
    checkmate.setBuffer(mate);

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
                        if (Sr == clickedRow && Sc == clickedCol)
                        {
                            // unselect it
                            cur = nullptr;
                            unhighlight(allleagalmove);
                        }
                        else
                        {
                            
                            int Er = clickedRow;
                            int Ec = clickedCol;

                            if (cur->isleagalmove(RC, Er, Ec))
                            {
                                Piece* temp = RC[Er][Ec];
                                bool isCapture = (temp != nullptr);
                                RC[Er][Ec] = cur;
                                RC[Sr][Sc] = nullptr;
                                if (isKinginCheck(Turn) || isSelfCheck(Turn))
                                {
                                    Illegal.play();
                                    RC[Sr][Sc] = cur;
                                    RC[Er][Ec] = temp;
                                }
                                else
                                {
                                    cur->move(Er, Ec); // Perform the move
                                    unhighlight(allleagalmove);// Remove highlights
                                    if (isCapture)
                                    {
                                        if (isKinginCheck(Turn))
                                        {
                                            Check.play();
                                        }
                                        else
                                        {
                                            capture.play();
                                        }
                                    }
                                    else
                                    {
                                        
                                        Move.play();
                                    }
                                    RC[Sr][Sc] = nullptr;
                                    RC[Er][Ec] = cur;
                                    changeturn(); //Change the turn
                                    cur = nullptr;

                                    if (isCheckMate()==true)
                                    {
                                        checkmate.play();
                                        cout<<"Check Mate";
                                    }
                                    if (isStalemate() == true)
                                    {
                                        checkmate.play();
                                        cout << "Stale Mate";
                                    }
                                }
                              
                            }
                            else
                            {
                                cur = nullptr;
                                unhighlight(allleagalmove);//Remove highlights
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


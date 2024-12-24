#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
struct cordinates
{
	int x, y;
};
class Piece
{
protected:
	string typePiece;
	char color;
	sf::Vector2f position;
	cordinates index;
	string fileName;
	sf::Texture Piecetexture;
	sf::Sprite piece;
public:
	Piece(string TypePiece,char c,cordinates x, sf::Vector2f pos,string fileName);

	sf::Sprite SpritePiece();//getter sprite
	void move( int x, int y);//to make move
	bool getColor();//to get color
	string gettype();

	bool horizentalmove(int xpos,int ypos);
	bool verticalmove(int Er, int Ec);
	bool diagnolmove(int Er, int Ec);
	bool ishorizentalclear(Piece* RC[8][8], int Er, int Ec);
	bool isverticalclear(Piece* RC[8][8], int Er, int Ec);
	bool isdiagnolclear(Piece* RC[8][8],int xpos, int ypos);

	void highlight(Piece* RC[8][8], int Sr, int Sc, bool alllegalmove[8][8]);
	bool virtual isleagalmove(Piece* RC[8][8], int Er, int Ec) = 0;
};
Piece::Piece(string TypePiece,char c, cordinates x, sf::Vector2f pos,string fileName)
{
	typePiece = TypePiece;
	color = c;
	index.x = x.x;
	index.y = x.y;
	position.x = pos.x;
	position.y = pos.y;
	if (!Piecetexture.loadFromFile(fileName))
	{
		cout << "Image not loaded";
	}
	piece.setTexture(Piecetexture);
	piece.setPosition(pos.x,pos.y);
	piece.setScale(0.28f, 0.28f);
}

void Piece::move(int Er, int Ec)
{
		this->index.x = Er;
		this->index.y = Ec;
		this->position.x = ((Ec * 75) + 23);
		this->position.y = ((Er * 75) + 23);
		this->piece.setPosition(position);
	
}
bool Piece::getColor()
{
	return (this->color == 'W');
}
string Piece::gettype()
{
	return(this->typePiece);
}
bool Piece::verticalmove(int Er, int Ec)
{	
	if(this->index.y== Ec)
	{
		return true;
	}
	return false;
}
bool Piece::horizentalmove(int Er, int Ec)
{
	if (this->index.x == Er)
	{
		return true;
	}
	return false;
}
bool Piece::diagnolmove(int Er, int Ec)
{
	if (abs(this->index.x - Er) == abs(this->index.y - Ec)) {
		return true;
	}
	return false;
}
bool Piece::ishorizentalclear(Piece* RC[8][8], int Er, int Ec)
{
	// left to right
	if (this->index.y < Ec)
	{
		for (int c = this->index.y + 1; c < Ec; c++)
		{
			if (RC[this->index.x][c] != nullptr)
			{
				
				return false;
			}
		}
	}
	//right to left 
	else if(this->index.y > Ec)
	{
		for (int c = Ec + 1; c < this->index.y; c++)
		{
			if (RC[this->index.x][c] != nullptr)
			{
				
				return false;
			}
		}
	}
	
	return true;

}
bool Piece::isverticalclear(Piece* RC[8][8], int Er, int Ec)
{
	// down to up
	if (this->index.x < Er)
	{
		for (int c = this->index.x + 1; c < Er; c++)
		{
			if (RC[c][this->index.y] != nullptr)
			{
				return false;
			}
		}
	}
	//up to down 
	else if (this->index.x > Er)
	{
		for (int c = Er + 1; c < this->index.x; c++)
		{
			if (RC[c][this->index.y] != nullptr)
			{
				
				return false;
			}
		}
	}
	return true;
}
bool Piece::isdiagnolclear(Piece* RC[8][8], int Er, int Ec)
{
	// Moving up-left
	if (Er > this->index.x && Ec > this->index.y) 
	{
		for (int r = this->index.x + 1, c = this->index.y + 1; r < Er && c < Ec; r++, c++)
		{
			if (RC[r][c] != nullptr) 
			{
				return false;
			}
		}
	}
	// Moving up-right
	else if (Er > this->index.x && Ec < this->index.y) 
	{
		for (int r = this->index.x + 1, c = this->index.y - 1; r < Er && c > Ec; r++, c--) 
		{
			if (RC[r][c] != nullptr) 
			{
				return false;
			}
		}
	}
	// Moving down-left
	else if (Er < this->index.x && Ec > this->index.y)
	{
		for (int r = this->index.x - 1, c = this->index.y + 1; r > Er && c < Ec; r--, c++) 
		{
			if (RC[r][c] != nullptr) 
			{
				return false;
			}
		}
	}
	// Moving down-right
	else if (Er < this->index.x&& Ec < this->index.y) 
	{
		for (int r = this->index.x - 1, c = this->index.y - 1; r > Er && c > Ec; r--, c--)
		{
			if (RC[r][c] != nullptr) 
			{
				return false;
			}
		}
	}
	return true;
}
sf::Sprite Piece::SpritePiece() //getter
{
	return this->piece;
}
void Piece::highlight(Piece* RC[8][8], int Sr, int Sc, bool alllegalmove[8][8])
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			if (this->isleagalmove(RC,i,j) ==true )
			{
				
					alllegalmove[i][j] = true;
				
			}
		}
	}
}

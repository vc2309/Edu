#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid(): td{nullptr}, ob{nullptr} {}

Grid::~Grid() { delete td; delete ob;}

// Deletes the already existing grid
void Grid::clearGrid() 
{
	theGrid.erase(theGrid.begin(), theGrid.end()); // Clearing all pre existing data
	delete td;
}

Colour Grid::whoWon() const
{
	int ctrb,ctrw;
	ctrb=ctrw=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(theGrid[i][j].getInfo().colour==Colour::Black)
			{
				ctrb++;
			}
			else if(theGrid[i][j].getInfo().colour==Colour::White)
			{
				ctrw++;
			}
		}
	}

	ctrb==ctrw ? return Colour::NoColour : (ctrb>ctrw ? return Colour::Black : return Colour::White);

}
void Grid::setObserver(Observer<Info, State> *ob)
{
	this->ob=ob;
}


void Grid::init(int n) 
{	gridSize = n;
	clearGrid(); //Delete preexisting grid
	
	td = new TextDisplay(n); 
	
	// Loop to populate the grid and initialize
	for (int i = 0; i < gridSize; ++i)
	{
		vector<Cell> v;
		theGrid.emplace_back(v);
		for (int j = 0; j < gridSize; ++j)
		{
			Cell newCell;
			newCell.setCoords(i, j);
			theGrid[i].emplace_back(newCell);
		}
	}

	// Setting up the observer list for every cell in the grid

	for(int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
		{
			if(i != 0)
			{
				theGrid[i][j].attach(&theGrid[i-1][j]); // !Row 0
			}
			if (i != gridSize - 1)
			{
				theGrid[i][j].attach(&theGrid[i+1][j]); //!end of rows
			}
			if (j != 0)
			{
				theGrid[i][j].attach(&theGrid[i][j - 1]); //!Column 0
			}
			if (j != gridSize - 1)
			{
				theGrid[i][j].attach(&theGrid[i][j + 1]); //!end of Columns
			}
			theGrid[i][j].attach(td);
		}
	}

}
void setPiece(size_t r, size_t c, Colour colour)
{
	theGrid[r][c].setPiece(colour);
}

void Grid::toggle(int r, int c) 
{
  theGrid[r][c].toggle();
}

bool Grid::isFull() const
{
	for(int row=0;row<n;row++)
	{
		for(int col=0;col<n;col++)
		{
			if(theGrid[row][col].getInfo().colour==Colour::NoColour)
			{
				return false;	//If there is an empty cell, the grid isn't full
			}
		}
	}
	return true;	//All cells occupied
}

ostream &operator<<(ostream &out, const Grid &g) 
{
	out << *(g.td);
	return out;
}


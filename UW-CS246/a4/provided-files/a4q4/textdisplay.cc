#include <iostream>
#include "textdisplay.h"
#include "cell.h"
using namespace std;
// ctor
TextDisplay::TextDisplay(int n): gridSize{n}
{
	for (int i = 0; i < gridSize; ++i)
	{
		vector <char> newvec;
		theDisplay.emplace_back(newvec);
		for(int j = 0; j < gridSize; ++j)
		{
			theDisplay[i].emplace_back('-');
		}
	}
}

// Changing appropriate fxns on notif
void TextDisplay::notify(Subject<Info, State> &whoNotified) 
{
	Info cell_inf=whoNotified.getInfo();
	
	if(cell_inf.colour==Black)
	{
		theDisplay[cell_inf.row][cell_inf.col] = 'B';
	}
	else if(cell_inf.colour==White)
	{
		theDisplay[cell_inf.row][cell_inf.col] = 'W';
	}
	else
	{
		theDisplay[cell_inf.row][cell_inf.col] = '-';
	}
}


ostream &operator<<(ostream &out, const TextDisplay &td) 
{
	for(int row = 0; row < td.gridSize; ++row)
	{
		for (int col = 0; col < td.gridSize; ++col)
		{
			out << td.theDisplay[row][col];
		}
		out << endl;
	}
	return out;

}

TextDisplay::~TextDisplay() {}
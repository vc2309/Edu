#include "observer.h"
#include "cell.h"

Cell::Cell(size_t r, size_t c): r{r}, c{c} {}



void Cell::setPiece(Colour colour)
{
	this->colour=colour;
	notify(*this);
}

//Toggles between Black and white colour of a cell
void Cell::toggle() 
{
	if (colour==Colour::Black)
	{
		colour=Colour::White;
	}
	else if(colour==Colour::White)
	{
		colour=Colour::Black;
	}
	notify(*this);
}

Info Cell::getInfo()
{
	Info inf;
	inf.colour=colour;
	inf.row=r;
	inf.col=c;
	return inf;
}

// Adds an observer to the cell's observer list
void Cell::setObserver(Observer *o)
{
	observers.emplace_back(o);
}

//Notifies on change and updates
void Cell::notify(Subject<Info, State> &whoFrom) 
{
	if(this!=&whoFrom)
	{
		toggle();

	}
	else
	{int length = observers.size();
		for(int i = 0; i < length; ++i)
		{
			
				observers[i]->notify(whoFrom);
				
		}}
}



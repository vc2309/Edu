#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "grid.h"
#include "state.h"
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Grid g;

  // Add code here
Colour turn=Colour::Black;
  try {
  while (true) {
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
      // Add code here
      g.init(n);
    }
    else if (cmd == "play") {
      int r = 0, c = 0;
      cin >> r >> c;
      // Add code here
      g.setPiece(r,c,turn);
      turn= (turn==Colour::Black)? Colour::White : Colour::Black; //Alternate turn after each turn
    }
    if(g.isFull() || cin.fail()) //Game over
    {
      break;
    }
  }

  g.whoWon()==Colour::NoColour ? "Tie!" : (g.whoWon()==Colour::Black? cout<<"Black Wins!"<<endl; : cout<<"White Wins!"<<endl;);
  }
  catch (ios::failure &) {
    exit(-1);
  }  // Any I/O failure quits
}

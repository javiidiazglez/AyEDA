#ifndef _AH_
#define _AH_

#include <iostream>
#include <vector>

using namespace std;
class Grid;

enum State {muerta, viva};

class Cell{
  private:
    State state_;         // estado true (vivo), false (muerto)
    int i_; 
    int j_;               // posicion en rejilla
    int neighbor_;        // vecinos vivos
  public:
    Cell (int i = 0, int j = 0);
    ~Cell();
    State getState() const;
    State setState(State state);

    void updateState();
    int neighbors(const Grid& grid);
};

ostream& operator<<(ostream& os, const Cell& b);

#endif

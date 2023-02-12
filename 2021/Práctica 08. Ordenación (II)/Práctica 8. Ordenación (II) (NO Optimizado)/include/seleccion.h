
#include <vector>

//template <class Clave>

class seleccion
{
  private:
    std::vector<int> select_v;
    int select_sz;

  public:
    seleccion();
    ~seleccion();
    std::vector<int> metodo(std::vector<int> a, int sz);
    void swap_pos(int i, int j);

};

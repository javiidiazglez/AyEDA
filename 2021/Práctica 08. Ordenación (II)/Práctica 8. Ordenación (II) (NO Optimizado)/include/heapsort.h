#include <vector>

//template <class Clave>
class heapsort
{
private:
  std::vector<int> heap_v;
  int heap_sz;

public:
  heapsort();
  ~heapsort();
  std::vector<int> metodo(std::vector<int> a, int sz);
  void baja(int i, int sz);
  void swap_pos(int i, int j);
};

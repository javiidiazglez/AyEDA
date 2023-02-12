#include <vector>

//template <class Clave>
class mergesort
{
private:
	std::vector<int> merge_v;
	std::vector<int> auxilar;
	int merge_sz;

public:
	mergesort();
	~mergesort();
	std::vector<int> metodo(std::vector<int> a, int sz);
	void merge_sort(int inic, int fin);
	void show_merge_changes(int i);
};

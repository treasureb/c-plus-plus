#include"5_26RBTree.h"

int main()
{
	int arr[10] = { 2, 6, 12 ,3, 5, 75 ,45,26,17,22};
	RBTree<int, int> s;
	for (int idex = 0; idex < 10; idex++)
	{
		s.Insert(arr[idex], idex);
	}
	s.CheckRBTree();
	return 0;
}
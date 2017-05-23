#include"5_15SortBinaryTree.h"

int main()
{
	int a[10] = { 5, 3, 1, 4, 0, 2, 7, 6, 8, 9 };
	BSTree<int, int> s;
	for (int idx = 0; idx < 10; idx++)
	{
		s.Insert_R(a[idx], idx);
	}
	s.MidOrder();
	s.Remove(5);
	s.MidOrder();
	return 0;
}
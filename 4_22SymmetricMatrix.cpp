#include<iostream>
using namespace std;


template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(int* a, size_t N)
		:_row(N)
		, _col(N)
	{
		size_t idx = 0;
		_pData = new T[N*(N - 1) >> 1];
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j <= i; j++)
					_pData[idx++] = a[i*N + j];
			}
	}

	~SymmetricMatrix()
	{
		if (!_pData)
		{
			delete _pData;
			_pData = NULL;
		}
	}

	T& Acess(int row, int col)
	{
		if (col > row)
			std::swap(row, col);
		return _pData[row*(row+1)/2 + col];
	}
	
	template<class T>
	friend ostream& operator<<(ostream& _cout, SymmetricMatrix<T>&s)
	{
		for (size_t i = 0; i < s._row; ++i)
		{
			for (size_t j = 0; j < s._col; ++j)
			{
				_cout << s.Acess(i,j)<<" ";
			}
			_cout << endl;
		}
		return _cout;
	}
private:
	T* _pData;
	size_t _row;
	size_t _col;
};

void Test()
{
	int a[5][5] = {
		{ 0, 1, 2, 3, 4 },
		{ 1, 0, 1, 2, 3 }, 
		{ 2, 1, 0, 1, 2 },
		{ 3, 2, 1, 0, 1 },
		{ 4, 3, 2, 1, 0 } };
	SymmetricMatrix<int> sm((int*)a, sizeof(a) / sizeof(a[0]));
	cout << sm.Acess(2,1) << endl;
	cout << sm.Acess(1,2) << endl;
	cout << sm << endl;
}
int main()
{
	Test();
	return 0;
}
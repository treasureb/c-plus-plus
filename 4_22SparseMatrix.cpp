#include<iostream>
#include<vector>
using namespace std;

template<class T>
class SparseMatrix
{
	template<class T>
	struct Trituple
	{
		Trituple(size_t row, size_t col, const T& data)
		:_row(row)
		, _col(col)
		, _data(data)
		{};
		Trituple()
		{};

		size_t _row;
		size_t _col;
		T _data;
	};
public:
	SparseMatrix(int* array, size_t row, size_t col, const T& invalid)
		:_row(row)
		, _col(col)
		, _invalid(invalid)
	{
		for (size_t i = 0; i < row; ++i)
		{
			for (size_t j = 0; j < col; ++j)
			if (array[i*col + j] != invalid)
				_sm.push_back(Trituple<T>(i, j, array[i*col + j]));
		}
	};
	SparseMatrix()
	{};

	T& Access(int row, int col)
	{

		/*for (size_t i = 0; i < _sm.size(); ++i)
		{
		if (_sm[i]._row == row && _sm[i]._col == col)
		return _sm[i]._data;
		}

		return _invalid;*/

		vector<Trituple<T>>::iterator it = _sm.begin();
		while (it != _sm.end())
		{
			if (it->_row == row && it->_col == col)
				return it->_data;
			++it;
		}

		return _invalid;
	}

	template<class T>
	friend ostream& operator<<(ostream& _cout, SparseMatrix<T> &s)
	{
		size_t index = 0;
		for (size_t i = 0; i < s._row; ++i)
		{
			for (size_t j = 0; j < s._col; ++j)
			{
				if (index < s._sm.size() && s._sm[index]._row == i && s._sm[index]._col == j)//如果没有第一个判断，会越界
					_cout << s._sm[index++]._data << " ";
				else
					_cout << s._invalid << " ";
			}
			_cout << endl;
		}
		return _cout;
	}

	SparseMatrix<T> Transport()
	{
		SparseMatrix<T> sm;//需要默认的构造函数
		sm._col = _row;
		sm._row = _col;
		sm._invalid = _invalid;

		sm._sm.resize(_sm.size());//有第二个参数，所以需要默认的构造函数，或者给出缺省值

		//统计原矩阵中每一列有多少个有效元素
		int* pCount = new int[_col];
		memset(pCount, 0, _col*sizeof(pCount[0]));
		for (size_t i = 0; i<_sm.size(); ++i)
		{
			pCount[_sm[i]._col]++;
		}

		//原矩阵中每一列在新矩阵中的起始地址
		int* pAddr = new int[_col];
		memset(pAddr, 0, _col*sizeof(pAddr[0]));
		for (size_t i = 1; i < _col; ++i)
		{
			pAddr[i] = pAddr[i - 1] + pCount[i - 1];
		}

		//放置元素
		for (size_t i = 0; i < _sm.size(); ++i)
		{
			int& addar = pAddr[_sm[i]._col];
			sm._sm[addar] = Trituple<T>(_sm[i]._col, _sm[i]._row, _sm[i]._data);
			addar++;
		}

		return sm;
		//for (size_t i = 0; i < _col; ++i)//复杂度太高
		//{
		//	vector<Trituple<T>>::iterator it = _sm.begin();
		//	while (it != _sm.end())
		//	{
		//		if (it->_col == i)
		//			sm._sm.push_back(Trituple<T>(i,it->_row,it->_data));
		//		++it;
		//	}
		//}
		//for (size_t i = 0; i < _sm.size(); ++i)
		//{
		//	//std::swap(_sm[i]._row, _sm[i]._col);
		//	//sm._sm.push_back(Trituple<T>(_sm[i]._col, _sm[i]._row, _sm[i]._data));必须是行优先打印
		//}
		//return sm;

	SparseMatrix<T> operator+(const  SparseMatrix<T>& sp)
		{
			assert(_row == sp._row&&_col == sp._col);
			SparseMatrix<T> ret;
			ret._row = _row;
			ret._col = _col;
			ret._invalid = _invalid;
			int leftAddr = 0;
			int rightAddr = 0;
			int iLidx = 0;
			int iRidx = 0;
			while (iLidx < _sm.size() && iRidx < sp.sm.size())
			{
				leftAddr = _sm[i]._row*_col + _sm[i]._col;
				rightAddr = _sm[iRidx]._row*_col + _sm[iRidx]._col;
				if (leftAddr>rightAddr)
				{
					ret._sm.push_back(sp._sm[iRight]);
					iRidex++;
				}
			}
			else
			{
				Trituple<T>.temp(_sm[iRidx]);
				temp._data += sp._sm[iRidx]._data;
				if (temp._data != _invalid)
					ret._sm.push_back(temp);

				iLidx++;
				iRidx++;
			}
		}
		while (iLidx < _sm.size())
			ret._sm.push_back(_sm.[iLidx++]);
		while (iRidx < _sm.size())
			ret._sm.push_back(sp._sm[iRidx++]);

		return ret;
	}
private:
	vector<Trituple<T>> _sm;
	size_t _row;
	size_t _col;
	T _invalid;

};

int main()
{
	int array[6][5] = {
		{ 1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 1, 0, 3, 0, 5 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 } };

	SparseMatrix<int> s((int*)array, 6, 5, 0);
	cout << s.Access(3, 2) << endl;
	cout << s << endl;
	cout << s.Transport() << endl;
	return 0;
}
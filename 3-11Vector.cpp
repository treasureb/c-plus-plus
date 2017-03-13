#include<memory.h>
#include<iostream>
typedef int DataType;
using namespace std;

class Vector
{
public:
	//explicit Vector(size_t capacity = 3);
		//有size个值为data的元素
	Vector()
		:_pData(NULL)
		, _capacity(0)
		, _size(0)
	{}

	Vector(const Vector& v)
		: _pData(new DataType[v._capacity])
		,_capacity(v._capacity)
		, _size(v._size)
	{
		memcpy(_pData, v._pData, sizeof(DataType)*_size);
	}
	~Vector()
	{
		if (_pData)
		{
			delete[] _pData;
			cout << "~Vector" << endl;
		}
	}
	Vector& operator=(const Vector& v)
	{
		if (this != &v)//防止自复制
		{
			delete[] _pData;
			_pData = new DataType[v._capacity];
			memcpy(_pData, v._pData, v._size*sizeof(DataType));
			_size = v._size;
			_capacity = v._capacity;
		}
		return *this;
	}


	void PushBack(const DataType& data)
	{
		CheckCapacity();
		_pData[_size++] = data;
	}
	void PopBack()
	{
		if (_size == 0)
		{
			cout << "Vector Is Empty!\n" << endl;
		}
		_size--;
	}
	void Insert(size_t pos, const DataType& data)
	{
		CheckCapacity();
		if (pos > _size)
		{
			cout << "Error pos!\n" << endl;
			return;
		}
		for (int i = _size - 1; i >= (int)pos; i--)
		{
			_pData[i + 1] = _pData[i];
		}
		_pData[pos] = data;
		_size++;

	}
	size_t Find(const DataType& data)const
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_pData[i] == data)
			{
				return i;
			}
		}
	}
	void Clear();
	/*size_t Size()const
	{
		return _size;
	}*/
	void ReSize(size_t size, const DataType& data = DataType());
	size_t Capacity()const
	{
		return _capacity;
	}
	void PrintfVector()
	{
		for (size_t i = 0; i < _size; i++)
		{
			cout << _pData[i] << " ";
		}
		cout << "" << endl;
	}
	bool Empty()const
	{
		;
	}
		DataType& Front()
	{
		return _pData[0];
	}
		const DataType& Back()const
		{
			return _pData[_size - 1];
		}
	void Assign(size_t n, const DataType& data = DataType());
	DataType& operator[](size_t index);
	const DataType& operator[](size_t index)const;
	DataType& At(size_t index);
	const DataType& At(size_t index)const;
private:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			_capacity = _capacity * 2 + 3;//因为在构造时，capacity为0，所以后面加3
			DataType* temp = (DataType*)malloc(_capacity*sizeof(DataType));
			memcpy(temp, _pData, _size*sizeof(DataType));
			delete[] _pData;
			_pData = temp;
		}
	}
	friend std::ostream& operator<<(ostream& _cout, const Vector&v);
	
private:
	DataType* _pData;
	size_t _capacity;
	size_t _size;
};

//ostream& operator<<(ostream& _cout, const Vector&v)
//{
//	;
//}

int main()
{
	Vector v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.Front();
	v.Back();
	v.PrintfVector();
	return 0;
}
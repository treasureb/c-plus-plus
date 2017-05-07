#include<iostream>
using namespace std;
#pragma warning(disable:4996);

template<class T>
class CirQueue
{
public:
	CirQueue(unsigned size)
		: _size(size)
		, _front(0)
		, _rear(0)
	{
		_data = new T[size];
	}

	~CirQueue()
	{
		delete[] _data;
	}

	void PushQueue(T x)throw(bad_exception)
	{
		if (Full())
			//cout << "queue is full,can't put" << x << "into it" << endl;
			throw bad_exception();

		else
		{
			_rear = (_rear + 1) % _size;
			_data[_rear] = x;
		}
	}

	int PopQueue()throw(bad_exception)
	{
		if (Empty())
		{
			//cout << "queue is empty!" << endl;
			throw bad_exception();
		}
		_front = (_front + 1) % _size;
		//T temp = _data[_front];
		//_front = (_front+1)%_size;
		//return tmp;
		return _data[_front];
	}

	bool Empty()
	{
		return _front == _rear;
	}

	bool Full()
	{
		return _front == (_rear + 1) % _size;
	}

	int GetQueue()
	{
		if (Empty())
			cout << "queue is empty!" << endl;
		else
		{
			return _data[(_front + 1) % _size];
		}
	}

	void PrintQueue()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _data[i] << " ";
		}
		cout << endl;
	}
private:
	T* _data;
	int _front;
	int _rear;
	size_t _size;
};

int main()
{
	CirQueue<int> Q(5);
	Q.PushQueue(1);
	Q.PushQueue(2);
	Q.PushQueue(3);
	Q.PushQueue(4);
	//Q.PrintQueue();
	cout << Q.PopQueue() << endl;
	cout << Q.GetQueue() << endl;
	cout << Q.PopQueue() << endl;
	cout << Q.PopQueue() << endl;
	Q.PopQueue();
	return 0;
}
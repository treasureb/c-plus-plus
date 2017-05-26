

template <class T>
class Greate
{
public:
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

template <class T>
class Less
{
public:
	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};

template <class T,class Compare>
void BubbleSort(T* array, int size)
{
	for (int i = 0; i < size - 1;i++)
		bool isChange
}
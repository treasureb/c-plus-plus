#include<iostream>
using namespace std;

//template<typename T>//�˴���typename������class�滻,��������typename
//inline T Add(T left, T right)
//{
//	return left + right;
//}
//template<typename T,U>//ÿһ��ģ���β�ǰ�������class����typename�ؼ�������
//void FunTest1(T t1, U u)
//{
//
//}
//
//int main()
//{
//	cout << Add(10, 20) << endl;
//	cout << Add(1.1, 1.2)<<endl;
//	cout << Add(10, (int)1.1)<<endl;//ǰ������ͱ��뱣��һ��
//	cout << Add((int)1.1,10)<<endl;
//
//	return 0;
//}
//typedef int T;
//template<typename T>
//void Funtest(T t)
//{
//	cout << "t Type =" << typeid(t).name() << endl;
//	return;
//}
//
//T gloab;//TΪtypedef�е�T��
//int main()
//{
//	Funtest(10);//ʹ��ģ���е�T��
//	cout << "gloab Type =" << typeid(gloab).name() << endl;
//	return 0;
//}

//template<typename T,int N>
//void FunTest(T (&array)[N])
//{
//	cout << typeid(array).name() << endl;
//	for (int idex = 0; idex < N; ++idex)
//	{
//		array[idex] = 0;
//	}
//}
//int main()
//{
//	int a[5];
//	FunTest(a);
//	//Fumtest(&b);
//	return 0;
//}
template<typename T>
T Max(const T left, const T right)
{
	return left > right ? left : right;
}

template<typename T>
T Max(const T left, const T mid, const T right)
{
	return Max(Max(left, mid), right);
}

template<class T>
int compare(T t1, T t2)
{
	if (t1 < t2)
		return -1;
	if (t1 > t2)
		return 1;
	return 0;
}
template<>
int compare<const char*>(const char* const s1, const char* const s2)
{
	return strcmp(s1, s2);
}
int main()
{
	/*cout << Max(5, 7) << endl;
	cout << Max(1, 2, 3) << endl;*/
	const char* s3 = "1234";
	const char* s4 = "abcd";
	char* s1 = "abcd";
	char* s2 = "1234";
	cout << compare(s3, s4) << endl;
	cout << compare(s1, s2) << endl;
	return 0;
}

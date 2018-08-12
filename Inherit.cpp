#include<iostream>
using namespace std;

class Base
{
public:
	Base(int pub)
		:_pub(pub)
	{
		cout << "B()" << endl;
	}

	~Base()
	{
		cout << "~B()" << endl;
	}

	void ShowBase()
	{
		cout << "_pub=" << _pub << endl;
		cout << "_pri=" << _pri << endl;
		cout << "_pro" << _pro << endl;
	}
public:
	int _pub;
private:
	int _pri;
protected:
	int _pro;
};

class Derived :public Base
{
public:
	Derived(int d_pub)
		:_d_pub(d_pub)
	{
		cout << "D()" << endl;
	}

	~Derived()
	{
		cout << "~D()" << endl;
	}

	void ShowDerived()
	{
		cout << "_d_pub=" << _d_pub << endl;
		//cout << "_d_pri=" << _d_pri << endl;
		cout << "_d_pro=" << _d_pro << endl;
	}
public:
	int _d_pub;
private:
	int _d_pri;
protected:
	int _d_pro;


};
int main()
{
	Derived D;
	return 0;
}

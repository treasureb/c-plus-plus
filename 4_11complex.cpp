#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0.0, double image = 0.0)
		:_real(real)
		,_image(image)
	{};

	Complex(const Complex & c)
	{
		_real = c._real;
		_image = c._image;
	}
	
	~Complex()
	{};

	Complex& operator=(const Complex& c)
	{
		if (this != &c)
		{
			_real = c._real;
			_image = c._image;
		}

		return *this;
	}

	void Display()
	{
		cout << "_real :" << _real << " ";
		cout << "_image :" << _image << endl;
	}

	Complex operator+(const Complex& c)
	{
		Complex temp;
		temp._real = this->_real + c._real;
		temp._image = this->_image + c._image;
		return temp;
	}

	Complex operator-(const Complex& c)
	{
		Complex temp;
		temp._real = this->_real - c._real;
		temp._image = this->_image - c._image;
		return temp;
	}

	Complex operator*(const Complex& c)
	{
		Complex temp;
		temp._real = (this->_real*c._real)- (this->_image*c._image);
		temp._image = (this->_image*c._real) + (this->_real*c._image);
		return temp;
	}

	Complex operator/(const Complex& c)
	{
		Complex temp;
		temp._real = (_image*c._real) - (_real*c._image);
		temp._image = pow(c._real, 2) + pow(c._image, 2);
		return temp;
	}

	Complex operator+=(const Complex& c)
	{
		_real += c._real;
		_image +=c._image;
		return *this;
	}

	Complex operator-=(const Complex& c)
	{
		_real -= c._real;
		_image -= c._image;
		return *this;
	}

	Complex operator++(int)//前置++
	{
		Complex temp;
		temp._real++;
		return temp;
	}

	Complex operator++()//后置++
	{
		this->_real++;
		return *this;
	}

	Complex operator--(int)//前置--
	{
		Complex temp;
		temp._real--;
		return temp;
	}

	Complex operator--()//后置--
	{
		this->_real--;
		return *this;
	}


private:
	double _real;
	double _image;
};



int main()
{
	Complex a(1, 2);
	Complex b(2, 4);
	Complex c;
	c = a + b;
	c.Display();
	return 0;
}
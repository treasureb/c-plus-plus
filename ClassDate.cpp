Date.h

#include<iostream>

using namespace std;
#define num 100;


class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date();
	Date(int year, int month, int day);
	Date& operator=(const Date& d);
	Date(const Date& d);
	~Date();
	Date ToCurrect(Date& d);
	int Getdaysinmonth(int year, int month);
	Date operator -(int days);
	int operator -(const Date& d);
	Date operator+(int days);
	Date& operator++();
	Date operator++(int);
	Date& Date::operator--();
	Date Date::operator--(int);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};





//����Ĳ�����ʵ��

#include"Date.h"


Date::Date()
{}
//���캯��
Date::Date(int year = 2000, int month = 1, int day = 1)
:_year(year)
, _month(month)
, _day(day)
{
	if ((year<0) ||
		(month>13 && month <= 0) ||
		(day <= 0) && (day>Getdaysinmonth(year, month)))
	{
		cout << "���벻�Ϸ������������룺" << endl;
		//cin >> "year:" >> year >> "month:" >> month >> "day:" >> day >> endl;
	}




}


//�ж�ÿ���µ������Ϸ���
int Date::Getdaysinmonth(int year, int month)
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((((0 == year % 4) && (0 != year % 100)) || (0 == year % 400)) && (month == 2))
	{
		days[month] = 29;
	}
	return days[month];
}


//���ںϷ���
Date Date::ToCurrect(Date& d)
{
	if (d._day > Getdaysinmonth(d._year, d._month))
	{
		while (d._day > Getdaysinmonth(d._year, d._month))
		{
			d._day -= Getdaysinmonth(d._year, d._month);
			if (d._month == 12)
			{
				d._year++;
				d._month = 1;
			}
			else
			{
				++d._month;
			}
		}
	}
	else
	{
		while (d._day <= 0)
		{
			if (d._month == 1)
			{
				d._year--;
				d._month = 12;
			}
			else
			{
				--d._month;
			}
			d._day += Getdaysinmonth(d._year, d._month);
		}
	}
	return d;
}




//�������캯��
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}


//��ֵ�����������
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
//��������
Date::~Date()
{
	//cout << "�ѱ�����" << endl;
}


//��ȥ����һ������
Date Date::operator-(int days)
{
	if (days < 0)
	{
		days = 0 - days;
	}
	Date temp(*this);
	temp._day -= days;
	while (temp._day < 0)
	{
		if (temp._month == 1)
		{
			temp._month = 12;
			temp._day += 31;
			temp._year -= 1;
		}
		else
		{
			--temp._month;
			temp._day += Getdaysinmonth(_year, temp._month);
		}
	}
	return temp;
}


//�����������
int Date::operator-(const Date& d)
{
	Date mindate = *this;
	Date maxdate = d;
	int count = 0;
	if (mindate > maxdate)
	{
		std::swap(mindate, maxdate);


	}
	while (mindate != maxdate)
	{
		++mindate;
		count++;
	}
	return count;
}
//��������һ������
Date Date::operator+(int days)
{
	if (days < 0)
	{
		days = 0 - days;
	}
	else
	{
		Date temp(*this);
		temp._day += days;
		while (temp._day >Getdaysinmonth(temp._month, temp._day))
		{
			if (temp._month == 12)
			{
				temp._month = 1;
				temp._day += 1;
				temp._year += 1;
			}
			else
			{
				++temp._month;
				temp._day -= Getdaysinmonth(_year, temp._month);
			}
		}
		return temp;
	}
}


//������ǰ��++
Date& Date::operator++()
{
	++_day;
	ToCurrect(*this);
	return *this;
}


//�����ĺ���++
Date Date::operator++(int)
{
	Date temp(*this);
	temp._day = temp._day + 1;
	ToCurrect(*this);
	return temp;
}


//������ǰ��--
Date& Date::operator--()
{
	--_day;
	ToCurrect(*this);
	return *this;
}


//�����ĺ���--
Date Date::operator--(int)
{
	Date temp(*this);
	temp._day = temp._day - 1;
	ToCurrect(*this);
	return temp;
}


//�������ڼ��ȽϵĲ���������
bool Date:: operator>(const Date& d)
{
	return ((_year > d._year) || ((_year == d._year) && (_month > d._month)) || ((_year == d._year) && (_month == d._month) && (_day > d._day)));
}
bool Date:: operator<(const Date& d)
{
	return ((_year < d._year) || ((_year == d._year) && (_month < d._month)) || ((_year == d._year) && (_month == d._month) && (_day < d._day)));
}


bool Date::operator==(const Date& d)
{
	return ((_year == d._year) && (_month == d._month) && (_day == d._day));
}


bool Date::operator<=(const Date& d)
{
	return ((_year <= d._year) && (_month <= d._month) && (_day <= d._day));
}


bool Date::operator>=(const Date& d)
{
	return ((_year >= d._year) && (_month >= d._month) && (_day >= d._day));
}


bool Date::operator!=(const Date& d)
{
	return !(operator==(d));
	//return((_year != d._year) && (_month != d._month) && (_day != d._day));
}


ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}
void test1()
{
	Date d1(2017, 1, 4);
	Date d2(2016, 1, 1);
	Date d3(d1);
	Date d4(d1);
	int count1 = 0;
	count1 = d1 - d2;
	cout << "�����������Ϊ��" << count1 << endl;
	d4 = d1 - num;
	cout << "����num���Ϊ��" << d4 << endl;
	d3 = d1 + num;
	cout << "��ȥnum���Ϊ��" << d3 << endl;

}
int main()
{
	test1();
}
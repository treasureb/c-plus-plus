#include<iostream>
using namespace std;

class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{};

	Time(const Time& t)
	{
		_hour = t._hour;
		_minute = t._minute;
		_second = t._second;
	}

	~Time()
	{};

	void SetTime()
	{
		cin >> _hour >> _minute >> _second;
	}

	void ShowTime()
	{
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}

	void AddSecondTime()
	{
		++_second;
		if (_second >= 60)
		{
			_second = 0;
			AddMinuteTime();
		}
	}

	void AddMinuteTime()
	{
		++_minute;
		if (_minute >= 60)
		{
			_minute = 0;
			AddHourTime();
		}
	}

	void AddHourTime()
	{
		++_hour;
		if (_hour >= 24)
		{
			_hour = 0;
		}
	}
private:
	int _hour;
	int _minute;
	int _second;
};

int main()
{
	int i=0;
	Time t1(8, 20, 50);
	for (; i < 20; i++)
	{
		t1.AddSecondTime();
		t1.ShowTime();
	}

	Time t2(10, 56, 50);
	for (int i=0; i < 10; i++)
	{
		t2.AddMinuteTime();
		t2.ShowTime();
	}

	Time t3(21, 20, 50);
	for (int i=0; i < 10; i++)
	{
		t3.AddHourTime();
		t3.ShowTime();
	}
	return 0;
}
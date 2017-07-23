#include<iostream>
#include<string>
using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price)
		:bookNO(book)
		,price(sales_price)
	{}
	
	std::string isbn()const
	{
		return bookNO;
	}
	
	virtual double net_price(std::size_t n)const
	{
		return n*price;
	}

	virtual void Debug()
	{
		cout << " bookNO: " << bookNO << " price: " << price << endl;
	}

	virtual ~Quote() = default;


private:
	std::string bookNO;
protected:
	double price = 0.0;
};


class Bulk_quote :public Quote
{
public:
	Bulk_quote()
	{}
	Bulk_quote(const std::string&book, double price, std::size_t qty = 0, double dis = 0)//����Ĳ��֣����û���Ĺ��캯������ʼ��
		:Quote(book, price)//���ȳ�ʼ������ĳ�Ա
		, min_qty(qty)
		, discount(dis)
	{}
	double net_price(std::size_t cnt)const override
	{
		if (cnt >= min_qty)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}

	virtual void Debug()
	{
		Quote::Debug();//��Ϊ�̳���Quote�����Ժ��л���ĳ�Ա
		cout << " min_qty: " << min_qty << " discount: " << discount << endl;
	}
private:
	std::size_t min_qty;
	double discount; 
};

class Limited_quote :public Quote
{
public:
	double net_price(size_t cnt)const override
	{
		if (cnt <= max_qty)
			return cnt*(1 - discount)*price;
		else
			return max_qty*(1 - discount)*price + (cnt - max_qty)*price;
	}

private:
	size_t max_qty;
	double discount;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << " ISBN: " << item.isbn() << " # sold " << n << " total due: " << ret << endl;
	return ret;
}

class Disc_quote :public Quote
{
public:
	Disc_quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double dis = 0.0)
		:Quote(book, sales_price)
		, quantity(qty)
		, discount(dis)
	{}

	double net_price(size_t cnt)const =0;
	
private:
	size_t quantity;
	double discount;
};

int main()
{
	Quote b1("0-2017-723", 42.8);
	Bulk_quote b2("0-2017-723", 42.8, 20, 0.75);
	print_total(cout,b1, 20);
	print_total(cout,b2, 20);
	b1.Debug();
	b2.Debug();
	
	return 0;
}
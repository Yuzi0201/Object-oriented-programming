#include <iostream>
using namespace std;

class normal
{
public:
	normal(int x);
	~normal();
	int input() { cout << "Please input the basic salary: "; cin >> basic; }
	int pay() { salary = basic; }
	int print() { cout << "This worker's salary is:" << salary << endl; }
protected:
	int basic;
	int salary;
};

normal::normal(int x=0)
{
	this->basic = x; this->salary = x;
	cout << "This is normal worker A's salary" << endl;
}

normal::~normal()
{
}

class saler:public normal
{
public:
	saler(int x);
	~saler();
	static int Commission_rate; int input_rate() { cin >> Commission_rate; }
	int input() { cout << "Please input the sales volume: "; cin >> sale; }
	int pay() { salary = basic+sale*Commission_rate; }
protected:
	int sale;
};
int saler::Commission_rate = 0;
saler::saler(int x=0)
{
	this->sale = x;
}

saler::~saler()
{
}

class ceo:public saler
{
public:
	ceo();
	~ceo();

private:

};

ceo::ceo()
{
}

ceo::~ceo()
{
}

int main()
{
	cout << "Please enter the Commission rate:  ";
	normal A; saler B;
	B.input_rate;
	A.input; A.pay; A.print;
	B.input; B.pay; B.print;

}


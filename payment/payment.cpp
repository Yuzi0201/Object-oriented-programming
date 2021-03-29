#include <iostream>
using namespace std;

class normal
{
public:
	normal(int x);
	~normal();
	void input() { cout << "Please input the basic salary: "; cin >> basic; }
	void pay() { salary = basic; }
	void print() { cout << "This worker's salary is:" << salary << endl << endl << endl; }
protected:
	int basic;
	int salary;
};

normal::normal(int x=0)
{
	this->basic = x; this->salary = x;
}

normal::~normal()
{
}

class saler:public normal
{
public:
	saler(int x);
	~saler();
	static int Commission_rate; void input_rate() { cin >> Commission_rate; }
	void salerinput() { input(); cout << "Please input the sales volume: "; cin >> sale; }
	void pay() { salary = basic+sale*Commission_rate; }
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
	ceo( int x);
	~ceo();
	void ceoinput() { salerinput(); cout << "Please input the extra salary: "; cin >> extra; }
	void pay() { salary = basic + sale * Commission_rate + extra; }
private:
	int extra;
};

ceo::ceo(int x=0)
{
	this->extra = x;
}

ceo::~ceo()
{
}

int main()
{
	cout << "Welcome to the Wage calculation system!!" << endl;
	cout << "Please enter the Commission rate:  ";
	saler test; test.input_rate();
	normal A; saler B; ceo C;
	while (true)
	{
		cout << "Please enter the number of employee type:" << endl;
		cout << "1.Normal employeer 2.Saler 3.CEO" << endl;
		int chooser; cin >> chooser;
		switch (chooser)
		{
		case 1:A.input(); A.pay(); A.print(); break;
		case 2:B.salerinput(); B.pay(); B.print(); break;
		case 3:C.ceoinput(); C.pay(); C.print(); break;
		default:cout << "Wrong input!Please enter 1,2 or 3!!" << endl;
			break;
		}
		cout << "enter 1 to quit, 2 to continue:  "; int continue_chooser; cin >> continue_chooser;
		cout << endl;
		if (continue_chooser==1)
		{
			return 0;
		}
	}
}


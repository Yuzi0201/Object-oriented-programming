#pragma once
class normal
{
protected:
	int basicsalary, salary;
public:
	normal(int x);
	~normal();
	virtual void input();
	virtual void pay();
	void print();
};

normal::normal(int x = 0)
{
	this->basicsalary = x;
}

normal::~normal()
{
}

void normal::input()
{
	cout << "Please enter the basic salary" << endl;
	cin >> basicsalary;
}

void normal::pay()
{
	salary = basicsalary;
}

void normal::print()
{
	cout << "The salary of this man is " << salary << endl;
}

class Salesman :public normal
{
protected:
	int sales;
public:
	Salesman(int);
	~Salesman();
	static int Commission_rate;
	void input_rate() { cin >> Commission_rate; }
	void input() {
		cout << "Please enter the basic salary" << endl;
		cin >> basicsalary; cout << "Please input the sales volume: "; cin >> sales;
	}
	void pay() { salary = basicsalary + sales * Commission_rate; }
};
int Salesman::Commission_rate = 0;
Salesman::Salesman(int x = 0)
{
	this->sales = x;
}

Salesman::~Salesman()
{
}

class Salesmanager :public Salesman
{
private:
	int jobsalary;
public:
	Salesmanager(int);
	~Salesmanager();
	void input() {
		cout << "Please enter the basic salary" << endl;
		cin >> basicsalary; cout << "Please input the sales volume: "; cin >> sales;
		cout << "Please input the extra salary: "; cin >> jobsalary;
	}
	void pay() { salary = basicsalary + sales * Commission_rate + jobsalary; }
};

Salesmanager::Salesmanager(int x = 0)
{
	this->jobsalary = x;
}

Salesmanager::~Salesmanager()
{
}
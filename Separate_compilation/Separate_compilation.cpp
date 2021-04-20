#include<iostream>
using namespace std;
#include "class.h"

int main()
{
	cout << "Welcome to the Wage calculation system!!" << endl;
	cout << "Please enter the Commission rate:  ";
	Salesman test; test.input_rate();
	normal A; Salesman B; Salesmanager C;
	normal *p;
	while (true)
	{
		cout << "Please enter the number of employee type:" << endl;
		cout << "1.Normal employeer 2.Salesman 3.Salesmanager" << endl;
		int chooser; cin >> chooser;
		switch (chooser)
		{
		case 1:p = &A; p->input(); p->pay(); p->print(); break;
		case 2:p = &B; p->input(); p->pay(); p->print(); break;
		case 3:p = &C; p->input(); p->pay(); p->print(); break;
		default:cout << "Wrong input!Please enter 1,2 or 3!!" << endl;
			break;
		}
		cout << "enter 1 to quit, 2 to continue:  "; int continue_chooser; cin >> continue_chooser;
		cout << endl;
		if (continue_chooser == 1)
		{
			return 0;
		}
	}
}
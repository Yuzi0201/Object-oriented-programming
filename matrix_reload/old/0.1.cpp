#include<iostream>
using namespace std;

class matrix
{
public:
	matrix(int, int);
	matrix(double **, int, int);
	~matrix();
	friend matrix operator+(const matrix &, const matrix &);
	matrix & operator=(matrix);
	friend ostream & operator<<(ostream &output, const matrix &);
	friend istream & operator>>(istream &input, matrix &);
private:
	int m, n;
	double **a;
};

matrix::matrix(int m, int n)
{
	this->m = m; this->n = n;
	a = new double*[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new double[n];
	}
}

matrix::matrix(double **T, int m, int n)
{
	this->m = m; this->n = n;
	a = T;
}

matrix::~matrix()
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] != NULL)
		{
			delete[]a[i];
			a[i] = NULL;
		}
	}
	delete[]a;
	a = NULL;
}
matrix & matrix::operator=(matrix A)
{
	m = A.m; n = A.n;
	for (int i = 0; i < A.m; i++)
	{
		for (int k = 0; k < A.n; k++)
		{
			a[i][k] = A.a[i][k];
		}
	}
	return *this;
	// TODO: �ڴ˴����� return ���
}
int main()
{
	int m, n;
	cout << "enter m: "; cin >> m; cout << "enter n: "; cin >> n;
	matrix A(m, n); cout << "Please enter this " << m << " x " << n << " matrix" << endl; cin >> A;
	matrix B(m, n); cout << "Please enter this " << m << " x " << n << " matrix" << endl; cin >> B;
	cout << "C=A+B=" << endl;
	matrix C(m, n);
	C = A + B;
	cout << C << endl;
}

matrix operator+(const matrix &A, const matrix &B)
{
	//matrix C(A.m, A.n);
	double **T;
	T = new double*[A.m];
	for (int i = 0; i < A.m; i++)
	{
		T[i] = new double[A.n];
	}
	for (int i = 0; i < A.m; i++)
	{
		for (int k = 0; k < A.n; k++)
		{
			//C.a[i][k] = A.a[i][k] + B.a[i][k];
			T[i][k] = A.a[i][k] + B.a[i][k];
		}
	}
	//return C; ������ע�Ͳ�������д����Ϊһ�����˺����ͻ���������������ͻᵼ�¸�ֵʱ�����������Ҳ���ָ�룩
	return matrix(T, A.m, A.n); //�˴������˹��캯��
}

ostream & operator<<(ostream & output, const matrix &A)
{
	for (int i = 0; i < A.m; i++)
	{
		for (int k = 0; k < A.n; k++)
		{
			cout << A.a[i][k] << "  ";
		}
		cout << endl;
	}
	return output;
	// TODO: �ڴ˴����� return ���
}

istream & operator>>(istream & input, matrix &A)
{

	for (int i = 0; i < A.m; i++)
	{
		for (int k = 0; k < A.n; k++)
		{
			cin >> A.a[i][k];
		}
	}
	return input;
	// TODO: �ڴ˴����� return ���
}
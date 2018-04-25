#include "Array.h"
#include "Matrix.h"
#include "IndexOutOfBoundsException.h"
#include <iostream>
using namespace std;

template<typename T>
void fillMatrix(Matrix<T>& m)
{
	int i,j;
	for(i = 0;i < m.numRows();i++)
	{
		m[i][0] = T();
	}
	for(j = 0;j < m.numCols();j++)
	{
		m[0][j] = T();
	}
	for(i = 1;i <m.numRows();i++)
	{
		for(j = 1; j < m.numCols();j++)
		{
			m[i][j] = T(i*j);
		}
	}
}

void test_int_matrix()
{
	Matrix<int> M(10,5);
	fillMatrix(M);
	cout << M << endl;
}

void test_double_matrix()
{
	Matrix <double> m(8,10);
	fillMatrix(m);
	cout << m << endl;
}

void generate_exception(Matrix<double>& m)
{
	for(int i = 0;i <= m.numRows();i++)
	{
		cout<<"	EXCEPTION INDEX: " << i <<endl;
		m[i];
	}
}

void test_double_matrix_exceptions()
{
	cout << "Starting...\n"<<endl;
	Matrix<double> M(8,10);
	fillMatrix(M);
	cout << M;
	try
	{
		generate_exception(M);
	}
	catch(IndexOutOfBoundsException& e)
	{
		cout << "ERROR: Index is out of Bounds" << endl;
		
	}
}
int main()
{

	test_int_matrix();
	test_double_matrix();
	test_double_matrix_exceptions();
	return 0;
}

#ifndef MATRIX_H
#define MATRIX_H

#include "Array.h"
#include "IndexOutOfBoundsException.h"
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

template<typename matElement>
class Matrix
{
	private:
		int rows,cols;
		Array<Array<matElement>*> m;
	public:
		Matrix(int newRows,int newCols):rows(newRows),cols(newCols),m(rows)
		{
			for(int i = 0;i < rows;++i)
			{
				m[i] = new Array<matElement>(cols);
			}
		}
		int numRows()
		{
			return rows;
		}
		int numCols()
		{
			return cols;
		}
		Array<matElement>&  operator [](int row)
		{
			if(row < rows && row >= 0)
			{
				return *m[row];
			} else {
				IndexOutOfBoundsException e;
				throw e;		
			}
		}
		void print(ostream& out)
		{
			for(int i = 0;i < rows; ++i)
			{
				cout << m[i] << endl;
			}
		}
		~Matrix()
		{
			for(int row = 0; row < rows; ++row)
			{
				delete m[row];
			}
		}
		friend ostream& operator <<(ostream& out, Matrix& m)

		{
			m.print(out);
			return out;
		}
};





















#endif

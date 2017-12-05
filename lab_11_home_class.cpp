// lab_11_home_class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector.h"
#include "Matrix.h"
#include <iostream>

using namespace std; 

int main()
{
	Matrix m1;
	m1.set_size(3, 3);
	m1.print();
	cout << "------" << endl;
	m1.set_size(4, 4);
	m1.print();
	cout << "------" << endl;
	for (int i = 0; i < m1.num_rows(); ++i)
	{
		for (int j = 0; j < m1.num_cols(); ++j)
		{
			m1.set(i, j, rand() % 100);
		}
	}
	m1.print();
	cout << "------" << endl;
	m1.set_size(5, 5);
	m1.print();
	cout << "------" << endl;
	m1.set_size(4,6);
	m1.print();
	cout << "------" << endl;
	m1.set_size(3, 3);
	m1.print();
	cout << "------" << endl;
	

	Vector v1; 
	v1.set_size(1, 3);
	v1.print();

    return 0;
}


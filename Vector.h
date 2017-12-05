#pragma once
#include "Matrix.h"
class Vector :
	public Matrix
{
public:
	Vector();
	~Vector();
	void Vector::scalar_mult(int &scalar_mult, int **vector1, int **vector2, int p1, int p2); // функция для скалярного умножения векторов 

private:
	int k; 
	int *data1;

};


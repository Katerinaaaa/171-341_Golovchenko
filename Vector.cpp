#include "stdafx.h"
#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <algorithm>


using namespace std; 

Vector::Vector() // создание класса векторов 
{
	k = 0; // количество столбцов 
	data1 = 0; // вектор 
}


Vector operator + (Vector & vector1,
	Vector & vector2) // перегрузка оператора + 
{
	Vector vector_result;
	vector_result.j = vector1.j + vector2.j;

	return vector_result;
}

Vector operator - (Vector & vector1,
	Vector & vector2) // перегрузка оператора - 
{
	Vector vector_result;
	vector_result.j = vector1.j - vector2.j;

	return vector_result;
}

Vector operator * (Vector & vector1,
	Vector & vector2) // перегрузка оператора * 
{
	Vector vector_result;
	vector_result.j = vector1.j * vector2.j;

	return vector_result;
}


void Vector::scalar_mult (int &scalar_mult, int **vector1, int **vector2, int p1, int p2) // функция для вычисления скалярного произведения векторов 
{
	{
		for (int j = 0; j < p1; j++)
		{
			scalar_mult = scalar_mult + vector1[0][j] * vector2[0][j]; // формула скалярного умножения векторов 
		}
	}

}

Vector::~Vector() // вызов деструктора 
{
	delete[] data1; 
}

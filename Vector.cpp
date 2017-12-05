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


void Vector::scalar_mult (int &scalar_mult, int **vector1, int **vector2, int p1, int p2) // функци€ дл€ вычислени€ скал€рного произведени€ векторов 
{
	{
		for (int j = 0; j < p1; j++)
		{
			scalar_mult = scalar_mult + vector1[0][j] * vector2[0][j]; // формула скал€рного умножени€ векторов 
		}
	}

}

Vector::~Vector() // вызов деструктора 
{
	delete[] data1; 
}

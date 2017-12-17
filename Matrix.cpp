#include "stdafx.h"
#include "Matrix.h"
#include <algorithm>
#include <iostream> 

using namespace std;

Matrix::Matrix() // создание класса матриц
{
	m = 0; // количество столбцов 
	n = 0; // количество строк 
	data = 0; // матрица 
}

int Matrix::get(int i, int j) 
{
	if ((data != 0) &&(i < n) && (j < m))
	{
		return data[i * m + j]; // чтение элемента на позиции [i, j] 
	}
	else
	{
		return 0;
	}
}


Matrix operator + (Matrix & matrix1, 
				Matrix & matrix2)
{
	Matrix result;
	result.i = matrix1.i + matrix2.i;
	result.j = matrix1.j + matrix2.j;

	return result; 
}


Matrix operator - (Matrix & matrix1,
	Matrix & matrix2)
{
	Matrix result;
	result.i = matrix1.i - matrix2.i;
	result.j = matrix1.j - matrix2.j;

	return result;
}


Matrix operator * (Matrix & matrix1,
	Matrix & matrix2)
{
	Matrix result;
	result.i = matrix1.i * matrix2.i;
	result.j = matrix1.j * matrix2.j;

	return result;
}

Matrix operator * (Matrix & matrix1,
	Matrix & vector1)
{
	Matrix result;
	result.j = matrix1.j * vector1.j;

	return result;
}

ostream & operator << (ostream & matrix1,
	Matrix & matrix2)
{
	matrix1 << "Matrix: " << endl;
	matrix1 << "\ti = " << matrix2.i << ";" << endl;
	matrix1 << "\tj = " << matrix2.j << ";" << endl;

	return matrix1;
}


void Matrix::set(int i, int j, int value) 
{
	if ((data != 0) && (i < n) && (j < m))
	{
		data[i * m + j] = value; // запись элемента на позицию [i, j]
	}
}

void Matrix::set_size(int new_n, int new_m) // задание размера матрицы
{
	int *new_data = new int[new_n * new_m];
	for (int i = 0; i < new_n; ++i)
	{
		for (int j = 0; j < new_m; ++j)
		{
			new_data[i * new_m + j] = get(i, j);
		}
	}
	n = new_n; 
	m = new_m; 
	delete[] data; 
	data = new_data; 
}

int Matrix:: num_rows() // количество строк 
{
	return n; 
}

int Matrix::num_cols() // количество столбцов 
{
	return m; 
}

void Matrix::print() // печать матрицы 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << get(i, j) << " ";
		}
		cout << endl;
	}
}

void Matrix:: matrix_mult(int **matrix_result, int **matrix1, int **matrix2, int t1, int p1, int t2, int p2) //произведение матриц 
{

	for (int i = 0; i < t1; i++)
	{
		for (int j = 0; j < p2; j++)
		{
			int s = 0;
			for (int z = 0; z < p1; z++)
			{
				s = s + matrix1[i][z] * matrix2[z][j]; // формула умножения двух матриц 
			}
			matrix_result[i][j] = s;
		}
	}
}

void Matrix:: matrix_matrix(int **result, int **matrix1, int **matrix2, int n1, int m1, int n2, int m2) // функция для подсчета суммы матриц 
{

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j]; // формула сложения матриц
		}

	}
}



Matrix::Matrix(int nn, int mm) // вызов конструктора 
{
	data = 0;
	n = 0;
	m = 0;
	set_size(nn, mm); // создание матрицы размером 0х0 
}

Matrix::~Matrix() // вызов деструктора 
{
	delete[] data; 
}

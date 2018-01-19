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

Matrix::Matrix(const Matrix& other)
{
	m = other.m;
	n = other.n;
	data = new int[m * n];
	for (int i = 0; i < m * n; i++)
	{
		data[i] = other.data[i];
	}
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
				Matrix & matrix2) // перегрузка оператора +
{
	if (matrix1.num_cols() != matrix2.num_cols() ||
		matrix1.num_rows() != matrix2.num_rows())
	{
		cout << "WRONG" << endl;
		exit(1);
	}

	Matrix result(matrix1.num_rows(), matrix1.num_cols());
	for (int i = 0; i < matrix1.num_rows(); i++)
	{
		for (int j = 0; j < matrix1.num_cols(); j++)
		{
			int value = matrix1.get(i, j) + matrix2.get(i, j);
			result.set(i, j, value); 
		}
	}



	return result; 
}


Matrix operator - (Matrix & matrix1,
	Matrix & matrix2) // перегрузка оператора +
{
	if (matrix1.num_cols() != matrix2.num_cols() ||
		matrix1.num_rows() != matrix2.num_rows())
	{
		cout << "WRONG" << endl;
		exit(2);
	}

	Matrix result(matrix1.num_rows(), matrix1.num_cols());
	for (int i = 0; i < matrix1.num_rows(); i++)
	{
		for (int j = 0; j < matrix1.num_cols(); j++)
		{
			int value = matrix1.get(i, j) - matrix2.get(i, j);
			result.set(i, j, value);
		}
	}

	return result;
}


Matrix operator * (Matrix & matrix1,
	Matrix & matrix2) // перегрузка оператора * (матрица*матрица) 
{
	if (matrix1.num_cols() != matrix2.num_rows())
	{
		cout << "WRONG" << endl;
		exit(3);
	}

	Matrix result(matrix1.num_rows(), matrix2.num_cols());
	for (int i = 0; i < matrix1.num_rows(); i++)
	{
		for (int j = 0; j < matrix2.num_cols(); j++)
		{
			int value = 0;

			for (int k = 0; k < matrix1.num_cols(); k++)
			{
				value += matrix1.get(i, k) * matrix2.get(k, j);
			}
			result.set(i, j, value);
		}
	}
	
	return result;
}

ostream & operator << (ostream & os,
	Matrix & matrix1) // перегрузка оператора << 
{	
	for (int i = 0; i < matrix1.num_rows(); i++)
	{
		os << "\t[ ";
		for (int j = 0; j < matrix1.num_cols(); j++)
		{
			os << matrix1.get(i, j) << " "; 
		}
		os << "]" << endl;
	}

	return os;
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

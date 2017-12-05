#include "stdafx.h"
#include "Matrix.h"
#include <algorithm>
#include <iostream> 

using namespace std;

Matrix::Matrix() // �������� ������ ������
{
	m = 0; // ���������� �������� 
	n = 0; // ���������� ����� 
	data = 0; // ������� 
}

int Matrix::get(int i, int j) 
{
	if ((data != 0) &&(i < n) && (j < m))
	{
		return data[i * m + j]; // ������ �������� �� ������� [i, j] 
	}
	else
	{
		return 0;
	}
}

void Matrix::set(int i, int j, int value) 
{
	if ((data != 0) && (i < n) && (j < m))
	{
		data[i * m + j] = value; // ������ �������� �� ������� [i, j]
	}
}

void Matrix::set_size(int new_n, int new_m) // ������� ������� �������
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

int Matrix:: num_rows() // ���������� ����� 
{
	return n; 
}

int Matrix::num_cols() // ���������� �������� 
{
	return m; 
}

void Matrix::print() // ������ ������� 
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

void Matrix:: matrix_mult(int **matrix_result, int **matrix1, int **matrix2, int t1, int p1, int t2, int p2) //������������ ������ 
{

	for (int i = 0; i < t1; i++)
	{
		for (int j = 0; j < p2; j++)
		{
			int s = 0;
			for (int z = 0; z < p1; z++)
			{
				s = s + matrix1[i][z] * matrix2[z][j]; // ������� ��������� ���� ������ 
			}
			matrix_result[i][j] = s;
		}
	}
}

void Matrix:: matrix_matrix(int **result, int **matrix1, int **matrix2, int n1, int m1, int n2, int m2) // ������� ��� �������� ����� ������ 
{

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j]; // ������� �������� ������
		}

	}
}



Matrix::Matrix(int nn, int mm) // ����� ������������ 
{
	data = 0;
	n = 0;
	m = 0;
	set_size(nn, mm); // �������� ������� �������� 0�0 
}

Matrix::~Matrix() // ����� ����������� 
{
	delete[] data; 
}

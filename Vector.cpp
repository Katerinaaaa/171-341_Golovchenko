#include "stdafx.h"
#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <algorithm>


using namespace std; 

Vector::Vector() // �������� ������ �������� 
{
	k = 0; // ���������� �������� 
	data1 = 0; // ������ 
}


void Vector::scalar_mult (int &scalar_mult, int **vector1, int **vector2, int p1, int p2) // ������� ��� ���������� ���������� ������������ �������� 
{
	{
		for (int j = 0; j < p1; j++)
		{
			scalar_mult = scalar_mult + vector1[0][j] * vector2[0][j]; // ������� ���������� ��������� �������� 
		}
	}

}

Vector::~Vector() // ����� ����������� 
{
	delete[] data1; 
}

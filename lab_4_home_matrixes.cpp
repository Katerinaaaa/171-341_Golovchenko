// lab_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/*Лабораторная работа № 4*/

// Задачи: 
// 1) сложение матриц
// 2) сложение векторов 
// 3) умножение матриц 
// 4) умножение матрицы на вектор 
// 5) скалярное умножение векторов 
// 6) векторное умножение векторов 
// реализовать программно 


int main()
{

	int matrix1[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } }; // объявление матрицы (1)

	int matrix2[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } }; // объявление матрицы (2) 

	int matrix_result[3][3] = { { 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 } }; // обявление результирующей матрицы (в неё будет записан ответ) 

	int vector1[1][3] = { 1,
		2,
		3 }; // объявление вектора (1) 

	int vector2[1][3] = { 1, 2, 3 }; // объявление вектора (2) 


	int vector_result[1][3] = { 0, 0, 0 }; // объявление результирующего вектора (в него будет записан ответ) 

	int scalar_mult = 0; // объявление переменной (в нее будет записан ответ скалярноего произведения) 

						 // СЛОЖЕНИЕ МАТРИЦ (ЗАДАНИЕ №1) 

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix_result[i][j] = matrix1[i][j] + matrix2[i][j]; // формула сложения матриц
		}

	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix_result[i][j] << "\t"; // вывод результирующей матрицы
		}
		std::cout << std::endl;
	}


	// СЛОЖЕНИЕ ВЕКТОРОВ (ЗАДАНИЕ №2) 

	for (int j = 0; j < 3; j++)
	{
		vector_result[0][j] = vector1[0][j] + vector2[0][j];  // формула сложения векторов 
	}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << vector_result[0][i] << '\t'; // вывод результирующего вектора 
	}
	std::cout << std::endl;


	// УМНОЖЕНИЕ МАТРИЦ (ЗАДАНИЕ №3) 

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix_result[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				matrix_result[i][j] = matrix_result[i][j] + matrix1[i][k] * matrix2[k][j]; // формула умножения матриц 
			}
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			std::cout << matrix_result[i][j] << '\t'; // вывод результирующей матрицы 
		}
		std::cout << std::endl;
	}

	//	УМНОЖЕНИЕ МАТРИЦЫ НА ВЕКТОР (ЗАДАНИЕ №4)  

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {

			matrix_result[i][j] = 0;

			matrix_result[i][0] = matrix_result[i][0] + matrix1[i][j] * vector1[0][j]; // формула умножения матрицы на вектор 
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << matrix_result[i][0] << '\t' << std::endl; // вывод результирующей матрицы 
	}

	// СКАЛЯРНОЕ УМНОЖЕНИЕ ВЕКТОРОВ (ЗАДАНИЕ №5) 


	for (int j = 0; j < 3; j++)
	{

		scalar_mult = vector1[1][j] * vector2[1][j]; // формула скалярного умножения векторов 
	}


	std::cout << std::endl;
	std::cout << scalar_mult << std::endl; // вывод скалярного произведения 


										   // ВЕКТОРНОЕ УМНОЖЕНИЕ ВЕКТОРОВ (ЗАДАНИЕ №6) 


	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				matrix_result[i][j] = 1;
			}

		}
		else {
			if (i == 1) {
				for (int j = 0; j < 3; j++) {
					matrix_result[i][j] = vector1[0][j];
				}
			}
			else {
				for (int j = 0; j < 3; j++) {
					matrix_result[i][j] = vector2[0][j];
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		vector_result[0][i] = 0;
	}

	std::cout << std::endl;

	vector_result[0][0] = matrix_result[1][1] * matrix_result[2][2] - matrix_result[1][2] * matrix_result[2][1];
	vector_result[0][1] = matrix_result[1][0] * matrix_result[2][2] - matrix_result[1][2] * matrix_result[2][0]; // формула векторного умножения векторов 
	vector_result[0][2] = matrix_result[1][0] * matrix_result[2][1] - matrix_result[1][1] * matrix_result[2][0];

	std::cout << vector_result[0][0] << "\n";
	std::cout << vector_result[0][1] << "\n"; // вывод векторного произведения  
	std::cout << vector_result[0][2] << "\n";

	getchar();

	return 0;
}


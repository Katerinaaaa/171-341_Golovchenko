// lab_8_dyn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

void print_1d(int **vector, int m) // вывод на экран одномерного массива 
{
	for (int j = 0; j < m; ++j)
	{
		std::cout << vector[0][j] << " ";
	}
	std::cout << std::endl;

}


void print_2d(int **matrix, int n, int m) // вывод на экран двумерного массива 
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}



void matrix_mult(int **matrix_result, int **matrix1, int **matrix2, int t1, int p1, int t2, int p2) //произведение матриц 
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


void delete_matrix(int **matrix, int n) // удаление матрицы  
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}


int **alloc_matrix(int n, int m) // создание матрицы при помощи динамического массива 
{
	int **matrix_result = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix_result[i] = new int[m];
	}
	return matrix_result;
}



void matrix_matrix(int **result, int **matrix1, int **matrix2, int n1, int m1, int n2, int m2) // функция для подсчета суммы матриц 
{

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j]; // формула сложения матриц
		}

	}
}


void summs_vector(int **result, int **vector1, int **vector2, int k1, int k2) // функция для подсчета суммы векторов 
{

	for (int j = 0; j < k1; j++)
	{
		result[0][j] = 0;
		result[0][j] = vector1[0][j] + vector2[0][j];  // формула сложения векторов 
	}
}

void matrix_x_vector(int **result, int **matrix, int **vector, int t1, int p1, int t2) // функция для умножения матрицы на вектор 
{

	for (int j = 0; j < p1; j++)
	{
		result[0][j] = 0;
	}

	for (int i = 0; i < t1; i++)
	{
		for (int j = 0; j < p1; j++)
		{
			result[0][i] = result[0][i] + matrix[i][j] * vector[0][j]; // формула умножения матрицы на вектор 
		}
	}
}

void scalar_vector(int &scalar_mult, int **vector1, int **vector2, int p1, int p2) // функция для скалярного умножения векторов 
{
	for (int j = 0; j < p1; j++)
	{
		scalar_mult = scalar_mult + vector1[0][j] * vector2[0][j]; // формула скалярного умножения векторов 
	}
}

void vector_x_vector(int **result, int **vector1, int **vector2, int p1, int p2) // функция для векторного умножения векторов 
{

	for (int i = 0; i < p1; i++) {		// векторное умножение векторов 
		if (i == 0) {
			for (int j = 0; j < p2; j++) {
				result[i][j] = 1;
			}

		}
		else {
			if (i == 1) {
				for (int j = 0; j < p1; j++) {
					result[i][j] = vector1[0][j];
				}
			}
			else {
				for (int j = 0; j < p2; j++) {
					result[i][j] = vector2[0][j];
				}
			}
		}
	}

	for (int i = 0; i < p2; i++) {
		result[0][i] = 0;
	}

}


void matrix_summ() // функция, подсчитывающая сумму двух матриц 
{
	int n1, m1, n2, m2;
	std::cin >> n1 >> m1 >> n2 >> m2; // ввод пользователем размерностей двух матриц 

	int **matrix1 = alloc_matrix(n1, m1); // создание первой матрицы 
	int **matrix2 = alloc_matrix(n2, m2); // создание второй матрицы 
	int **result = alloc_matrix(n1, m2); // создание результирующей матрицы 

	for (int i = 0; i < n1; ++i)
	{
		for (int j = 0; j < m1; ++j)
		{
			matrix1[i][j] = rand(); // матрица 1 забивается рандомными числами 
		}
	}

	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			matrix2[i][j] = rand();  // матрица 2 забивается рандомными числами 
		}
	}

	std::cout << "Matrix 1: " << std::endl;
	print_2d(matrix1, n1, m1); // вывод на экран первой матрицы 
	std::cout << "Matrix 2: " << std::endl;
	print_2d(matrix2, n2, m2); // вывод на экран второй матрицы 

	matrix_matrix(result, matrix1, matrix2, n1, m1, n2, m2); // вызов функции для подсчета суммы двух матриц 
	std::cout << "-------------------------" << std::endl
		<< "Result: " << std::endl;

	if (m1 != m2, n1 != n2) // проверка возможности сложения матриц 
	{
		std::cout << "Cannot summ matrixes" << std::endl; // вывод сообщения при невозможности сложения 
		return;
	}
	else
	{
		print_2d(result, n1, m2); // вывод на экран результирующей матрицы 
	}

	delete_matrix(matrix1, n1);
	delete_matrix(matrix2, m2); // удаление динамических массивов по окончании их использования
	delete_matrix(result, n1);

}

void vector_summ() // функция для сложения векторов  
{
	int k1, k2;
	std::cin >> k1 >> k2; // ввод пользователем размерностей двух векторов  

	int **vector1 = alloc_matrix(1, k1); // создание первого вектора 
	int **vector2 = alloc_matrix(1, k2); // создание второго вектора 
	int **result = alloc_matrix(1, k2); // создание результирующего вектора 

	for (int j = 0; j < k1; j++)
	{
		vector1[0][j] = rand(); // вектор 1 забивается рандомными числами 
	}

	for (int j = 0; j < k2; j++)
	{
		vector2[0][j] = rand(); // вектор 2 забивается рандомными числами 

	}

	std::cout << "Vector 1: " << std::endl;
	print_1d(vector1, k1); // вывод на экран вектора 1 
	std::cout << "Vector 2: " << std::endl;
	print_1d(vector2, k2); // вывод на экран вектора 2 

	summs_vector(result, vector1, vector2, k1, k2); // вызов функции для подсчета суммы двух матриц 
	std::cout << "-------------------------" << std::endl
		<< "Result: " << std::endl;

	if (k1 != k2) // проверка возможности сложения векторов 
	{
		std::cout << "Cannot summ vectors" << std::endl; // вывод сообщения при невозможности сложения 
		return;
	}
	else
	{
		print_2d(result, 1, k2); // вывод результирующей матрицы 
	}

	delete_matrix(vector1, 1);
	delete_matrix(vector2, 1); // удаления динамических массивов по окончании их использования 
	delete_matrix(result, 1);
}

void calc_matrix() // функция, подсчитывающая произведение двух матриц 
{
	int t1, p1, t2, p2;
	std::cin >> t1 >> p1 >> t2 >> p2; // ввод пользователем размерностей двух матриц 

	int **matrix1 = alloc_matrix(t1, p1); // создание первой матрицы 
	int **matrix2 = alloc_matrix(t2, p2); // создание второй матрицы 
	int **result = alloc_matrix(t2, p1); // создание результирующей матрицы 

	for (int i = 0; i < t1; i++)
	{
		for (int j = 0; j < p1; j++)
		{
			matrix1[i][j] = rand(); // матрица 1 забивается рандомными числами 
		}
	}

	for (int i = 0; i < t2; ++i)
	{
		for (int j = 0; j < p2; ++j)
		{
			matrix2[i][j] = rand();  // матрица 2 забивается рандомными числами 
		}
	}

	std::cout << "Matrix 1: " << std::endl;
	print_2d(matrix1, t1, p1); // вывод на экран первой матрицы 
	std::cout << "Matrix 2: " << std::endl;
	print_2d(matrix2, t2, p2); // вывод на экран второй матрицы 

	matrix_mult(result, matrix1, matrix2, t1, p1, t2, p2); // вызов функции для подсчета произвдения двух матриц 
	std::cout << "-------------------------" << std::endl
		<< "Result: " << std::endl;

	if (p1 != t2) //  проверка возможности умножения 
	{
		std::cout << "Cannot multiply matrixes" << std::endl; // вывод сообщения в случае невозможности перемножения матриц 
		return;
	}
	else
	{
		print_2d(result, t1, p2); // вывод на экран результирующей матрицы 
	}

	delete_matrix(matrix1, t1);
	delete_matrix(matrix2, p2); // удаление динамических массивов по окончании их использования
	delete_matrix(result, t1);
}

void matrix_mult_vector() // функция, подсчитывающая произведение матриц на вектор 
{
	int t1, p1, p2;
	std::cin >> t1 >> p1 >> p2; // ввод пользователем размерностей матрицы и вектора  

	int **matrix = alloc_matrix(t1, p1); // создание матрицы 
	int **vector = alloc_matrix(1, p2); // создание вектора  
	int **result = alloc_matrix(1, p2); // создание результирующего вектора 

	for (int i = 0; i < t1; i++)
	{
		for (int j = 0; j < p1; j++)
		{
			matrix[i][j] = rand(); // матрица забивается рандомными числами 
		}
	}


	for (int j = 0; j < p2; ++j)
	{
		vector[0][j] = rand();  // вектор забивается рандомными числами 
	}


	std::cout << "Matrix: " << std::endl;
	print_2d(matrix, t1, p1); // вывод на экран матрицы 
	std::cout << "Vector: " << std::endl;
	print_1d(vector, p2); // вывод на экран вектора  

	matrix_x_vector(result, matrix, vector, t1, p1, p2); // вызов функции для подсчета произвдения двух матриц 
	std::cout << "-------------------------" << std::endl
		<< "Result: " << std::endl;

	if (t1 != p2) //  проверка возможности умножения 
	{
		std::cout << "Cannot multiply matrixes" << std::endl; // вывод сообщения в случае невозможности перемножения матрицы и вектора  
		return;
	}
	else
	{
		print_1d(result, p1); // вывод на экран результирующей матрицы 
	}

	delete_matrix(matrix, t1);
	delete_matrix(vector, 1); // удаление динамических массивов по окончании их использования
	delete_matrix(result, 1);
}

void scalar_mult_vector() // функция, подсчитывающая скалярное произведение двух векторов  
{
	int p1, p2;
	std::cin >> p1 >> p2; // ввод пользователем размерностей двух векторов 

	int **vector1 = alloc_matrix(1, p1); // создание первого вектора  
	int **vector2 = alloc_matrix(1, p2); // создание второго вектора 



	for (int j = 0; j < p1; j++)
	{
		vector1[0][j] = rand(); // вектор 1 забивается рандомными числами 
	}


	for (int j = 0; j < p2; j++)
	{
		vector2[0][j] = rand();  // вектор 2 забивается рандомными числами 
	}


	std::cout << "Vector 1: " << std::endl;
	print_1d(vector1, p1); // вывод на экран первого вектора  
	std::cout << "Vector 2: " << std::endl;
	print_1d(vector2, p2); // вывод на экран второго вектора   

	int scalar_mult = 0; // создание переменной, в которую будет записан результат скалярного произведения 
	scalar_vector(scalar_mult, vector1, vector2, p1, p2);
	std::cout << "-------------------------" << std::endl
		<< "Result: " << std::endl;

	if (p1 != p2) //  проверка возможности умножения 
	{
		std::cout << "Cannot multiply vectors" << std::endl; // вывод сообщения в случае невозможности перемножения матрицы и вектора  
		return;
	}
	else
	{
		std::cout << scalar_mult << std::endl;  // вывод на экран результата скалярного произведения  
	}

	delete_matrix(vector1, 1);
	delete_matrix(vector2, 1); // удаление динамических массивов по окончании их использования

}

void vector_mult_vector() // функция, подсчитывающая векторное произведение двух векторов  
{
	int p1, p2;
	std::cin >> p1 >> p2; // ввод пользователем размерностей двух векторов 

	int **vector1 = alloc_matrix(1, p1); // создание первого вектора  
	int **vector2 = alloc_matrix(1, p2); // создание второго вектора 
	int **result = alloc_matrix(p1, p2); // создание переменной, в которую будет записан результат скалярного произведения  


	for (int j = 0; j < p1; j++)
	{
		vector1[0][j] = rand(); // вектор 1 забивается рандомными числами 
	}


	for (int j = 0; j < p2; ++j)
	{
		vector2[0][j] = rand();  // вектор 2 забивается рандомными числами 
	}


	std::cout << "Vector 1: " << std::endl;
	print_1d(vector1, p1); // вывод на экран первого вектора  
	std::cout << "Vector 2: " << std::endl;
	print_1d(vector2, p2); // вывод на экран второго вектора   


	vector_x_vector(result, vector1, vector2, p1, p2);
	std::cout << "-------------------------" << std::endl
		<< "Result: " << std::endl;

	if (p1 != p2) //  проверка возможности умножения 
	{
		std::cout << "Cannot multiply vectors" << std::endl; // вывод сообщения в случае невозможности перемножения матрицы и вектора  
		return;
	}
	else
	{
		print_1d(result, p1);  // вывод на экран результата скалярного произведения  
	}

	delete_matrix(vector1, 1);
	delete_matrix(vector2, 1); // удаление динамических массивов по окончании их использования
	delete_matrix(result, p1);

	return;
}




int main()
{

	matrix_summ(); // вызов функции для подсчета суммы двух матриц (ЗАДАНИЕ № 1) 

	vector_summ(); // вызов функции для подсчета суммы векторов (ЗАДАНИЕ № 2) 

	calc_matrix(); // вызов функции для подсчета произведения двух матриц (ЗАДАНИЕ № 3) 

	matrix_mult_vector(); // вызов функции для подсчета произведения матрицы на вектор (ЗАДАНИЕ № 4) 

	scalar_mult_vector(); // вызов функции для подсчета скалярного произведения векторов (ЗАДАНИЕ № 5) 

	vector_mult_vector(); // вызов функции для подсчета векторного произведения векторов (ЗАДАНИЕ № 6) 

	getchar();

	return 0;
}


// lab_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/* ЛАБОРАТОРНАЯ РАБОТА № 2
МАССИВЫ И УКАЗАТЕЛИ*/

int main()
{
	// переменная, хранящая адрес другой переменной в памяти, называется указателем

	int a = 231;
	double ch = 10.005;

	int * ptr_int = &a; // pointer - указатель 
	double * ptr_ch = &ch;

	// все указатели всегда одной и той же разрядности (размера) 
	std::cout << "int pointer size = " << sizeof(ptr_int) << std::endl;
	std::cout << "char pointer size = " << sizeof(ptr_ch) << std::endl;
	std::cout << "double pointer size = " << sizeof(double *) << std::endl;
	std::cout << "long long pointer size = " << sizeof(long long *) << std::endl;


	// содержимое указателей 
	std::cout << "ptr_int = 0x" << std::hex << ptr_int << std::endl;
	std::cout << "ptr_ch = 0x" << std::hex << ptr_ch << std::endl;

	// в дальнейшем будет показано, что каким бы ни был огромным тип данных (строка, объект, массив) 
	// указатель на него всегда будет занимать 4/8 байт, что и является основным преимужеством указателей 

	// оператор разыменования указателей: чтобы получить значение, хранящееся по данному указателю, 
	// нужно еще раз применить оператор *  
	std::cout << std::endl << "*ptr_int =  " << std::dec << *ptr_int << std::endl;
	std::cout << "*ptr_ch = " << *ptr_ch << std::endl;

	// массив - блок из нескольких однотипных данных 
	// задавать с помощью массивов удобно: 
	// 1) вектора и матрицы 
	// 2) множество точек из 3D и 2D геометрии 
	// 3) какой-либо числовой ряд, таблица и т.д. 
	// 4) строка - массив символов 
	// 5) видеобуфер (двумерный массив, соответствующий пиклелям экрана) 

	int arr[5] = { 1, 50, 11, 12, 1000 }; // одномерный массив из 5 целых знаковых чисел 

										  // в оперативной памяти массив хратится компактно (без разрывов, элемент за элементом)  

	std::cout << arr[0] << '\t' <<
		arr[1] << '\t' << // в одинарных кавычках - только один символ (char),	в двойных - любое множество 
		arr[2] << '\t' << // в общем случае можно везде использовать двойные 
		arr[3] << '\t' <<
		arr[4] << '\t' << std::endl;

	int arr2D[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } };

	std::cout << std::endl;
	std::cout << arr2D[0][0] << '\t' << arr2D[0][1] << '\t' << arr2D[0][2] << '\t' << std::endl <<
		arr2D[1][0] << '\t' << arr2D[1][1] << '\t' << arr2D[1][2] << '\t' << std::endl <<
		arr2D[2][0] << '\t' << arr2D[2][1] << '\t' << arr2D[2][2] << '\t' << std::endl;

	// если не инициализировать переменные (включая массив) - там хранится неопределённое число 
	// для инициализации всего массива нулями, прописывается = {0} 
	// 1) на полях проставить точку остановки 
	// 2) в коде выпадающей подсказки посмотреть значение переменной 

	// по сути, квадратные скобки работают, как разыменование и смещение 
	std::cout << "*(*(arr2D+2)+2) = arr2D[2][2] = " << *(*(arr2D + 2) + 2) << std::endl;

	// arr2D тип **int (указатель на тип int) 
	// arr2D[1] тип *int - указатель на одну строчку - одномерный массив внутри двухмерного 
	// двумерный массив уложен в одномерном пространстве ОП построчно 
	// arr2D[1][1] тип int - двойные скобки дважды разыменуют указатель 
	// все статические массивы в памяти расположены компактно 

	// если не инициализировать переменные (включая массив) - там хранится неопределенное число 
	// для инициализации всего массива нулями, приписывается = {0}
	// 


	getchar();

	return 0;
}


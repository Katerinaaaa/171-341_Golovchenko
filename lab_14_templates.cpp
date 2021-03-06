// lab_14_templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>		// std::cout 
#include <typeinfo>		// operator typed 

/* ШАБЛОНЫ */

// В ходе изучения было выяснено, что во время выполнения программы можно менять рамерности массива, 
// но не его тип 

// однако на уровне исходного кода (текста программы) можно использовать с минимальными изменениями 
// одни и те же фрагменты (а так же целые функции и классы) с различными типами данных. 
// Например, настроить вектора и матрицы из ДЗ на работу с double, long long, short, char с минимальной доработкой 

using namespace std; 

template<typename SomeType>
SomeType fnc1(SomeType p1, SomeType p2)
{
	cout << typeid(SomeType).name() << endl; // проверка, с каким типом данных работает функция 
	return p1 / p2; 
}


//более сложный пример функции с шаблоном 
template<typename SomeType1,
		typename SomeType2, 
		int n> // в шаблоне можно прописывать не только типы, но и параметры 
SomeType1 fnc2(SomeType1 p1, SomeType2 p2)
{
	
	SomeType1 tmp = p1; 
	for (int i = 0; i < n, i++)
	{
		p1 / p2; 
	}
		return tmp;
}

// каждый раз компилятор анализирует каждый вызов шаблонной функции и определяет, какой тип аргументов используется 
// и под каждый набор аргументов создает, неявно от программиста, реализацию (перегрузку) функции данного типа 
// то есть, вместо того, чтобы написать несколько перегрузорк fnc1(double p1, double p2), fnc1(int p1, int p2), 
// fnc1(char p1, char p2), программист задаёт правило, по которому КОМПИЛЯТОР САМ СОЗДАЁТ ПЕРЕГРУЗКИ  

int main()
{
	double d = 10.5; 
	char c = 15; 
	unsigned long long l = 100500;

	fnc1(d, d);
	fnc1<int>(c, c); // в угловых скобках компилятору можно явно задавать тип, по которому строить функции 
	fnc1(l, l); 

	

	getchar(); 
    return 0;
}

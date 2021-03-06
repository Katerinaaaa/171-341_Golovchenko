// lab_5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/* ЛАБОРАТОРНАЯ РАБОТА № 5*/

// ФУНКЦИИ 

// 1) что такое функции и как ими пользоваться 
// 2) области видимости 
// 3) передача параметров по значению 


// Функция - фрагмент кода, имеющий собственное имя (индентификатор), а так же интерфейс - входные и выходные параметры 
// код оформляется в виде функции в случаях: 
// 1) необходимость частого использования одного и того же фрагмента кода 
// 2) для упорядочивания больших массивов кода 
// 
// 
// Синтаксис объявления функции 
// тип_вых_параметра имя_функции( тип имя_параметра1,
//								  тип имя_параметра1, 
//								  ...) // заголовок функции 
// или ОБЪЯВЛЕНИЕ 

// тело или определение функции  
//{
// ... выполняемые операторы 
// return выходное_значение; (если функция void, то просто return) 
//}

// нет выходного значения 
//  void имя_функции(тип имя_параметра1,
//					 тип имя_параметра2,
//					 ...) 

//  void имя_функции() // нет входных и выходных 

// пример 1 
int fnc1(double p1, // параметр... размерность... [м]
	char p2, // <значение параметра> размерность [см]
	int const p3) // <значение параметра> размерность [км]
				  // передача параметров по значению 
{
	p1 = 2.5;
	//p3 = 10; 
	return p1 + p2 / 100 + p3 * 1000; // типы приводятся автоматиччески 
}

// пример 2 ОБЪЯВЛЕНИЕ функции в начале отдельно от теда 
int fnc2(double p1, // параметр... размерность... [м]
	char p2, // <значение параметра> размерность [см]
	int p3); // <значение параметра> размерность [км]


using namespace std;
int main()
{
	double d = 1.5;
	char ch = 1000;
	int ret_value = 0;

	fnc1(d, ch, 5); // Функцию можно использовать без выхода параметров // такой способ передачи называется передачей по значению 
	ret_value = fnc1(d, ch, 5);
	cout << "fnc1(d,ch,5) = " << fnc1(d, ch, 5) << std::endl;
	cout << "fnc2(d,ch,5) = " << fnc2(d, ch, 5) << std::endl;

	getchar();
	return 0;
}

// ОПРЕДЕЛЕНИЕ функции в самом конце 
int fnc2(double p1, // параметр... размерность... [м]
	char p2, // <значение параметра> размерность [см]
	int p3) // <значение параметра> размерность [км]
			// заголовок функции повторяется и должен быть в точности таким же 
{

	return p1 + p2 / 100 + p3 * 1000; // типы приводятся автоматиччески 
}

// через выходной параметр функция в любом случае может возвращать одно число/одну переменную 
// если требуется возвращать из функции несколько выходных параметров 
// они возвращаются по ссылке 

void fnc3(double a, double b, // входные параметры, переданные ПО ЗНАЧЕНИЮ 
	double &c, double &d) // параметры переданы ПО ССЫЛКЕ, через них можно как передавать, так и выводить значения 
{
	c = a + b;
	d = a - b;
	return;
}

// функция работает аналогично: 

void fnc3(double a, double b, // входные параметры, переданные ПО ЗНАЧЕНИЮ 
	double *c, double *d) // параметры переданы ПО ССЫЛКЕ, через них можно как передавать, так и выводить значения 
{
	*c = a + b; // * - оператор разыменования 
	*d = a - b; // в версии с амперсендом & компиллятор сам "расставляет * "   
	return;
}

// это значит, что в функцию передаются адреса (указатели) 
// на некоторые внешние данные, а не копии самих данных 
// и по адресу (указателю) из функции можно изменить сам оригинал 

// Функция должна быть объявлена ДО момента ее первого использования 
// так делать нельзя потому, что компиллятор обрабатывает текст программы всего лишь один раз, 
// и если он встретит функцию где-то после, 
// назад с объявленной функцией уже не вернется 

// переменные, объявленные внутри функции, видны толко внутри функции 
// те данные, которые передаются в параметры, передаются в виде копий 
// их можно менять внутри функции 

// ПЕРЕДАЧА МАССИВОВ В ФУНКЦИЮ 
// первый способ передачи (и возвращения) массива в функцию 
void fnc4_1(int matr[3][3]) // передаётся некопия всего массива, а указатель на первый элемент 
							// несмотря на то, что передаём по значению 
{
	// раз передаётся указатель на оригинальный массив 
	// следовательно, меняется тоже исходный внешний оригинальый массив 
	matr[1][1] = 10; // какие-то действия с массивом и его элементами 
	return;
}

// второй способ предачи (и возвращения) массива в функцию 
void fnc4_2(int matr[][3]) // пользователь должен самостоятельно следить за тем, 
						   // чтобы индекс не превышал длину массива 

{
	matr[1][1] = 10; // какие-то действия с массивом и его элементами 
	return;
}

// третий способ передачи (и возвращения) массива в функцию 
void fnc4_3(int(&matr)[3][3])
{
	matr[1][1] = 10; // какие-то действия с массивом и его элементами 
	return;
}

// четвёртый способ передачи (и возвращения) массива в функию 
void fnc4_4(int ** matr) // пользователь должен самостоятельно следить за тем, 
						 // чтобы индекс не превышал длину массива 
{
	matr[1][1] = 10;
	return;
}


// стек- специальная область памяти. При вызове функции 
// копии параметров, локальные переменные функции и адрес обратного перехода 
// занимают место в стеке 
// после returrn переменные и параметры "стираются", и выполняется переход по обратному адресу  

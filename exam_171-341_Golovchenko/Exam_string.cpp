#include "stdafx.h"
#include "Exam_string.h"
#include <iostream> 

using namespace std; 

Exam_string::Exam_string() // создание класса строк 
{
	int a = 0; // длина строки 
	int max = 0; // длина увеличенной строки 
	char *st = 0; // динамический массив, хранящий строку 
	char *new_st = 0; // динамический массив, хранящий строку (новую) 
}

Exam_string::Exam_string(const Exam_string& other) // создание пустой строки 
{
	a = other.a; 
	st = new char[a]; // создание динамического массива (строка нулевой длины) 
	for (int i = 0; i < a; i++)
	{
		st[i] = other.st[i]; 
	}
}

char Exam_string::get(int i) // чтение строки 
{
	if ((st != 0) && (i < a)) // если строка не нулевая И если i < a (не выходит за пределы строки) 
	{
		return st[i]; // вывод требуемого символа 
	}
	else
	{
		return 0; // выход из программы 
	}
}

char Exam_string::insert(int i, int value) // Метод, вставляющий на заданную позицию 
// внутри строки указанную в параметрах последовательность символов(*char)
{
	if ((st != 0) && (i < a)) // строка не должна быть нулевой, 
							// а так же не должно происходить переполнение строки 
	{
		st[i] = value; // программа записывает символ в выбранное место 
	}
	else
	{
		return 0; 
	}

}

void Exam_string::add(char s) // Метод add(), принимающий строку символов *char,
						// либо стандартную строку std∷string и выполняющий
						// конкатенацию(сложение имеющейся строки с
						// принимаемой)
{
	if (a + 1 > max)
	{
		grow();
	}
	st[a] = s; 
	a = a + 1; 
}

void Exam_string::grow() // увеличение размера строки 
{
	new_st = new char[2 * max + 1];

	for (int i = 0; i < max; i++)
	{
		new_st[i] = st[i]; 
	}
	delete[] st; 
	st = new_st; 

	max = 2 * max + 1; 
}

void Exam_string::clear() // очищение строки 
{
	a = 0; 
}

char Exam_string::print()
{
	for (int i = 0; i < a; i++)
	{
		cout << get(i) << " "; 
	}
}

Exam_string::~Exam_string()
{
	delete[] st; 
}

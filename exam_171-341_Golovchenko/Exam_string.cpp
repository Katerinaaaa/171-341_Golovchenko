#include "stdafx.h"
#include "Exam_string.h"
#include <iostream> 
#include <string>

using namespace std; 

Exam_string::Exam_string() // создание класса строк 
{
	int a = 0; // длина строки 
	int max = 0; // длина увеличенной строки 
	char *st = 0; // динамический массив, хранящий строку 
	char *new_st = 0; // динамический массив, хранящий строку (новую) 
}

Exam_string::Exam_string(const Exam_string& other) // создание пустой строки (конструктор №1) 
{
	a = other.a; 
	st = new char[a]; // создание динамического массива (строка нулевой длины) 
	for (int i = 0; i < a; i++)
	{
		st[i] = other.st[i]; 
	}
}

Exam_string::Exam_string(const char *source) // копирование из массива char (конструктор №2) 
{
	a = 0; 
	// Вычисление длины исходной строки 
	while (source[a] != 0)
	{
		a++; 
	}
	max = a;
	st = new char[max]; 

	// Копирование исходной строки 
	for (int i = 0; i < a; i++)
	{
		st[i] = source[i]; 
	}
}

Exam_string::Exam_string(const std::string& source) // копирование из std::string (конструктор №3) 
{
	// Выделение такого количества байт, сколько потребуется для работы 
	max = source.size();
	a = max;
	st = new char[max];
	// копирование исходнной строки 
	for (int i = 0; i < source.size(); i++) 
	{
		st[i] = source[i];
	}
}

int Exam_string::num() // вывод размера строки 
{
	return a; 
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

char Exam_string::cut(int s, int number) // Метод, удаляющий с заданной позиции заданное в
										// параметрах количество символов 
{
	if (number + s < a)
	{
		for (int i = number; i < number + s; i++)
		{
			st[i] = ' ';
		}
		for (int i = number; i < s + number; i++)
		{
			st[i] = st[i + s];
			st[number + s] = '\0'; 
		}
	}
	else
	{
		return 0; 
	}
}

void Exam_string::clear() // очищение строки 
{
	a = 0; 
}

void Exam_string::print() // вывод строки на экран 
{
	for (int i = 0; i < a; i++)
	{
		cout << get(i) << " "; 
	}
}

Exam_string::~Exam_string() // деструктор 
{
	delete[] st; // удаление строки 
}

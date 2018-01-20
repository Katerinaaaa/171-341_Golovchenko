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

char Exam_string::insert()
{

}

void Exam_string::add()
{

}

void Exam_string::clear()
{

}

Exam_string::~Exam_string()
{
	delete[] st; 
}

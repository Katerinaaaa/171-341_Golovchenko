// lab_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"//при компилляци берется все содержимое текстового файла заголовка и вставляется вместо соответствующего include 
// *.h - header - заголовок 
#include <iostream> // в угловых скобках - файлы, которые следует искать в системных папках (это определенный набор папок). в кавычках - файлы из папки проекта 
#include <bitset> 
#include <cmath>

/*ЛАБОРАТОРНАЯ РАБОТА № 1*/

int main()// точка входа оформлена в виде функции. Функция - фрагмент кода, имеющий собественное имя (идентификатор)  
{
	std::cout << "Hello world\n";
	// esc - последовательность - служебные и непечатуемые символы (переносы, возврат строки и т.д.) 
	// включает строку через "\" 
	// при обработке компиллятор пропускает слеш, а вместо следующей буквы вставляет соответствующий символ 
	std::cout << "Hello world" << std::endl; // шаблон endl в конечном счете представляет тот же самый символ "\n" 
											 // в некоторых системах требуется писать "\r\n" n - new line, r - return 

	std::cout << "sizeof(int) = " << sizeof(int) << std::endl; // объект cout вместе с оператором << позволяет выводить одновременно
															   // как строки, так и переменные других типов, не заботясь о преобразовании их в строк 
															   // Автомотически делает приведение типов к строке 
	std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
	std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
	std::cout << "sizeof(double) = " << sizeof(double) << std::endl;
	std::cout << "sizeof(float) = " << sizeof(float) << std::endl;

	std::cout << "sizeof(long) = " << sizeof(long) << std::endl;
	std::cout << "sizeof(long int) = " << sizeof(long int) << std::endl;
	std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;
	std::cout << "sizeof(long long int) = " << sizeof(long long int) << std::endl;

	std::cout << "sizeof(true) = " << sizeof(true) << std::endl;
	std::cout << "sizeof(false) = " << sizeof(false) << std::endl;
	std::cout << "sizeof(bool) = " << sizeof(bool) << std::endl;

	int a = INT_MAX;  // 1) объявление переменной а типа integer, 2) инициализация 
	std::cout << "a = " << std::bitset <32>(a) << std::endl;
	int b = 0b10000000000000000000000000000000; // если к наибольшему знаковому положительному целому прибавить единицу, происходит переполнение
												// и получается наименьшее отрицательное число 
	unsigned int b_without_sign = 0b10000000000000000000000000000000;
	int oct = 0100;
	int hex = 0xff;
	std::cout << "b = " << b << std::endl;
	std::cout << "oct = " << oct << std::endl; // ввод числа в восьмеричном виде 
	std::cout << "0xff = " << 0xff << std::endl; // ввод числа в шестандцатеричном виде 
	std::cout << "b_without_sign = " << b_without_sign << std::endl; // если при объявлении переменной прописывается unsign, то число не может быть отрицательным
																	 // и его допустимый диапазон удваивается 
	int temp = a + b + hex + oct;

	// целые числа беззнаковые представлены в разрядах оперативной памяти, в разрядах регистра процессора в двоичном виде 

	// процессор не умеет работать с битами и с одиночными байтами и даже с одиночными char или short 
	// в процессоре есть 16- и 32-разрядные ячейки памяти, если вы загружаете char или boolean, то незанятые разряды будут нулевыми 

	getchar(); // ожидание ввода пользователя - 1 символ 
	return 0; // возврат из функции main, по сути - завершение работы приложения  
}


// lab_17_data_structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <cmath>
#include <exception>



// STD - стандартная библиотека языка С++ 
// функции print_f, getchr, fopen, read - из данной библиотеки 
// является связующим звеном между 
// [C++] -> [STD] -> [OC]

// STL - standard template library (template - шаблон) 
// это расширение библиотеки  STD, содержащее структуры данных 
// и функции по работе с ними 
// именно из STL подключаются потоки cout, cin, fstream, ifstream, ofstream, 
// контейнеры array, vector, list, map, 
// итераторы, 
// алгоритмы sort, copy и т.д. 

// std::array 
// инкапсуллирует массивы постоянной (неизменной) длины, является шаблоном 

// std::vector 

// std::list 

// std::map 

int main()
{
	// std::array 
	// инкапсуллирует массивы постоянной (неизменной) длины, является шаблоном 

	std::array<double, 10> double_array1; // объект, построенный из шаблона std::array<>, инкапсуллирующий массив 
	double_array1[5] = 10.5; 
	double_array1.fill(0.0);
	int array_length = double_array1.size();
	// double_array.swap() - функция для обмена между содержимым двух массивов 
	std::sort(double_array1.begin(), double_array1.end()); 
	std::array<double, 10> double_array2 = { 0 }; 
	std::copy(double_array1.begin(), double_array1.end(), double_array2.begin());

	// для создания двумерных массивов 
	std::array<std::array<int, 3>, 3> mat33; 
	mat33[1][1] = 100; 
	
	// итератор- это объект, ссылающийся на элемент массива, вектора или списка 
	// "улучшенный" вариант переменной-счётчика 
	// нужен для связи шаблонов STL 
	std::array<double, 10>::iterator array_iterator; 

	// std::vector 
	// инкапсуллирует одномерный массив и предоставляет средства 
	//  для измерения его длины 
	// очень близким к std::vector по функционалу является std::string 
	// ОСНОВНОЙ НЕДОСТАТОК 
	// однако каждый раз при увеличении длины vector запрашивает у ОС 
	// новую область памяти и копирует туда старую (старую освобождает) 
	// ОСНОВНОЕ ПРЕИМУЩЕСТВО 
	// доступ к элементам осуществляется быстро напрямую по адресу 
	// [адрес_1 + i]
	// ВЫВОД 
	// доступ быстрый, а вставка или увеличение - медленное 

	std::vector<long long> long_vector = { 10, 15, 20 };

	std::cout << "vector<> = "; 
	for (long long value : long_vector)
		std::cout << '\t' << value; 
	std::cout << std::endl; 
	
	long_vector.push_back(25);
	long_vector.push_back(0);

	std::cout << "vector<> after push() ";
	for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;

	// также у std::vector присутствует весь функционал std::arrat:
	// размер, сортировка, итераторы, копирование, обмен и т.д. 

	std::sort(long_vector.begin(), long_vector.end());

	std::cout << "vector<> after sort() ";
	for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;

	long_vector[2] = 11; 

	// вставка в vector 
	long_vector.insert(long_vector.begin() + 2, 100500/*с помощью шаблона можно вставить несколько значений*/); 
	std::cout << "vector<> after insert() ";
	for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;

	// std::list 
	// всё наоборот: вставка и увеличение списка производится быстрее, чем в vector, 
	// а доступ - медленнее, причём чем дальше от 1-го элемента - тем МЕДЛЕННЕЕ 
	// так как для доступа к i-му элементу (определения его адреса в ОП) необоходимо 
	// пройти по цепочке от 1-го элемента 

	// в отличие от array и vector - не является компактным массивом в памяти, 
	// элементы std::list представлены отдельными объектами, связанными друг с другом 
	// указателями, которые они хранят 
	// [null|данные|указатель] ---> [указатель|данные|указатель] 
	//													/
	//												   /
	//												  /
	//												 /
	//											[указатель|данные|указатель] <---> [указатель|данные|указатель] 
	
	std::list<char> char_list = { 'b' };
	char_list.push_front('a'); // вставка перед первым элементом 
	char_list.push_back('c'); // вставка после последнего 

	for (char ch : char_list)
	{
		std::cout << ch << std::endl;
	}

	// если класс простой и не содержит динамических данных 
	class sample_class
	{
		int a;
		double b; 
	};

	// список можно составлять из объектов класса 
	std::list<sample_class> obj_list1; 
	// в противном случае - из указателей на объекты 
	std::list<sample_class*> obj_list2;


	// std::map 
	// состоит из пар "ключ" - "значение" 
	// например "TU-154" - 5000, "B777" - 6000, "A320" - 6500
	std::map<std::string, double> plane_and_range =
		{ {"TU-154", 5000}, {"B777", 6000}, {"A320", 6500} }; 
	plane_and_range.insert(std::pair<std::string, double>("A380", 10000.0));

	std::cout << "The range of Boeing 777 is " << plane_and_range["B777"] << std::endl; 
	std::cout << "The range of A380 is " << plane_and_range["A380"] << std::endl;
	// plane_and_range.insert({ "A380", 10000.0 });
	// std::cout << "The range of A380 is " << plane_and_range["A380"] << std::endl;

	double d_array[5] = { 1, 2, 3, 4, 5 }; 
	int i = 60000;
	try // в try помещается код, потенциально способный исключения: 
		// функции, не получающие доступа к файлам, портам, устройствам и т.д. 
		// функции, неправильно работающие с памятью 
		
	{
		d_array[i] = 15;
		throw 1; 
	}

	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl; 
	}
	
	catch (...)
	{
		std::cout << "Error in \"d_array[i] = 15\"" << std::endl; 
	}

	getchar(); 
    return 0;
}



// в курс не вошли темы, необходимые для штатной коммерческой разработки ПО 

//	- юнит-тестирование (на каждый модуль или проект создаётся проект, котрый 
// производит тестирование, сборка и запуск sln настраивается таким образом, что 
// в первую очередь собирается базовый проект, затем собирается код теста и запускается)
//	- технологии, процессы и шаблоны разработки (SCRUM, Waterfall, Agile, ...) 
//	- создание графических приложений 
//	- многопоточные и асинхронные приложения 

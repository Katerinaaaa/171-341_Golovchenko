// lab_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 


// ЛАБОРАТОРНАЯ РАБОТА № 9 
// КЛАССЫ И ОБЪЕКТЫ


//Класс - тип данных, объединяющий под одним идентификатором именем класс, подходящие по смыслу данные(свойства) и функции по их обработке(методы) 
//Свойства - переменные в классе 
//Метод - функция в классе 
//Объект - экземпляр класса, его реализация в оперативеной памяти


/* ПРИМЕР
класс Оружие
int число оставшихся зарядов
int ёмкость магазина
double дальность
double начальная скорость
double вес
bool oprics
bool loaded

функция зарядка (число оставшихся зарядов -> max)
функция проиграть анимацию ()
функция выстрел (вес - 1 патрон, анимация выстрела, число оставшихся зарядов - 1, ...)
*/

/*
объявляется пользовательский тип данных - класс
class имя_класса {

private:
int число_оставшихся_зарядов;
int ёмкость_магазина = 30; - значение, присваемое при создании объекта
public:
double дальность = 1500;
double начальная_скорость;
double вес;
bool optics;
bool loaded;

имя_метода(тип параметрб тип параметр); - всё, как в обычной функции
зарядка (параметры);
проиграть_анимацию(параметры);
выстрел(параметры);
}


...

Имя_класса weapon1;
Имя_класса * weapon2 = new Имя_класса();

...

weapon1.ёмкость_магазина = 60; // еслиобъект создавался как переменная, для доступа используется "."
weapon1.выстрел(параметры);

weapon2-> ёмкость_магазина = 100; // если объект создавался по ссылке, для доступа используется "->"
weapon2->выстрел(параметры);
*/

/*
классы и объекты имеют смысл только для человека на уровне исходных кодов,
после компиляции в машинные коды ЭВМ имеет дело с отдельными переменными и функциями
*/

/*
конструктор и деструктор - специфические функции объекта, которые срабатывают
автоматически, соответственно, при создании и удалении объекта

имя конструктора совпадает с именем класса, имя деструктора начинается с тильды ~Имя_класса()
*/

/*
свойства и методы класса имеют 3 спецификатора доступа: private, public и protected
свойства и методы public могут вызываться извне объекта
свойства и меоды private могут вызываться только методами самого объекта
protected ведёт себя более сложным образом и будет описана в теме "Наследование"

*/

using namespace std;

class weapon_class // возвращаемых параметров у конструктора нет и быть не может (по правилам языка) 
{
public:

	weapon_class() // в конструкторе проводится инициализация свойств класса и прочие требуемые начальные действия 
	{
		weight = 3.5;
		cartridges = capacity;
		cout << "Weapon_class()" << endl;
	}
private:
	int cartridges; // число_оставшихся_зарядов
	int capacity = 30; // ёмкость_магазина 
public:
	double range = 1500; // дальность 
	double velocity; // начальная_скорость 
	double weight; // вес 
	bool optics;
	bool loaded;

	void load() // перезарядка 
	{
		cartridges = capacity;
	}

	void play_animation();

	void shot()
	{
		return;
	}

	~weapon_class() // деструктор
	{
		cout << "~weapon_class()" << endl;
	}
};


void weapon_class::play_animation() // метод, определяемый все класса, начинается с имя_класса:: 
{
	return;
}

void fnc1()
{
	cout << "fnc1" << endl;
	int a;
	double b;
	weapon_class weapon;
	cout << "fnc1 return" << endl;
	// тут был вызвани диструктор объекта weapon 
	return;
	// pop 
	// pop 
	// pop 
}


int main()
{
	weapon_class weapon1; // если объект компактный и не может значительно менять свой размер во время жизненного цикла 
						  // weapon1.cartridges = 1e06; // в private размещаются, как правило, свойства и методы, 
						  // относящиеся ко внутренней механике объекта, доступ к которым стороннего пользователя может повлечь 
						  // нарушение правильной работы объекта, поэтому с такими свойствами и методами работают с помощью 
						  // публичных методов класса, обеспечивающих дополнительные проверки и ограничения 
	weapon1.load(); // функция load не присваивает слишком маленькие или большие значения 
	weapon_class * weapon2 = new weapon_class(); // если объект значительно меняет свой размер во время жизненного цикла 

	delete weapon2; // здесь срабатывет деструктор weapon1 

					// пролог функции 
					// push 10 
					// push 5 
					// push ret_addr  

	fnc1();

	getchar();
	return 0;
}

// С ++ язык высокого уровня потому, что: 
// 1) компиллятор автоматически прописывает вызов конструктора и деструктора (без ведома программиста) 
// 2) автоматическое размещение пролога и эпилога фукнций 


// задание 
// 1) создать класс для вектора и матрицы. ядром класса будет private-массив, хранящий матрицу или вектор 
// 2) создать в каждом классе по 2 конструктора: 
//		без параметров (инициализирующий матрицу класса нулями) 
//		с параметром - массивом (копирующий значения параметра в свойство-матрицу класса) 
// 3) реализовать написанные ранее функции как члены класса 
// 4) объявить класс в *.h-файле с соответствующим названием, а методы описать *.cpp-файлы с тем же названием 
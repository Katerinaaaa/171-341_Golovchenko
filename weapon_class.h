#pragma once

#include <iostream> 

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

	void shot();

	~weapon_class(); // деструктор
};

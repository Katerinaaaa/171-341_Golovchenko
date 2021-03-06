// lab_10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// СТАТИЧЕСКИЕ И ДИНАМИЧЕСКИЕ БИБЛИОТЕКИ 

// EXE 

// *.lib (англ. library) - файлы статически подключаемых библиотек 
// *.dll (Dynamic Linked Library) - файлы динамически подключаемых библиотек 

// *.a (англ. object) - статические библиотеки в Linux 
// *.so (англ. object) - динамические библиотеки в Linux 

// Библиотека *.lib или *.dll - файл, содержащий готовый машинный код для 
// многократного повторного использования
// Код из статических библиотек помещается в *.exe в момент его сборки (после компиляции) 
// и далее является частью самого *.exe 

// если несколько *.exe используют один и тот же *.lib код дублируется в каждом *.exe 

// Код из динамической библиотеки может использоваться одновременно многими приложенинями 
// из одного и того же *.dll файла, загруженного в ОП 

// если нескольког *.exe используют один и тот же *.dll, *.dll может быть единственным на машине 
// и использоваться всеми
// по сути ОС представляет собой набор типовых наиболее часто используемых программами функций, 
// собранных в динамические библиотеки: функции для работы с файлами, с сетью, с устройствами, 
// функции безопасности, менеджмент процессов и т.д. 
// прикладные приложения, работая на ОС, не нуждаются в собственном коде для таких тривиальных операций 
// преимущества 1) снижение размера приложений 2) унификация 3) безопасность (варианты взаимодействия 
// приложений с системными ресурсами: файлами, аппаратурой ограничены типовым и безопасным набором 
// системных функций) 

// огромное количество сторонних, в т.ч. и открытых бесплатных библиотек собирается и подключается 
// именно в виде lib или dll (PoDoFo - для работы и криптографической подписи PDF, множество эталонных 
// библиотек libjpeg, libpng для работы со сжатием изображений, криптографические библиотеки OpenSSL, OpenSSH)


extern int fnc1(double p1, char p2); // прототип функции, с помощью которго линковщик (компоновщик) 
									 // не находит саму функцию в подключенном *.lib 


									 // неявное связывание: dll грузятся в ОП при запуске exe 
									 // в случае динамического связывания к exe всё равно подключается lib, но этот lib содержит не 
									 // реализации самих функций, а только таблицу адресов, где их искать в dll 
extern "C" __declspec(dllimport) int fnc2(double p1, char p2); // по этому объявлению компоновщик ищет

#include <iostream>

using namespace std;



int main()
{

	cout << "FROM LIB:\tfnc1(10, 5) = " << fnc1(10, 5) << endl;
	cout << "FROM imlicit DLL:\tfnc2(10, 5) = " << fnc2(10, 5) << endl;

	getchar();
	return 0;
}


// exam171341Golovchenko.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Exam_string.h"

using namespace std; 

int main()
{
	Exam_string str1; 

	while (1)
	{
		for (int i = 0; i < 10000; i++)
		{
			
			str1.add('a');


			str1.print();

			cout << endl;

			str1.clear();
		}
	}

	// str1.add('m'); 
	// str1.print();

	// str1.add('n'); 
	// str1.print(); 

//	str1.cut(2, g); 
//	str1.print(); 

	getchar(); 

    return 0;
}


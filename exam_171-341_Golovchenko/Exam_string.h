#pragma once
class Exam_string
{
public:

	Exam_string(); // вызов конструктора 
	Exam_string(const Exam_string& other);
	~Exam_string(); // вызов деструктора 

	char get(int i); // метод 
	char set(); // метод 

private:

	int a; // используемая длина строки 
	int max; // полный размер строки (использумый + пустота) 
	char *st; // строка (передана как динамический массив) 
	char *new_st; // обновленная строка строка (передана как динамический массив) 
};


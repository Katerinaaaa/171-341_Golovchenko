#pragma once
class Exam_string
{
public:
	Exam_string();
	~Exam_string();

private:
	int a; // используемая длина строки 
	int max; // полный размер строки (использумый + пустота) 
	char *st; // строка (передана как динамический массив) 
	char *new_st; // обновленная строка строка (передана как динамический массив) 
};


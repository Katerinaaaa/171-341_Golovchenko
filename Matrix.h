#pragma once
class Matrix
{

public:

	void set_size(int n, int m); // ������� ������� ������� 

	int get (int i, int j); // ������ �������� �� ������� [i, j]

	void set(int i, int j, int value); // ������ �������� �� ������� [i, j]

	void print (); // ����� ������� �� ����� 

	int num_rows(); // ���������� ����� 

	int num_cols(); // ���������� �������� 
	
	void matrix_mult(int **matrix_result, int **matrix1, int **matrix2, int t1, int p1, int t2, int p2); // ������������ ������ 

	void matrix_matrix(int **result, int **matrix1, int **matrix2, int n1, int m1, int n2, int m2); // �������� ������ 



	Matrix();
	Matrix(int n, int m); 
	virtual ~Matrix();

private:

	int m; // ���������� �������� 

	int n; // ���������� ����� 

	int *data; // ������ 

};


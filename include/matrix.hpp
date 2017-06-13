#include <fstream>
#include <iostream>

using namespace std;

class Matrix {

private:
	int row, col, **mas;
public:
	Matrix(int length = 4);
	Matrix(int, int);
	Matrix(const Matrix&);
	
        int Element(int i, int j);
	~Matrix();
	void fill(const char*);
	void show() const;
	int rows();
	int columns();
	Matrix operator+(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	bool operator==(const Matrix&) const;
	Matrix operator=(const Matrix& x) const;
};

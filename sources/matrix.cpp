#include "matrix.hpp"

Matrix::Matrix(int length) {
	row = length;
	col = length;

	mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
		for (int j = 0; j < col; j++) {
			mas[i][j] = 0;
		}
	}
}

Matrix::Matrix(int r, int c) {
	row = r;
	col = c;

	mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
		for (int j = 0; j < col; j++) {
			mas[i][j] = 0;
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < row; i++) {
		delete[] mas[i];
	}

	delete[] mas;
}

Matrix::Matrix(const Matrix&a) {
	row = a.row;
	col = a.col;

	mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
		for (int j = 0; j < col; j++) {
			mas[i][j] = a.mas[i][j];
		}
	}
}

void Matrix::fill( const char*file) {
	ifstream fin1(file);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fin1 >> mas[i][j];
		}
	}
}

void Matrix::show() const {
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

Matrix Matrix::operator+(const Matrix& a) const {

	Matrix help(row, col);


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			help.mas[i][j] = mas[i][j] + a.mas[i][j];
		}
	}
	return help;
}

Matrix Matrix::operator*(const Matrix& a) const {

	Matrix help(row, col);


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			help.mas[i][j] = 0;
			for (int k = 0; k < col; k++) {
				help.mas[i][j] += mas[i][k] * a.mas[k][j];
			}
		}
	}
	return help;
}

int Matrix::rows() {
	return row;
}

int Matrix::columns() {
	return col;
}

int Matrix::Element(int i, int j)
        {
            if (i<row && j<col)
                return mas[i][j];
            else
                cout << "Error: 1";
        }

bool Matrix::operator==(const Matrix& m) const
{
	if (row != m.row || col != m.col)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
		
				if (mas[i][j] != m.mas[i][j])
				{
					return false;
				}
			}
		}
	}
	return true;
}

Matrix Matrix::operator=(const Matrix& a) const
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mas[i][j] = a.mas[i][j];
		}
	}
	return *this;
}


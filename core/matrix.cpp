#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "matrix.h"

template<typename T>
void Matrix<T>::allocSpace()
{
	this->matrix = new T*[rows_];
	for (unsigned i = 0; i < rows_; ++i) {
		this->matrix[i] = new T[cols_];
	}
}

template<typename T>
Matrix<T>::Matrix(unsigned rows, unsigned cols) : rows_(rows), cols_(cols)
{
	Matrix<T>::allocSpace();
	for (unsigned i = 0; i < rows_; ++i) {
		for (unsigned j = 0; j < cols_; ++j) {
			this->matrix[i][j] = default(T);
		}
	}
}

template<typename T>
Matrix<T>::Matrix() : rows_(1), cols_(1)
{
	allocSpace();
	p[0][0] = default(T);
}

template<typename T>
Matrix<T>::~Matrix()
{
	for (unsigned i = 0; i < rows_; ++i) {
		delete[] this->matrix[i];
	}
	delete[] this->matrix;
}

template<typename T>
void CopyValues(const Matrix<T> & matrix)
{
	for (unsigned i = 0; i < rows_; ++i) {
		for (unsigned j = 0; j < cols_; ++j) {
			this->matrix[i][j] = matrix.matrix[i][j];
		}
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix) : rows_(matrix.rows_), cols_(matrix.cols_)
{
	Matrix<T>::allocSpace();
	CopyValues(matrix);
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix)
{
	if (this == &matrix) {
		return *this;
	}

	if (this->rows_ != matrix.rows_ || this->cols_ != matrix.cols_) {
		this->~Matrix();

		this->rows_ = matrix.rows_;
		this->cols_ = matrix.cols_;
		allocSpace();
	}

	this->CopyValues(matrix);

	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& matrix)
{
	for (unsigned i = 0; i < this->rows_; ++i) {
		for (unsigned j = 0; i < this->cols_; ++j) {
			this->matrix[i][j] += matrix.matrix[i][j]
		}
	}

	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>&)
{
	for (unsigned i = 0; i < this->rows_; ++i) {
		for (unsigned j = 0; i < this->cols_; ++j) {
			this->matrix[i][j] -= matrix.matrix[i][j]
		}
	}

	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>&)
{
	// TODO: insert return statement here
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(T)
{
	// TODO: insert return statement here
}

template<typename T>
Matrix<T>& Matrix<T>::operator/=(T)
{
	// TODO: insert return statement here
}

template<typename T>
Matrix<T> Matrix<T>::operator^(int)
{
	return Matrix<T>();
}


template<typename T>
std::ostream & operator<<(std::ostream &, const Matrix<T>&)
{
	// TODO: insert return statement here
}

template<typename T>
std::istream & operator>>(std::istream &, Matrix<T>&)
{
	// TODO: insert return statement here
}

template<typename T>
Matrix<T> operator+(const Matrix<T>&, const Matrix<T>&)
{
	return Matrix<T>();
}

template<typename T>
Matrix<T> operator-(const Matrix<T>&, const Matrix<T>&)
{
	return Matrix<T>();
}

template<typename T>
Matrix<T> operator*(const Matrix<T>&, const Matrix<T>&)
{
	return Matrix<T>();
}

template<typename T>
Matrix<T> operator*(const Matrix<T>&, double)
{
	return Matrix<T>();
}

template<typename T>
Matrix<T> operator*(T, const Matrix<T>&)
{
	return Matrix<T>();
}

template<typename T>
Matrix<T> operator/(const Matrix<T>&, T)
{
	return Matrix<T>();
}

#endif
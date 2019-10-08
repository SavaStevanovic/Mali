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
void Matrix<T>::CopyValues(const Matrix<T> & matrix)
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
		for (unsigned i = 0; i < rows_; ++i) {
			delete[] this->matrix[i];
		}
		delete[] this->matrix;

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
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& matrix)
{
	Matrix<T> temp(this->rows_, matrix.cols_);
	for (unsigned i = 0; i < temp.rows_; ++i) {
		for (unsigned j = 0; j < temp.cols_; ++j) {
			for (unsigned k = 0; k < this->cols_; ++k) {
				temp.matrix[i][j] += this->matrix[i][k] * matrix.matrix[k][j];
			}
		}
	}
	return (*this = temp);
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(T multiplier)
{
	for (int i = 0; i < this->rows_; ++i) {
		for (int j = 0; j < this->cols_; ++j) {
			this->matrix[i][j] *= multiplier;
		}
	}
	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator/=(T devider)
{
	for (int i = 0; i < this->rows_; ++i) {
		for (int j = 0; j < this->cols_; ++j) {
			this->matrix[i][j] /= devider;
		}
	}
	return *this;
}

template<typename T>
std::ostream & operator<<(std::ostream &, const Matrix<T>& matrix)
{
	for (int i = 0; i < matrix.rows_; ++i) {
		os << matrix.matrix[i][0];
		for (int j = 1; j < matrix.cols_; ++j) {
			os << " " << matrix.matrix[i][j];
		}
		os << endl;
	}
	return os;
}

template<typename T>
std::istream & operator>>(std::istream &, Matrix<T>& matrix)
{
	for (int i = 0; i < matrix.rows_; ++i) {
		for (int j = 0; j < matrix.cols_; ++j) {
			is >> matrix.matrix[i][j];
		}
	}
	return is;
}

template<typename T>
Matrix<T> operator+(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
{
	Matrix temp_matrix(matrix1);
	return (temp_matrix += matrix2);
}

template<typename T>
Matrix<T> operator-(const Matrix<T>&, const Matrix<T>&)
{
	Matrix temp_matrix(matrix1);
	return (temp_matrix -= matrix2);
}

template<typename T>
Matrix<T> operator*(const Matrix<T>&, const Matrix<T>&)
{
	Matrix temp_matrix(matrix1);
	return (temp_matrix *= matrix2);
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& matrix, T multiplier)
{
	Matrix temp_matrix(matrix);
	return (matrix *= multiplier);
}

template<typename T>
Matrix<T> operator*(T multiplier, const Matrix<T>& matrix)
{
	Matrix temp_matrix(matrix);
	return (temp_matrix *= multiplier);
}

template<typename T>
Matrix<T> operator/(const Matrix<T>&, T devider)
{
	Matrix temp_matrix(matrix);
	return (matrix /= devider);
}

#endif
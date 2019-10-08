#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

template <typename T>
class Matrix {

private:
	unsigned rows_, cols_;
	T **matrix;

	void allocSpace();

public:
	Matrix(unsigned, unsigned);
	Matrix();
	virtual ~Matrix();
	Matrix(const Matrix<T>&);
	Matrix& operator=(const Matrix<T>&);

	inline T& operator()(unsigned  x, unsigned  y) { return p[x][y]; }

	Matrix<T>& operator+=(const Matrix<T>&);
	Matrix<T>& operator-=(const Matrix<T>&);
	Matrix<T>& operator*=(const Matrix<T>&);
	Matrix<T>& operator*=(T);
	Matrix<T>& operator/=(T);

	friend std::ostream& operator<<(std::ostream&, const Matrix<T>&);
	void CopyValues(const Matrix<T> & matrix);
	friend std::istream& operator>>(std::istream&, Matrix<T>&);

};


template <typename T>
Matrix<T> operator+(const Matrix<T>&, const Matrix<T>&);
template <typename T>
Matrix<T> operator-(const Matrix<T>&, const Matrix<T>&);
template <typename T>
Matrix<T> operator*(const Matrix<T>&, const Matrix<T>&);
template <typename T>
Matrix<T> operator*(const Matrix<T>&, T);
template <typename T>
Matrix<T> operator*(T, const Matrix<T>&);
template <typename T>
Matrix<T> operator/(const Matrix<T>&, T);

#endif
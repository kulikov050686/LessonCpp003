#pragma once
#include "Matrix.h"
#include <exception>

namespace MyMatrix
{
	class MatrixOperations
	{
	public:

		/// Печать матрицы
		static void Print(const Matrix& matrix);

		/// Умножение матрицы на число
		static Matrix MultByNumber(const double number, const Matrix& matrix);

		/// Сложение матриц
		static Matrix Addition(const Matrix& matrix1, const Matrix& matrix2);

		/// Вычитание матриц
		static Matrix Subtraction(const Matrix& matrix1, const Matrix& matrix2);
	};
}

#pragma once
#include "Matrix.h"

namespace MyMatrix
{
	class MatrixController
	{
	private:

		/// Первая матрица
		Matrix* matrix_1;

		/// Вторая матрица
		Matrix* matrix_2;
	public:

		/// Конструктор контроллера
		MatrixController();

		/// Деструктор контроллера
		~MatrixController();
	};
}




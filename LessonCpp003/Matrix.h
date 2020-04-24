#pragma once
#include <iostream>
#include <exception>
#include <random>

namespace MyMatrix
{
	class Matrix
	{
	private:

		/// Число столбцов матрицы
		int columns = 0;

		/// Число строк матрицы
		int rows = 0;

		/// Матрица
		double* vector = nullptr;

		/// Инициализация матрицы
		void InitMatrix();

		/// Генератор случайных чисел [min; max)
		int Random(int min, int max);

	public:

		/// Конструктор матрицы
		Matrix(int _rows, int _columns);

		/// Конструктор копирования матрицы
		Matrix(const Matrix& object);

		/// Проверяет является ли матрица квадратной
		bool IsSquare();

		/// Получить количество колонок матрицы
		int GetColumns();

		/// Получить количество строк матрицы
		int GetRows();

		/// Получить данные по номеру элемента матрицы
		double GetItem(int rowNumber, int columnNumber);

		/// Задать данные по номеру элемента матрицы
		void SetItem(int rowNumber, int columnNumber, double data);

		/// Заполняет матрицу произвольными целыми числами [min; max)
		void Create(int min, int max);

		/// Транспонирование матрицы
		void Transpose();

		/// Перегрузка оператора присваивания
		Matrix& operator = (const Matrix& object);

		/// Перегрузка оператора сравнения
		friend bool operator == (const Matrix& matrix1, const Matrix& matrix2);

		/// Перегрузка оператора сравнения
		friend bool operator != (const Matrix& matrix1, const Matrix& matrix2);

		/// Диструктор матрицы
		~Matrix();
	};
}

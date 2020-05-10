#include "Matrix.h"

namespace MyMatrix
{
	void Matrix::InitMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				vector[columns * i + j] = 0;
			}
		}
	}

	int Matrix::Random(int min, int max)
	{
		std::random_device rd;
		std::mt19937 mersenne(rd());

		return min + mersenne() % (max - min);
	}

	Matrix::Matrix(int _rows, int _columns)
	{
		if (_rows >= 1 && _columns >= 1)
		{
			columns = _columns;
			rows = _rows;

			vector = new double[rows * columns];
			InitMatrix();
		}
		else
		{
			throw std::exception("Error!");
		}
	}

	Matrix::Matrix(const Matrix& object)
	{
		if (vector != nullptr)
		{
			delete[] vector;
		}

		this->columns = object.columns;
		this->rows = object.rows;

		this->vector = new double[object.columns * object.rows];

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				this->vector[columns * i + j] = object.vector[columns * i + j];
			}
		}
	}

	bool Matrix::IsSquare()
	{
		return (columns == rows) ? true : false;
	}

	int Matrix::GetColumns()
	{
		return columns;
	}

	int Matrix::GetRows()
	{
		return rows;
	}

	double Matrix::GetItem(int rowNumber, int columnNumber)
	{
		if (0 <= rowNumber && rowNumber < rows && 0 <= columnNumber && columnNumber < columns)
		{
			return vector[columns * rowNumber + columnNumber];
		}

		throw std::exception("Error!");
	}

	void Matrix::SetItem(int rowNumber, int columnNumber, double data)
	{
		if (0 <= rowNumber && rowNumber < rows && 0 <= columnNumber && columnNumber < columns)
		{
			vector[columns * rowNumber + columnNumber] = data;
		}
		else
		{
			throw std::exception("Error!");
		}
	}

	void Matrix::Create(int min, int max)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				vector[columns * i + j] = Random(min, max);
			}
		}
	}

	void Matrix::Transpose()
	{
		double* temp = new double[columns * rows];

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				temp[columns * i + j] = vector[columns * i + j];
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				vector[rows * j + i] = temp[columns * i + j];
			}
		}

		std::swap(rows, columns);

		delete[] temp;
	}

	Matrix& Matrix::operator = (const Matrix& object)
	{
		if (this == &object)
		{
			return *this;
		}

		if (vector != nullptr)
		{
			delete[] vector;
		}

		this->columns = object.columns;
		this->rows = object.rows;		
		this->vector = new double[object.columns * object.rows];

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				this->vector[columns * i + j] = object.vector[columns * i + j];
			}
		}

		return *this;
	}
	
	Matrix::~Matrix()
	{
		delete[] vector;
	}

	bool operator == (const Matrix& matrix1, const Matrix& matrix2)
	{		
		return (matrix1.columns == matrix2.columns) && (matrix1.rows == matrix2.rows);
	}

	bool operator != (const Matrix& matrix1, const Matrix& matrix2)
	{
		return !(matrix1 == matrix2);
	}
}

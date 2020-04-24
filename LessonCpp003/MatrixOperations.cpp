#include "MatrixOperations.h"

namespace MyMatrix
{
	void MatrixOperations::Print(const Matrix& matrix)
	{
		Matrix temp = matrix;

		for (int i = 0; i < temp.GetRows(); i++)
		{
			for (int j = 0; j < temp.GetColumns(); j++)
			{
				std::cout << temp.GetItem(i, j) << " ";
			}

			std::cout << std::endl;
		}
	}

	Matrix MatrixOperations::MultByNumber(const double number, const Matrix& matrix)
	{
		double k = 0;
		Matrix temp = matrix;

		for (int i = 0; i < temp.GetRows(); i++)
		{
			for (int j = 0; j < temp.GetColumns(); j++)
			{
				k = number * temp.GetItem(i, j);
				temp.SetItem(i, j, k);
			}
		}

		return temp;
	}

	Matrix MatrixOperations::Addition(const Matrix& matrix1, const Matrix& matrix2)
	{
		Matrix temp1 = matrix1;
		Matrix temp2 = matrix2;

		if (temp1 == temp2)
		{
			Matrix addition(temp1.GetRows(), temp1.GetColumns());
			double data = 0;

			for (int i = 0; i < temp1.GetRows(); i++)
			{
				for (int j = 0; j < temp1.GetColumns(); j++)
				{
					data = temp1.GetItem(i, j) + temp2.GetItem(i, j);
					addition.SetItem(i, j, data);
				}
			}

			return addition;
		}

		throw std::exception("Error!");			
	}

	Matrix MatrixOperations::Subtraction(const Matrix& matrix1, const Matrix& matrix2)
	{
		Matrix temp1 = matrix1;
		Matrix temp2 = matrix2;

		if (temp1 == temp2)
		{
			Matrix addition(temp1.GetRows(), temp1.GetColumns());
			double data = 0;

			for (int i = 0; i < temp1.GetRows(); i++)
			{
				for (int j = 0; j < temp1.GetColumns(); j++)
				{
					data = temp1.GetItem(i, j) - temp2.GetItem(i, j);
					addition.SetItem(i, j, data);
				}
			}

			return addition;
		}

		throw std::exception("Error!");
	}
}

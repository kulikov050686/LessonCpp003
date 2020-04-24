#include <iostream>
#include "Matrix.h"
#include "MatrixOperations.h"

int main()
{
    MyMatrix::Matrix matrix1(4, 4);
    MyMatrix::Matrix matrix2(4, 4);
      

    matrix1.Create(10, 100);
    matrix2.Create(20, 30);

    MyMatrix::MatrixOperations::Print(matrix1);

    std::cout << std::endl;

    MyMatrix::MatrixOperations::Print(matrix2);

    std::cout << std::endl;

    if (matrix1 == matrix2)
    {
        MyMatrix::MatrixOperations::Print(MyMatrix::MatrixOperations::Addition(matrix1, matrix2));

        std::cout << std::endl;

        MyMatrix::MatrixOperations::Print(MyMatrix::MatrixOperations::Subtraction(matrix1, matrix2));
    }
    else
    {
        std::cout << "Not Еquality!!!" << std::endl;
    }
}

#include <iostream>

using namespace std;

// Функция для сложения двух матриц
int** addMatrices(int** matrix1, int** matrix2, int rows, int cols) 
{
    int** result = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        result[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Функция для умножения двух матриц
int** multiplyMatrices(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) 
{
    if (cols1 != rows2) 
    {
        cout << "Матрицы не могут быть перемножены" << endl;
        return nullptr;
    }

    int** result = new int* [rows1];
    for (int i = 0; i < rows1; i++) 
    {
        result[i] = new int[cols2];
    }

    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < cols2; j++) 
        {
            for (int k = 0; k < cols1; k++) 
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Функция для нахождения определителя квадратной матрицы
int determinant(int** matrix, int n) 
{
    if (n == 1) 
    {
        return matrix[0][0];
    }

    int det = 0;

    for (int j = 0; j < n; j++) 
    {
        int** subMatrix = new int* [n];
        for (int i = 0; i < n; i++) 
        {
            subMatrix[i] = new int[n];
        }
        for (int i = 1; i < n; i++) {
            int k = 0;
            for (int l = 0; l < n; l++) 
            {
                if (l != j) {
                    subMatrix[i - 1][k] = matrix[i][l];
                    k++;
                }
            }
        }
        det += (j % 2 == 0 ? 1 : -1) * matrix[0][j] * determinant(subMatrix, n - 1);
    }

    return det;
}

// Функция для транспонирования матрицы
int** transposeMatrix(int** matrix, int rows, int cols) 
{
    int** result = new int* [cols];
    for (int i = 0; i < cols; i++) 
    {
        result[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}
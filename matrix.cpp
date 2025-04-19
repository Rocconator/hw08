#include <iostream>
#include <string>
using namespace std;

#define MAX_ARRAY_SIZE 5

class MatrixFunctions {
public: 
    MatrixFunctions() {}

    void addMatrix(int leftMatrix[][MAX_ARRAY_SIZE], int rightMatrix[][MAX_ARRAY_SIZE], int row, int col, int result[][MAX_ARRAY_SIZE]) {
        zeroMatrix(result, MAX_ARRAY_SIZE, MAX_ARRAY_SIZE);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result[i][j] = leftMatrix[i][j] + rightMatrix[i][j];
            }
        }
    }

    void printMatrix(int matrix[][MAX_ARRAY_SIZE], int row, int col) {
        for (int i = 0; i < row; i++) {
            cout << "[";
            for (int j = 0; j < col; j++) {
                if (j == col - 1) {
                    cout << matrix[i][j];
                }
                else {
                    cout << matrix[i][j] << " ";
                }
            }
            cout << "]\n";
        }
    }

    void zeroMatrix (int matrix[][MAX_ARRAY_SIZE], int row, int col) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    void multiplyMatrix (int leftMatrix[][MAX_ARRAY_SIZE], int leftRow, int leftCol, int rightMatrix[][MAX_ARRAY_SIZE], int rightRow, int rightCol, int result[][MAX_ARRAY_SIZE]) {
        for (int i = 0; i < leftRow; i++) {
            for (int j = 0; j < rightCol; j++) {
                for (int k = 0; k < leftCol; k++) {
                    result[i][j] += leftMatrix[i][k] * rightMatrix[k][j];
                }
            }
        }
    }

    void scaleMatrix (int matrix[][MAX_ARRAY_SIZE], int row, int col, int scalar) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = scalar * matrix[i][j];
            }
        }
    }

    void transposeMatrix(int matrix[][MAX_ARRAY_SIZE], int row, int col, int result[][MAX_ARRAY_SIZE]) {

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        zeroMatrix(matrix, row, col);
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                matrix[i][j] = result[i][j];
            }
        }
    }
    
};

int main() {
    int firstRow = 2;
    int firstCol = 2;
    int secondRow = 2;
    int secondCol = 3;
    int thirdRow = 2;
    int thirdCol = 3;

    int matrixA[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {{6, 4}, {8, 3}};
    int matrixB[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {{1, 2, 3}, {4, 5, 6}};
    int matrixC[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {{2, 4, 6}, {1, 3, 5}};
    int result[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    int finalAnswer[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    
    MatrixFunctions test = MatrixFunctions();
    test.zeroMatrix(result, MAX_ARRAY_SIZE, MAX_ARRAY_SIZE);
    /*
    test.transposeMatrix(matrixC, thirdRow, thirdCol, result);
    
    for (int i = 0; i < thirdCol; i++) {
        cout << "[";
        for (int j = 0; j < thirdRow; j++) {
            if (j == thirdRow - 1) {
                cout << result[i][j];
            }
            else {
                cout << result[i][j] << " ";
            }
        }
        cout << "]\n";
    }
    */
   /*
    test.scaleMatrix(matrixB, secondRow, secondCol, 3, result);
    for (int i = 0; i < secondRow; i++) {
        cout << "[";
        for (int j = 0; j < secondCol; j++) {
            if (j == secondCol - 1) {
                cout << result[i][j];
            }
            else {
                cout << result[i][j] << " ";
            }
        }
        cout << "]\n";
    }
    */
    cout << "MATRIX A: \n";
    test.printMatrix(matrixA, firstRow, firstCol);
    cout << "MATRIX B: \n";
    test.printMatrix(matrixB, secondRow, secondCol);
    cout << "MATRIX C: \n";
    test.printMatrix(matrixC, thirdRow, thirdCol);
    test.zeroMatrix(result, MAX_ARRAY_SIZE, MAX_ARRAY_SIZE);
    test.scaleMatrix(matrixB, secondRow, secondCol, 3);
    cout << "SCALED MATRIX B: \n";
    test.printMatrix(matrixB, secondRow, secondCol);
    test.transposeMatrix(matrixC, thirdRow, thirdCol, result);
    test.zeroMatrix(result, MAX_ARRAY_SIZE, MAX_ARRAY_SIZE);
    int newThirdRow = thirdCol; 
    int newThirdCol = thirdRow;
    cout << "TRANSPOSED MATRIX C: \n";
    test.printMatrix(matrixC, newThirdRow, newThirdCol);
    test.multiplyMatrix(matrixB, secondRow, secondCol, matrixC, newThirdRow, newThirdCol, result);
    cout << "MULTIPLIED MATRICES (3B x C^T): \n";
    test.printMatrix(result, secondRow, newThirdCol);
    test.addMatrix(matrixA, result, firstRow, firstCol, finalAnswer);
    cout << "FINAL ANSWER (A + 3B x C^T): \n";
    test.printMatrix(finalAnswer, firstRow, firstCol);

}
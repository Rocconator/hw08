#include <iostream>
#include <string>
using namespace std;

#define MAX_ARRAY_SIZE 5

class MatrixFunctions {
public: 
    MatrixFunctions() {}

    void addMatrix(int leftMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int rightMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col, int result[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE]) {
        zeroMatrix(result, MAX_ARRAY_SIZE, MAX_ARRAY_SIZE);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result[i][j] = leftMatrix[i][j] + rightMatrix[i][j];
            }
        }
        zeroMatrix(leftMatrix, row, col);
        zeroMatrix(rightMatrix, row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                leftMatrix[i][j] = result[i][j];
            }
        }

        zeroMatrix(result, row, col);
    }

    void printMatrix(int matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col) {
        if (row == 0 && col == 0) {
            cout << "\t[]\n";
            return;
        }
        for (int i = 0; i < row; i++) {
            cout << "\t[";
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

    void printMatrices(int matrixA[][MAX_ARRAY_SIZE], int firstRow, int firstCol, int matrixB[][MAX_ARRAY_SIZE], int secondRow, int secondCol, int matrixC[][MAX_ARRAY_SIZE], int thirdRow, int thirdCol) {
        cout << "Matrix A:\n";
        printMatrix(matrixA, firstRow, firstCol);
        cout << "Matrix B:\n";
        printMatrix(matrixB, secondRow, secondCol);
        cout << "Matrix C:\n";
        printMatrix(matrixC, thirdRow, thirdCol);
    }
    void zeroMatrix(int matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    void multiplyMatrix(int leftMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int leftRow, int leftCol, int rightMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int rightRow, int rightCol, int result[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE]) {
        for (int i = 0; i < leftRow; i++) {
            for (int j = 0; j < rightCol; j++) {
                for (int k = 0; k < leftCol; k++) {
                    result[i][j] += leftMatrix[i][k] * rightMatrix[k][j];
                }
            }
        }
        zeroMatrix(leftMatrix, leftRow, leftCol);
        zeroMatrix(rightMatrix, rightRow, rightCol);

        for (int i = 0; i < leftRow; i++) {
            for (int j = 0; j < rightCol; j++) {
                leftMatrix[i][j] = result[i][j];
            }
        }
        zeroMatrix(result, MAX_ARRAY_SIZE, MAX_ARRAY_SIZE);
    }

    void scaleMatrix(int matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col, int scalar) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = scalar * matrix[i][j];
            }
        }
    }

    void transposeMatrix(int matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col, int result[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE]) {

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
        zeroMatrix(result, MAX_ARRAY_SIZE, MAX_ARRAY_SIZE);
    }
};

int main() {
    /*
    int firstRow = 2;
    int firstCol = 2;
    int secondRow = 2;
    int secondCol = 3;
    int thirdRow = 2;
    int thirdCol = 3;
    */
    int firstRow = 0;
    int firstCol = 0;
    int secondRow = 0;
    int secondCol = 0;
    int thirdRow = 0;
    int thirdCol = 0;
    
    int matrixA[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    int matrixB[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    int matrixC[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

    do {
        cout << "Enter the dimensions for your first matrix (at max 5x5) in this format: (row col) ";
        cin >> firstRow >> firstCol;
        if (firstRow > MAX_ARRAY_SIZE || firstCol > MAX_ARRAY_SIZE) {
            cout << "Error: Dimensions outside of bounds, please try again.\n";
        }
        cin.clear();
        cin.ignore(10000, '\n');
    } while (firstRow > MAX_ARRAY_SIZE || firstCol > MAX_ARRAY_SIZE);
    
    //cout << "\nFirst row: " << firstRow << " - First Col: " << firstCol << "\n";
    
    do {
        cout << "Enter the dimensions for your second matrix (at max 5x5) in this format: (row col) ";
        cin >> secondRow >> secondCol;
        if (secondRow > MAX_ARRAY_SIZE || secondCol > MAX_ARRAY_SIZE) {
            cout << "Error: Dimensions outside of bounds, please try again.\n";
        }
        cin.clear();
        cin.ignore(10000, '\n');
    } while (secondRow > MAX_ARRAY_SIZE || secondCol > MAX_ARRAY_SIZE);
    
    //cout << "\nSecond row: " << secondRow << " - Second Col: " << secondCol << "\n";
    
    do {
        cout << "Enter the dimensions for your third matrix (at max 5x5) in this format: (row col) ";
        cin >> thirdRow >> thirdCol;
        if (thirdRow > MAX_ARRAY_SIZE || thirdCol > MAX_ARRAY_SIZE) {
            cout << "Error: Dimensions outside of bounds, please try again.\n";
        }
        cin.clear();
        cin.ignore(10000, '\n');
    } while (thirdRow > MAX_ARRAY_SIZE || thirdCol > MAX_ARRAY_SIZE);
    
    //cout << "\nThird row: " << thirdRow << " - Third Col: " << thirdCol << "\n";
    
    cout << "Enter the elements of your first matrix row by row in this format: (a1 a2 a3)\n";
    for (int i = 0; i < firstRow; i++) {
        for (int j = 0; j < firstCol; j++) {
            cin >> matrixA[i][j];
        }
    } 
    
    cout << "Enter the elements of your second matrix row by row in this format: (b1 b2 b3)\n";
    for (int i = 0; i < secondRow; i++) {
        for (int j = 0; j < secondCol; j++) {
            cin >> matrixB[i][j];
        }
    }
    
    cout << "Enter the elements of your third matrix row by row in this format: (c1 c2 c3)\n";
    for (int i = 0; i < thirdRow; i++) {
        for (int j = 0; j < thirdCol; j++) {
            cin >> matrixC[i][j];
        }
    }
    /*
    int matrixA[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {{6, 4}, {8, 3}};
    int matrixB[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {{1, 2, 3}, {4, 5, 6}};
    int matrixC[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {{2, 4, 6}, {1, 3, 5}};
    */    

    int result[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

    MatrixFunctions test = MatrixFunctions();
    //test.initializeMatrices(matrixA, firstRow, firstCol, matrixB, secondRow, secondCol, matrixC, thirdRow, thirdCol);

    bool running = true;
    while (running) {
        int num = 0;
        cout << "Select an option from the menu: \n";
        cout << "1. Add Matrices\n2. Scale Matrix\n3. Transpose Matrix\n4. Multiply Matrices\n5. Print Matrices\n6. Exit\n";
        cin >> num;
        if (num < 1 || num > 6) {
            cout << "Please select a valid option and try again.\n";
        }
        else {
            switch (num) {
                char first;
                char second;
                case 1:
                    cout << "What matrices would you like to add? Use capital letters A, B, or C to designate each matrix (A C)\n";
                    cin >> first >> second;
                    while ((first < 65 || first > 67) || (second < 65 || second > 67)) {
                        cout << "One of your choices was invalid, please try again.\n";
                        cin >> first >> second;
                    }
                    
                    if ((first == 'A' && second == 'B') || (first == 'B' && second == 'A')) {
                        test.addMatrix(matrixA, matrixB, firstRow, firstCol, result);
                        cout << "The result has been put into Matrix A.\n";
                        secondRow = 0;
                        secondCol = 0;
                    }
                    else if ((first == 'B' && second == 'C') || (first == 'C' && second == 'B')) {
                        test.addMatrix(matrixB, matrixC, secondRow, secondCol, result);
                        cout << "The result has been put into Matrix B.\n";
                        thirdRow = 0;
                        thirdCol = 0;
                    }
                    else if ((first == 'A' && second == 'C') || (first == 'C' && second == 'A')) {
                        test.addMatrix(matrixA, matrixC, firstRow, firstCol, result);
                        cout << "The result has been put into matrix A.\n";
                        thirdRow = 0;
                        thirdCol = 0;
                    }
                    else {
                        cout << "An error has occurred in addMatrix (case 1)";
                        return 1;
                    }
                    break;
                case 2:
                    char scalarChoice;
                    int scalar;
                    cout << "Which matrix would you like to scale? Use capital letters A, B, or C to choose\n";
                    cin >> scalarChoice;
                    while (scalarChoice < 65 || scalarChoice > 67) {
                        cout << "Your choice was invalid, please try again.\n";
                        cin >> scalarChoice;
                    }
                    cout << "How much would you like to scale the matrix by? ";
                    cin >> scalar; 
                    if (scalarChoice == 'A') {
                        test.scaleMatrix(matrixA, firstRow, firstCol, scalar);
                        //test.printMatrix(matrixA, firstRow, firstCol);
                    }
                    else if (scalarChoice == 'B') {
                        test.scaleMatrix(matrixB, secondRow, secondCol, scalar);
                        //test.printMatrix(matrixB, secondRow, secondCol);
                    }
                    else if (scalarChoice == 'C') {
                        test.scaleMatrix(matrixC, thirdRow, thirdCol, scalar);
                        //test.printMatrix(matrixC, thirdRow, thirdCol);
                    }
                    else {
                        cout << "An error has occurred in scaleMatrix (case 2)";
                        return 2;
                    }
                    break;
                case 3:
                    char transposeChoice;
                    cout << "Which matrix would you like to transpose? Use capital letters to choose\n";
                    cin >> transposeChoice;
                    while (transposeChoice < 65 || transposeChoice > 67) {
                        cout << "Your choice was invalid, please try again.\n";
                    }
                    if (transposeChoice == 'A') {
                        test.transposeMatrix(matrixA, firstRow, firstCol, result);
                        int temp = 0;
                        temp = firstRow;
                        firstRow = firstCol;
                        firstCol = temp;
                        //test.printMatrix(matrixA, firstRow, firstCol);
                    }
                    else if (transposeChoice == 'B') {
                        test.transposeMatrix(matrixB, secondRow, secondCol, result);
                        int temp = 0;
                        temp = secondRow;
                        secondRow = secondCol;
                        secondCol = temp;
                        //test.printMatrix(matrixB, secondRow, secondCol);
                    }
                    else if (transposeChoice == 'C') {
                        test.transposeMatrix(matrixC, thirdRow, thirdCol, result);
                        int temp = 0;
                        temp = thirdRow;
                        thirdRow = thirdCol;
                        thirdCol = temp;
                        //test.printMatrix(matrixC, thirdRow, thirdCol);
                    }
                    else {
                        cout << "An error has occurred in transposeMatrix (case 3)";
                        return 3;
                    }
                    break;
                case 4:
                    char multFirst;
                    char multSecond;
                    cout << "Which matrices would you like to multiply? Use capital letters to designate which each matrix (A C)\n";
                    cin >> multFirst >> multSecond;
                    while ((multFirst < 65 || multFirst > 67) || (multSecond < 65 || multSecond > 67)) {
                        cout << "One of your choices was invalid, please try again.\n";
                        cin >> multFirst >> multSecond;
                    }

                    if (multFirst == 'A' && multSecond == 'B') {
                        test.multiplyMatrix(matrixA, firstRow, firstCol, matrixB, secondRow, secondCol, result);
                        cout << "The result has been put into Matrix A.\n";
                        secondRow = 0;
                        firstCol = secondCol;
                        secondCol = 0;
                    }
                    else if (multFirst == 'B' && multSecond == 'A') {
                        test.multiplyMatrix(matrixB, secondRow, secondCol, matrixA, firstRow, firstCol, result);
                        cout << "The result has been put into Matrix B.\n";
                        firstRow = 0;
                        secondCol = firstCol;
                        firstCol = 0;
                    }
                    else if (multFirst == 'B' && multSecond == 'C') {
                        test.multiplyMatrix(matrixB, secondRow, secondCol, matrixC, thirdCol, thirdRow, result);
                        cout << "The result has been put into Matrix B.\n";
                        thirdRow = 0;
                        secondCol = thirdCol;
                        thirdCol = 0;
                    }
                    else if (multFirst == 'C' && multSecond == 'B') {
                        test.multiplyMatrix(matrixC, thirdRow, thirdCol, matrixB, secondRow, secondCol, result);
                        cout << "The result has been put into Matrix C.\n";
                        secondRow = 0;
                        thirdCol = secondCol;
                        secondCol = 0;
                    }
                    else if (multFirst == 'A' && multSecond == 'C') {
                        test.multiplyMatrix(matrixA, firstRow, firstCol, matrixC, thirdRow, thirdCol, result);
                        cout << "The result has been put into Matrix A.\n";
                        thirdRow = 0;
                        firstCol = thirdCol;
                        thirdCol = 0;
                    }
                    else if (multFirst == 'C' && multSecond == 'A') {
                        test.multiplyMatrix(matrixC, thirdRow, thirdCol, matrixA, firstRow, firstCol, result);
                        cout << "The result has been put into Matrix C.\n";
                        firstRow = 0;
                        thirdCol = firstCol;
                        firstCol = 0;
                    }
                    else {
                        cout << "An error has occurred in multiplyMatrix (case 4)";
                        return 4;
                    }
                    break;
                case 5:
                    test.printMatrices(matrixA, firstRow, firstCol, matrixB, secondRow, secondCol, matrixC, thirdRow, thirdCol);
                    break;
                case 6:
                    running = false;
                    cout << "Thanks for using this program, these are the final states of each matrix:\n";
                    test.printMatrices(matrixA, firstRow, firstCol, matrixB, secondRow, secondCol, matrixC, thirdRow, thirdCol);
                    break;
                default: 
                    break;
            }

        }
    }
    return 0;
}
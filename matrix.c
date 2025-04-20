#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_SIZE 5
#define MAX_STR_LENGTH 50

void printMatrix(int matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col) {
    if (row == 0 && col == 0) {
        printf("[]\n");
        return;
    }
    for (int i = 0; i < row; i++) {
        printf("[");
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                printf("%d", matrix[i][j]);
            }
            else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("]\n");
    }
}

void printMatrices(int matrixA[][MAX_ARRAY_SIZE], int firstRow, int firstCol, int matrixB[][MAX_ARRAY_SIZE], int secondRow, int secondCol, int matrixC[][MAX_ARRAY_SIZE], int thirdRow, int thirdCol) {
    printf("Matrix A:\n");
    printMatrix(matrixA, firstRow, firstCol);
    printf("Matrix B:\n");
    printMatrix(matrixB, secondRow, secondCol);
    printf("Matrix C:\n");
    printMatrix(matrixC, thirdRow, thirdCol);
}

void zeroMatrix(int matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 0;
        }
    }
}

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

int main() {
    int firstRow = 0;
    int firstCol = 0;
    int secondRow = 0;
    int secondCol = 0;
    int thirdRow = 0;
    int thirdCol = 0;

    int matrixA[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    int matrixB[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    int matrixC[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    int result[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

    do {
        printf("Enter the dimensions for your first matrix (at max 5x5) in this format: (row col) ");
        scanf(" %d %d", &firstRow, &firstCol);
        if (firstRow > MAX_ARRAY_SIZE || firstCol > MAX_ARRAY_SIZE) {
            printf("Error: Dimensions outside of bounds, please try again.\n");
        }
    } while (firstRow > MAX_ARRAY_SIZE || firstCol > MAX_ARRAY_SIZE);
    
    //printf("First row: %d - First Col: %d\n", firstRow, firstCol);
    
    do {
        printf("Enter the dimensions for your second matrix (at max 5x5) in this format: (row col) ");
        scanf(" %d %d", &secondRow, &secondCol);
        if (secondRow > MAX_ARRAY_SIZE || secondCol > MAX_ARRAY_SIZE) {
            printf("Error: Dimensions outside of bounds, please try again.\n");
        }
    } while (secondRow > MAX_ARRAY_SIZE || secondCol > MAX_ARRAY_SIZE);
    
    //printf("\nSecond row: %d - Second Col: %d\n", secondRow, secondCol);
    
    do {
        printf("Enter the dimensions for your third matrix (at max 5x5) in this format: (row col) ");
        scanf(" %d %d", &thirdRow, &thirdCol);
        if (thirdRow > MAX_ARRAY_SIZE || thirdCol > MAX_ARRAY_SIZE) {
            printf("Error: Dimensions outside of bounds, please try again.\n");
        }
    } while (thirdRow > MAX_ARRAY_SIZE || thirdCol > MAX_ARRAY_SIZE);
    
    printf("Enter the elements of your first matrix row by row in this format: (a1 a2 a3)\n");
    for (int i = 0; i < firstRow; i++) {
        for (int j = 0; j < firstCol; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    } 
    printf("Enter the elements of your second matrix row by row in this format: (b1 b2 b3)\n");
    for (int i = 0; i < secondRow; i++) {
        for (int j = 0; j < secondCol; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    printf("Enter the elements of your third matrix row by row in this format: (c1 c2 c3)\n");
    for (int i = 0; i < thirdRow; i++) {
        for (int j = 0; j < thirdCol; j++) {
            scanf("%d", &matrixC[i][j]);
        }
    }

    int running = 1;
    while (running) {
        int num = 0;
        printf("Select an option from the menu: \n");
        printf("1. Add Matrices\n2. Scale Matrix\n3. Transpose Matrix\n4. Multiply Matrices\n5. Print Matrices\n6. Exit\n");
        scanf(" %d", &num);
        if (num < 1 || num > 6) {
            printf("Please select a valid option and try again.\n");
        }
        else {
            switch (num) {
                case 1:
                    char first;
                    char second;

                    printf("What matrices would you like to add? Use capital letters A, B, or C to designate each matrix (A C)\n");
                    scanf(" %c %c", &first, &second);
                    printf("%c\n", first);
                    printf("%c\n", second);
                    
                    while (((int) first < 65 || (int) first > 67) || ((int) second < 65 || (int) second > 67)) {
                        printf("One of your choices was invalid, please try again.\n");
                        scanf(" %c %c", &first, &second);
                    }
                    
                    if ((first == 'A' && second == 'B') || (first == 'B' && second == 'A')) {
                        addMatrix(matrixA, matrixB, firstRow, firstCol, result);
                        printf("The result has been put into Matrix A.\n");
                        secondRow = 0;
                        secondCol = 0;
                    }
                    else if ((first == 'B' && second == 'C') || (first == 'C' && second == 'B')) {
                        addMatrix(matrixB, matrixC, secondRow, secondCol, result);
                        printf("The result has been put into Matrix B.\n");
                        thirdRow = 0;
                        thirdCol = 0;
                    }
                    else if ((first == 'A' && second == 'C') || (first == 'C' && second == 'A')) {
                        addMatrix(matrixA, matrixC, firstRow, firstCol, result);
                        printf("The result has been put into matrix A.\n");
                        thirdRow = 0;
                        thirdCol = 0;
                    }
                    else {
                        printf("An error has occurred in addMatrix (case 1)");
                        return 1;
                    }
                    break;
                
                case 2:
                    char scalarChoice;
                    int scalar;
                    printf("Which matrix would you like to scale? Use capital letters A, B, or C to choose\n");
                    scanf(" %c", &scalarChoice);
                    while ((int) scalarChoice < 65 || (int) scalarChoice > 67) {
                        printf("Your choice was invalid, please try again.\n");
                        scanf(" %c", &scalarChoice);
                    }
                    printf("How much would you like to scale the matrix by? ");
                    scanf(" %d", &scalar);
                    if (scalarChoice == 'A') {
                        scaleMatrix(matrixA, firstRow, firstCol, scalar);
                        //printMatrix(matrixA, firstRow, firstCol);
                    }
                    else if (scalarChoice == 'B') {
                        scaleMatrix(matrixB, secondRow, secondCol, scalar);
                        //printMatrix(matrixB, secondRow, secondCol);
                    }
                    else if (scalarChoice == 'C') {
                        scaleMatrix(matrixC, thirdRow, thirdCol, scalar);
                        //printMatrix(matrixC, thirdRow, thirdCol);
                    }
                    else {
                        printf("An error has occurred in scaleMatrix (case 2)");
                        return 2;
                    }
                    break;
                case 3:
                    char transposeChoice;
                    printf("Which matrix would you like to transpose? Use capital letters to choose\n");
                    scanf(" %c", &transposeChoice);
                    while ( (int) transposeChoice < 65 || (int) transposeChoice > 67) {
                        printf("Your choice was invalid, please try again.\n");
                    }
                    if (transposeChoice == 'A') {
                        transposeMatrix(matrixA, firstRow, firstCol, result);
                        int temp = 0;
                        temp = firstRow;
                        firstRow = firstCol;
                        firstCol = temp;
                        //printMatrix(matrixA, firstRow, firstCol);
                    }
                    else if (transposeChoice == 'B') {
                        transposeMatrix(matrixB, secondRow, secondCol, result);
                        int temp = 0;
                        temp = secondRow;
                        secondRow = secondCol;
                        secondCol = temp;
                        //printMatrix(matrixB, secondRow, secondCol);
                    }
                    else if (transposeChoice == 'C') {
                        transposeMatrix(matrixC, thirdRow, thirdCol, result);
                        int temp = 0;
                        temp = thirdRow;
                        thirdRow = thirdCol;
                        thirdCol = temp;
                        //printMatrix(matrixC, thirdRow, thirdCol);
                    }
                    else {
                        printf("An error has occurred in transposeMatrix (case 3)");
                        return 3;
                    }
                    break;
                case 4:
                    char multFirst;
                    char multSecond;
                    printf("Which matrices would you like to multiply? Use capital letters to designate which each matrix (A C)\n");
                    scanf(" %c %c", &multFirst, &multSecond);
                    while (((int) multFirst < 65 || (int) multFirst > 67) || ((int) multSecond < 65 || (int) multSecond > 67)) {
                        printf("One of your choices was invalid, please try again.\n");
                        scanf(" %c %c", &multFirst, &multSecond);
                    }

                    if (multFirst == 'A' && multSecond == 'B') {
                        multiplyMatrix(matrixA, firstRow, firstCol, matrixB, secondRow, secondCol, result);
                        printf("The result has been put into Matrix A.\n");
                        secondRow = 0;
                        firstCol = secondCol;
                        secondCol = 0;
                    }
                    else if (multFirst == 'B' && multSecond == 'A') {
                        multiplyMatrix(matrixB, secondRow, secondCol, matrixA, firstRow, firstCol, result);
                        printf("The result has been put into Matrix B.\n");
                        firstRow = 0;
                        secondCol = firstCol;
                        firstCol = 0;
                    }
                    else if (multFirst == 'B' && multSecond == 'C') {
                        multiplyMatrix(matrixB, secondRow, secondCol, matrixC, thirdCol, thirdRow, result);
                        printf("The result has been put into Matrix B.\n");
                        thirdRow = 0;
                        secondCol = thirdCol;
                        thirdCol = 0;
                    }
                    else if (multFirst == 'C' && multSecond == 'B') {
                        multiplyMatrix(matrixC, thirdRow, thirdCol, matrixB, secondRow, secondCol, result);
                        printf("The result has been put into Matrix C.\n");
                        secondRow = 0;
                        thirdCol = secondCol;
                        secondCol = 0;
                    }
                    else if (multFirst == 'A' && multSecond == 'C') {
                        multiplyMatrix(matrixA, firstRow, firstCol, matrixC, thirdRow, thirdCol, result);
                        printf("The result has been put into Matrix A.\n");
                        thirdRow = 0;
                        firstCol = thirdCol;
                        thirdCol = 0;
                    }
                    else if (multFirst == 'C' && multSecond == 'A') {
                        multiplyMatrix(matrixC, thirdRow, thirdCol, matrixA, firstRow, firstCol, result);
                        printf("The result has been put into Matrix C.\n");
                        firstRow = 0;
                        thirdCol = firstCol;
                        firstCol = 0;
                    }
                    else {
                        printf("An error has occurred in multiplyMatrix (case 4)");
                        return 4;
                    }
                    break;
                case 5:
                    printMatrices(matrixA, firstRow, firstCol, matrixB, secondRow, secondCol, matrixC, thirdRow, thirdCol);
                    break;
                case 6:
                    running--;
                    printf("Thanks for using this program, these are the final states of each matrix\n");
                    printMatrices(matrixA, firstRow, firstCol, matrixB, secondRow, secondCol, matrixC, thirdRow, thirdCol);
                    break;
            }
        }
    }
    return 0;
}
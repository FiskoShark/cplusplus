##include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// --------------------------------------------------------------------------------------- int ---------------------------------------- //
void initializeMatrix(int** matrix, int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = rand() % 21 - 10;
}

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void findMinMaxDiagonal(int** matrix, int size, int& minVal, int& maxVal) {
    minVal = maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }
}

// ------------------------------------------------------------------------------------- double --------------------------- //
void initializeMatrix(double** matrix, int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = (rand() % 2001 - 1000) / 100.0; 
}

void printMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void findMinMaxDiagonal(double** matrix, int size, double& minVal, double& maxVal) {
    minVal = maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }
}

// ---------------------------------------------------------------------------------- char ------------------------------- //
void initializeMatrix(char** matrix, int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = 'A' + rand() % 26;
}

void printMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void findMinMaxDiagonal(char** matrix, int size, char& minVal, char& maxVal) {
    minVal = maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }
}

// ---------------------------------------------------------------------------- count element ------------------------------- //
void countElements(int arr[], int size, int& positive, int& negative, int& zero) {
    positive = negative = zero = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) ++positive;
        else if (arr[i] < 0) ++negative;
        else ++zero;
    }
}

int main() {
    int size = 3;
    int** intMatrix = new int* [size];
    for (int i = 0; i < size; ++i)
        intMatrix[i] = new int[size];

    initializeMatrix(intMatrix, size);
    printMatrix(intMatrix, size);

    int minInt, maxInt;
    findMinMaxDiagonal(intMatrix, size, minInt, maxInt);
    cout << "int diagonal min: " << minInt << ", max: " << maxInt << endl;

    


    int arr[] = { 1, -2, 0, 5, 0, -8, 7 };
    int positive, negative, zero;
    countElements(arr, 7, positive, negative, zero);

    cout << "positive: " << positive << ", negative: " << negative << ", zero: " << zero << endl;

  


    for (int i = 0; i < size; ++i)
        delete[] intMatrix[i];
    delete[] intMatrix;

    return 0;
}
include <iostream>
using namespace std;


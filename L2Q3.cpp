#include <iostream>
using namespace std;

const int SIZE = 3; // You can change matrix size as needed

// Function to display a matrix
void displayMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

// Boolean Join (OR)
void joinMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            result[i][j] = A[i][j] | B[i][j];
}

// Boolean Meet (AND)
void meetMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            result[i][j] = A[i][j] & B[i][j];
}

// Boolean Product (using AND-OR logic)
void booleanProduct(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) {
                result[i][j] = result[i][j] | (A[i][k] & B[k][j]);
            }
        }
    }
}

int main() {
    int A[SIZE][SIZE] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 1, 0}
    };

    int B[SIZE][SIZE] = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}
    };

    int result[SIZE][SIZE];

    cout << "Matrix A:\n";
    displayMatrix(A);
    cout << "\nMatrix B:\n";
    displayMatrix(B);

    // Join
    joinMatrix(A, B, result);
    cout << "\nJoin (A OR B):\n";
    displayMatrix(result);

    // Meet
    meetMatrix(A, B, result);
    cout << "\nMeet (A AND B):\n";
    displayMatrix(result);

    // Boolean Product
    booleanProduct(A, B, result);
    cout << "\nBoolean Product (A x B):\n";
    displayMatrix(result);

    return 0;
}

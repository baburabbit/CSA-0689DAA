#include <stdio.h>

#define N 4

void addMatrix(int A[][N], int B[][N], int C[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int A[][N], int B[][N], int C[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassenMatrixMultiply(int A[][N], int B[][N], int C[][N]) {
    if (N == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = N / 2;

    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize];
    int M5[newSize][newSize], M6[newSize][newSize], M7[newSize][newSize];

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    subtractMatrix(B12, B22, M1);
    strassenMatrixMultiply(A11, M1, C11);

    addMatrix(A11, A12, M1);
    strassenMatrixMultiply(M1, B22, C12);

    addMatrix(A21, A22, M1);
    strassenMatrixMultiply(M1, B11, C21);

    subtractMatrix(B21, B11, M1);
    strassenMatrixMultiply(A22, M1, C22);

    addMatrix(C11, C12, C[0]);
    addMatrix(C21, C22, C[1]);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i + newSize][j + newSize] = C[1][j];
            C[i + newSize][j] = C[0][j];
        }
    }
}

void printMatrix(int matrix[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int B[N][N] = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    };

    int C[N][N];

    strassenMatrixMultiply(A, B, C);

    printf("Matrix A:\n");
    printMatrix(A);

    printf("Matrix B:\n");
    printMatrix(B);

    printf("Matrix C (Result of A * B):\n");
    printMatrix(C);

    return 0;
}


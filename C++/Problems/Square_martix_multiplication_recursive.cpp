#include <iostream>
#include <vector>
using namespace std;
using matrix = vector<vector<int> >;

matrix add(matrix &A, matrix &B){
    int n = A.size();
    matrix C(n, vector<int>(n,0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

matrix multiply(matrix &A, matrix &B){
    int n = A.size();
    matrix C(n, vector<int>(n,0));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newsize = n/2;

    matrix A11(newsize, vector<int>(newsize,0));
    matrix A12(newsize, vector<int>(newsize,0));
    matrix A21(newsize, vector<int>(newsize,0));
    matrix A22(newsize, vector<int>(newsize,0));

    matrix B11(newsize, vector<int>(newsize,0));
    matrix B12(newsize, vector<int>(newsize,0));
    matrix B21(newsize, vector<int>(newsize,0));
    matrix B22(newsize, vector<int>(newsize,0));

    for (int i = 0; i < newsize; ++i)
        for (int j = 0; j < newsize; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newsize];
            A21[i][j] = A[i + newsize][j];
            A22[i][j] = A[i + newsize][j + newsize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newsize];
            B21[i][j] = B[i + newsize][j];
            B22[i][j] = B[i + newsize][j + newsize];
        }

    matrix P1 = multiply(A11, B11);
    matrix P2 = multiply(A12, B21);
    matrix C11 = add(P1, P2);

    matrix P3 = multiply(A11, B12);
    matrix P4 = multiply(A12, B22);
    matrix C12 = add(P3, P4);

    matrix P5 = multiply(A21, B11);
    matrix P6 = multiply(A22, B21);
    matrix C21 = add(P5, P6);

    matrix P7 = multiply(A21, B12);
    matrix P8 = multiply(A22, B22);
    matrix C22 = add(P7, P8);

    for (int i = 0; i < newsize; i++)
    {
        for (int j = 0; j < newsize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newsize] = C12[i][j];
            C[i + newsize][j] = C21[i][j];
            C[i + newsize][j + newsize] = C22[i][j];
        }
        
    }
    return C;
}

void printMatrix(const matrix &mat) {
    for (auto &row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    matrix A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6}
    };

    matrix B = {
        {6, 5, 4, 3},
        {2, 1, 0, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    matrix C = multiply(A, B);

    cout << "Resultant Matrix C:" << endl;
    printMatrix(C);

    return 0;
}
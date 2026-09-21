#include <iostream>
using namespace std;

struct Tensor {
    int rows;
    int cols;
    float* data;

    Tensor(int r, int c) {
        rows = r;
        cols = c;
        data = new float[rows * cols];

    
    }
    ~Tensor() {
        delete[] data;
    }
    float& at(int r, int c) {
        return data[r * cols + c];
    }
};


void matmul(Tensor& A,Tensor& B,Tensor& C) {
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            float sum = 0.0f;
            for (int k = 0; k < A.cols; k++){
                sum += A.at(i, k) * B.at(k, j);
            }
            C.at(i, j) = sum;
        }
    }
} 


int main(){
    Tensor A(2, 2);
    A.at(0, 0) = 1.0f; A.at(0, 1) = 2.0f;
    A.at(1, 0) = 3.0f; A.at(1, 1) = 4.0f;

    Tensor B(2, 2);
    B.at(0, 0) = 5.0f; B.at(0, 1) = 6.0f;
    B.at(1, 0) = 7.0f; B.at(1, 1) = 8.0f;

    Tensor C(2, 2);

    matmul(A, B, C);
    cout << "=== Result Matrix C (A x B) ===\n";
    for (int r = 0; r < C.rows; r++) {
        for (int c = 0; c < C.cols; c++) {
            cout << C.at(r, c) << " ";
        }
        cout << "\n";
    } 

    return 0;
}
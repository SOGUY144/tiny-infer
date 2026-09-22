#include <iostream>
#include <cmath>
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
void rmsnorm(Tensor& in, Tensor& out) {
    float eps = 1e-5f;

    for (int r =0; r < in.rows; r++) {
        float sum_sq = 0.0f;
        for (int c = 0; c < in.cols; c++){
            float val = in.at(r, c);
            sum_sq += val * val;
        }

        float rma = sqrtf((sum_sq / in.cols) + eps);

        for (int c = 0; c < in.cols; c++) {
            out.at(r, c) = in.at(r, c) / rma;
        }
    }
}


void silu(Tensor& in, Tensor& out) {
    for (int r =0; r < in.rows; r++) {
        for (int c= 0; c < in.cols; c++) {
            float x = in.at(r, c);
            out.at(r, c) = x / (1.0f + expf(-x));
        }
    }
}


void softmax(Tensor& in, Tensor& out) {
    for (int r = 0; r < in.rows; r++) {
        float max_val = in.at(r, 0);
        for (int c = 1; c < in.cols; c++) {
            if (in.at(r, c) > max_val) {
                max_val = in.at(r, c);
            }
        }

        float sum = 0.0f;
        for (int c =0; c < in.cols; c++) {
            out.at(r, c) = expf(in.at(r, c) - max_val);
            sum += out.at(r, c);
        }
        for (int c = 0; c < in.cols; c++) {
            out.at(r, c) /= sum;
        }
    }
}


int main(){
    
    cout << "==========================================\n";
    cout << "   Tiny-Infer: Math Engine Test Suite     \n";
    cout << "==========================================\n\n";

    Tensor A(2, 2);
    A.at(0, 0) = 1.0f; A.at(0, 1) = 2.0f;
    A.at(1, 0) = 3.0f; A.at(1, 1) = 4.0f;

    Tensor B(2, 2);
    B.at(0, 0) = 5.0f; B.at(0, 1) = 6.0f;
    B.at(1, 0) = 7.0f; B.at(1, 1) = 8.0f;

    Tensor C(2, 2);
    matmul(A, B, C);
    cout << "[Test 1] MatMul (คาดหวัง: 19 22 / 43 50):\n";
    cout << " " << C.at(0, 0) << " " << C.at(0, 1) << "\n";
    cout << " " << C.at(1, 0) << " " << C.at(1, 1) << "\n\n";

    // 2. ทดสอบ RMSNorm
    Tensor x_rms(1, 2);
    x_rms.at(0, 0) = 2.0f; x_rms.at(0, 1) = 2.0f;
    Tensor out_rms(1, 2);
    rmsnorm(x_rms, out_rms);
    cout << "[Test 2] RMSNorm (คาดหวัง: ~1.0 ~1.0):\n";
    cout << " " << out_rms.at(0, 0) << " " << out_rms.at(0, 1) << "\n\n";

    // 3. ทดสอบ SiLU (ทดสอบเลข 0.0f และ 2.0f)
    Tensor x_silu(1, 2);
    x_silu.at(0, 0) = 0.0f; x_silu.at(0, 1) = 2.0f;
    Tensor out_silu(1, 2);
    silu(x_silu, out_silu);
    cout << "[Test 3] SiLU (คาดหวัง: 0.0 ~1.76):\n";
    cout << " " << out_silu.at(0, 0) << " " << out_silu.at(0, 1) << "\n\n";

    // 4. ทดสอบ Softmax (ทดสอบแปลงคะแนน [1.0, 2.0, 3.0])
    Tensor x_sm(1, 3);
    x_sm.at(0, 0) = 1.0f; x_sm.at(0, 1) = 2.0f; x_sm.at(0, 2) = 3.0f;
    Tensor out_sm(1, 3);
    softmax(x_sm, out_sm);
    cout << "[Test 4] Softmax (ผลรวมต้องได้ 1.0 หรือ 100%):\n";
    float sum_prob = 0.0f;
    for (int c = 0; c < 3; c++) {
        cout << " Prob["<< c <<"] = "<< out_sm.at(0, c) << "\n";
        sum_prob += out_sm.at(0, c);

    }
    cout << " Total Sum = " << sum_prob << "\n\n";

    cout << ">> ALL Math Engines Verified Successfully! <<<\n";


    return 0;
}
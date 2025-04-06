#include <iostream>
using namespace std;

int main() {
    int K;
    cin >> K;

    int* A = new int[K+1]; // number of As
    int* B = new int[K+1]; // number of Bs

    // starts with: "A"
    A[0] = 1;
    B[0] = 0;

    for(int i = 1; i <= K; i++) {
        A[i] = B[i-1];
        B[i] = A[i-1] + B[i-1];
    }

    cout << A[K] << " " << B[K];

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // make matrix1 and matrix2
    int** matrix1 = new int*[N];
    int** matrix2 = new int*[N];
    for(int i = 0; i < N; i++) {
        matrix1[i] = new int[M];
        matrix2[i] = new int[M];
    }

    // initialize matrix1
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> matrix1[i][j];
    
    // initialize matrix2
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> matrix2[i][j];

    // print matrix that is matrix1 + matrix2
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << matrix1[i][j] + matrix2[i][j];
            if(j != M-1) {cout << " ";}
        }
        if(i != N-1) {cout << endl;}
    }

    // delete matrix1 and matrix2
    for(int i = 0; i < N; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    matrix1 = nullptr;
    matrix2 = nullptr;

    return 0;
}
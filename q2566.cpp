#include <iostream>
using namespace std;

int main() {
    // make matrix
    int** matrix = new int*[9];
    for(int i=0; i<9; i++)
        matrix[i] = new int[9];

    int max_val = 0, max_i = 0, max_j = 0;
    // max_i and max_j stores the location (i,j) of max_val

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_i = i;
                max_j = j;
            }
        }
    
    cout << max_val << endl;
    cout << max_i+1 << " " << max_j+1;

    // delete matrix
    for(int i = 0; i < 9; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = nullptr;
    
    return 0;
}
#include <iostream>
using namespace std;

// swap arr[i] and arr[j]
void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main() {
    int N, M;
    cin >> N >> M;

    int* baskets = new int[N+1];
    // baskets[0] is left as garbage

    for(int k = 0; k <= N; k++) {
        // initialize ball number inside each basket
        baskets[k] = k; 
    }

    int i, j; // swap balls in i-th and j-th basket
    for(int k = 0; k < M; k++) {
        cin >> i >> j;
        swap(baskets, i, j);
    }

    for(int k = 1; k <= N; k++) {
        cout << baskets[k];
        if (k != N) { cout << " "; }
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {

    int N, M;

    cin >> N >> M;

    int* baskets = new int[N+1];

    for(int x = 1; x <= N; x++) {
        // initialize every basket to 0
        baskets[x] = 0; 
    }

    for(int x = 0; x < M; x++) {
        int i, j, k;
        cin >> i >> j >> k;

        for(int y = i; y <= j; y++) {
            baskets[y] = k;
        }
    }

    for(int x = 1; x <= N; x++) {
        cout << baskets[x];
        if(x != N) { cout << " "; }
    }

    delete[] baskets;
    baskets = nullptr;

    return 0;
}
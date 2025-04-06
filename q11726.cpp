#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n; // target rectangle size is 2 * n

    int* methods = new int[n+1]; // to use indices 1 ~ n

    methods[1] = 1; // 1 way to fit a 2 * 1 rectangle
    methods[2] = 2; // 2 ways to fit a 2 * 2 rectangle

    for (int i = 3; i <= n; i ++) {
        methods[i] = (methods[i-1] + methods[i-2]) % 10007;
    }

    cout << methods[n];

    return 0;
}
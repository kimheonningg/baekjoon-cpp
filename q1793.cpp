#include <iostream>
using namespace std;

// FIXME: datatype with range longer than "long" is needed for methods array

int main() {
    int n;
    cin >> n; // rectangle size is 2 * n

    long* methods = new long[n+1];
    methods[1] = 1; // 1 way to fill a rectangle with size 2 * 1
    methods[2] = 3; // 3 ways to fill a rectangle with size 2 * 2

    for(int i = 3; i <= n; i++) {
        methods[i] = methods[i-1] + 2 * methods[i-2];
    } 

    cout << methods[n];

    return 0;
}
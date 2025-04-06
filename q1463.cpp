#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int* methods = new int[N+1];
    methods[1] = 0;
    methods[2] = 1; // 2-1 = 1
    methods[3] = 1; // 3/3 = 1

    for (int i = 4; i <= N; i++) {
        methods[i] = methods[i-1] + 1;

        if(i % 2 == 0) { // try dividing with 2
            methods[i] = min(methods[i], methods[i/2] + 1);
        }

        if(i % 3 == 0) { // try dividing with 3
            methods[i] = min(methods[i], methods[i/3] + 1);
        }
    } 

    cout << methods[N];

    return 0;
}
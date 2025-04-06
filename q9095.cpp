#include <iostream>
using namespace std;

int main() {
    int T, n;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> n;
        int* methods = new int[n+1];
        methods[1] = 1; // 1
        methods[2] = 2; // 1+1, 2
        methods[3] = 4; // 1+1+1, 1+2, 2+1, 3

        for(int j = 4; j <= n; j++) {
            methods[j] = methods[j-1] + methods[j-2] + methods[j-3];
        }
        
        cout << methods[n] << endl;

        delete[] methods;
        methods = nullptr;
    }
    return 0;
}
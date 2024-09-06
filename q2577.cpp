#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int multiplied = A * B * C;

    int numArray[10] = {0};

    while (multiplied > 0) {
        numArray[multiplied % 10] ++;
        multiplied = multiplied / 10;
    }

    for(int i = 0; i < 10; i++)
        cout << numArray[i] << endl;

    return 0;
}
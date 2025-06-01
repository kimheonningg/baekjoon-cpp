#include <iostream>
using namespace std;

int main() {
    int A, B;

    cin >> A >> B;

    int count = 1;
    while(true){
        // calculate backwards: from B to A
        if(A == B) {
            break;
        }
        else if (A > B) { // not valid
            count = -1;
            break;
        }

        if(B%10 == 1) { // if B ends with 1
            B /= 10; // remove the last digit 1
            count ++;
        }
        else if(B%2 == 0) { // if B is even
            B /= 2;
            count ++;
        }
        else { // not valid
            count = -1;
            break;
        }
    }

    cout << count;

    return 0;
}
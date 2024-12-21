#include <iostream>
using namespace std;

int main() {
    int students[30] = {0};
    for(int i = 0; i < 28; i++) {
        int submitted;
        cin >> submitted;
        students[submitted-1]++;
    }
    for(int i = 0; i < 30; i++) {
        if(students[i] == 0)
            cout << i+1 << endl;
    }
    return 0;
}
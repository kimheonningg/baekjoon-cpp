#include <iostream>
using namespace std;

int main() {
    int number;
    int actual_piece_num[6] = {1, 1, 2, 2, 2, 8};
    int answer[6] = {0};

    for(int i = 0; i < 6; i++) {
        cin >> number;
        answer[i] = actual_piece_num[i] - number;
    }

    for(int i = 0; i < 6; i++) {
        cout << answer[i];
        if(i != 5) { cout << " "; }
    }

    return 0;
}
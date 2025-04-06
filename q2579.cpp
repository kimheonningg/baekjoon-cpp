#include <iostream>
using namespace std;

int main() {
    int stair_num;
    cin >> stair_num;

    int* stairs = new int[stair_num]; // stores the score on each step
    int* scores = new int[stair_num]; // stores the cumulative score

    for (int i = 0; i < stair_num; i++)
        cin >> stairs[i];

    scores[0] = stairs[0];
    scores[1] = stairs[0] + stairs[1];
    scores[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for (int i = 3; i < stair_num; i++) {
        scores[i] = max (
            scores[i-2] + stairs[i],
            scores[i-3] + stairs[i-1] + stairs[i]
        );
    }

    cout << scores[stair_num-1];

    return 0;
}
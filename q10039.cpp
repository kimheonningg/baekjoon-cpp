#include <iostream>
using namespace std;

int main() {
    int each_score;
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        cin >> each_score;
        if(each_score < 40) { each_score = 40; }
        sum += each_score;
    }

    int average = sum / 5;

    cout << average;

    return 0;
}
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string N;
    int B;

    cin >> N >> B;

    int smallestDiget; // stores the rightmost number of N
    int currentMultiplier = 1;
    int currentDiget = N.length()-1;
    int answer = 0; // stores the number in decimal

    while (currentDiget >= 0) {
        if(isdigit(N[currentDiget])) {
            smallestDiget = (N[currentDiget] - '0');
        }
        else { // N[currentDiget] is an alphabet
            smallestDiget = (N[currentDiget] - 'A' + 10);
        }
        answer += smallestDiget * currentMultiplier;
        currentMultiplier *= B;
        currentDiget --;
    }

    cout << answer;

    return 0;
}
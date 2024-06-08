#include <iostream>
#include <string>
using namespace std;

int main() {

    int T;
    cin >> T;

    string input, answer="";

    for(int i = 0; i < T; i++) {
        cin >> input;

        answer += input[0];
        answer += input[input.length()-1];
        answer += "\n";
    }

    cout << answer;

    return 0;
}
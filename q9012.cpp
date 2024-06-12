#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str) {
    stack<char> stk;

    for(char elem: str) {
        if(elem == '(') { stk.push(elem); }
        else {
            if(stk.empty()) return false;
            else if(stk.top() == '(') {
                stk.pop();
                continue;
            }
            return false;
        }
    }

    if(stk.empty()) return true;
    return false;
}

int main() {
    int T;
    cin >> T;

    string input;

    string* answer = new string[T];

    for(int i = 0; i < T; i++) {
        cin >> input;
        if(isValid(input)) { answer[i] = "YES"; }
        else { answer[i] = "NO"; }
    }

    for(int i = 0; i < T; i++) {
        cout << answer[i] << endl;
    }

    // erase answer
    delete[] answer;
    answer = nullptr;
}
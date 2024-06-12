#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {

    int N, x;
    cin >> N;

    string instruction;
    stack<int> stk;
    vector<int> answers;

    for(int i = 0; i < N; i++) {

        cin >> instruction;

        if(instruction == "push") {
            cin >> x;
            stk.push(x);
        }

        else if(instruction == "pop") {
            if(stk.empty()) {answers.push_back(-1);}
            else {
                answers.push_back(stk.top());
                stk.pop();
            }
        }

        else if(instruction == "size") {
            answers.push_back(stk.size());
        }

        else if(instruction == "empty") {
            if(stk.empty()) { answers.push_back(1); }
            else{ answers.push_back(0); }
        }

        else { // instruction == "top"
            if(stk.empty()) {answers.push_back(-1);}
            else { answers.push_back(stk.top()); }
        }
    }

    for(int i = 0; i < answers.size(); i++) {
        cout << answers[i] << endl;
    }
    
    return 0;
}
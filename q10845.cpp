#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main() {

    int N, x;
    cin >> N;

    string instruction;
    queue<int> q;
    vector<int> answers;

    for(int i = 0; i < N; i++) {
        cin >> instruction;
        
        if(instruction == "push") {
            cin >> x;
            q.push(x);
        }

        else if(instruction == "pop") {
            if(q.empty()) { answers.push_back(-1); }
            else { 
                answers.push_back(q.front());
                q.pop();
            }
        }

        else if(instruction == "size") {
            answers.push_back(q.size());
        }

        else if(instruction == "empty") {
            if(q.empty()) { answers.push_back(1); }
            else { answers.push_back(0); }
        }

        else if(instruction == "front") {
            if(q.empty()) { answers.push_back(-1); }
            else { answers.push_back(q.front()); }
        }

        else { // instruction == "back"
            if(q.empty()) { answers.push_back(-1); }
            else { answers.push_back(q.back()); }
        }
    }

    for(int i = 0; i < answers.size(); i++) {
        cout << answers[i] << endl;
    }

    return 0;
}
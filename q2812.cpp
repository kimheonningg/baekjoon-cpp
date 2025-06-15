#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    
    string s;
    cin >> s;

    stack<char> final_string;
    int delete_count = 0;

    for(int i = 0; i < s.size(); i ++) {
        while(!final_string.empty() && delete_count < K && s[i] > final_string.top()) { 
            // if the string can be deleted and
            // final_string top must be deleted
            delete_count ++;
            final_string.pop();
        }
        final_string.push(s[i]);
    }

    while(delete_count < K) {
        delete_count++;
        final_string.pop(); 
        // if there are characters that needs to be deleted left,
        // start deleting from the last character
    }

    // reverse the order of the stack
    stack<char> answer;
    while(!final_string.empty()) {
        answer.push(final_string.top());
        final_string.pop();
    }

    // print the final answer
    while(!answer.empty()) {
        cout << answer.top();
        answer.pop();
    }

    return 0;
}
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string input; // lower case only
    int M; // number of instructions

    cin >> input;

    stack<char> left; // chars at the left of the cursor
    stack<char> right; // chars at the right of the cursor

    for(int i = 0; i < (int)input.size(); i++)
        left.push(input[i]); // since the cursor is at the rightmost at first
        // the leftmost element is at the top of the stack

    // no elements are at the right of the cursor

    cin >> M;
    for (int i = 0; i < M; i++) { // for each instructions
        char instruction; // L or D or B or P
        cin >> instruction;
        switch(instruction) {
            case 'L': // move cursor 1 step to the left
                // move the leftmost element(= top of the left stack) of 'left' to the top of 'right'
                if(!left.empty()) {
                    char current_leftmost = left.top();
                    left.pop();
                    right.push(current_leftmost);
                }
                break;
            case 'D': // move cursor 1 step to the right
                // move the rightmost element to the top of 'left'
                if(!right.empty()) {
                    char current_rightmost = right.top();
                    right.pop();
                    left.push(current_rightmost);
                }
                break;
            case 'B': // delete the letter at the left of the cursor
                if(!left.empty()) {
                    left.pop();
                }
                break;
            case 'P': // add a char at the left of the cursor
                char c;
                cin >> c;
                left.push(c);
                break;
        }
    }

    // for printing

    // move chars of 'left' to 'right'
    // then print 'right' from top to bottom

    while(!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()) {
        cout << right.top();
        right.pop();
    }

    return 0;
}
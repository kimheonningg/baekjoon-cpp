#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
RULES:
- Operands
  immediately print operands A~Z

- Operators
  1)
  +, -, *, / : compare with stack top.  
  If the stack top operator precedence is the same or higher than the current operator,
  Print & pop stack top
  
  2)
  ( : put inside stack

  3)
  ) : Print & pop stack top until ( shows

  - we do not print ( or )

  4)
  If stack is not empty after traversal, pop until stack is empty
*/

int main() {

    string input;

    stack<char> operators; 
    // the stack only stores operators, as operands are immediately printed

    cin >> input; 
    // primary infix equation

    for (int i = 0; i < (int)input.length(); i++) {

        // if current char is an operand
        if(input[i] >= 'A' && input[i] <= 'Z')
            cout << input[i]; // immediately print the operand
        
        // if current char is an operator
        else {
            // 1) if current char is + - * /
            // operator precedence: + = - < * = /
            if(input[i] == '+' || input[i] == '-') {
                while (!operators.empty() && operators.top() != '(' &&
                        // same or higher precedence
                       (operators.top() == '+' || operators.top() == '-' ||
                        operators.top() == '*' || operators.top() == '/')) {
                    cout << operators.top();
                    operators.pop();
                }
                operators.push(input[i]);
            }

            else if(input[i] == '*' || input[i] == '/') {
                while (!operators.empty() && operators.top() != '(' &&
                        // same or higher precedence
                       (operators.top() == '*' || operators.top() == '/' )) {
                    cout << operators.top();
                    operators.pop();
                }
                operators.push(input[i]);
            }
            
            // 2) if current char is (
            else if(input[i] == '(') 
                operators.push(input[i]);
            
             // 3) if current char is )
            else if(input[i] == ')') {
                while(!operators.empty() && operators.top() != '(') {
                    cout << operators.top();
                    operators.pop();
                }

                if (!operators.empty()) operators.pop(); // pop (
            }
        }
    }

     // 4) if stack is not empty after traversal
    while (!operators.empty()) {
        cout << operators.top();
        operators.pop();
    }

    return 0;
}
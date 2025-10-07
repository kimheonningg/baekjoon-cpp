#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;

int main() {
    int N; // number of operands
    string input; // postfix equation

    cin >> N;
    cin >> input;

    double* values = new double[N]; // values corresponding to operands

    for(int i = 0; i < N; i++) cin >> values[i];

    stack<double> results;

    for(int i = 0; i < (int)input.length(); i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') { // currently an operand
            results.push(values[(input[i] - 'A')]); // corresponding value
        }
        else { // currently an operator
            double right = results.top(); 
            results.pop();

            double left = results.top(); 
            results.pop();

            switch (input[i]) {
                case '+': results.push(left + right); break;
                case '-': results.push(left - right); break;
                case '*': results.push(left * right); break;
                case '/': results.push(left / right); break;
            }
        }
    }

    cout << fixed << setprecision(2) << results.top() << '\n';
    delete[] values;
    return 0;

    return 0;
}
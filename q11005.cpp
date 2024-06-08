#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, B;

    cin >> N >> B;

    vector<char> answer;

    while (N > 0) {
        int remainder = N % B;
        if(remainder >= 10) {
            answer.push_back((char)('A' + remainder-10));
        }
        else {
            answer.push_back((char)(remainder+'0'));
        }
        N = N/B;
    }

    for(auto itr = answer.rbegin(); itr != answer.rend(); itr++)
        cout << *itr;
    
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;

    cin >> input;

    bool isPalindrome = true;

    for(int i = 0; i < input.length()/2; i++)
        if(input[i] != input[input.length()-1-i])
            isPalindrome = false;

    cout << (isPalindrome ? 1 : 0) ;
    
    return 0;
}
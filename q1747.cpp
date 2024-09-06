#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(int n) {
    if(n < 10) return true;
    vector<int> digitsReversed;
    while(n > 0){
        digitsReversed.push_back(n % 10);
        n = n / 10;
    }
    for(int i = 0; i < digitsReversed.size()/2; i++) {
        if(digitsReversed[i] != digitsReversed[digitsReversed.size()-1-i])
            return false;
    }
    return true;
}

bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i < n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    while(true) {
        if(isPalindrome(N) && isPrime(N)) break;
        N++;
    }

    cout << N;

    return 0;
}
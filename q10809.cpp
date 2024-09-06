#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    int alphaNumArr[26]; // array that stores the number of each alphabet
    for (int i = 0; i < 26; i++)
        alphaNumArr[i] = -1;

    cin >> S;

    for(int i = 0; i < S.length(); i++)
        if(alphaNumArr[S[i]-'a'] == -1)
            alphaNumArr[S[i]-'a'] = i;

    for(int i = 0; i < 26; i++)
        cout << alphaNumArr[i] << " ";

    return 0;
}
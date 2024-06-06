#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string word;
    cin >> word;

    int alphabet_num[26] = {0};

    for(int i = 0; i < word.length(); i++) {
        alphabet_num[toupper(word[i]) - 'A'] ++;
    }

    int max_num = 0;
    char max_alphabet;
    // true if there are more than one max_alphabet
    bool isMultiple = false;

    for(int i = 0; i < 26; i++) {
        if(max_num < alphabet_num[i]) {
            max_num = alphabet_num[i];
            max_alphabet = toupper('A' + i);
            isMultiple = false;
        }
        else if(max_num == alphabet_num[i]) {
            isMultiple = true;
        }
    }

    if(isMultiple) { cout << "?"; }
    else { cout << max_alphabet; }

    return 0;
}
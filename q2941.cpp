#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    set<string> croatian_alphabet_two_letters = {
        "c=", 
        "c-",
        // "dz=",
        "d-",
        "lj",
        "nj",
        "s=",
        "z="
    };

    string croatian_alphabet_three_letters = "dz=";

    string input;
    cin >> input;

    int answer = 0;

    for(int i = 0; i < input.length(); i++) {
        if(
            i < input.length() - 1 &&
            croatian_alphabet_two_letters.find(input.substr(i,2)) != croatian_alphabet_two_letters.end()
        ) {
            answer ++;
            i ++;
            continue;
        }

        else if(
            i < input.length() - 2 &&
            input.substr(i,3) == croatian_alphabet_three_letters
        ) {
            answer ++;
            i+= 2;
            continue;
        }

        else {
            answer ++;
        }
    }
    
    cout << answer << endl;
    return 0;
}
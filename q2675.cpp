#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, R;
    string S;

    cin >> T;

    string* answer = new string[T]; // array that stores the answer strings
    // initialize every answer elements to empty string ""
    for(int i = 0; i < T; i++)
        answer[i] = "";

    for(int i = 0; i < T; i++) {
        
        cin >> R >> S;

        for(int j = 0; j < S.length(); j++)
            for(int k = 0; k < R; k++)
                answer[i] += S[j];
    }

    for(int i = 0; i < T; i++) {
        cout << answer[i];
        if(i != T-1) cout << endl;
    }

    // delete answer array
    delete[] answer;
    answer = nullptr;

    return 0;
}
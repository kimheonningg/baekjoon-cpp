#include <iostream>
#include <set>
using namespace std;

int main() {
    int T, C; // C in cents

    cin >> T;

    int** answerArr = new int*[T];
    for(int i=0; i<T; i++)
        answerArr[i] = new int[4];
    
    // initialize answerArr to 0
    for(int i = 0; i < T; i++)
        for(int j = 0; j < 4; j++)
            answerArr[i][j] = 0;

    // stores the values of Quarter, Dime, Nickel, and Penny
    int coinValArr[4] = {25, 10, 5, 1};

    for(int i=0; i<T; i++) {
        
        cin >> C;
        
        int j = 0;

        while(C > 0) {
            answerArr[i][j] = C/coinValArr[j];
            C = C%coinValArr[j];
            j++;
        }
    }

    // print answerArr
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < 4; j++) {
            cout << answerArr[i][j];
            if(j != 3) {cout << " ";}
        }
        if(i != T-1) {cout << endl;}
    }

    return 0;
}
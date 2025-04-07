#include <iostream>
using namespace std;

void draw(int i, int j, int N) {
    if ((i/N)%3 == 1 && (j/N)%3 == 1) cout << ' '; // empty in the middle
    else {
        if (N/3 == 0) cout << '*'; // cannot divide anymore, so print *
        else draw(i, j, N/3); // divide into smaller blocks
    }
}

int main() {
    int N;
    cin >> N; // N = 3^n
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            draw(i, j, N);
        }
        cout << endl;
    }
    return 0;
}
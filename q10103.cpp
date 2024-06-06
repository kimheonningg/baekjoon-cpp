#include <iostream>
using namespace std;

int main() {
    int antonia_score = 100;
    int david_score = 100;

    int n;
    cin >> n;

    int a, b; // roll result of each round

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(a > b) { david_score -= a; }
        else if (b > a) { antonia_score -= b; }
    }

    cout << antonia_score << endl;
    cout << david_score;

    return 0;
}
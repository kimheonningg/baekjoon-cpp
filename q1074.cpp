#include <iostream>
using namespace std;

int r, c, answer = 0;

void find_place(int y, int x, int size) {
    if(y == r && x == c) {
        cout << answer << endl;
        return;
    }

    if( y <= r && r < y + size && x <= c && c < x + size) {
        // target exists inside current block- search in Z order
        
        // find left top block
        find_place (y, x, size/2);

        // find right top block
        find_place (y, x + size/2, size/2);

        // find left bottom block
        find_place (y + size/2, x, size/2);

        // find right bottom block
        find_place (y + size/2, x + size/2, size/2);
    }
    else {
        // target does not exist inside current block- skip the whole block
        answer += size * size;
    }
}

int main() {
    int N;
    cin >> N >> r >> c; // r-th row, c-th column
    find_place(0, 0, (1 << N)); // 1 << n shifts 1 left N times, so is equal to 2^N
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long N, M;
    cin >> N >> M;
    long long* tree_heights = new long long[N];

    for(long long i = 0; i < N; i++)
        cin >> tree_heights[i];

    // sort the trees in ascending order
    sort(tree_heights, tree_heights + N);
    
    long long min_cut_height = 0;
    long long max_cut_height = tree_heights[N-1];

    long long answer_height = 0; // initialize with the worst case

    // instead of linearly searching which cutting height is optimal,
    // use binary search to find the optimal cutting height
    while (min_cut_height <= max_cut_height) { // while cutting is allowed
        long long sum = 0; // sum of all cutted tree pieces
        long long cutting_height = (min_cut_height + max_cut_height) / 2;

        for(long long i = 0; i < N; i++) {
            // sum up all the cutted tree pieces, if possible
            if(tree_heights[i] - cutting_height > 0) {
                sum += tree_heights[i] - cutting_height; // cutted wood piece
            }
        }

        if(sum >= M) { // this height is okay, but we need to check if there is a better solution
            answer_height = cutting_height;
            min_cut_height = cutting_height + 1; // search for a better solution
        }
        else {
            // we need to go lower
            max_cut_height = cutting_height - 1;
        }
    }

    cout << answer_height;

    return 0;
}
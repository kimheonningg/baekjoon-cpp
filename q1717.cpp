#include <iostream>
using namespace std;

int parent[1000001]; // since 1 <= n <= 1000000
int rank_u[1000001]; // to use union by rank

void make_set(int x) {
    parent[x] = x; // a singleton set
    rank_u[x] = 1;
}

int find_set(int x) {
    if(parent[x] != x) 
        parent[x] = find_set(parent[x]); // for path compression
    return parent[x];
}

void union_set(int x, int y) {
    int x_root = find_set(x);
    int y_root = find_set(y);
    if(x_root == y_root) return; // already union-ed

    // union by rank
    if(rank_u[x_root] > rank_u[y_root]) // add y to x
        parent[y_root] = x_root; // set x_root as a parent of y_root
    else {
        parent[x_root] = y_root; // set y_root as a parent of x_root
        if(rank_u[x_root] == rank_u[y_root]) rank_u[y_root]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); // makes cin faster
    cin.tie(nullptr); // prevents auto flush

    int n, m;
    cin >> n >> m ;

    for (int i = 0; i <= n; i++) {
        make_set(i);
    }

    int c, a, b;
    for (int i = 0; i < m; i++) {
        cin >> c >> a >> b;
        if (c == 0) { // union a and b
            union_set(a, b);
        }
        else if (c == 1) { // check if a and b are in the same set
            if(find_set(a) == find_set(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
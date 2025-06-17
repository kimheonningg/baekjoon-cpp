#include <iostream>
using namespace std;

int N;
char** grid;
bool** visited;

// define directions
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {

    if(visited[x][y]) return; // (x,y) already visited

    visited[x][y] = true; // visit (x,y)

    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) continue;
        if(grid[x][y] == grid[next_x][next_y] && !visited[next_x][next_y])
            // do dfs only when (next_x, next_y) is the same color with (x, y) 
            dfs(next_x, next_y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    grid = new char*[N];
    visited = new bool*[N];
    for(int i = 0; i < N; i++) {
        grid[i] = new char[N];
        visited[i] = new bool[N];
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    // normal person
    int normal_count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) { // not visited yet
                dfs(i, j);
                normal_count ++;
            }
        }
    }

    // color-blinded person
    // change all green to red
    // and initialize visited array to false
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 'G')
                grid[i][j] = 'R';
            visited[i][j] = false;
        }
    
    int color_blind_count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) { // not visited yet
                dfs(i, j);
                color_blind_count ++;
            }
        }
    }

    cout << normal_count << " " << color_blind_count;

    return 0;
}
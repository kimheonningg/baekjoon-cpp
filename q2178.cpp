#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int** maze;
bool** visited;
queue<pair<int, int>> visited_queue;
int** moved_distance;

// directions in the order: up, down, left, right
int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

void bfs(int x, int y) {
    visited[x][y] = true; // visit (x,y)
    visited_queue.push(make_pair(x, y));
    moved_distance[x][y] ++;

    while (!visited_queue.empty()) {
        int front_x = visited_queue.front().first;
        int front_y = visited_queue.front().second;

        visited_queue.pop();

        for(int i = 0; i < 4; i++) { // for all 4 directions 
            // (adj_x, adj_y) is the coordinate of an adjacent node
            int adj_x = front_x + x_dir[i];
            int adj_y = front_y + y_dir[i];

            // check if (adj_x, adj_y) it is visit-able
            if((0 <= adj_x && adj_x < N) && (0 <= adj_y && adj_y < M) /* (adj_x, adj_y) is in range */
            && !visited[adj_x][adj_y] /* (adj_x, adj_y) is not visited yet */
            && maze[adj_x][adj_y] == 1 /* (adj_x, adj_y) is a path */ ) {
                // visit (adj_x, adj_y) 
                visited[adj_x][adj_y] = true;
                visited_queue.push(make_pair(adj_x, adj_y));
                moved_distance[adj_x][adj_y] = moved_distance[front_x][front_y] + 1;
            }
        }
    }
    
}

int main() {
    cin >> N >> M;

    // define the size of the 2D arrays- maze, visited, moved_distance
    maze = new int*[N]; 
    visited = new bool*[N];
    moved_distance = new int*[N];
    for (int i = 0; i < N; i++) {
        maze[i] = new int[M];
        visited[i] = new bool[M];
        moved_distance[i] = new int[M];
    }

    for (int i = 0; i < N; i ++) {
        string row_str; // change the given row (int value) into a string
        cin >> row_str;
        for (int j = 0; j < row_str.length(); j++) {
            maze[i][j] = row_str[j] - '0'; // convert char into int
            visited[i][j] = false; // init all elements of visited as false
            moved_distance[i][j] = 0; // init all elements of moved_distance as 0
        }
    }

    // do BFS to solve the problem
    bfs(0, 0);

    cout << moved_distance[N-1][M-1];

    return 0;
}
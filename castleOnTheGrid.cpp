#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class nodeG {
public:
    char data;
    int dist;
    bool visited;
    int x;
    int y;
    nodeG () {
    }
    nodeG (int i, int j, char d, int di, bool v) {
        x = i;
        y = j;
        data = d;
        dist = di;
        visited = v;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N, a, b, c, d;
    char inp;

    cin >> N;
    vector<vector<nodeG> > grid(N, vector<nodeG>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inp;
            nodeG input(i, j, inp, 0, false);
            if (inp == 'X')
                input.visited = true;
            grid[i][j] = input;
        }
    }

    cin >> a >> b >> c >> d;

    grid[a][b].visited = true;
    queue<nodeG> q;
    q.push(grid[a][b]);

    while (!q.empty()) {
        nodeG curr = q.front();
        q.pop();

        if ((curr.x == c) && (curr.y == d)) {
            cout << curr.dist;
            break;
        }

        for (int l = curr.x - 1; l >= 0; l--) {
            if (!grid[l][curr.y].visited) {
                grid[l][curr.y].visited = true;
                grid[l][curr.y].dist = curr.dist + 1;
                q.push(grid[l][curr.y]);
            }
            else
                break;
        }
        for (int r = curr.x + 1; r < N; r++) {
            if (!grid[r][curr.y].visited) {
                grid[r][curr.y].visited = true;
                grid[r][curr.y].dist = curr.dist + 1;
                q.push(grid[r][curr.y]);
            }
            else
                break;
        }
        for (int u = curr.y - 1; u >= 0; u--) {
            if (!grid[curr.x][u].visited) {
                grid[curr.x][u].visited = true;
                grid[curr.x][u].dist = curr.dist + 1;
                q.push(grid[curr.x][u]);
            }
            else
                break;
        }
        for (int d = curr.y + 1; d < N; d++) {
            if (!grid[curr.x][d].visited) {
                grid[curr.x][d].visited = true;
                grid[curr.x][d].dist = curr.dist + 1;
                q.push(grid[curr.x][d]);
            }
            else
                break;
        }
    }

    return 0;
}
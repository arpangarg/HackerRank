#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class nodeLevel {
public:
    int node;
    int level;
    
    nodeLevel() {
        node = level = -1;
    }
    
    nodeLevel(int n, int l) {
        node = n;
        level = l;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N, M, S;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N >> M;

        int graph[N][N] = {0};
        vector<int> distances(N, -1);
        int x, y;
        
        for (int j = 0; j < M; j++) {
            cin >> x >> y;
            graph[x-1][y-1] = 1;
            graph[y-1][x-1] = 1;
        }

        cin >> S;

        queue<nodeLevel> q;

        nodeLevel st(S, 1);

        q.push(st);

        while (!q.empty()) {
            nodeLevel node = q.front();
            q.pop();

            for (int k = 0; k < N; k++) {
                if (graph[node.node-1][k] != 0) {
                    nodeLevel n(k+1, node.level+1);
                    q.push(n);
                    if (distances[k] == -1)
                        distances[k] = 6*node.level;
                }
            }
        }
        
        for (int m = 0; m < N; m++) {
            if (m == S - 1)
                continue;
            cout << distances[m] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
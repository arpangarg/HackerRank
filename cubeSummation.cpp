#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class block {
public:
    int x;
    int y;
    int z;
    long long W;
    block(int xc, int yc, int zc, long long wval) {
        x = xc;
        y = yc;
        z = zc;
        W = wval;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int T, N, M, x, y, z, x1, y1, z1, x2, y2, z2;
    long long W;
    string q;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        vector<block> cube;
        for (int j = 0; j < M; j++) {
            cin >> q;
            
            if (q == "UPDATE") {
                cin >> x >> y >> z >> W;
                block b = block(x, y, z, W);
                cube.push_back(b);
            }
            else {
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                long long sum = 0;

                for (int m = 0; m < cube.size(); m++) {
                    if((cube[m].x >= x1) && (cube[m].x <= x2) && (cube[m].y >= y1)
                      && (cube[m].y <= y2) && (cube[m].z >= z1) && (cube[m].z <= z2))
                        sum += cube[m].W;
                }

                cout << sum << endl;
            }
        }
        cube.clear();
    }

    return 0;
}
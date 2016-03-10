#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        
        bool inner = 1, outer = 1;
        
        for (int i = 0; (i <= R - r) && outer; i++) {
            for (int j = 0; (j <= C - c) && outer; j++) {
                if (G[i][j] == P[0][0]) {
                    inner = true;
                    for (int a = 0; (a < r) && inner; a++) {
                        for (int b = 0; (b < c) && inner; b++) {
                            if (G[i + a][j + b] != P[a][b])
                                inner = false;
                        }
                    }
                    if (inner)
                        outer = false;
                }
            }
        }
        
        if(outer)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        
    }
    return 0;
}
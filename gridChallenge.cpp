#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N;
        
        vector<string> G(N);
        
        for (int j = 0; j < N; j++)
            cin >> G[j];
        
        for (int m = 0; m < N; m++) {
            for (int x = N - 1; x > 0; x--) {
                for (int y = 0; y < x; y++) {
                    if (G[m][y] > G[m][y+1])
                        swap(G[m][y], G[m][y+1]);
                    else
                        continue;
                }
            }
        }
        
        bool isLexo = true;
        
        for (int col = 0; col < N; col++) {
            for (int row = 0; row < N - 1; row++) {
                if (G[row][col] > G[row+1][col]) {
                    isLexo = false;
                    break;
                }
            }
            if (!isLexo)
                break;
        }
        
        if (isLexo)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<long long> > nCr;

void updateNCR(int n) {
    if (n <= nCr.size())
        return;

    int nCrSize = nCr.size();

    for (int i = nCrSize - 1; i < n - 1; i++) {
        vector<long long> toPush(nCr[i].size() + 1, 1);

        for (int j = 1; j < nCr[i].size(); j++)
            toPush[j] = ((nCr[i][j-1] % 1000000000) + (nCr[i][j] % 1000000000)) % 1000000000;

        nCr.push_back(toPush);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int T, N, K;
    vector<long long> row1(1, 1);
    vector<long long> row2(3, 1);
    row2[1] = 2;
    nCr.push_back(row1);
    nCr.push_back(row2);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;

        int n = K + N - 1;
        
        updateNCR(n);
        
        cout << nCr[n-1][K] << endl;
        /*for (int a = 0; a < nCr.size(); a++) {
            for (int b = 0; b < nCr[a].size(); b++)
                cout << nCr[a][b] << " ";
            cout << endl;
        }
        cout << endl << endl;*/
    }

    return 0;
}
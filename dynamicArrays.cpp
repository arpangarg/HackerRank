#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N, Q;
    cin >> N >> Q;
    
    vector<vector<int> > sequences(N);
    int queryType, x, y, lastans = 0;
    
    while (Q > 0) {
        cin >> queryType >> x >> y;
        int seqNum = (x ^ lastans) % N;
        if (queryType == 1)
            sequences[seqNum].push_back(y);
        else {
            int printIndex = y % sequences[seqNum].size();
            cout << sequences[seqNum][printIndex] << endl;
            lastans = sequences[seqNum][printIndex];
        }
        Q--;
    }
        
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N, K;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        
        if (K >= N/2)
            cout << 2*(N-K-1);
        else
            cout << 2*(K+1) - 1;
        
        cout << endl;
        
    }
    
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N;
        int toPr = 1;
        for (int j = 0; j < N; j++)
            toPr = (toPr * 2) % 100000;
        cout << toPr - 1 << endl;
        
    }
    
    return 0;
}
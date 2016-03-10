#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N, input;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N;
        if (N % 2 == 0) {
            for (int a = 0; a < N; a++)
                cin >> input;
            cout << 0 << endl;
        }
        else {
            int result = 0;
            for (int a = 1; a <= N; a++) {
                cin >> input;
                if (a % 2 == 1)
                    result ^= input;
            }
            cout << result << endl;
        }
    }
    
    return 0;
}
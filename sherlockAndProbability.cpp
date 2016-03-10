#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N, K;
    string S;
    cin >> T;
    
    for (int a = 0; a < T; a++) {
        cin >> N >> K;
        cin >> S;

        int count = 0;
        for (int i = 0; i < N; i++) {
            int start = (i - K < 0) ? 0 : i - K;
            int end = (i + K >= N) ? N : i + K + 1;

            for (int j = start; j < end; j++) {
                if ((S[i] == '1') && (S[j] == '1'))
                    count++;
            }
        }
        int getGCD = gcd(count, N*N);
        cout << count/getGCD << "/" << N*N/getGCD << endl;
    }
    
    return 0;
}
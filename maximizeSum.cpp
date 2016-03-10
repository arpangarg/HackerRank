#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N;
    long long M;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        
        vector<long long> arr(N);

        for (int j = 0; j < N; j++)
            cin >> arr[j];
        
        long long sum = 0;
        long long maxVal = 0;
        
        for (int x = 0; x < N; x++) {
            for (int y = x; y < N; y++) {
                sum += arr[i];
                maxVal = (sum % M > maxVal) ? sum % M : maxVal;
            }
            sum = 0;
        }
        cout << maxVal << endl;
    }
    
    return 0;
}
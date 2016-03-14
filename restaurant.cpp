#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd (int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, l, b;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> l >> b;
        int gcomd = gcd(l, b);
        int res = l*b/(gcomd*gcomd);
        cout << res << endl;
        
    }
    
    return 0;
}
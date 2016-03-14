#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, a, b, x, y;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> a >> b >> x >> y;
        
        if (gcd(a, b) == gcd(x, y))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;        
    }
    
    return 0;
}
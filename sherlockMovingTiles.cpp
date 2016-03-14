#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int L, S1, S2, Q;
    long long q;
    cout << fixed << setprecision(20);
    cin >> L >> S1 >> S2 >> Q;
    
    for (int i = 0; i < Q; i++) {
        cin >> q;
        
        double t = sqrt(2)*(L - sqrt(static_cast<double>(q)))/(abs(S2 - S1));
        cout << t << endl;
        
    }
    
    return 0;
}
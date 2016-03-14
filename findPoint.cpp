#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, Px, Py, Qx, Qy;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> Px >> Py >> Qx >> Qy;
        
        cout << 2*Qx - Px << " " << 2*Qy - Py <<  endl;
    }
    
    return 0;
}
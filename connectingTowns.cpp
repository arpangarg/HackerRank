#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N, Ni, totRoutes;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N;
        totRoutes = 1;
        for (int j = 0; j < N - 1; j++) {
            cin >> Ni;
            totRoutes = (totRoutes*Ni) % 1234567;
        }
        cout << totRoutes << endl;
    }
    
    return 0;
}
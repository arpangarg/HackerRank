#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, m, input;

    map<int, int> A, B;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        A[input]++;
    }
    
    cin >> m;
    for (int j = 0; j < m; j++) {
        cin >> input;
        B[input]++;
    }
    
    for(map<int, int>::iterator it = B.begin(); it != B.end(); it++) {
        if (A.find(it->first) == A.end() || A[it->first] != it->second)
            cout << it->first << " ";
    }
    
    return 0;
}
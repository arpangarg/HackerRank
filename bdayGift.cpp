#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N, input;
    double expVal = 0;
    cout << fixed << setprecision(1);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        expVal += input*0.5;
    }
    
    cout << expVal;
    
    return 0;
}
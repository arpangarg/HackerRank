#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N, a, b;
    long long aMin = 1000001, bMin = 1000001;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        
        if (a < aMin)
            aMin = a;
        if (b < bMin)
            bMin = b;
    }
    long long res = aMin*bMin;
    cout << res;
    return 0;
}
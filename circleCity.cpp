#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int t;
    long long d, k;
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> d >> k;
        long long count = 0;
        for (long long j = 1; j <= sqrt(d); j++) {
            double doubsqrt = sqrt(double(d) - j*j);
            long long intsqrt = static_cast<long long>(doubsqrt);
            if (intsqrt == doubsqrt)
                count++;
        }

        count = 4*count;

        if (count <= k)
            cout << "possible";
        else
            cout << "impossible";
        cout << endl;
    }
    
    return 0;
}
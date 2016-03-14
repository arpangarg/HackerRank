#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int T;
    long long n;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> n;
        long long temp = n % static_cast<long long>(10e9 + 7);
        cout << (temp * temp) % static_cast<long long>(10e9 + 7)  << endl;
    }

    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N;

    cin >> N;
    
    long long a[N];
    long long d[N];
    
    for (int i = 0; i < N; i++)
        cin >> a[i] >> d[i];

    int start = 0;
    int curr = start;
    long long sum_a = 0;
    long long sum_d = 0;

    while (true) {
        sum_a += a[curr];
        sum_d += d[curr];

        if (sum_d > sum_a) {
            curr = (curr + 1) % N;
            start = curr;
            sum_a = 0;
            sum_d = 0;
        }
        else {
            curr = (curr + 1) % N;
            if (curr == start) {
                cout << start;
                break;
            }
        }
    }

    return 0;
}
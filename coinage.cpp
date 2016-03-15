#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int T, N, A, B, C, D;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> A >> B >> C >> D;
        int count = 0;
        for (int b = 0; (b <= B) && (2*b <= N); b++) {
            for (int c = 0; (c <= C) && (5*c + 2*b <= N); c++) {
                for (int d = 0; (d <= D) && (10*d + 5*c + 2*b <= N); d++) {
                    if (N - (10*d + 5*c + 2*b) <= A)
                        count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int T, N, c;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;

        int cVal[N+1] = {0};
        long output = 1, choices = 0;

        for (int j = 0; j < N; j++) {
            cin >> c;
            cVal[c]++;
        }

        for (int k = 0; k < N; k++) {
            choices += cVal[k];
            if (choices == 0 || cVal[N] != 0) {
                output = 0;
                break;
            }
            output = (output % 1000000007) * (choices % 1000000007) % 1000000007;
            choices--;
        }
        cout << output << endl;
    }

    return 0;
}
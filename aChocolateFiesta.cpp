#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N, a;

    int nEven = 0, nOdd = 0;
    int numStud = 1;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a % 2) {
            nOdd++;
        }
        else {
            nEven++;
        }
    }

    for (int j = 0; j < nEven; j++)
        numStud = (numStud * 2) % 1000000007;
    for (int j = 1; j < nOdd; j++)
        numStud = (numStud * 2) % 1000000007;
    
    cout << numStud - 1;
    
    return 0;
}
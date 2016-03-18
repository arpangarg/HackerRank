#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int T, A, B;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        
        int rootA_int = sqrt(A);
        int rootB_int = sqrt(B);
        double rootA_doub = sqrt(A);
        double rootB_doub = sqrt(B);

        int numSqInt = rootB_int - rootA_int;

        if (rootA_doub == rootA_int)
            numSqInt++;
        cout << numSqInt << endl;
    }

    return 0;
}
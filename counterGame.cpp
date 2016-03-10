#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T;
    unsigned long long N;

    string players[2] = {"Louise", "Richard"};
    
    int currWinner;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N;
        currWinner = 1;
        while (N != 1) {
            /*
            if (N & (N - 1) == 0)
                N /= 2;
            else {
                int largestP = 1;
                while ((largestP << 1) < N)
                    largestP <<= 1;
                N -= largestP;
            }*/
            unsigned long long largestP = 1;
            while ((largestP << 1) < N)
                largestP <<= 1;
            N -= largestP;
            
            currWinner = (currWinner + 1) % 2;
        }
        cout << players[currWinner] << endl;
    }
    
    return 0;
}
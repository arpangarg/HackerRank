#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> primeNums;
    primeNums.push_back(2);
    int i = 2;
    while (primeNums.size() < Q) {
        for (int j=2; j<i; j++)
        {
            if (i % j == 0) 
                break;
            else if (i == j+1)
                primeNums.push_back(i);
        }
        i++;
    }

    vector<stack<int> > nonPrime(2);
    int num;
    
    for (int k = 0; k < N; k++) {
        cin >> num;
        nonPrime[0].push(num);
    }

    vector<stack<int> > primePiles(Q);
    bool checkStack = 0, nonDivStack = 1;
    int plateNumber;
    
    for (int m = 0; m < Q; m++) {
        while(!nonPrime[checkStack].empty()) {
            plateNumber = nonPrime[checkStack].top();
            nonPrime[checkStack].pop();

            if (plateNumber % primeNums[m] == 0)
                primePiles[m].push(plateNumber);
            else
                nonPrime[nonDivStack].push(plateNumber);
        }
        
        checkStack = !checkStack;
        nonDivStack = !nonDivStack;
    }
    
    for (int m = 0; m < Q; m++) {
        while (!primePiles[m].empty()) {
            cout << primePiles[m].top() << endl;
            primePiles[m].pop();
        }
    }
    
    while (!nonPrime[checkStack].empty()) {
        cout << nonPrime[checkStack].top() << endl;
        nonPrime[checkStack].pop();
    }
    
    return 0;
}
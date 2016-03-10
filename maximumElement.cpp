#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, q, x;
    stack<int> s, maxim;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> q;
        if (q == 1) {
            cin >> x;
            if (s.empty()) {
                s.push(x);
                maxim.push(x);
            }
            else {
                if (x >= maxim.top())
                    maxim.push(x);
                s.push(x);
            }
        }
        else if (q == 2) {
            if (s.top() == maxim.top())
                maxim.pop();
            s.pop();
        }
        else
            cout << maxim.top() << endl;
    }
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int Q, q;
    long long v;
    priority_queue<long long, vector<long long>, greater<long long> > minHeap;
    vector<long long> temp;
    
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> q;
        if (q == 1) {
            cin >> v;
            minHeap.push(v);
        }
        else if (q == 2) {
            cin >> v;
            while (true) {
                if (minHeap.top() == v) {
                    minHeap.pop();
                    for (int k = 0; k < temp.size(); k++) {
                        minHeap.push(temp[k]);
                    }
                    temp.clear();
                    break;
                }
                else {
                    temp.push_back(minHeap.top());
                    minHeap.pop();
                }
            }
        }
        else {
            cout << minHeap.top() << endl;
        }
    }

    return 0;
}
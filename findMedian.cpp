#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int totalNumber;
    cin >> totalNumber;
    cout << fixed << setprecision(1);

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int input;

    for (int i = 0; i < totalNumber; i++) {
        //cout << "SIZES: " << minHeap.size() << " " << maxHeap.size() << endl;

        cin >> input;
        if (maxHeap.empty()) {
            maxHeap.push(input);
            cout << static_cast<double>(input) << endl;
            continue;
        }

        if (input > maxHeap.top())
            minHeap.push(input);
        else
            maxHeap.push(input);

        if (int(maxHeap.size()) - int(minHeap.size()) > 1) {
            int transfer = maxHeap.top();
            maxHeap.pop();
            minHeap.push(transfer);
        }
        else if (int(minHeap.size()) - int(maxHeap.size()) > 1) {
            int transfer = minHeap.top();
            minHeap.pop();
            maxHeap.push(transfer);
        }

        if (minHeap.size() > maxHeap.size())
            cout << static_cast<double>(minHeap.top()) << endl;
        else if(maxHeap.size() > minHeap.size())
            cout << static_cast<double>(maxHeap.top()) << endl;
        else
            cout << (minHeap.top() + maxHeap.top())/2.0 << endl;
    }

    return 0;
}
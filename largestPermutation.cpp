#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N, K;
    
    cin >> N >> K;
    
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    int max, maxIndex, numSwaps = 0;
    for (int j = 0; j < N - 1; j++) {
        max = arr[j];
        maxIndex = j;
        for (int m = j + 1; m < N; m++) {
            if (arr[m] > max) {
                max = arr[m];
                maxIndex = m;
            }
        }
        if (maxIndex == j) {
            continue;
        }
        else {
            numSwaps++;
            swap(arr[j], arr[maxIndex]);
        }
        if (numSwaps == K)
            break;
    }
    
    for (int n = 0; n < N; n++)
        cout << arr[n] << " ";
    
    return 0;
}
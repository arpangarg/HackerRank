#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findSum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N;
        
        int *nums = new int[N];
        
        for (int j = 0; j < N; j++)
            cin >> nums[j];

        if (N == 1) {
            cout << "YES" << endl;
            continue;
        }
        if (N == 2) {
            cout << "NO" << endl;
            continue;
        }

        int totalSum = findSum(nums, N);
        int leftSum = 0, rightSum;
        bool elemExists = false;
        
        for (int k = 1; k < N - 1; k++) {
            leftSum += nums[k-1];
            rightSum = totalSum - leftSum - nums[k];
            if (leftSum == rightSum) {
                elemExists = true;
                break;
            }
        }
        if (elemExists)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
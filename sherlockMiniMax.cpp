#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findStart(int A[], int size, int P) {
    if (P < A[0])
        return 0;
    else if (P > A[size - 1])
        return size - 1;
    else {
        int i = 0;
        while (P > A[i])
            i++;
        return i;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N;
    cin >> N;
    
    int A[N];
    
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    int P, Q;
    
    cin >> P >> Q;
    
    sort(A, A + N);
    
    int max = 0, maxNum = 0;
    int check, num;

    int index = findStart(A, N, P);

    if (index == N - 1) {
        cout << Q;
        return 0;
    }
    
    for (num = P; num <= Q; num++) {
        if (index == 0 && num <= A[index]) {
            if (A[index] - num > max) {
                max = A[index] - num;
                maxNum = num;
            }
            if (A[index] >= Q) {
                cout << P;
                return 0;
            }
            else {
                index++;
                num = A[index - 1];
                continue;
            }
        }
        else {
            //cout << index << " " << num;
            if (num > A[index]) {
                index++;
                if (index == N)
                    break;
            }
            //cout << "   " << index << " " << num << endl;
            check = min(abs(A[index] - num), abs(A[index-1] - num));
            if (check > max) {
                max = check;
                maxNum = num;
            }
        }
    }
    
    if (index == N) {
        int toRet = (Q - A[N - 1] > max) ? Q : maxNum;
        cout << toRet;
        return 0;
    }
    
    cout << maxNum;
    
    return 0;
}
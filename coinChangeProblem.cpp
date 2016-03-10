#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getWays (vector<int> C, int N) {
    if (C.empty())
        return 0;
    else if (C.size() == 1) {
        if (N % C[0] == 0)
            return 1;
        else
            return 0;
    }
    else if (N == 0)
        return 1;


    int coin = C.back();
    C.pop_back();

    int sum = 0;
    while (N >= 0) {
        //cout << N << "   C.size: " << C.size() << "    ";
        //for (int i = 0; i < C.size(); i++) cout << C[i] << " ";
        //cout << endl;
        sum += getWays(C, N);
        N -= coin;
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N, M, input;
    cin >> N >> M;
    
    vector<int> C;
    while (cin >> input)
        C.push_back(input);
    
    sort(C.begin(), C.end());
    
    cout << getWays(C, N);
    
    return 0;
}
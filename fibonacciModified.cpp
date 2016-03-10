#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> add(vector<int> bigger, vector<int> smaller) {
    int carry = 0;
    vector<int> toRet;
    int temp;
    for (int i = 0; i < smaller.size(); i++) {
        temp = smaller[i] + bigger[i] + carry;
        toRet.push_back(temp % 10);
        carry = temp / 10;
    }
    for (int j = smaller.size(); j < bigger.size(); j++) {
        toRet.push_back(bigger[j] + carry);
        carry = 0;
    }
    return toRet;
}

vector<int> mulScalar(vector<int> v, int s, int numZeros) {
    int carry = 0;
    vector<int> toRet;
    int temp;
    
    for (int k = 0; k < numZeros; k++)
        toRet.push_back(0);
    
    for (int i = 0; i < v.size(); i++) {
        temp = v[i] * s + carry;
        toRet.push_back(temp % 10);
        carry = temp / 10;
    }
    if (carry != 0)
        toRet.push_back(carry);
    return toRet;
}

vector<int> squareV(vector<int> v) {
    vector<int> toRet;
    //vector<vector<int> > intermediate(v.size());
    for (int i = 0; i < v.size(); i++) {
        //intermediate[i] = mulScalar(v, v[i], i);
        toRet = add(mulScalar(v, v[i], i), toRet);
    }
    return toRet;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    vector<int> nmin1, nmin2;
    int input, N;

    cin >> input;
    nmin2.push_back(input);
    cin >> input;
    nmin1.push_back(input);

    cin >> N;

    vector<int> result;

    for (int i = 2; i < N; i++) {
        result = add(squareV(nmin1), nmin2);
        nmin2 = nmin1;
        nmin1 = result;
    }

    for (int j = result.size() - 1; j >= 0; j--)
        cout << result[j];

    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int findChildLen(string st1, string st2) {
    for (int i = 0; i < st1.length(); i++) {
        for (int j = 0; j < st2.length(); j++) {
            if(st1[i] == st2[j]) {
                int len1 = 1 + findChildLen(st1.substr(i + 1), st2.substr(j + 1));
                int len2 = 1 + findChildLen(st2.substr(j + 1), st1.substr(i + 1));
                return (len1 > len2) ? len1 : len2;
            }
        }
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string st1, st2;
    int childLen1 = 0, childLen2 = 0;
    int maxLength = 0;
    
    cin >> st1 >> st2;
    
    childLen1 = findChildLen(st1, st2);
    childLen2 = findChildLen(st2, st1);
    
    maxLength = (childLen1 > childLen2) ? childLen1 : childLen2;
    
    cout << maxLength;
    
    return 0;
}
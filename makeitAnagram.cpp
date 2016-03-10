#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int stringArr[2][26] = {0};
    int sNum = 0;
    string input;
    int deletions = 0;
    
    while (cin >> input) {
        for (int i = 0; i < input.length(); i++) {
            stringArr[sNum][input[i] - int('a')]++;
        }
        sNum++;
    }
    
    for (int j = 0; j < 26; j++) {
        deletions += abs(stringArr[0][j] - stringArr[1][j]);
    }
    
    cout << deletions;
    
    return 0;
}
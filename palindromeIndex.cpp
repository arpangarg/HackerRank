#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int returnIndex(string input) {
    int i = 0;
    int j = input.length() - 1;
    while (i < j) {
        if (input[i] != input[j]) {
            if (input[i+1] == input[j])
                return i;
            else
                return j;
        }
        i++;
        j--;
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string input;
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> input;
        cout << returnIndex(input) << endl;
    }
    
    return 0;
}
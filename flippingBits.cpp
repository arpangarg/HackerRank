#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T;
    uint32_t input;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> input;
        cout << ~input << endl;
    }
    return 0;
}
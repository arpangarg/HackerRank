#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T;
    cin >> T;
    
    string st[2];
    bool match = false;
    
    for (int i = 0; i < T; i++) {
        int stAr[2][26] = {0};
        cin >> st[0] >> st[1];
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < st[j].length(); k++) {
                stAr[j][st[j][k] - int('a')]++;
            }
        }
        for (int m = 0; m < 26; m++) {
            if ((stAr[0][m] > 0) && (stAr[1][m] > 0)) {
                cout << "YES" << endl;
                match = true;
                break;
            }
        }
        if (!match)
            cout << "NO" << endl;
        match = false;
    }
    
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    k = k % 26;
    char capA = 'A';
    char smA = 'a';
    
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= capA) && (s[i] <= 'Z')) {
            int ascii_val = int(s[i]) + k;
            if (ascii_val > 'Z')
                ascii_val -= 26;
            s[i] = ascii_val;
        }
        else if ((s[i] >= smA) && (s[i] <= 'z')) {
            int ascii_val = int(s[i]) + k;
            if (ascii_val > 'z')
                ascii_val -= 26;
            s[i] = ascii_val;
        }
    }

    cout << s;

    return 0;
}
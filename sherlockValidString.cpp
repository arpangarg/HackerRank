#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string input;
    cin >> input;
    
    int stAr[26] = {0};
    
    for (int i = 0; i < input.length(); i++) {
        stAr[input[i] - int('a')]++;
    }
    
    int startInd = 0;
    int freq;
    bool setOne = false, canBeDone = true;
    
    for (int j = 0; j < 26; j++) {
        if (stAr[j] ==  0)
            continue;
        else {
            startInd = j;
            freq = stAr[j];
            break;
        }
    }
    
    for (int k = startInd; k < 26; k++) {
        if (stAr[k] == 0)
            continue;
        else {
            if (stAr[k] - freq == 0)
                continue;
            else if (abs(stAr[k] - freq) == 1) {
                if (setOne) {
                    canBeDone = false;
                    break;
                }
                else
                    setOne = true;
            }
            else {
                canBeDone = false;
                break;
            }
        }
    }
    
    if(canBeDone)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}
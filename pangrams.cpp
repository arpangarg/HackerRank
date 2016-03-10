#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int panArray[26] = {0};
    string inWord;

    while (cin >> inWord) {
        for(int i = 0; i < inWord.length(); i++)
            if (inWord[i] >= int('A') && inWord[i] <= int('Z'))
                panArray[inWord[i] - int('A')]++;
            else
                panArray[inWord[i] - int('a')]++;
    }
    
    bool pangram = true;
    
    for (int k = 0; k < 26; k++) {
        if(panArray[k] == 0) {
            cout << "not pangram";
            pangram = false;
            break;
        }
    }

    if (pangram)
        cout << "pangram";
    return 0;
}
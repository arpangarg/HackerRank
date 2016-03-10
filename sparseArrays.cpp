#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numStrings;
    cin >> numStrings;
    
    vector<string> stringsVector(numStrings);
    for (int i = 0; i < numStrings; i++)
        cin >> stringsVector[i];
    
    int numQueries;
    cin >> numQueries;
    
    string queryStr;
    for (int k = 0; k < numQueries; k++) {
        cin >> queryStr;
        
        int count = 0;
        
        for (int x = 0; x < numStrings; x++) {
            if (queryStr == stringsVector[x])
                count++;
        }
        cout << count << endl;
    }
    
    return 0;
}
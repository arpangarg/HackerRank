#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void addLexos(string s, vector<string> &lexo) {
    if (s.length() < 1)
        return;
    else if (s.length() == 1) {
        lexo.push_back(s);
    }
    else {
        addLexos(s.substr(1, s.length() - 1), lexo);
        int lexoSize = lexo.size();
        for (int i = 0; i < lexoSize; i++) {
            lexo.push_back(s.substr(0, 1) + lexo[i]);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T, N;
    string input;

    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N >> input;
        
        sort(input.begin(), input.end());
        
        vector<string> lexoPart, lexo;

        for (int j = N; j > 0; j--) {
            addLexos(input.substr(0, j), lexoPart);
            lexo.insert(lexo.end(), lexoPart.begin(), lexoPart.end());
            lexoPart.clear();
        }
        
        sort(lexo.begin(), lexo.end());
        
        for (int k = 0; k < lexo.size(); k++)
            cout << lexo[k] << endl;
        lexo.clear();
    }
    
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int N;
        cin >> N;
        
        int x = 0;
        int y = 0;
        bool found = false;
        for (x = 0; x <= N; x++) {
            double y_doub = (N - 5*x)/3.0;
            y = (N - 5*x)/3;
            if (y_doub == y && y >= 0) {
                found = true;
                break;
            }
        }
        
        if (found) {
            for (int i = 0; i < y; i++)
                cout << 555;
            for (int j = 0; j < x; j++)
                cout << 33333;
        }
        else
            cout << -1;
        cout << endl;
    }
    return 0;
}
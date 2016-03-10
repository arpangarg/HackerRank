#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    
    vector<int> areaList(1000001, 0);
    int height, maxHeight = 0;
    int maxArea = 0;

    for (int i = 0; i < N; i++) {
        cin >> height;
        for (int j = 1; j <= height; j++)
            areaList[j]++;
        for (int k = height + 1; k <= maxHeight; k++) {
            if (areaList[k] > 0) {
                maxArea = (areaList[k] * k > maxArea) ? areaList[k] * k : maxArea;
                areaList[k] = 0;
            }
        }
        maxHeight = height;
    }
    
    for (int x = 1; x <= maxHeight; x++)
        maxArea = (areaList[x] * x > maxArea) ? areaList[x] * x : maxArea;
    
    cout << maxArea;
    return 0;
}
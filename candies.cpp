#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void updateCandies(int ratings[], int candies[], int start, int end, int numC) {
    if (end - start < 0)
        return;
    else if (end - start == 0) {
        candies[start] = numC;
        return;
    }
    
    vector<int> indexes;
    
    if (ratings[start] <= ratings[start+1]) {
        candies[start] = numC;
        indexes.push_back(start);
    }
    
    for (int i = start + 1; i < end; i++) {
        if((ratings[i-1] >= ratings[i]) && (ratings[i+1] >= ratings[i])) {
            candies[i] = numC;
            indexes.push_back(i);
        }
    }
    
    if (ratings[end] <= ratings[end - 1]) {
        candies[end] = numC;
        indexes.push_back(end);
    }
    
    //for (int z = 0; z < 10; z++) cout << candies[z] << " ";
    //cout << endl;
    //for (int y = 0; y < indexes.size(); y++) cout << indexes[y] << " ";
    //cout << endl << endl;
    
    if (indexes[0] != start)
        updateCandies(ratings, candies, start, indexes[0] - 1, numC + 1);
    
    for (int k = 0; k < indexes.size() - 1; k++)
        updateCandies(ratings, candies, indexes[k] + 1, indexes[k + 1] - 1, numC + 1);
    
    if (indexes[indexes.size() - 1] != end)
        updateCandies(ratings, candies, indexes[indexes.size() - 1] + 1, end, numC + 1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N;
    cin >> N;
    
    int ratings[N];
    for (int i = 0; i < N; i++)
        cin >> ratings[i];
    
    int candies[N] = {0};
    
    updateCandies(ratings, candies, 0, N - 1, 1);
    
    int minCandies = 0;
    for (int k = 0; k < N; k++)
        minCandies += candies[k];
    
    cout << minCandies;
    
    return 0;
}
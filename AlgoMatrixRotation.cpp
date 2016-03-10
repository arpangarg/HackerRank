#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> getMapped(int x, int y, int M, int N, int R) {
    enum direction {down, right, up, left};
    direction dir;

    if ((y == 0) && (x != M - 1))
        dir = down;
    else if ((y == N - 1) && (x != 0))
        dir = up;
    else if ((x == M - 1) && (y != N - 1))
        dir = right;
    else
        dir = left;

    while (true) {
        if (dir == down) {
            if (x + R > M - 1) {
                R -= M - 1 - x;
                x = M - 1;
                dir = right;
            }
            else {
                x += R;
                break;
            }
        }
        else if (dir == right) {
            if (y + R > N - 1) {
                R -= N - 1 - y;
                y = N - 1;
                dir = up;
            }
            else {
                y += R;
                break;
            }
        }
        else if (dir == up) {
            if (x - R < 0) {
                R -= x;
                x = 0;
                dir = left;
            }
            else {
                x -= R;
                break;
            }
        }
        else {
            if (y - R < 0) {
                R -= y;
                y = 0;
                dir = down;
            }
            else {
                y -= R;
                break;
            }
        }
    }
    vector<int> toRet {x, y};
    return toRet;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int M, N, R;

    cin >> M >> N >> R;
    
    

    vector<vector<int> > original(M, vector<int>(N));
    vector<vector<int> > rotated(M, vector<int>(N));
    
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++)
            cin >> original[m][n];
    }
    
    int M_cur = M, N_cur = N;
    int R_cur = R % (2*M + 2*N - 4);
    int i = 0, j = 0;
    vector<int> mapResult(2);
    int loop = 0;

    while ((M_cur > 1) && (N_cur > 1)) {
        for (int z = 0; z < 2*M_cur + 2*N_cur - 4; z++) {
            mapResult = getMapped(i, j, M_cur, N_cur, R_cur);
            //if (loop == 1)
              //  cout << "x: " << mapResult[0] << " y: " << mapResult[1] << " for i: " << i << " j: " << j << endl;
            rotated[mapResult[0] + loop][mapResult[1] + loop] = 
                original[i + loop][j + loop];

            mapResult = getMapped(i, j, M_cur, N_cur, 1);
            i = mapResult[0];
            j = mapResult[1];
        }
        M_cur -= 2;
        N_cur -= 2;
        R_cur = R % (2*M_cur + 2*N_cur - 4);
        loop++;
    }
    
    for (int a = 0; a < M; a++) {
        for (int b = 0; b < N; b++)
            cout << rotated[a][b] << " ";
        cout << endl;
    }
    
    return 0;
}
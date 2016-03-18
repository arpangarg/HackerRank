#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int Q, k, t;
    string s, w;
    stack<string> st;

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> w;
            if (st.empty())
                s = "";
            else
                s = st.top();
            s += w;
            st.push(s);
        }
        else if (t == 2) {
            cin >> k;
            s = st.top();
            s = s.substr(0, s.length() - k);
            st.push(s);
        }
        else if (t == 3) {
            cin >> k;
            s = st.top();
            cout << s[k-1] << endl;
        }
        else {
            st.pop();
        }
    }
    
    return 0;
}
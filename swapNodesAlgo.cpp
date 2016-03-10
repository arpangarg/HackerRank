#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
public:   
    int key;
    int depth;
    Node *left;
    Node *right;
    
    Node() {
        left = right = 0;
    }
    Node (int k, int d, Node *l = 0, Node *r = 0) {
        key = k;
        depth = d;
        left = l;
        right = r;
    }
};

void inOrder(Node *root) {
    if (!root)
        return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int numNodes;
    cin >> numNodes;
    
    queue<Node*> inQ;
    
    Node *root = new Node(1, 1);
    inQ.push(root);
    
    int left, right, parDepth;
    while (!inQ.empty()) {
        Node *temp = inQ.front();
        inQ.pop();
        
        parDepth = temp->depth;
        
        cin >> left >> right;
        
        if (left != -1) {
            Node *leftT = new Node(left, parDepth + 1);
            temp->left = leftT;
            inQ.push(leftT);
        }
        
        if (right != -1) {
            Node *rightT = new Node(right, parDepth + 1);
            temp->right = rightT;
            inQ.push(rightT);
        }
    }
    
    int T, k;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> k;

        inQ.push(root);

        while (!inQ.empty()) {
            Node *temp = inQ.front();
            inQ.pop();

            if (temp->depth % k == 0) {
                Node *toswap = temp->left;
                temp->left = temp->right;
                temp->right = toswap;
            }

            if (temp->left)
                inQ.push(temp->left);
            if (temp->right)
                inQ.push(temp->right);
        }
        inOrder(root);
        cout << endl;
    }
    
    return 0;
}
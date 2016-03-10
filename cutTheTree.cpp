#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    int value;
    int sum;
    vector<Node*> children;
    
    Node() {
        sum = -1;
    }
    Node(int k, int v) {
        key = k;
        value = v;
        sum = -1;
    }
};

Node * findTree(Node *root, int k) {
    if (root == 0 || root->key == k)
        return root;
    else {
        for (int i = 0; i < root->children.size(); i++) {
            Node * toRet = findTree(root->children[i], k);
            if (toRet)
                return toRet;
        }
        return 0;
    }
}

int evaluateSums(Node *root) {
    if (root == 0)
        return 0;
    else {
        int sum = 0;
        for (int i = 0; i < root->children.size(); i++)
            sum += evaluateSums(root->children[i]);
        sum += root->value;
        root->sum = sum;
        return sum;
    }
}

void findMinSum(Node *currTree, int rootSum, int &minSum) {
    int sumT1 = rootSum - currTree->sum;
    int sumT2 = currTree->sum;
    minSum = abs(sumT1 - sumT2) < minSum ? abs(sumT1 - sumT2) : minSum;
    
    for (int i = 0; i < currTree->children.size(); i++)
        findMinSum(currTree->children[i], rootSum, minSum);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N;

    cin >> N;
    
    int values[N];

    for (int i = 0; i < N; i++)
        cin >> values[i];
    
    Node *root = new Node(1, values[0]);
    int vert1, vert2;
    Node *parent, *child, *temp;
    
    for (int j = 0; j < N - 1; j++) {
        cin >> vert1 >> vert2;
        
        temp = findTree(root, vert1);
        if (temp) {
            parent = temp;
            child = new Node(vert2, values[vert2 - 1]);
        }
        else {
            parent = findTree(root, vert2);
            child = new Node(vert1, values[vert1 - 1]);
        }
        
        parent->children.push_back(child);        
    }
    
    evaluateSums(root);
    
    int minSum = root->sum;
    findMinSum(root, root->sum, minSum);
    
    cout << minSum;

    return 0;
}
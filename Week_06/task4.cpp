#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    vector<Node*> children;
    int childCount = 0;
};

constexpr int MAX_SIZE = 1e6;
Node conteiner[MAX_SIZE];

int fillChildren(Node* root) {
    root->childCount = root->children.size();
    int count = root->children.size();
    
    for(int i = 0; i < count; i++) {
        root->childCount += fillChildren(root->children[i]);
    }
    
    return root->childCount;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    cin >> N;
    
    int parent, child;
    for(int i = 0; i < N - 1; i++) {
        cin >> parent >> child;
        conteiner[parent].children.push_back(&conteiner[child]);
    }
    
    fillChildren(&conteiner[0]);
    
    for(int i = 0; i < N; i++) {
        cout << conteiner[i].childCount << " ";
    }
    
    return 0;
}

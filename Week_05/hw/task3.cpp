#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    int start = 0;
    int end = 0;
    vector<Node*> children;
};

const long long MAX_SIZE = 1e6;
Node conteiner[MAX_SIZE];

void DFS(Node* root, int& time) {
    root->start = time;
    time++;
    
    for(auto child : root->children) {
        DFS(child, time);
    }
    
    root->end = ++time;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    int parent, child;
    for(int i = 0; i < N - 1; i++) {
        cin >> parent >> child;
        conteiner[parent].children.push_back(conteiner + child);
    }
    
    Node* root = conteiner;
    int time = 0;
    DFS(root, time);
    
    int Q;
    cin >> Q;
    
    for(int i = 0; i < Q; i++) {
        cin >> parent >> child;
        cout << ((conteiner[parent].start < conteiner[child].start && conteiner[parent].end > conteiner[child].end) ? "YES\n" : "NO\n");
    }
    
    return 0;
}

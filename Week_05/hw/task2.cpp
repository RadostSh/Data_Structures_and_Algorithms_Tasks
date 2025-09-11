#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

const size_t MAX_SIZE = 3e6;
Node conteiner[MAX_SIZE];

bool isValidBST(Node* root, long long min, long long max) {
    if(!root) {
        return true;
    }
    
    if(root->val <= min || root->val >= max) {
        return false;
    }
    
    return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;
        
        for(int j = 0; j < N; j++) {
            int val, leftIdx, rightIdx;
            cin >> val >> leftIdx >> rightIdx;
        
            conteiner[j].val = val;
            conteiner[j].left = leftIdx != -1 ? &conteiner[leftIdx] : nullptr;
            conteiner[j].right = rightIdx != -1 ? &conteiner[rightIdx] : nullptr;
        }
        cout << isValidBST(&conteiner[0], LLONG_MIN, LLONG_MAX) << endl;
    }
    
    return 0;
}
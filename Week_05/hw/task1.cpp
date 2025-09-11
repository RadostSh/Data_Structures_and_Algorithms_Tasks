#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;
};

Node conteiner[1000000];
long long sum[1000000]{0};
long long minIdx = 100000;
long long maxIdx = 100000;

void sumColl(Node* root, int idx) {
    if(!root) {
        return;
    }
    
    sum[idx] += root->val;
    
    if(idx < minIdx) {
        minIdx = idx;
    }
    if(idx > maxIdx) {
        maxIdx = idx;
    }
    
    sumColl(root->left, idx - 1);
    sumColl(root->right, idx + 1);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int val, leftIdx, rightIdx;
        cin >> val >> leftIdx >> rightIdx;
        
        conteiner[i].val = val;
        conteiner[i].left = leftIdx != -1 ? &conteiner[leftIdx] : nullptr;
        conteiner[i].right = rightIdx != -1 ? &conteiner[rightIdx] : nullptr;
    }
    
    sumColl(&conteiner[0], minIdx);
    
    for(long long i = minIdx; i <= maxIdx; i++) {
        if(sum[i]) {
            cout << sum[i] << " ";
        }
    }
    
    
    return 0;
}

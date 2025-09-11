#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    long long val;
    TreeNode* left;
    TreeNode* right;
    
    long long leftCount = 0;
    long long rightCount = 0;
};

const size_t MAX_SIZE = 1e6;
TreeNode conteiner[MAX_SIZE];

void fillCount(TreeNode* root) {
    if(root->left == nullptr) {
        root->leftCount = 0;
    } else {
        fillCount(root->left);
        root->leftCount = root->left->leftCount + root->left->rightCount + 1;
    }
    
    if(root->right == nullptr) {
        root->rightCount = 0;
    } else {
        fillCount(root->right);
        root->rightCount = root->right->rightCount + root->right->leftCount + 1;
    }
}

long long getMaxScore(TreeNode* root, long long upperCount) {
    long long curr = 1;
    
    if(upperCount != 0) {
        curr *= upperCount;
    }
    
    if (root->leftCount != 0)
    {
        curr *= root->leftCount;
    }

    if (root->rightCount != 0)
    {
        curr *= root->rightCount;
    }
    
    if(root->left != nullptr) {
        curr = max(curr, getMaxScore(root->left, upperCount + 1 + root->rightCount));
    }
    
    if(root->right != nullptr) {
        curr = max(curr, getMaxScore(root->right, upperCount + 1 + root->leftCount));
    }
    
    return curr;
}

long long maxScore(TreeNode* root) {
    if(root == nullptr || (root->leftCount + root->rightCount) == 0) {
        return 0;
    }
    
    return getMaxScore(root, 0);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int left, right;
        cin >> left >> right;
        
        conteiner[i].val = i;
        conteiner[i].left = left != -1 ? &conteiner[left] : nullptr;
        conteiner[i].right = right != -1 ? &conteiner[right] : nullptr;
    }
    
    fillCount(&conteiner[0]);
    
    cout << maxScore(&conteiner[0]);
    
    return 0;
}
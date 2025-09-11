/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dfs(TreeNode* root, int targetSum, long prefixSum, map<long, int>& pathWithPrefixSum) {
        if(!root) {
            return 0;
        }

        prefixSum += root->val;

        int paths = 0;
        if(pathWithPrefixSum.count(prefixSum - targetSum)) {
            paths += pathWithPrefixSum[prefixSum - targetSum];
        }

        pathWithPrefixSum[prefixSum]++;
        paths += dfs(root->right, targetSum, prefixSum, pathWithPrefixSum);
        paths += dfs(root->left, targetSum, prefixSum, pathWithPrefixSum);
        pathWithPrefixSum[prefixSum]--;
        return paths;

    }
public:
    int pathSum(TreeNode* root, int targetSum) {
       map<long, int> pathWithPrefixSum;
        pathWithPrefixSum[0] = 1;
        return dfs(root, targetSum, 0l, pathWithPrefixSum);
    }
};
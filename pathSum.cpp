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
public:
    unordered_map<long long, int> prefix;
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
    int dfs(TreeNode* root, long long curSum, int targetSum){
        if(root == nullptr) return 0;
        int ret = 0;
        curSum += root->val;
        if(prefix.find(curSum - targetSum) != prefix.end()){
            ret = prefix[curSum - targetSum];
        }

        prefix[curSum]++;
        ret += dfs(root->left, curSum, targetSum);
        ret += dfs(root->right, curSum, targetSum);
        prefix[curSum]--;
        return ret;
    }
};
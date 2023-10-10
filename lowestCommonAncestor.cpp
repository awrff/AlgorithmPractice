/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /* 
            节点有3种情况
                1.nullptr
                2.p或者q
                    以root == p为例，如果q是p的子节点，那么返回p合理；如果q不是p的子节点，同样返回p给上层做判断
                3.都不是
         */
        if(root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr) {
            return root;
        }
        if(left != nullptr) return left;
        else return right;
    }
};
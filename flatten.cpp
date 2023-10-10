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
    void flatten(TreeNode* root) {
        if(root == nullptr) return ;
        while(root != nullptr){
            // 找左边子节点
            TreeNode* leftChild = root->left;
            if(leftChild != nullptr){
                // 找左边子节点的最后一个节点
                TreeNode* lastOfLeftChild = leftChild;
                while(lastOfLeftChild->right != nullptr) 
                    lastOfLeftChild = lastOfLeftChild->right;
                // 将右边子节点接在左侧最后一个节点后
                lastOfLeftChild->right = root->right;
                // 将左边子节点接在右侧
                root->right = leftChild;
                // 左侧置空
                root->left = nullptr;
            } 
            root = root->right;
        }
    }
};
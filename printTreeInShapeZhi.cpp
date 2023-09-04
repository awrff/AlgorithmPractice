/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <vector>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > Print(TreeNode* pRoot) {
        // write code here
        if (pRoot == nullptr) return {};
        bool rev = false;
        queue<TreeNode*> q;
        q.push(pRoot);
        // 添加nullptr作为一层的分隔
        q.push(nullptr);
        vector<vector<int>> result;
        vector<int> layer;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                if(rev) reverse(layer.begin(), layer.end());
                result.push_back(layer);
                layer.clear();
                rev = !rev;
                if(!q.empty())q.push(nullptr);
                continue;
            }
            layer.push_back(node->val);
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);    
        }
        return result;
    }
};
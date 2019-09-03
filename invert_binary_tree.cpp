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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            swap(cur->left, cur->right);
            if(cur->left != NULL) stk.push(cur->left);
            if(cur->right != NULL) stk.push(cur->right);
        }
        return root;
    }
};

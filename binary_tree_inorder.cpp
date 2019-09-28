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
    vector<int> ret;
    vector<int> inorderTraversal(TreeNode* root) {
        inorderHelper(root);
        return this->ret;
    }
private:
    void inorderHelper(TreeNode* root){
        if(root == NULL) return ;
        inorderHelper(root->left);
        ret.push_back(root->val);
        inorderHelper(root->right);
        return;
    }
};

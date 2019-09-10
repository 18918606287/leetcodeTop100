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
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return robHelper(root, l, r);
    }
private:
    int robHelper(TreeNode* root, int& l, int& r){
        if(root == NULL) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = robHelper(root->left, ll, lr);
        r = robHelper(root->right, rl, rr);
        return max(ll+lr+rl+rr+root->val, l+r);
    }
};

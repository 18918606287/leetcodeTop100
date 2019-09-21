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
    int maximal = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        searchHelper(root);
        return maximal;
    }
private:
    int searchHelper(TreeNode* root){
        if(root == NULL) return 0;
        int left = searchHelper(root->left);
        int right = searchHelper(root->right);
        int cur = left + right;
        if(cur > maximal) maximal = cur;
        return max(left , right)+1;
    }
};

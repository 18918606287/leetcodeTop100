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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL)
            if(root->right == NULL) return true;
            else return false;
        else if(root->right == NULL) return false;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root->left);
        stk2.push(root->right);
        while(!stk1.empty() && !stk2.empty()){
            TreeNode* cur1 = stk1.top();
            TreeNode* cur2 = stk2.top();
            stk1.pop();
            stk2.pop();
            if(cur1->val != cur2->val) return false;
            if(cur1->left != NULL && cur2->right != NULL){
                stk1.push(cur1->left);
                stk2.push(cur2->right);
            } else if(cur1->left != NULL || cur2->right != NULL) return false;
                
            if(cur1->right != NULL && cur2->left != NULL){
                stk1.push(cur1->right);
                stk2.push(cur2->left);
            } else if(cur1->right != NULL || cur2->left != NULL) return false;
        }
        if(!stk1.empty() || !stk2.empty()) return false;
        return true;
    }
};

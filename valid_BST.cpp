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
bool ret = true;
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> arr;
        validHelper(arr, root);
        return is_sorted(arr.begin(), arr.end()) && !hasDup(arr);
    }
private:
    void validHelper(vector<int>& arr, TreeNode* root){
        if(!root) return;
        validHelper(arr, root->left);
        arr.push_back(root->val);
        validHelper(arr, root->right);
        return;
    }
    bool hasDup(vector<int>& arr){
        for(int i = 1; i < arr.size(); i++){
            if (arr[i] == arr[i-1]) return true;
        }
        return false;
    }
};

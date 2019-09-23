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
    int cnt = 0;
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        unordered_map<int, int> path;
        path[0]++;
        backtrace(root, sum, root->val, path);
        return this->cnt;
    }
private:
    void backtrace(TreeNode* root, int sum, int partSum, unordered_map<int, int>& path){
        if(root == NULL) return;
        if(path.find(partSum - sum) != path.end()){
            //cout<<partSum - sum<<"?"<<endl;
            //See a continous subarray(i,j) as two sum(j) - sum(i), store all number of sum(k).
            this->cnt += path[partSum - sum];
        }
            
        path[partSum]++;
        if(root->left) backtrace(root->left, sum, partSum + root->left->val, path);
        if(root->right) backtrace(root->right, sum, partSum + root->right->val, path);
        if(path[partSum] > 1) path[partSum]--;
        else path.erase(partSum);
        return ;
    }
};

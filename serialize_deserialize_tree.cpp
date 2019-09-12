/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "[]";
        string ret = "[";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> new_q;
            bool flag = false;
            string sub = "";
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                if(cur != NULL){
                    flag = true;
                    sub += to_string(cur->val);
                    sub += ",";
                    new_q.push(cur->left);
                    new_q.push(cur->right);
                } else sub += "null,";
            }
            if(flag){
                q = new_q;
                ret += sub;
            }
        }
        
        //delete 'null's in the back. 
        int j = ret.length();
        int i = j - 5;
        while(i >= 0 && ret.substr(i, j-i) == "null,") {
            j -= 5;
            i -= 5;
        }
        ret = ret.substr(0, i+5);
        
        ret[ret.length()-1] = ']';
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]") return NULL;
        vector<TreeNode*> q = split(data);
        TreeNode* root = q[0];
        TreeNode* cur = root;
        int idx = 0;
        int i = 1;
        while(i < q.size()){
            while(q[idx] == NULL) idx++;
            cur = q[idx];
            cur->left = q[i];
            if(i+1 >= q.size()) return root;
            cur->right = q[i+1];
            i += 2;
            idx++;
        }
        return root;
    }
    vector<TreeNode*> split(string& data){
        vector<TreeNode*> q;
        
        int i = 1;
        int j = 1;
        while(i < data.length()){
            while(data[j] != ',' && data[j] != ']') j++;
            string sub = data.substr(i,j-i);
            if(sub == "null") q.push_back(NULL);
            else q.push_back(new TreeNode(stoi(sub)));
            j++;
            i = j;
        }
        return q;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

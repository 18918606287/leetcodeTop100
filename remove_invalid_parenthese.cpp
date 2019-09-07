class Solution {
public:
    int maxL = 0;
    vector<string> removeInvalidParentheses(string s) {
        
        int left = 0, right = 0;
        for(char& c:s){
            if(c == '(') left++;
            else if(c ==')'){
                if(left <= 0) right++;
                else left--;
            }
        }
        set<string> ans;
        backtrace(s, 0, 0, 0, left, right, "", ans);
        return vector<string>(ans.begin(), ans.end());
    }
private:
    void backtrace(string& s, int idx, int left, int right, int leftRem, int rightRem, string solution, set<string>& ans){
        if(s.length() == idx){
            if(leftRem == 0 && rightRem == 0){
                if(solution.length() > maxL){
                    ans.clear();
                    maxL = solution.length();
                    ans.insert(solution);
                } else if(solution.length() == maxL) ans.insert(solution);
            }
        return;
        }
        if(left < right) return;
        if(s[idx] == '('){
            backtrace(s, idx+1, left+1, right, leftRem, rightRem, solution + s[idx], ans);
            if(leftRem > 0)
                backtrace(s, idx+1, left, right, leftRem-1, rightRem, solution, ans);
        } else if(s[idx] == ')') {
            if(left >= right)
                backtrace(s, idx+1, left, right+1, leftRem, rightRem, solution + s[idx], ans);
            if(rightRem > 0)
                backtrace(s, idx+1, left, right, leftRem, rightRem-1, solution, ans);
        } else backtrace(s, idx+1, left, right, leftRem, rightRem, solution + s[idx], ans);
        
        return ;
    }
};

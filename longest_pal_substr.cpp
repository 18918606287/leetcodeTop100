class Solution {
public:
    string longestPalindrome(string s) {
        string new_s = "#";
        
        for(char c:s){
            new_s += c;
            new_s += "#";
        }
        vector<int> radius(new_s.length(), 0);
        int left_bound = 0;
        int round_idx = 0;
        int maxR = 0;
        string ret = "";
        for(int i = 0; i < new_s.length(); i++){
            int r = 0;
            if(2*round_idx >= i) r = min(left_bound - i, radius[2*round_idx - i]);
            while(i >= r && i + r < new_s.length() && new_s[i+r] == new_s[i-r]) r++;
            if(i+r > left_bound){
                left_bound = i+r;
                round_idx = i;
            }
            if(maxR < r){
                ret = s.substr((i-r+1)/2, r-1);
                maxR = r;
            }
            radius[i] = r;
        }
        return ret;
    }
};

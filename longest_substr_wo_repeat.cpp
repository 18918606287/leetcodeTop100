class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int loc[256];
        for(int i = 0; i < 256; i++) loc[i] = -1;
        int start = 0;
        int ret = 0;
        for(int i = 0; i < s.length(); i++){
            if(loc[s[i]] >= start)
                start = loc[s[i]] + 1;
            loc[s[i]] = i;
            ret = max(i - start + 1, ret);
        }
        return ret;
    }
};

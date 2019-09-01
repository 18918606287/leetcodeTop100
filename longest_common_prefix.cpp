class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs[0];
        string common = common_of_two(strs[0], strs[1]);
        for(string& str:strs)
            common = common_of_two(str, common);
        return common;
    }
    
private:
    string common_of_two(string& str1, string& str2){
        if(str1.length() > str2.length()) swap(str1, str2);
        for(int i = 0; i < str1.length(); i++)
            if(str1[i] != str2[i]) return str1.substr(0, i);
        return str1;
    }
};

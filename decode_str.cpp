class Solution {
public:
    string decodeString(string s) {
        return decodeHelper(s, 0, s.length());
    }
private:
    string decodeHelper(string& s, int i, int j){
        if(i == j || i == j-1) return s.substr(i, j-i);
        string ret = "";
        int k = i;
        int sum = 0;
        while(k < j && (s[k] < '0' || s[k] > '9')) ret += s[k++];
        while(k < j && s[k] >= '0' && s[k] <= '9') sum = sum * 10 + s[k++] - '0';
       // cout<<sum<<endl;
        //if(k == j) return s.substr(i, j);
        if(s[k] == '['){
            int l = k+1;
            int left = 1;
            while(l < j){
                if(s[l] == '[') left++;
                else if(s[l] == ']') left--;
                if(left == 0) break;
                l++;
            }
            string subs = decodeHelper(s, k+1, l);
            //cout<<subs<<endl;
            for(int _ = 0; _ < sum; _++)
                ret += subs;
            return ret + decodeHelper(s, l+1, j);
        }
        return s.substr(i, j-i);
    }
};

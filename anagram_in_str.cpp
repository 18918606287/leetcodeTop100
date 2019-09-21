class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return vector<int>();
        vector<int> a1(26,0);
        vector<int> a2(26,0);
        int k = p.size();
        for(auto c:p){
            a1[c-'a'] += 1;
        }
        for(int i = 0; i < k; i++){
            a2[s[i]-'a'] += 1;
        }
        vector<int> ret;
        if(a1 == a2) ret.push_back(0);
        for(int i = k; i < s.size(); i++){
            a2[s[i]-'a']++;
            a2[s[i-k]-'a']--;
            if(a1==a2) ret.push_back(i-k+1);
        }
        return ret;
    }
};

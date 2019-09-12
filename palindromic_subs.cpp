class Solution {
public:
    int countSubstrings(string s) {
        string newS = "#";
        for(char& c:s){
            newS += c;
            newS += "#";
        }
        int cunt = 0;
        int N = newS.length();
        int rightMax = 0;
        int lastIdx = 0;
        vector<int> radius(N, 0);
        for(int i = 0; i < N; i++){
            int r = 0;
            if(lastIdx*2 - i >= 0) r = min(radius[lastIdx*2 - i], rightMax - i);
            while(r <= i && i+r < newS.length() && newS[i+r] == newS[i-r]) r++;
            if(rightMax < i+r){
                rightMax = i+r;
                lastIdx = i;
            }
            radius[i] = r;
            cunt += r/2;
        }
        return cunt;
    }
};

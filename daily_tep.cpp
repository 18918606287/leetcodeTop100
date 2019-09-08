class Solution {
public:
    int _=[](){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        return 0;
    }();
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans = vector<int>(n, 0);
        for(int i = n-2; i >= 0; i--){
            if(T[i] < T[i+1]) ans[i] = 1;
            else{
                int j = i+1;
                while(j < n && T[j] <= T[i] && ans[j] != 0) j += ans[j];
                if(j != n && (T[j] > T[i])) ans[i] = j - i;
            }
        }
        return ans;
    }
};

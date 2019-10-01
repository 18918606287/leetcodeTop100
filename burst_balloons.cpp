class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        //memo[l][r] means the max from idx l to r, recursion from last choice.
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, 0));
        for(int diff = 0; diff <= n+1; diff++)
            for(int l = 0; l <= n+1-diff; l++){
                int r = l+diff;
                for(int i = l+1; i < r; i++){
                    int left = l>=1?nums[l-1]:1;
                    int right = r<=n?nums[r-1]:1;
                    memo[l][r] = max(memo[l][r], memo[l][i] + memo[i][r] + nums[i-1]*left*right);
                }
            }
        return memo[0][n+1];
    }
};

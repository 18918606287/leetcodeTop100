class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        std::sort(coins.rbegin(), coins.rend());
        dfs(0, coins, amount, 0);
        if(ans == INT_MAX) return -1;
        return ans;
    }
private:
    int ans = INT_MAX;
    void dfs(int index, vector<int>& coins, int amount, int k){
        if(index == coins.size()-1){
            if(amount%coins[index] == 0)
                ans = min(ans, k + amount/coins[index]);
            return;
        }
        
        for(int i = amount/coins[index]; i >= 0 && k+i < ans; i--)//k+1 < ans is purning
            dfs(index+1, coins, amount - i*coins[index], k+i);
    }
};

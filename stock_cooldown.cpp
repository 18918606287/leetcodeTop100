class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        vector<int> hold_stock(n, 0), hold_no_stock(n, 0), cooldown(n, 0);
        hold_stock[0] = -prices[0];
        cooldown[0] = INT_MIN;
        for(int i = 1; i < n; i++){
            hold_no_stock[i] = max(hold_no_stock[i-1], cooldown[i-1]);
            hold_stock[i] = max(hold_stock[i-1], hold_no_stock[i-1] - prices[i]);
            cooldown[i] = max(cooldown[i-1], hold_stock[i-1] + prices[i]);
        }
        return max(cooldown[cooldown.size()-1], hold_no_stock[hold_no_stock.size()-1]);
    }
};

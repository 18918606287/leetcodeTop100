class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int buy = prices[0];
        int maxPro = 0;
        for(int price:prices){
            if(price < buy){
                buy = price;
            } 
            maxPro = max(maxPro, price-buy);
        }
        return maxPro;
    }
};

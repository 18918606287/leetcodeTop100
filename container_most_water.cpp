class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);        
        std::cin.tie(nullptr);        
        std::cout.tie(nullptr);
    }
    int maxArea(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size();
        int i = 0;
        int j = n-1;
        int maxA = (j-i)*min(height[i],height[j]);
        while(i < j){
            maxA = max(maxA, (j-i)*min(height[i],height[j]));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxA;
    }
};

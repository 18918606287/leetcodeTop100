class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int maxIdx = 0;
        int j = 0;
        int h = height[0];
        int water = 0;
        int cur = 0;
        int n = height.size();
        for(int i = 0; i < height.size(); i++){
            if(height[i] >= h){
                h = height[i];
                water += cur;
                cur = 0;
                maxIdx = i;
            } else {
                cur += h - height[i];
            }
        }
        h = height[n-1];
        cur = 0;
        for(int i = n - 1; i >= maxIdx;i--){
            if(height[i] >= h){
                h = height[i];
                water += cur;
                cur = 0;
            } else {
                cur += h - height[i];
            }
        }
        return water;
    }
};

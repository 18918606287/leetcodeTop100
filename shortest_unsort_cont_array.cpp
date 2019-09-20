class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int maximal = INT_MIN, minimal = INT_MAX;
        int l = -1, r = -1;
        for(int i = 0; i < n; i++){
            maximal = max(maximal, nums[i]);
            if(nums[i] < maximal) r = i;
        }
        for(int i = n-1; i >= 0; i--){
            minimal = min(minimal, nums[i]);
            if(nums[i] > minimal) l = i;
        }
        return r-l>0?r-l+1:0;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int j = n-1;
        for(int k = 0; k <= j; k++)
            if(nums[k] == 0) swap(nums[i++], nums[k]);
            else if (nums[k] == 2) swap(nums[j--], nums[k--]);
        return ;
    }
};

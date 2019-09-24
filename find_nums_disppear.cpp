class Solution {
public:
    int __ =[](){
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        return 0;
    }();
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int idx = abs(nums[i])-1;
            if(nums[idx] > 0)
                nums[idx] = -abs(nums[idx]);
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                res.push_back(i+1);            
        }
        return res;
    }
};

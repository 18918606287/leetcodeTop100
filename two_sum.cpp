class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> idx;
        for(int i = 0; i < nums.size(); i++){
            if(idx.find(target - nums[i]) == idx.end()) idx[nums[i]] = i;
            else return {idx[target-nums[i]], i};
        }
        return vector<int>();
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int exo = 0;
        for(int& num:nums)
            exo ^= num;
        return exo;
    }
};

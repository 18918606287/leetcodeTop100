class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == 0){
                if(j < i)
                    j = i + 1;
                while(j < nums.size() && nums[j] == 0) j++;
                if(j != nums.size() && j > i)
                    swap(nums[i], nums[j]);
            } else j = max(j,i);
        }
        return ;
    }
};

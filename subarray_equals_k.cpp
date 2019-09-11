class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;

        unordered_map<int, int> umap; //sum --> count
        int result = 0;
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) result++; //XXX instead of umap[0] = 1
            
            if (umap.count(sum-k)) {
                result += umap[sum-k];
            }
            
            umap[sum]++;
        }
        
        return result;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> mp;
        for(int num : nums){
            sum += num;
            mp[num]++;
        } 
        if(sum%2 == 1) return false;
        sum /= 2;
        return dfs(mp, 0, sum);
    }
private:
    bool dfs(unordered_map<int, int>& mp, int sum, int& target){
        if(sum == target) return true;
        if(sum > target) return false;
        else {
            for(auto& it: mp){
                if(it.second <= 0) continue;
                it.second--;
                if(dfs(mp, sum + it.first, target)) return true;
                it.second++;
            }
        }
        return false;
    }
};

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if(intervals.empty()) return ret;
        sort(intervals.begin(), intervals.end(), cmp);
        ret.push_back(intervals[0]);
        int last = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] <= ret[last][1])
                ret[last][1] = max(ret[last][1], intervals[i][1]);
            else{
                ret.push_back(intervals[i]);
                last++;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for(auto interval:intervals){
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int s = 0;
        int e = 0;
        int cur = 0;
        int maximal = 0;
        while(s < starts.size() && e < ends.size()){
            while(s < starts.size() && starts[s] < ends[e]){
                s++;
                cur++;
            }
            if(cur > maximal ) maximal = cur;
            cur--;
            e++;
        }
        return maximal;
    }
};

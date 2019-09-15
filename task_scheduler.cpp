class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> num(26, 0);
        for(char c:tasks) num[c-'A']++;
        sort(num.begin(), num.end());
        int max_val = num[25] - 1;
        int idle = max_val * n;
        for(int i = 24; i >= 0 &&num[i] > 0; i--)
            idle -= min(num[i], max_val);
        //the situation that no idle and there's more 
        idle = max(0, idle);
        //calculate the number of idle and add the length of tasks
        return idle + tasks.size();
    }
};

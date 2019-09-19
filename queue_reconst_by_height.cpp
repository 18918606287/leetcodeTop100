class Solution {
public:
    int _ = [](){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return 0;
    }();
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ret(people.size(), vector<int>());
        sort(people.begin(), people.end(), this->cmp);
        for(auto& p:people){
            int i = 0;
            int order = 0;
            while(i < ret.size()){
                if(!ret[i].size()) order++;
                if(order == p[1]+1) break;
                i++;
            }
            //if(i == ret.size()) cout<<"here"<<endl;
            ret[i].push_back(p[0]);
            ret[i].push_back(p[1]);
        }
        return ret;
    }
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
};

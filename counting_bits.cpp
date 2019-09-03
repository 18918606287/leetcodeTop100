int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        ret.push_back(0);
        for(int i = 1; i <= num; i++)
            ret.push_back(ret[i>>1] + (i&1));
        return ret;
    }
};

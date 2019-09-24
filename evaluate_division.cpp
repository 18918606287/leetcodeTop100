class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        if(equations.empty() || queries.empty()) return vector<double>();
        unordered_map<string, vector<string>> edge;
        map<pair<string, string>, double> val;
        set<string> visited;
        for(int i = 0; i < values.size(); i++){
            edge[equations[i][0]].push_back(equations[i][1]);
            edge[equations[i][1]].push_back(equations[i][0]);
            val[{equations[i][0], equations[i][1]}] = values[i];
            val[{equations[i][1], equations[i][0]}] = 1.0/values[i];
        }
        vector<double> ret;
        for(auto q:queries){
            ret.push_back(dfs(q[0], q[1], edge, val, visited));
        }
        return ret;
    }
private:
    double dfs(string start, string end, unordered_map<string, vector<string>>& edge, map<pair<string, string>, double>& val, set<string>& visited){
        if(edge.find(start) == edge.end() || edge.find(end) == edge.end()) return -1;
        if(start == end) return 1;
        if(val.find({start, end}) != val.end()) return val[{start,end}];
        visited.insert(start);
        vector<string> next_nodes = edge[start];
        for(string nxt:next_nodes){
            if(visited.find(nxt) == visited.end()){
                double subgraph = dfs(nxt, end, edge, val, visited);
                if(subgraph != -1){
                    visited.erase(start);
                    return subgraph*val[{start, nxt}];
                }
            }
        }
        visited.erase(start);
        return -1;
    }
};

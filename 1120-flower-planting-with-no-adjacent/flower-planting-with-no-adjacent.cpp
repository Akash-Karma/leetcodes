class Solution {
private:
    bool solve(vector<vector<int>> &adj, vector<int>& color, int node, int n){
        if(node >= n) return true;
        if(color[node] == 0){
            for(int i=1; i<=4; i++){
                if(isValid(adj, color, node, i)){
                    color[node] = i;
                    if(solve(adj, color, node+1, n)) return true;
                    color[node] = 0;
                }
            }
            return false;
        }
        return true;
    }

    bool isValid(vector<vector<int>> &adj, vector<int>& color, int node, int i){
        for(auto it: adj[node]){
            if(color[it] == i) return false;
        }
        return true;
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(auto it: paths){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        vector<int> ans;
        vector<int> color(n,0);
        solve(adj, color, 0, n);
        return color;
    }
};
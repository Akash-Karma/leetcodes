class Solution {
private:
    int dfs(vector<vector<int>> &adj, int idx, int k, vector<bool>& vis){
        vis[idx] = 1;
        if(k<0) return 0;
        if(k == 0) return 1;
        int nodes = 1;
        for(auto it: adj[idx]){
            if(!vis[it]) nodes += dfs(adj, it, k-1, vis);
        }
        return nodes;
    } 
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> adj1(edges1.size()+1);
        vector<vector<int>> adj2(edges2.size()+1);
        for(auto it: edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto it: edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        vector<int> ans(adj1.size());
        for(int i=0; i<adj1.size(); i++){
            vector<bool> vis(adj1.size(), 0);
            ans[i] = dfs(adj1, i, k, vis);
        }
        int maxi= 0;
        for(int i=0; i<adj2.size(); i++){
            vector<bool> vis(adj2.size(), 0);
            maxi = max(maxi, dfs(adj2, i, k-1, vis));
        }
        for(auto &it: ans) it+=maxi;
        return ans;

    }
};
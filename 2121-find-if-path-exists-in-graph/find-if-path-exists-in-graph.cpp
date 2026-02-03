class Solution {
private:
    bool dfs(vector<vector<int>>& adj, int source, int destination, vector<bool> &vis){
        vis[source]=1;
        for(auto it : adj[source]){
            if(it==destination) return true;
            if(!vis[it]){
                if(dfs(adj,it,destination,vis)) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true; 
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,0);
        return dfs( adj,source,destination,vis);
    }
};
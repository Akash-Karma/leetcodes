class Solution {
private:
    void dfs(int node, vector<bool> &vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it, vis, adj);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool> vis(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]) count++;dfs(i,vis,adj);

        }
            return count;

    }
};
class Solution {
private:
    bool bipartite(int idx, bool color, vector<int> & vis,vector<vector<int>>& adj ){

        vis[idx]=color;
        for(auto &it :adj[idx]){
            if(vis[it]==-1){
                if( !(bipartite(it,!color,vis,adj))) return false;
            }
            else{
                if(vis[it]==color) return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        for(auto &e:dislikes){
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
            if(!(bipartite(i,0,vis,adj))) return false;
        }
        }
    return true;
    }
};
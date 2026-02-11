class Solution {
private:
    bool bipartite(vector<vector<int>>& graph, int start, vector<int> &vis){
        queue<int> q;
        q.push(start);
        vis[start]=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto &it:graph[temp]){
                if(vis[it]==-1){
                    vis[it]=!vis[temp];
                    q.push(it);
                }
                else{
                    if(vis[it]==vis[temp]) return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
        bool check=false;
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1)
            if(!(bipartite(graph,i,vis))) return false;
        }
        return true;
    }
};
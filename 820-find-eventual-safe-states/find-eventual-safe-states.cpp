class Solution {
private:
    bool dfs(vector<vector<int>>& graph,vector<bool> &vis,vector<bool> &path,vector<bool> &check, int idx){
        vis[idx]=1;
        check[idx]=0;
        path[idx]=1;
        for(auto &it:graph[idx]){
            if(!vis[it]){
                
                if(dfs(graph,vis,path,check,it)){
                    check[idx]=0;
                    return true;
                }
            }
            else if(path[it]==1){
                check[idx]=0;
                return true;
            }
        }
        check[idx]=1;
        path[idx]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        vector<bool> vis(graph.size(),0);
        vector<bool> path(graph.size(),0);
        vector<bool> check(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                dfs(graph,vis,path,check,i);
            }
        }
        for(int i=0;i<path.size();i++){
            if(check[i]==1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
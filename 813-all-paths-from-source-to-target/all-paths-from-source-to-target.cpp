class Solution {
private:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans, vector<int> &path, int start, int finish){
        path.push_back(start);
    if(start==finish){
        ans.push_back(path);
        path.pop_back();
        return;
    }
        for(auto &e:graph[start]){
            dfs(graph,ans,path,e,finish);
        }
        path.pop_back();
            
}
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph,ans,path,0,graph.size()-1);
        return ans;
    }
};
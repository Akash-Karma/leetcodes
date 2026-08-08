class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int topoSort = 0;
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort++;
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return numCourses == topoSort;
    }
};
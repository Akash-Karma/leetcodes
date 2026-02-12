class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topoSort;
        queue<int> q;
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto & e: prerequisites){
            adj[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            topoSort.push_back(temp);
            for(auto &e:adj[temp]){
                inDegree[e]--;
                if(inDegree[e]==0) q.push(e);
            }
        }
        return topoSort.size()==numCourses;
    }
};
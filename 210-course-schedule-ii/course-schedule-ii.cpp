class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        for(auto &e:prerequisites){
            adj[e[1]].push_back(e[0]);
            inDegree[e[0]]++;

        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(auto & it: adj[temp]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};
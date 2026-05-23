class Solution {
private:
    void dfs(vector<int> &edges, vector<int>& dist, int node, int time){
        if(dist[node]>0) return;
        dist[node]=time;
        if(edges[node]==-1) return;
        
        int next=edges[node];
        if(dist[next]==-1)
        dfs(edges,dist, next,time+1 );

    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1(edges.size(),-1), dist2(edges.size(),-1);

        dfs(edges, dist1, node1, 0);
        dfs(edges, dist2, node2, 0);
        int ans=-1, minW=INT_MAX;
        for(int i=0;i<edges.size();i++){
            if(dist1[i]>=0 && dist2[i]>=0){
                int d=max(dist1[i], dist2[i]);
                if(minW>d){
                    minW=d;
                    ans=i;
                }
                
            }
        }
        return ans;
    }
};
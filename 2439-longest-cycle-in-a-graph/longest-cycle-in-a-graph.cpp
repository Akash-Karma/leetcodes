class Solution {
int ans=-1;
private:
    void dfs(vector<int> &edges, vector<int> &timer, int i, int time){
        if(timer[i]==-1) return;
        if(edges[i]==-1){
            timer[i]=-1;
            return;
        }

        timer[i]=time;

        if(timer[edges[i]]==0){
            dfs(edges, timer, edges[i], time+1);
        }
        else if(timer[edges[i]]>0){
            ans=max(ans, timer[i]-timer[edges[i]]+1);
        }
        timer[i]=-1;
    }
public:
    int longestCycle(vector<int>& edges) {
        vector<int> timer(edges.size(), 0); //0:not visited, -1: already processed, >0: in process

        for(int i=0;i<edges.size();i++){
            if(timer[i]==0){
                dfs(edges, timer, i, 0);
            }
        }
        return ans;
    }
};